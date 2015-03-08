#include "types.h"
#include "Graphics.h"//GraphicsManageもここで取り込まれる
#include "Window.h"//WinDataもここで取り込まれる
#include <d3d11.h>
#include <DirectXMath.h>
#include "DDSTextureLoader.h"
#include "..\\shader\\vs.h"
#include "..\\shader\\ps.h"

#pragma comment(lib, "d3d11.lib")
#ifndef _DEBUG
#    pragma comment(lib, "DirectXTex.lib")
#else
#    pragma comment(lib, "DirectXTex_d.lib")
#endif

#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }

namespace Azalea{

GRAPHICSMANAGE GraphicsManage;

// 描画周りの基本的な情報
GRAPHICSSYSTEMDATA GraphicsSysData;


//XXX:設計イケテない。
void SetTexutureFile(LPCWSTR texPath)
{
	HWND hWnd = WinData.MainWindow;

	//テクスチャ読み込み
	if (FAILED(DirectX::CreateDDSTextureFromFile(GRH.hpDevice, texPath, NULL, &GRH.hpShaderResourceView))) {
		MessageBox(hWnd, _T("CreateDDSTextureFromFile"), _T("Err"), MB_ICONSTOP);
		TerminateDirectX();
	}

	//テクスチャをコンテキストに設定
	ID3D11ShaderResourceView* hpShaderResourceViews[] = { GRH.hpShaderResourceView };
	GRH.hpDeviceContext->PSSetShaderResources(0, 1, hpShaderResourceViews);
}

int InitializeDirectX(void)
{
	HWND hWnd = WinData.MainWindow;

	//デバイスの生成
	HRESULT hr;
	hr = D3D11CreateDevice(
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		0,
		NULL,
		0,
		D3D11_SDK_VERSION,
		&GRH.hpDevice,
		NULL,
		&GRH.hpDeviceContext);
	if FAILED(hr)
	{
		MessageBox(hWnd, _T("D3D11CreateDevice"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//インターフェース取得
	if (FAILED(GRH.hpDevice->QueryInterface(__uuidof(IDXGIDevice1), (void**)&GRH.hpDXGI))){
		MessageBox(hWnd, _T("QueryInterface"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//アダプター取得
	if (FAILED(GRH.hpDXGI->GetAdapter(&GRH.hpAdapter))){
		MessageBox(hWnd, _T("GetAdapter"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//ファクトリー取得
	GRH.hpAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&GRH.hpDXGIFactory);
	if (GRH.hpDXGIFactory == NULL){
		MessageBox(hWnd, _T("GetParent"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//ALT+Enterでフルスクリーンを許可する
	if (FAILED(GRH.hpDXGIFactory->MakeWindowAssociation(hWnd, 0))){
		MessageBox(hWnd, _T("MakeWindowAssociation"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//スワップチェイン作成
	GRH.hDXGISwapChainDesc.BufferDesc.Width = 1980;
	GRH.hDXGISwapChainDesc.BufferDesc.Height = 1080;
	GRH.hDXGISwapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
	GRH.hDXGISwapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	GRH.hDXGISwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
	GRH.hDXGISwapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	GRH.hDXGISwapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	GRH.hDXGISwapChainDesc.SampleDesc.Count = 1;
	GRH.hDXGISwapChainDesc.SampleDesc.Quality = 0;
	GRH.hDXGISwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	GRH.hDXGISwapChainDesc.BufferCount = 1;
	GRH.hDXGISwapChainDesc.OutputWindow = hWnd;
	GRH.hDXGISwapChainDesc.Windowed = TRUE;
	GRH.hDXGISwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	GRH.hDXGISwapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	if (FAILED(GRH.hpDXGIFactory->CreateSwapChain(GRH.hpDevice, &GRH.hDXGISwapChainDesc, &GRH.hpDXGISwpChain))){
		MessageBox(hWnd, _T("CreateSwapChain"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//そのスワップチェインのバックバッファ取得
	if (FAILED(GRH.hpDXGISwpChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&GRH.hpBackBuffer))){
		MessageBox(hWnd, _T("SwpChain GetBuffer"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//そのバックバッファから描画ターゲット生成
	if (FAILED(GRH.hpDevice->CreateRenderTargetView(GRH.hpBackBuffer, NULL, &GRH.hpRenderTargetView))){
		MessageBox(hWnd, _T("CreateRenderTargetView"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//更にその描画ターゲットをコンテキストに設定
	GRH.hpDeviceContext->OMSetRenderTargets(1, &GRH.hpRenderTargetView, NULL);

	//ビューポート設定
	GRH.vp.TopLeftX = 0;
	GRH.vp.TopLeftY = 0;
	GRH.vp.Width = 1920;
	GRH.vp.Height = 1080;
	GRH.vp.MinDepth = 0.0f;
	GRH.vp.MaxDepth = 1.0f;
	GRH.hpDeviceContext->RSSetViewports(1, &GRH.vp);

	//ポリゴン頂点構造体
	struct Vertex3D {
		float pos[3];	//x-y-z
		float col[4];	//r-g-b-a
		float tex[2];   //x-y
	};

	////頂点データ(三角ポリゴン1枚)
	//Vertex3D hVectorData[TYOUTEN] = {
	//	{ { +0.0f, +0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { +0.5f, -0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, -0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } }
	//};
	////頂点データ(四角ポリゴン1枚)
	//Vertex3D hVectorData[TYOUTEN] = {
	//	{ { +0.5f, +0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, +0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { +0.5f, -0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, -0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } }
	//};
	////頂点データ(五角ポリゴン1枚)
	//Vertex3D hVectorData[TYOUTEN] = {
	//	{ { +0.0f, +0.8f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { +0.5f, +0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, +0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { +0.5f, -0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, -0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } }
	//};
	////頂点データ(六角ポリゴン1枚)
	//Vertex3D hVectorData[TYOUTEN] = {
	//	{ { +0.0f, +0.8f, +0.5f }, { 0.0f, 0.0f, 0.0f, 1.0f } },
	//	{ { +0.5f, +0.4f, +0.5f }, { 0.0f, 0.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, +0.4f, +0.5f }, { 0.0f, 1.0f, 0.0f, 1.0f } },
	//	{ { +0.5f, -0.4f, +0.5f }, { 0.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, -0.4f, +0.5f }, { 1.0f, 0.0f, 0.0f, 1.0f } },
	//	{ { +0.0f, -0.8f, +0.5f }, { 1.0f, 0.0f, 1.0f, 1.0f } }
	//};
	////頂点データ(四角ポリゴン1枚)
	//Vertex3D hVectorData[TYOUTEN] = {
	//	//500x811
	//	{ { -0.27f, +0.75f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f } },
	//	{ { +0.27f, +0.75f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 1.0f, 0.0f } },
	//	{ { -0.27f, -0.75f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f } },
	//	{ { +0.27f, -0.75f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f } }
	//};
	////頂点データ(六角ポリゴン1枚)
	//Vertex3D hVectorData[TYOUTEN] = {
	//	//500x811
	//	{ { +0.0f, +0.75f, +0.5f }, { 0.0f, 0.0f, 0.0f, 0.0f }, { +0.5f, +0.0f } },
	//	{ { +0.4f, +0.35f, +0.5f }, { 0.0f, 0.0f, 0.0f, 0.0f }, { +1.25f, +0.27f } },
	//	{ { -0.4f, +0.35f, +0.5f }, { 0.0f, 0.0f, 0.0f, 0.0f }, { -0.25f, +0.27f } },
	//	{ { +0.4f, -0.35f, +0.5f }, { 0.0f, 0.0f, 0.0f, 0.0f }, { +1.25f, +0.73f } },
	//	{ { -0.4f, -0.35f, +0.5f }, { 0.0f, 0.0f, 0.0f, 0.0f }, { -0.25f, +0.73f } },
	//	{ { +0.0f, -0.75f, +0.5f }, { 0.0f, 0.0f, 0.0f, 0.0f }, { +0.5f, +1.00f } },
	//};
	Vertex3D hVectorData[TYOUTEN] = {
		//500x811
		{ { -0.27f, +0.55f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f } },
		{ { +0.27f, +0.55f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 1.0f, 0.0f } },
		{ { -0.27f, -0.55f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f } },
		{ { +0.27f, -0.55f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f } }
	};

	////頂点レイアウト
	////５番目のパラメータは先頭からのバイト数なので，COLORにはPOSITIONのfloat型4バイト×3を記述
	//D3D11_INPUT_ELEMENT_DESC hInElementDesc[] = {
	//		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	//		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 4 * 3, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	//};
	////頂点レイアウト
	//５番目のパラメータは先頭からのバイト数なので，COLORにはPOSITIONのfloat型4バイト×3を記述
	D3D11_INPUT_ELEMENT_DESC hInElementDesc[] = {
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 4 * 3, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 4 * 3 + 4 * 4, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	//頂点バッファ作成
	GRH.hBufferDesc.ByteWidth = sizeof(Vertex3D)* TYOUTEN;
	GRH.hBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	GRH.hBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	GRH.hBufferDesc.CPUAccessFlags = 0;
	GRH.hBufferDesc.MiscFlags = 0;
	GRH.hBufferDesc.StructureByteStride = sizeof(float);

	GRH.hSubResourceData.pSysMem = hVectorData;
	GRH.hSubResourceData.SysMemPitch = 0;
	GRH.hSubResourceData.SysMemSlicePitch = 0;

	if (FAILED(GRH.hpDevice->CreateBuffer(&GRH.hBufferDesc, &GRH.hSubResourceData, &GRH.hpBuffer))){
		MessageBox(hWnd, _T("CreateBuffer"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//その頂点バッファをコンテキストに設定
	UINT hStrides = sizeof(Vertex3D);
	UINT hOffsets = 0;
	GRH.hpDeviceContext->IASetVertexBuffers(0, 1, &GRH.hpBuffer, &hStrides, &hOffsets);

	//プリミティブ(ポリゴンの形状)をコンテキストに設定
	//GRH.hpDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);//三角形の場合
	GRH.hpDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);//四角形の場合

	//頂点レイアウト作成
	if (FAILED(GRH.hpDevice->CreateInputLayout(hInElementDesc, ARRAYSIZE(hInElementDesc), &g_vs_main, sizeof(g_vs_main), &GRH.hpInputLayout))){
		MessageBox(hWnd, _T("CreateInputLayout"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//頂点レイアウトをコンテキストに設定
	GRH.hpDeviceContext->IASetInputLayout(GRH.hpInputLayout);

	//頂点シェーダー生成
	if (FAILED(GRH.hpDevice->CreateVertexShader(&g_vs_main, sizeof(g_vs_main), NULL, &GRH.hpVertexShader))){
		MessageBox(hWnd, _T("CreateVertexShader"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//ピクセルシェーダー生成
	if (FAILED(GRH.hpDevice->CreatePixelShader(&g_ps_main, sizeof(g_ps_main), NULL, &GRH.hpPixelShader))){
		MessageBox(hWnd, _T("CreateVertexShader"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//ラスタライザ生成
	GRH.hRasterizerDesc = {
		D3D11_FILL_SOLID,
		D3D11_CULL_NONE,	//プリミティブ(ポリゴンの形状)→ポリゴンの裏表を無くす
		FALSE,
		0,
		0.0f,
		FALSE,
		FALSE,
		FALSE,
		FALSE,
		FALSE
	};
	if (FAILED(GRH.hpDevice->CreateRasterizerState(&GRH.hRasterizerDesc, &GRH.hpRasterizerState))){
		MessageBox(hWnd, _T("CreateRasterizerState"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//ローカル座標
	//  ↓ワールド変換
	//ワールド座標
	//  ↓ビュー変換
	//カメラから見た座標
	//  ↓透視変換(透視射影変換)
	//遠近感のある座標
	//  ↓ビューポート(切り取り)
	//描画

	//ワールド変換用行列
	GSC.vWorld = DirectX::XMMatrixIdentity();
	DirectX::XMMATRIX hRotate;
	hRotate = DirectX::XMMatrixRotationZ(AZ_TO_RAD(-45.0f));//横に回転
	GSC.vWorld = XMMatrixMultiply(GSC.vWorld, hRotate);
	hRotate = DirectX::XMMatrixRotationY(AZ_TO_RAD(-45.0f));//縦に回転
	GSC.vWorld = XMMatrixMultiply(GSC.vWorld, hRotate);
	//ビュー変換用行列
	DirectX::XMVECTOR hEye = DirectX::XMVectorSet(0.0f, 0.0f, -1.0f/*奥行き？*/, 0.0f);	//カメラの位置
	DirectX::XMVECTOR hAt = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);		//焦点の位置
	DirectX::XMVECTOR hUp = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	GSC.vView = DirectX::XMMatrixLookAtLH(hEye, hAt, hUp);
	//透視射影変換行列
	GSC.vProjection = DirectX::XMMatrixPerspectiveFovLH(AZ_TO_RAD(45.0f)/*何に使うのか不明*/, 16.0f / 9.0f, 0.0f, 1000.0f);

	//シェーダに送る変換行列
	struct ConstantBuffer
	{
		DirectX::XMMATRIX mWorld;//ワールド変換行列
		DirectX::XMMATRIX mView;//ビュー変換行列
		DirectX::XMMATRIX mProjection;//透視射影変換行列
	};
	//変換行列バッファ作成
	///XXX:hBufferDescは管理不要よね？
	GRH.hBufferDesc.ByteWidth = sizeof(ConstantBuffer);
	GRH.hBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	GRH.hBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	GRH.hBufferDesc.CPUAccessFlags = 0;
	GRH.hBufferDesc.MiscFlags = 0;
	GRH.hBufferDesc.StructureByteStride = sizeof(float);
	if (FAILED(GRH.hpDevice->CreateBuffer(&GRH.hBufferDesc, NULL, &GRH.hpConstantBuffer))){
		MessageBox(hWnd, _T("ConstantBuffer"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	ConstantBuffer hConstantBuffer;
	hConstantBuffer.mWorld = DirectX::XMMatrixTranspose(GSC.vWorld);
	hConstantBuffer.mView = DirectX::XMMatrixTranspose(GSC.vView);
	hConstantBuffer.mProjection = DirectX::XMMatrixTranspose(GSC.vProjection);
	GRH.hpDeviceContext->UpdateSubresource(GRH.hpConstantBuffer, 0, NULL, &hConstantBuffer, 0, 0);

	//グラフィックパイプライン処理
	//頂点シェーダーをコンテキストに設定
	GRH.hpDeviceContext->VSSetShader(GRH.hpVertexShader, NULL, 0);
	//変換シェーダをコンテキストに設定
	GRH.hpDeviceContext->VSSetConstantBuffers(0, 1, &GRH.hpConstantBuffer);
	//ハルシェーダー：無し
	GRH.hpDeviceContext->HSSetShader(NULL, NULL, 0);
	//テッセレーターは無し
	//ドメインシェーダー：無し
	GRH.hpDeviceContext->DSSetShader(NULL, NULL, 0);
	//ジオメトリシェーダー：無し
	GRH.hpDeviceContext->GSSetShader(NULL, NULL, 0);
	//ラスタライザーをコンテキストに設定
	GRH.hpDeviceContext->RSSetState(GRH.hpRasterizerState);
	//ピクセルシェーダーをコンテキストに設定
	GRH.hpDeviceContext->PSSetShader(GRH.hpPixelShader, NULL, 0);

	return 0;
}

int TerminateDirectX(void)
{
	//ポインタで生成したものはリリースする必要がある
	//どの変数か識別し易いように，hpで始めてある

	SAFE_RELEASE(GRH.hpRenderTargetView);
	SAFE_RELEASE(GRH.hpBackBuffer);
	SAFE_RELEASE(GRH.hpDXGISwpChain);
	SAFE_RELEASE(GRH.hpDXGIFactory);
	SAFE_RELEASE(GRH.hpAdapter);
	SAFE_RELEASE(GRH.hpDXGI);
	SAFE_RELEASE(GRH.hpDeviceContext);
	SAFE_RELEASE(GRH.hpDevice);

	return 0;
}

int Draw(void)
{
	// 背景色設定
	GRH.BackColor[0] = 0.0f;
	GRH.BackColor[1] = 0.0f;
	GRH.BackColor[2] = 1.0f;
	GRH.BackColor[3] = 1.0f;
	GRH.hpDeviceContext->ClearRenderTargetView(GRH.hpRenderTargetView, GRH.BackColor);

	//描画
	GRH.hpDeviceContext->Draw(TYOUTEN, 0);

	return 0;
}
int Flip(void)
{
	//バックバッファをスワップ
	GRH.hpDXGISwpChain->Present(0, 0);

	return 0;
}


}//namespace Azalea


