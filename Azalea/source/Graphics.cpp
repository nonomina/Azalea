#include "types.h"
#include "Graphics.h"//GraphicsManage�������Ŏ�荞�܂��
#include "Window.h"//WinData�������Ŏ�荞�܂��
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

// �`�����̊�{�I�ȏ��
GRAPHICSSYSTEMDATA GraphicsSysData;


//XXX:�݌v�C�P�e�Ȃ��B
void SetTexutureFile(LPCWSTR texPath)
{
	HWND hWnd = WinData.MainWindow;

	//�e�N�X�`���ǂݍ���
	if (FAILED(DirectX::CreateDDSTextureFromFile(GRH.hpDevice, texPath, NULL, &GRH.hpShaderResourceView))) {
		MessageBox(hWnd, _T("CreateDDSTextureFromFile"), _T("Err"), MB_ICONSTOP);
		TerminateDirectX();
	}

	//�e�N�X�`�����R���e�L�X�g�ɐݒ�
	ID3D11ShaderResourceView* hpShaderResourceViews[] = { GRH.hpShaderResourceView };
	GRH.hpDeviceContext->PSSetShaderResources(0, 1, hpShaderResourceViews);
}

int InitializeDirectX(void)
{
	HWND hWnd = WinData.MainWindow;

	//�f�o�C�X�̐���
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

	//�C���^�[�t�F�[�X�擾
	if (FAILED(GRH.hpDevice->QueryInterface(__uuidof(IDXGIDevice1), (void**)&GRH.hpDXGI))){
		MessageBox(hWnd, _T("QueryInterface"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//�A�_�v�^�[�擾
	if (FAILED(GRH.hpDXGI->GetAdapter(&GRH.hpAdapter))){
		MessageBox(hWnd, _T("GetAdapter"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//�t�@�N�g���[�擾
	GRH.hpAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&GRH.hpDXGIFactory);
	if (GRH.hpDXGIFactory == NULL){
		MessageBox(hWnd, _T("GetParent"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//ALT+Enter�Ńt���X�N���[����������
	if (FAILED(GRH.hpDXGIFactory->MakeWindowAssociation(hWnd, 0))){
		MessageBox(hWnd, _T("MakeWindowAssociation"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//�X���b�v�`�F�C���쐬
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

	//���̃X���b�v�`�F�C���̃o�b�N�o�b�t�@�擾
	if (FAILED(GRH.hpDXGISwpChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&GRH.hpBackBuffer))){
		MessageBox(hWnd, _T("SwpChain GetBuffer"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//���̃o�b�N�o�b�t�@����`��^�[�Q�b�g����
	if (FAILED(GRH.hpDevice->CreateRenderTargetView(GRH.hpBackBuffer, NULL, &GRH.hpRenderTargetView))){
		MessageBox(hWnd, _T("CreateRenderTargetView"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//�X�ɂ��̕`��^�[�Q�b�g���R���e�L�X�g�ɐݒ�
	GRH.hpDeviceContext->OMSetRenderTargets(1, &GRH.hpRenderTargetView, NULL);

	//�r���[�|�[�g�ݒ�
	GRH.vp.TopLeftX = 0;
	GRH.vp.TopLeftY = 0;
	GRH.vp.Width = 1920;
	GRH.vp.Height = 1080;
	GRH.vp.MinDepth = 0.0f;
	GRH.vp.MaxDepth = 1.0f;
	GRH.hpDeviceContext->RSSetViewports(1, &GRH.vp);

	//�|���S�����_�\����
	struct Vertex3D {
		float pos[3];	//x-y-z
		float col[4];	//r-g-b-a
		float tex[2];   //x-y
	};

	////���_�f�[�^(�O�p�|���S��1��)
	//Vertex3D hVectorData[TYOUTEN] = {
	//	{ { +0.0f, +0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { +0.5f, -0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, -0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } }
	//};
	////���_�f�[�^(�l�p�|���S��1��)
	//Vertex3D hVectorData[TYOUTEN] = {
	//	{ { +0.5f, +0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, +0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { +0.5f, -0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, -0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } }
	//};
	////���_�f�[�^(�܊p�|���S��1��)
	//Vertex3D hVectorData[TYOUTEN] = {
	//	{ { +0.0f, +0.8f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { +0.5f, +0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, +0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { +0.5f, -0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, -0.5f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f } }
	//};
	////���_�f�[�^(�Z�p�|���S��1��)
	//Vertex3D hVectorData[TYOUTEN] = {
	//	{ { +0.0f, +0.8f, +0.5f }, { 0.0f, 0.0f, 0.0f, 1.0f } },
	//	{ { +0.5f, +0.4f, +0.5f }, { 0.0f, 0.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, +0.4f, +0.5f }, { 0.0f, 1.0f, 0.0f, 1.0f } },
	//	{ { +0.5f, -0.4f, +0.5f }, { 0.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, -0.4f, +0.5f }, { 1.0f, 0.0f, 0.0f, 1.0f } },
	//	{ { +0.0f, -0.8f, +0.5f }, { 1.0f, 0.0f, 1.0f, 1.0f } }
	//};
	////���_�f�[�^(�l�p�|���S��1��)
	//Vertex3D hVectorData[TYOUTEN] = {
	//	//500x811
	//	{ { -0.27f, +0.75f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f } },
	//	{ { +0.27f, +0.75f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 1.0f, 0.0f } },
	//	{ { -0.27f, -0.75f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f } },
	//	{ { +0.27f, -0.75f, +0.5f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f } }
	//};
	////���_�f�[�^(�Z�p�|���S��1��)
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

	////���_���C�A�E�g
	////�T�Ԗڂ̃p�����[�^�͐擪����̃o�C�g���Ȃ̂ŁCCOLOR�ɂ�POSITION��float�^4�o�C�g�~3���L�q
	//D3D11_INPUT_ELEMENT_DESC hInElementDesc[] = {
	//		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	//		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 4 * 3, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	//};
	////���_���C�A�E�g
	//�T�Ԗڂ̃p�����[�^�͐擪����̃o�C�g���Ȃ̂ŁCCOLOR�ɂ�POSITION��float�^4�o�C�g�~3���L�q
	D3D11_INPUT_ELEMENT_DESC hInElementDesc[] = {
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 4 * 3, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 4 * 3 + 4 * 4, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	//���_�o�b�t�@�쐬
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

	//���̒��_�o�b�t�@���R���e�L�X�g�ɐݒ�
	UINT hStrides = sizeof(Vertex3D);
	UINT hOffsets = 0;
	GRH.hpDeviceContext->IASetVertexBuffers(0, 1, &GRH.hpBuffer, &hStrides, &hOffsets);

	//�v���~�e�B�u(�|���S���̌`��)���R���e�L�X�g�ɐݒ�
	//GRH.hpDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);//�O�p�`�̏ꍇ
	GRH.hpDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);//�l�p�`�̏ꍇ

	//���_���C�A�E�g�쐬
	if (FAILED(GRH.hpDevice->CreateInputLayout(hInElementDesc, ARRAYSIZE(hInElementDesc), &g_vs_main, sizeof(g_vs_main), &GRH.hpInputLayout))){
		MessageBox(hWnd, _T("CreateInputLayout"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//���_���C�A�E�g���R���e�L�X�g�ɐݒ�
	GRH.hpDeviceContext->IASetInputLayout(GRH.hpInputLayout);

	//���_�V�F�[�_�[����
	if (FAILED(GRH.hpDevice->CreateVertexShader(&g_vs_main, sizeof(g_vs_main), NULL, &GRH.hpVertexShader))){
		MessageBox(hWnd, _T("CreateVertexShader"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//�s�N�Z���V�F�[�_�[����
	if (FAILED(GRH.hpDevice->CreatePixelShader(&g_ps_main, sizeof(g_ps_main), NULL, &GRH.hpPixelShader))){
		MessageBox(hWnd, _T("CreateVertexShader"), _T("Err"), MB_ICONSTOP);
		return TerminateDirectX();
	}

	//���X�^���C�U����
	GRH.hRasterizerDesc = {
		D3D11_FILL_SOLID,
		D3D11_CULL_NONE,	//�v���~�e�B�u(�|���S���̌`��)���|���S���̗��\�𖳂���
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

	//���[�J�����W
	//  �����[���h�ϊ�
	//���[���h���W
	//  ���r���[�ϊ�
	//�J�������猩�����W
	//  �������ϊ�(�����ˉe�ϊ�)
	//���ߊ��̂�����W
	//  ���r���[�|�[�g(�؂���)
	//�`��

	//���[���h�ϊ��p�s��
	GSC.vWorld = DirectX::XMMatrixIdentity();
	DirectX::XMMATRIX hRotate;
	hRotate = DirectX::XMMatrixRotationZ(AZ_TO_RAD(-45.0f));//���ɉ�]
	GSC.vWorld = XMMatrixMultiply(GSC.vWorld, hRotate);
	hRotate = DirectX::XMMatrixRotationY(AZ_TO_RAD(-45.0f));//�c�ɉ�]
	GSC.vWorld = XMMatrixMultiply(GSC.vWorld, hRotate);
	//�r���[�ϊ��p�s��
	DirectX::XMVECTOR hEye = DirectX::XMVectorSet(0.0f, 0.0f, -1.0f/*���s���H*/, 0.0f);	//�J�����̈ʒu
	DirectX::XMVECTOR hAt = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);		//�œ_�̈ʒu
	DirectX::XMVECTOR hUp = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	GSC.vView = DirectX::XMMatrixLookAtLH(hEye, hAt, hUp);
	//�����ˉe�ϊ��s��
	GSC.vProjection = DirectX::XMMatrixPerspectiveFovLH(AZ_TO_RAD(45.0f)/*���Ɏg���̂��s��*/, 16.0f / 9.0f, 0.0f, 1000.0f);

	//�V�F�[�_�ɑ���ϊ��s��
	struct ConstantBuffer
	{
		DirectX::XMMATRIX mWorld;//���[���h�ϊ��s��
		DirectX::XMMATRIX mView;//�r���[�ϊ��s��
		DirectX::XMMATRIX mProjection;//�����ˉe�ϊ��s��
	};
	//�ϊ��s��o�b�t�@�쐬
	///XXX:hBufferDesc�͊Ǘ��s�v��ˁH
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

	//�O���t�B�b�N�p�C�v���C������
	//���_�V�F�[�_�[���R���e�L�X�g�ɐݒ�
	GRH.hpDeviceContext->VSSetShader(GRH.hpVertexShader, NULL, 0);
	//�ϊ��V�F�[�_���R���e�L�X�g�ɐݒ�
	GRH.hpDeviceContext->VSSetConstantBuffers(0, 1, &GRH.hpConstantBuffer);
	//�n���V�F�[�_�[�F����
	GRH.hpDeviceContext->HSSetShader(NULL, NULL, 0);
	//�e�b�Z���[�^�[�͖���
	//�h���C���V�F�[�_�[�F����
	GRH.hpDeviceContext->DSSetShader(NULL, NULL, 0);
	//�W�I���g���V�F�[�_�[�F����
	GRH.hpDeviceContext->GSSetShader(NULL, NULL, 0);
	//���X�^���C�U�[���R���e�L�X�g�ɐݒ�
	GRH.hpDeviceContext->RSSetState(GRH.hpRasterizerState);
	//�s�N�Z���V�F�[�_�[���R���e�L�X�g�ɐݒ�
	GRH.hpDeviceContext->PSSetShader(GRH.hpPixelShader, NULL, 0);

	return 0;
}

int TerminateDirectX(void)
{
	//�|�C���^�Ő����������̂̓����[�X����K�v������
	//�ǂ̕ϐ������ʂ��Ղ��悤�ɁChp�Ŏn�߂Ă���

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
	// �w�i�F�ݒ�
	GRH.BackColor[0] = 0.0f;
	GRH.BackColor[1] = 0.0f;
	GRH.BackColor[2] = 1.0f;
	GRH.BackColor[3] = 1.0f;
	GRH.hpDeviceContext->ClearRenderTargetView(GRH.hpRenderTargetView, GRH.BackColor);

	//�`��
	GRH.hpDeviceContext->Draw(TYOUTEN, 0);

	return 0;
}
int Flip(void)
{
	//�o�b�N�o�b�t�@���X���b�v
	GRH.hpDXGISwpChain->Present(0, 0);

	return 0;
}


}//namespace Azalea


