#pragma once

#include <d3d11.h>
#include <directxmath.h>

#include "types.h"

namespace Azalea{

#define AZ_PI ((FLOAT) 3.141592654f) 
#define AZ_TO_RAD(degree) ((degree) * (AZ_PI / 180.0f))
#define AZ_TO_DEG(radian) ((radian) * (180.0f / AZ_PI))

#define GRA        GraphicsManage
#define GRH        GraphicsManage.Hard
#define GRS        GraphicsManage.Soft
#define GSC        GraphicsSysData.Camera


//今は半固定値
//const int TYOUTEN = 3;	//ポリゴンの頂点数
//const int TYOUTEN = 4;	//ポリゴンの頂点数
//const int TYOUTEN = 5;	//ポリゴンの頂点数
const int TYOUTEN = 4;	//ポリゴンの頂点数

// ハードウエアアクセラレータを使用するグラフィックス処理で使用する情報の構造体
struct GRAPHICS_HARDDATA
{
	DXGI_SWAP_CHAIN_DESC hDXGISwapChainDesc;
	D3D11_VIEWPORT vp;
	//D3D11_INPUT_ELEMENT_DESC hInElementDesc;
	D3D11_BUFFER_DESC hBufferDesc;
	D3D11_SUBRESOURCE_DATA hSubResourceData;
	ID3D11Buffer* hpBuffer;
	ID3D11Buffer* hpConstantBuffer;
	ID3D11InputLayout* hpInputLayout;
	ID3D11VertexShader* hpVertexShader;
	ID3D11PixelShader* hpPixelShader;

	ID3D11RenderTargetView *hpRenderTargetView;
	ID3D11Texture2D* hpBackBuffer;
	IDXGISwapChain* hpDXGISwpChain;
	IDXGIFactory* hpDXGIFactory;
	IDXGIAdapter* hpAdapter;
	IDXGIDevice1* hpDXGI;
	ID3D11DeviceContext* hpDeviceContext;
	ID3D11Device* hpDevice;

	//ラスタライザ設定
	ID3D11RasterizerState* hpRasterizerState;
	D3D11_RASTERIZER_DESC hRasterizerDesc;

	//背景色設定
	float BackColor[4];;//R,G,B,?

	//テクスチャ設定
	ID3D11Resource* hpResource;
	ID3D11ShaderResourceView* hpShaderResourceView;


	int TYOUTEN;

#pragma region HIDE
//	int						NotUseDirect3D9Ex;						// Direct3D9Ex を使用しないかどうか
//	int						UseMultiThread;						// マルチスレッド対応フラグを使うかどうか
//	int						ValidAdapterNumber;					// UseAdapterNumber が有効かどうか( TRUE:有効  FALSE:無効 )
//	int						UseAdapterNumber;						// 使用するデバイスアダプタ番号
//	int						NonUseVertexHardwareProcess;			// 強制的に頂点演算をハードウエアで処理しないかどうか( TRUE:処理しない  FALSE:処理する )
//	int						UsePixelLightingShader;				// ピクセル単位でライティングを行うタイプのシェーダーを使用するかどうか( TRUE:使用する  FALSE:使用しない )
//	int						VertexHardwareProcess;					// 頂点演算をハードウエアで処理するかどうか( TRUE:処理する  FALSE:処理しない )
//	int						ValidVertexShader;						// 頂点シェーダーが使用可能かどうか( TRUE:使用可能  FALSE:不可能 )
//	int						ValidPixelShader;						// ピクセルシェーダーが使用可能かどうか( TRUE:使用可能  FALSE:不可能 )
//	int						ValidVertexShader_SM3;					// Shader Model 3.0 の頂点シェーダーが使用可能かどうか( TRUE:使用可能  FALSE:不可能 )
//	int						ValidPixelShader_SM3;					// Shader Model 3.0 のピクセルシェーダーが使用可能かどうか( TRUE:使用可能  FALSE:不可能 )
//	int						DisableAeroFlag;						// Aero を無効にするかどうかのフラグ( TRUE:無効にする  FALSE:無効にしない )
//	DWORD					NativeVertexShaderVersion;				// エミュレーション無しの頂点シェーダーのバージョン
//
//	int						UseBaseVertexShaderIndex;				// 使用する頂点シェーダーのライト・フォグ・フォンシェーディングの有無のみ設定した値
//	int						UseBasePixelShaderIndex;				// 使用するピクセルシェーダーのライト・フォンシェーディングの有無のみ設定した値
//	int						UseBaseVertexShaderIndex_PL;			// ピクセル単位ライティングタイプで使用する頂点シェーダーのライト・フォグ・フォンシェーディングの有無のみ設定した値
//	int						UseBasePixelShaderIndex_PL;			// ピクセル単位ライティングタイプで使用するピクセルシェーダーのライト・フォンシェーディングの有無のみ設定した値
//	int						UseOnlyPixelLightingTypeCode;			// ピクセル単位ライティングタイプのシェーダーコードを使用する指定になっているかどうか
//
//	D_D3DMULTISAMPLE_TYPE	FSAAMultiSampleType;					// FSAA用マルチサンプリングタイプ
//	int						FSAAMultiSampleQuality;				// FSAA用マルチサンプリングクオリティ
//	int						MipMapCount;							// 自動で作成するミップマップの数( -1:最大レベルまで作成する )
//	int						FullScreenEmulation320x240;			// フルスクリーンモードで 320x240 を指定されているかどうか( TRUE:指定されている  FALSE:指定されていない )
//	int						UseRenderTargetLock;					// 描画先サーフェスのロックを行うかどうか( TRUE:行う  FALSE:行わない )
//
//	int						ValidAdapterInfo;						// アダプタの情報が有効かどうか( TRUE:有効  FALSE:無効 )
//	int						AdapterInfoNum;						// アダプタ情報の数
//	D_D3DADAPTER_IDENTIFIER9	AdapterInfo[MAX_DEVICE_LISTUP];	// アダプタの情報
//
//	D_D3DFORMAT				ScreenFormat;										// 画面カラーフォーマット
//	D_D3DFORMAT				TextureFormat[DX_GRAPHICSIMAGE_FORMAT_3D_NUM];	// テクスチャフォーマット
//	D_D3DFORMAT				MaskColorFormat;									// マスクカラーバッファ用フォーマット
//	D_D3DFORMAT				MaskAlphaFormat;									// マスクアルファチャンネル用フォーマット
//	D_D3DFORMAT				ZBufferFormat[ZBUFFER_FORMAT_NUM];				// Ｚバッファフォーマット
//
//	IMAGEDATA2_SYSMEMTEXTURE SysMemTexture[SYSMEMTEXTURE_NUM];	// 非管理テクスチャへのデータ転送用システムメモリ配置テクスチャ
//	int						SysMemTextureInitNum;					// 初期化済みのシステムメモリテクスチャの数
//
//	IMAGEDATA2_SYSMEMSURFACE SysMemSurface[SYSMEMSURFACE_NUM];	// 非管理テクスチャへのデータ転送用システムメモリ配置サーフェス
//	int						SysMemSurfaceInitNum;					// 初期化済みのシステムメモリサーフェスの数
//
//	int						UserMaxTextureSize;					// ユーザー指定のテクスチャ最大サイズ
//	int						NotUseDivFlag;							// 画像分割を行わないかどうか( TRUE:行わない  FALSE:行う )
//	int						UseOldDrawModiGraphCodeFlag;			// 以前の DrawModiGraph 関数コードを使用するかどうかのフラグ
//
//	int						FlipRunScanline[2];					// ScreenFlip を実行したときのスキャンライン値
//	DWORD					FlipRunTime[2];						// ScreenFlip を実行したときの timeGetTime の値
//	int						FlipSkipFlag;							// Flipスキップ中か、フラグ( TRUE:スキップ中  FALSE:スキップ中ではない )
//
//	int						ValidTexTempRegFlag;					// テクスチャステージのテンポラリレジスタが使用できるかどうかのフラグ
//
//	DX_DIRECT3DSURFACE9		*BackBufferSurface;					// デバイスが持つバックバッファサーフェス
//	DX_DIRECT3DSURFACE9		*SubBackBufferSurface;					// ScreenCopy や GetDrawScreen を実現するために使用する描画可能サーフェス
//	DX_DIRECT3DSURFACE9		*ZBufferSurface;						// メインで使用するＺバッファ
//	int						ZBufferSizeX, ZBufferSizeY;			// Ｚバッファサーフェスのサイズ
//	int						UserZBufferSizeSet;					// 外部からＺバッファサイズの指定があったかどうか
//	int						ZBufferBitDepth;						// Ｚバッファサーフェスのビット深度
//	int						UserZBufferBitDepthSet;				// 会部からＺバッファのビット深度指定があったかどうか
//
//	IMAGEFORMATDESC			*DrawPrepFormat;						// 前回 DrawPreparation に入ったときの Format パラメータ
//	DX_DIRECT3DTEXTURE9		*DrawPrepTexture;						// 前回 DrawPreparation に入ったときの Texture パラメータ
//	int						DrawPrepParamFlag;						// 前回 DrawPreparation に入ったときの ParamFlag パラメータ
//	int						DrawPrepAlwaysFlag;					// 必ず DrawPreparation を行うかどうかのフラグ
//
//	D_D3DCAPS9				DeviceCaps;							// デバイス情報
//	int						TextureSizePow2;						// テクスチャのサイズが２のｎ乗である必要があるかどうか
//	int						TextureSizeNonPow2Conditional;			// 条件付でテクスチャのサイズが２のｎ乗でなくても大丈夫かどうか
//	int						MaxTextureSize;						// 最大テクスチャサイズ
//	int						ValidDestBlendOp;						// D3DBLENDOP_ADD 以外が使用可能かどうか( TRUE:使用可能  FALSE:使用不可能 )
//	int						WhiteTexHandle;						// 8x8の白いテクスチャのハンドル
//	int						MaxPrimitiveCount;						// 一度に描画できるプリミティブの最大数
//
//	DX_DIRECT3DSURFACE9		*TargetSurface[DX_RENDERTARGET_COUNT];	// 描画対象のサーフェス
//	int						RenderTargetNum;						// 同時に設定できるレンダリングターゲットの数
//
//	D_D3DVIEWPORT9			Viewport;								// ビューポート情報
//	RECT					ScissorRect;							// シザー矩形
//	int						ScissorTestEnable;						// シザー矩形の有効、無効( TRUE:有効 FALSE:無効 )
//
//	BYTE					*VertexBufferPoint[2][3];				// 各頂点バッファへのポインタ( [ ３Ｄ頂点かどうか ][ 頂点タイプ ] )
//	int						Use3DVertex;							// ３Ｄ頂点を使用しているかどうか( 1:使用している  0:使用していない )
//	int						VertexNum; 							// 頂点バッファに格納されている頂点の数
//	int						VertexType;							// 頂点バッファに格納されている頂点データ( 0:テクスチャなし  1:テクスチャあり  2:ブレンドテクスチャあり )
//	D_D3DPRIMITIVETYPE		PrimitiveType;							// 頂点バッファに格納されている頂点データのプリミティブタイプ
//
//	float					BlendTextureWidth;						// ブレンドテクスチャの幅
//	float					BlendTextureHeight;					// ブレンドテクスチャの高さ
//	float					InvBlendTextureWidth;					// ブレンドテクスチャの幅の逆数
//	float					InvBlendTextureHeight;					// ブレンドテクスチャの高さの逆数
//	DWORD					DiffuseColor;							// ディフューズカラー
//
//	int						GaussPass1_VS;							// ガウスフィルタシェーダーの１パス目の頂点シェーダー
//	int						GaussPass1_PS;							// ガウスフィルタシェーダーの１パス目のピクセルシェーダー
//	int						GaussPass2_VS;							// ガウスフィルタシェーダーの２パス目の頂点シェーダー
//	int						GaussPass2_PS;							// ガウスフィルタシェーダーの２パス目のピクセルシェーダー
//
//	BYTE					*VertexBufferNextAddress;				// 次のデータを格納すべき頂点バッファ内のアドレス
//	BYTE					NoTexVertexBuffer[D3DDEV_NOTEX_VERTBUFFERSIZE];	// テクスチャを使用しない頂点バッファ
//	BYTE					TexVertexBuffer[D3DDEV_TEX_VERTBUFFERSIZE];	// テクスチャを使用する頂点バッファ
//	BYTE					BlendTexVertexBuffer[D3DDEV_BLENDTEX_VERTBUFFERSIZE];	// ブレンドテクスチャを使用する頂点バッファ
//	BYTE					Vertex3DBuffer[D3DDEV_NOTEX_3D_VERTBUFFERSIZE];	// ３Ｄ用頂点バッファ
//
//	void					*CommonBuffer[COMMON_BUFFER_NUM];	// 汎用バッファ
//	DWORD					CommonBufferSize[COMMON_BUFFER_NUM];	// 汎用バッファのメモリ確保サイズ
//
//	RECT					DrawRect;							// 描画範囲
//
//	DX_DIRECT3DTEXTURE9		*RenderTexture;					// 描画時に使用するテクスチャー
//	DX_DIRECT3DTEXTURE9		*BlendTexture;						// 描画時に描画テクスチャーとブレンドするαチャンネルテクスチャー
//	DX_DIRECT3DTEXTURE9		*RenderTargetTexture;				// 描画対象となっているテクスチャー
//	DX_DIRECT3DSURFACE9		*RenderTargetSurface;				// 描画対象となっているテクスチャーのサーフェス
//	DX_DIRECT3DSURFACE9		*RenderTargetCopySurface;			// 描画対象となっているテクスチャーのコピーサーフェス
//	float					RenderTargetTextureInvWidth;		// 描画対象となっているテクスチャーの幅で1.0fを割ったもの
//	float					RenderTargetTextureInvHeight;		// 描画対象となっているテクスチャーの高さで1.0fを割ったもの
//#ifndef DX_NON_MODEL
//	DX_DIRECT3DVOLUMETEXTURE9	*RGBtoVMaxRGBVolumeTexture;	// RGBカラーを輝度を最大にしたRGB値に変換するためのボリュームテクスチャ
//#endif // DX_NON_MODEL
//
//	DIRECT3DBLENDINFO		BlendInfo;							// Direct3DDevice のブレンドに関係する設定値
//	float					FactorColorPSConstantF[4];		// ピクセルシェーダーを使ったＤＸライブラリ標準処理用の FactorColor の値
//	DIRECT3DBLENDINFO		UserBlendInfo;						// Direct3D 管理プログラム外から設定されるブレンドに関係する設定値
//	int						UserBlendInfoFlag;					// UserBlendInfo が有効かどうかフラグ( TRUE:有効  FALSE:無効 )
//	int						UserBlendInfoTextureStageIsTextureAndTextureCoordOnlyFlag;	// UserBlendInfo.TextureStageInfo の中で有効なパラメータが Texture と TextureCoordIndex だけかどうか( TRUE:その通り  FALSE:違う )
//
//	int						DrawMode;							// 描画モード
//	int						MaxAnisotropy;						// 最大異方性
//	int						MaxAnisotropyDim[8];				// 各サンプラの最大異方性
//	DX_D3DTEXFILTER_TYPE	MagFilter[8];					// 各サンプラの拡大フィルタ
//	DX_D3DTEXFILTER_TYPE	MinFilter[8];					// 各サンプラの縮小フィルタ
//	DX_D3DTEXFILTER_TYPE	MipFilter[8];					// 各サンプラのミップマップフィルタ
//	int						EnableZBufferFlag;					// Ｚバッファの有効フラグ
//	int						WriteZBufferFlag;					// Ｚバッファの更新を行うか、フラグ
//	int						ZBufferCmpType;					// Ｚ値の比較モード
//	int						ZBias;								// Ｚバイアス
//	int						TextureTransformUse[8];				// テクスチャ座標変換行列を使用するかどうか( TRUE:使用する  FALSE:使用しない )
//	MATRIX					TextureTransformMatrix[8];			// テクスチャ座標変換行列
//	int						TextureTransformMatrixDirectChange;	// テクスチャ座標変換行列を直接変更されたかどうか( TRUE:された  FALSE:されてない )
//
//	int						ShadowMapDrawSetupRequest;			// シャドウマップに対する描画準備リクエスト
//	int						ShadowMapDraw;						// シャドウマップに対する描画かどうかのフラグ
//	int						ShadowMapDrawHandle;				// シャドウマップに対する描画の際の、シャドウマップハンドル
//	int						NormalizeNormals;					// 法線自動正規化を行うかどうか
//	int						ShadeMode;							// シェーディングモード
//	int						FillMode;							// フィルモード
//	int						CullMode;							// カリングモード
//	int						TexAddressModeU[USE_TEXTURESTAGE_NUM];	// テクスチャアドレスモードＵ
//	int						TexAddressModeV[USE_TEXTURESTAGE_NUM];	// テクスチャアドレスモードＶ
//	int						TexAddressModeW[USE_TEXTURESTAGE_NUM];	// テクスチャアドレスモードＷ
//	int						FogEnable;							// フォグが有効かどうか( TRUE:有効  FALSE:無効 )
//	int						FogMode;							// フォグモード
//	DWORD					FogColor;							// フォグカラー
//	float					FogStart, FogEnd;					// フォグ開始アドレスと終了アドレス
//	float					FogDensity;						// フォグ密度
//	int						PerspectiveFlag;					// パースペクティブ補正有効フラグ
//
//	int						LightFlag;							// ライトを使用するかフラグ
//	int						LightEnableMaxIndex;				// 有効なライトの最大インデックス
//	int						LightEnableFlag[256];			// ライトが有効かどうかフラグ( TRUE:有効  FALSE:無効 )
//	LIGHT					LightParam[256];					// ライトのパラメータ
//
//	COLOR					GlobalAmbientLightColor;			// グローバルアンビエントライトカラー
//	MATERIAL				Material;							// デバイスにセットされているマテリアル
//	int						MaterialUseVertexDiffuseColor;		// 頂点のディフューズカラーをマテリアルのディフューズカラーとして使用するかどうか
//	int						MaterialUseVertexSpecularColor;	// 頂点のスペキュラカラーをマテリアルのスペキュラカラーとして使用するかどうか
//	int						UseSpecular;						// スペキュラを使用するかどうか
//
//	int						UseDiffuseRGBColor;				// ディフューズカラーのＲＧＢ値を使用するか、フラグ
//	int						UseDiffuseAlphaColor;				// ディフューズカラーのα値を使用するか、フラグ
//	int						BeginSceneFlag;					// BeginScene を実行してあるかどうか
//
//	int						IgnoreGraphColorFlag;				// 描画する画像の色成分を無視するかどうかのフラグ
//
//	int						UseAlphaChDrawShader;				// 描画先に正しいα値を書き込む為のシェーダーを使用するかどうか( TRUE:使用する  FALSE:使用しない )
//	int						BlendMode;							// ブレンドモード
//	int						BlendGraphType;					// ブレンド画像タイプ
//	int						BlendGraphFadeRatio;				// ブレンド画像のフェードパラメータ
//	int						BlendGraphBorderParam;				// ブレンド画像の境界パラメータ(０(ブレンド画像の影響０)　←　(ブレンド画像の影響少ない)　←　１２８(ブレンド画像の影響１００％)　→　(ブレンド画像の影響を超えて非描画部分が増える)　→２５５(全く描画されない) )
//	int						BlendGraphBorderRange;				// ブレンド画像の境界幅(０～２５５　狭い～広い　しかし４段階)
//	int						AlphaChannelValidFlag;				// αチャンネル有効フラグ
//
//	int						AlphaTestMode;						// アルファテストモード
//	int						AlphaTestParam;					// アルファテストパラメータ
//
//	int						AlphaTestValidFlag;				// αテスト有効フラグ( Func は必ず D_D3DCMP_GREATEREQUAL )
//	int						ChangeBlendParamFlag;				// ブレンド設定に関わる部分の変更があったか、フラグ
//	int						ChangeTextureFlag;					// テクスチャが変更されたか、フラグ
//	int						BlendMaxNotDrawFlag;				// ブレンド値が最大であることにより描画を行わないかどうか、フラグ
//	int						EdgeFontDrawFlag;					// 縁付きフォントを描画するかどうかのフラグ
//
//
//	int						DrawScreenBufferLockFlag;			// バックバッファをロックしているかどうかフラグ
//	DX_DIRECT3DSURFACE9		*DrawScreenBufferLockSMSurface;	// バックバッファをロックした際に直接ロックできない場合に使用するサーフェスのポインタ
//	int						DrawScreenBufferLockSMSurfaceIndex;// バックバッファをロックした際に直接ロックできない場合に使用するサーフェスキャッシュのインデックス
//	DX_DIRECT3DSURFACE9		*DrawScreenBufferLockSurface;		// ロックしたバックバッファ
//
//	void(*DeviceRestoreCallbackFunction)(void *Data);	// デバイスロストから復帰したときに呼ぶ関数
//	void					*DeviceRestoreCallbackData;		// デバイスロストから復帰したときに呼ぶ関数に渡すポインタ
//
//	void(*DeviceLostCallbackFunction)(void *Data);	// デバイスロストから復帰する前に呼ぶ関数
//	void					*DeviceLostCallbackData;			// デバイスロストから復帰する前に呼ぶ関数に渡すポインタ
//
//	int						UseShader;							// プログラマブルシェーダーを使用するかどうか( TRUE:使用する  FALSE:使用しない )
//	int						NormalDraw_NotUseShader;			// 通常描画にシェーダーを使用しないかどうか( TRUE:使用しない  FALSE:使用する )
//#ifndef DX_NON_FILTER
//	int						ValidRenderTargetInputTexture;		// 描画先を入力テクスチャとして使用できるかどうか( TRUE:使用できる  FALSE:使用できない )
//#endif // DX_NON_FILTER
//
//	DX_DIRECT3DVERTEXSHADER9		*SetVS;					// 現在 Direct3DDevice9 にセットしてある頂点シェーダー
//	DX_DIRECT3DPIXELSHADER9			*SetPS;					// 現在 Direct3DDevice9 にセットしてあるピクセルシェーダー
//	int								NormalPS;					// 通常描画用ピクセルシェーダーがセットされているかどうか
//	DX_DIRECT3DVERTEXDECLARATION9	*SetVD;					// 現在 Direct3DDevice9 にセットしてある頂点シェーダ宣言
//	DWORD							SetFVF;					// 現在 Direct3DDevice9 にセットしてある FVF コード
//	DX_DIRECT3DVERTEXBUFFER9		*SetVB;					// 現在 Direct3DDevice9 にセットしてある頂点バッファ
//	DX_DIRECT3DINDEXBUFFER9			*SetIB;					// 現在 Direct3DDevice9 にセットしてあるインデックスバッファ
//
//	// 固定機能パイプライン互換のシェーダー( テクスチャなし )
//	// [ 特殊効果( 0:通常描画  1:乗算描画  2:RGB反転  3:描画輝度４倍  4:乗算済みαブレンドモードの通常描画  5:乗算済みαブレンドモードのRGB反転  6:乗算済みαブレンドモードの描画輝度4倍 ) ]
//	// [ αチャンネル考慮版かどうか( 0:考慮しない  1:考慮する ) ]
//	// [ 乗算済みαブレンド用かどうか( 0:乗算済みαブレンド用ではない  1:乗算済みαブレンド用 ) ]
//	DX_DIRECT3DPIXELSHADER9          *BaseNoneTexPixelShader[7][2];
//
//	// 固定機能パイプライン互換のシェーダー( テクスチャあり )
//	// [ ブレンド画像とのブレンドタイプ( 0:なし  1:DX_BLENDGRAPHTYPE_NORMAL  2:DX_BLENDGRAPHTYPE_WIPE  3:DX_BLENDGRAPHTYPE_ALPHA ) ]
//	// [ 特殊効果( 0:通常描画  1:乗算描画  2:RGB反転  3:描画輝度４倍  4:乗算済みαブレンドモードの通常描画  5:乗算済みαブレンドモードのRGB反転  6:乗算済みαブレンドモードの描画輝度4倍 ) ]
//	// [ テクスチャRGB無視( 0:無視しない  1:無視する ) ]
//	// [ テクスチャAlpha無視( 0:無視しない  1:無視する ) ]
//	// [ αチャンネル考慮版かどうか( 0:考慮しない  1:考慮する ) ]
//	DX_DIRECT3DPIXELSHADER9          *BaseUseTexPixelShader[4][7][2][2][2];
//
//	// マスク処理用のシェーダー
//	DX_DIRECT3DPIXELSHADER9          *MaskEffectPixelShader;
//
//#ifndef DX_NON_MODEL
//	// モデル描画用ピクセル単位ライティングタイプの頂点シェーダー( リストは配列の左から )
//	// [ シャドウマップの有無( 0:無し 1:有り ) ]
//	// [ メッシュタイプ( 0:剛体メッシュ 1:4ボーン内スキニングメッシュ 2:8ボーン内スキニングメッシュ ) ]
//	// [ バンプマップの有無( 0:無し 1:有り ) ]
//	// [ フォグタイプ ]
//	DX_DIRECT3DVERTEXSHADER9         *MV1_PixelLighting_VertexShader[2][3][2][4];
//
//	// モデル描画用ピクセル単位ライティングタイプのトゥーン用ピクセルシェーダー( リストは配列の左から )
//	// [ シャドウマップの有無( 0:無し 1:有り ) ]
//	// [ トゥーンレンダリングタイプ( 0:トゥーンレンダリング type 1   1:トゥーンレンダリング Type 2 ) ]
//	// [ トゥーンレンダリングのスフィアマップの有無とブレンドタイプ( 0:スフィアマップは無い   1:MV1_LAYERBLEND_TYPE_MODULATE  2:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ トゥーンレンダリングのディフューズグラデーションのブレンドタイプ( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	// [ トゥーンレンダリングのスペキュラグラデーションのブレンドタイプ( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ スペキュラマップ ( 0:無い 1:ある ) ]
//	// [ バンプマップ ( 0:なし 1:あり ) ]
//	// [ ライトインデックス ]
//	// [ スペキュラの有無( 0:無し 1:有り ) ]
//	DX_DIRECT3DPIXELSHADER9         *MV1_PixelLighting_ToonPixelShader[2][2][3][2][2][2][2][84][2];
//
//	// モデル描画用ピクセル単位ライティングタイプのピクセルシェーダー( リストは配列の左から )
//	// [ シャドウマップの有無( 0:無し 1:有り ) ]
//	// [ マルチテクスチャのブレンドモード、MV1_LAYERBLEND_TYPE_TRANSLUCENT などに +1 したもの ( 0:マルチテクスチャ無し  1:αブレンド  2:加算ブレンド  3:乗算ブレンド  4:乗算ブレンド×2 ) ]
//	// [ スペキュラマップ ( 0:無い 1:ある ) ]
//	// [ バンプマップ ( 0:なし 1:あり ) ]
//	// [ ライトインデックス ]
//	// [ スペキュラの有無( 0:無し 1:有り ) ]
//	DX_DIRECT3DPIXELSHADER9         *MV1_PixelLighting_PixelShader[2][5][2][2][84][2];
//
//
//
//
//
//	// モデル描画用のトゥーンレンダリングの輪郭線描画用頂点シェーダー
//	// [ メッシュタイプ( 0:剛体メッシュ 1:4ボーン内スキニングメッシュ  2:8ボーン内スキニングメッシュ ) ]
//	// [ フォグタイプ ]
//	DX_DIRECT3DVERTEXSHADER9         *MV1_ToonOutLineVertexShader[3][4];
//
//	// モデル描画用のシャドウマップへのレンダリング用頂点シェーダー
//	// [ メッシュタイプ( 0:剛体メッシュ 1:4ボーン内スキニングメッシュ  2:8ボーン内スキニングメッシュ ) ]
//	DX_DIRECT3DVERTEXSHADER9         *MV1_ShadowMapVertexShader[3];
//
//	// モデル描画用のライティングなし頂点シェーダー
//	// [ メッシュタイプ( 0:剛体メッシュ 1:4ボーン内スキニングメッシュ  2:8ボーン内スキニングメッシュ ) ]
//	// [ フォグタイプ ]
//	DX_DIRECT3DVERTEXSHADER9         *MV1_NoLightingVertexShader[3][4];
//
//	// モデル描画用のライティングあり頂点シェーダー
//	// [ シェーダーモデル( 0:SM2  1:SM3 )
//	// [ シャドウマップの有無( 0:無し 1:有り ) ]
//	// [ メッシュタイプ( 0:剛体メッシュ 1:4ボーン内スキニングメッシュ  2:8ボーン内スキニングメッシュ ) ]
//	// [ バンプマップの有無( 0:無し 1:有り ) ]
//	// [ フォグタイプ ]
//	// [ ライトインデックス ]
//	// [ スペキュラの有無( 0:無し 1:有り ) ]
//	DX_DIRECT3DVERTEXSHADER9         *MV1_LightingVertexShader[2][2][3][2][4][20][2];
//
//
//	// モデル描画用のトゥーンレンダリングの輪郭線描画用ピクセルシェーダー
//	DX_DIRECT3DPIXELSHADER9         *MV1_ToonOutLinePixelShader;
//
//	// モデル描画用のシャドウマップへのトゥーンレンダリング用ピクセルシェーダー
//	// [ トゥーンレンダリングタイプ( 0:トゥーンレンダリング type 1   1:トゥーンレンダリング type 2 ) ]
//	// [ トゥーンレンダリングのスフィアマップの有無とブレンドタイプ( 0:スフィアマップは無い   1:MV1_LAYERBLEND_TYPE_MODULATE  2:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ トゥーンレンダリングのディフューズグラデーションのブレンドタイプ( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	DX_DIRECT3DPIXELSHADER9         *MV1_ShadowMapToonPixelShader[2][3][2];
//
//	// モデル描画用のシャドウマップへのレンダリング用ピクセルシェーダー
//	DX_DIRECT3DPIXELSHADER9         *MV1_ShadowMapPixelShader;
//
//	// モデル描画用のライティングなしトゥーン用ピクセルシェーダー( リストは配列の左から )
//	// [ トゥーンレンダリングタイプ( 0:トゥーンレンダリング type 1   1:トゥーンレンダリング type 2 ) ]
//	// [ トゥーンレンダリングのディフューズグラデーションのブレンドタイプ( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	DX_DIRECT3DPIXELSHADER9         *MV1_ToonNoLightingPixelShader[2][2];
//
//	// モデル描画用のライティングなしピクセルシェーダー
//	// [ マルチテクスチャのブレンドモード、MV1_LAYERBLEND_TYPE_TRANSLUCENT などに +1 したもの ( 0:マルチテクスチャ無し  1:αブレンド  2:加算ブレンド  3:乗算ブレンド  4:乗算ブレンド×2 ) ]
//	DX_DIRECT3DPIXELSHADER9         *MV1_NoLightingPixelShader[5];
//
//	// モデル描画用のライティングありトゥーン用ピクセルシェーダー
//	// [ シェーダーモデル( 0:SM2  1:SM3 )
//	// [ シャドウマップの有無( 0:無し 1:有り ) ]
//	// [ トゥーンレンダリングタイプ( 0:トゥーンレンダリング type 1   1:トゥーンレンダリング type 2 ) ]
//	// [ トゥーンレンダリングのスフィアマップの有無とブレンドタイプ( 0:スフィアマップは無い   1:MV1_LAYERBLEND_TYPE_MODULATE  2:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ トゥーンレンダリングのディフューズグラデーションのブレンドタイプ( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	// [ トゥーンレンダリングのスペキュラグラデーションのブレンドタイプ( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ スペキュラマップ ( 0:無い 1:ある ) ]
//	// [ バンプマップ ( 0:なし 1:あり ) ]
//	// [ ライトインデックス ]
//	// [ スペキュラの有無( 0:無し 1:有り ) ]
//	DX_DIRECT3DPIXELSHADER9         *MV1_ToonLightingPixelShader[2][2][2][3][2][2][2][2][10][2];
//
//	// モデル描画用のライティングありピクセルシェーダー
//	// [ シェーダーモデル( 0:SM2  1:SM3 )
//	// [ シャドウマップの有無( 0:無し 1:有り ) ]
//	// [ マルチテクスチャのブレンドモード、MV1_LAYERBLEND_TYPE_TRANSLUCENT などに +1 したもの ( 0:マルチテクスチャ無し  1:αブレンド  2:加算ブレンド  3:乗算ブレンド  4:乗算ブレンド×2 ) ]
//	// [ スペキュラマップ ( 0:無い 1:ある ) ]
//	// [ バンプマップ ( 0:なし 1:あり ) ]
//	// [ ライトインデックス ]
//	// [ スペキュラの有無( 0:無し 1:有り ) ]
//	DX_DIRECT3DPIXELSHADER9         *MV1_LightingPixelShader[2][2][5][2][2][10][2];
//
//
//
//
//	// 頂点シェーダ宣言( リストは配列の左から )
//	// [ バンプマップ情報付きかどうか( 1:バンプマップ付き 0:付いてない ) ]
//	// [ スキニングメッシュかどうか( 0:剛体メッシュ 1:4ボーン内スキニングメッシュ 2:8ボーン内スキニングメッシュ ) ]
//	// [ UVの数 ]
//	DX_DIRECT3DVERTEXDECLARATION9    *DefaultVertexDeclaration[2][3][9];
//
//#endif // DX_NON_MODEL
//
//	int						InitializeFlag;					// このフラグが立っている時は現在のステータスと変更
//	// 指定のステータスが同じでも必ず実行される
//	int						DisplayModeNum;					// 変更可能なディスプレイモードの数
//	DISPLAYMODEDATA			*DisplayMode;						// ディスプレイモードリスト
//
//	SHADERCONSTANTINFOSET	ShaderConstantInfo;				// シェーダーの定数情報
//
//	DX_DIRECT3DVERTEXDECLARATION9	*UserShaderDeclaration[DX_VERTEX_TYPE_NUM];	// ユーザーシェーダモードで使用する頂点データフォーマット
//
//	USERRENDERINFO			UserShaderRenderInfo;				// SetUseTextureToShader で設定された各ステージのテクスチャ情報や、ユーザー設定のシェーダー定数情報など
//
//	int						WorkDrawValidGrHandle[2][16][2];	// フィルター処理作業用描画可能テクスチャ[ 0:整数テクスチャ 1:浮動小数点テクスチャ ][ ２のｎ乗 ][ 作業用２枚 ]
//#ifndef DX_NON_FILTER
//	SHADERCODE_HANDLE		ShaderCode;						// ライブラリが用意するシェーダーコード
//#endif // DX_NON_FILTER
#pragma endregion 
};

// ソフトウエアレンダリングで使用する情報の構造体
struct GRAPHICS_SOFTDATA
{
#pragma region HIDE
	//MEMIMG					MainBufferMemImg;					// メイン画面用 MEMIMG
	//MEMIMG					FontScreenMemImgNormal;			// 半透明描画などの時に使うフォント用 MEMIMG ( アルファなし )
	//MEMIMG					FontScreenMemImgAlpha;				// 半透明描画などの時に使うフォント用 MEMIMG ( アルファつき )
	//MEMIMG					*TargetMemImg;						// 描画対象の MEMIMG
	//MEMIMG					*BlendMemImg;						// ブレンド描画用 MEMIMG
#pragma endregion
};

// グラフィック処理管理データ構造体
struct GRAPHICSMANAGE
{
#pragma region HIDE
//	int						InitializeFlag;						// 初期化フラグ
//
//	int						MainScreenSizeX, MainScreenSizeY;		// メイン画面のサイズ
//	int						MainScreenSizeX_Result, MainScreenSizeY_Result;	// GetDrawScreenSize の返り値になるサイズ
//	int						MainScreenColorBitDepth;				// メイン画面のカラービット深度
//	int						MainScreenRefreshRate;					// メイン画面のリフレッシュレート
//	RECT					OriginalDrawRect;						// ウインドウの位置によって改変される前の使用者が意図する正しい描画矩形
//	int						UseChangeDisplaySettings;				// ChangeDisplaySettings を使用して画面モードを変更したかどうか( TRUE:ChangeDisplaySettings を使用した  FALSE:ChangeDisplaySettings は使用していない )
//	int						ChangeGraphModeFlag;					// ChangeGraphMode を実行中かどうかのフラグ
//
//	int						ValidGraphDisplayArea;					// GraphDisplayArea に有効な値が入っているかどうか
//	RECT					GraphDisplayArea;						// 表画面に転送する裏画面の領域
//	RECT					LastCopySrcRect;						// 最後にフィット転送したときのコピー元矩形
//	RECT					LastCopyDestRect;						// 最後にフィット転送したときのコピー先矩形
//	int						EnableBackgroundColor;					// バックグラウンド塗り潰し用カラーが有効かどうかのフラグ
//	int						BackgroundRed, BackgroundGreen, BackgroundBlue;	// バックグラウンド塗り潰し用カラー
//
//	LONGLONG				VSyncWaitTime;							// 前回ＶＳＹＮＣ待ちをしてから次にチェックするまでに待つ時間
//	LONGLONG				VSyncTime;								// 前回ＶＳＹＮＣ待ちをした時間
//
//	int						ValidHardWare;							// ハードウエア描画が可能かどうか( TRUE:可能  FALSE:不可能 )
//	int						NotUseHardWare;						// ハードウエア描画の機能を使用しないかどうか( TRUE:使用しない  FALSE:使用する )
//	int						ChangeScreenModeNotGraphicsSystemFlag;	// 画面モードの変更時に画像ハンドルを削除しないかどうか( TRUE:しない  FALSE:する )
//
//
//	int						ShaderInitializeFlag;					// シェーダーバイナリのセットアップが完了しているかどうかのフラグ( TRUE:完了している  FALSE:完了していない )
//
//	DXARC					BaseShaderBinDxa;						// 基本シェーダーオブジェクトファイルＤＸＡ構造体
//	void					*BaseShaderBinDxaImage;				// 基本シェーダーオブジェクトファイルＤＸＡのバイナリイメージ
//
//#ifndef DX_NON_FILTER
//	DXARC					FilterShaderBinDxa;					// フィルターシェーダーオブジェクトファイルＤＸＡ構造体
//	void					*FilterShaderBinDxaImage;				// フィルターシェーダーオブジェクトファイルＤＸＡのバイナリイメージ
//
//	void					*RGBAMixS_ShaderPackImage;				// RGBAMix の S だけの組み合わせ２５６個のシェーダーパッケージバイナリイメージ
//
//	// RGBAMix の S だけの組み合わせ２５６個のシェーダー[ R ][ G ][ B ][ A ]
//	void					*RGBAMixS_ShaderAddress[4][4][4][4];
//	short					RGBAMixS_ShaderSize[4][4][4][4];
//#endif // DX_NON_FILTER
//
//	// ライトインデックスリスト
//	short					LightIndexList84[4][4][4][4][4][4];
//	short					LightIndexList20[4][4][4];
//
//	short					LightIndexList10[3][3][3];
//
//#ifndef DX_NON_MODEL
//	void					*ModelShaderPackImage;					// ３Ｄモデル用シェーダーパッケージバイナリイメージ
//
//	// モデル描画用ピクセル単位ライティングタイプの頂点シェーダー( リストは配列の左から )
//	// [ シャドウマップの有無( 0:無し 1:有り ) ]
//	// [ メッシュタイプ( 0:剛体メッシュ 1:4ボーン内スキニングメッシュ 2:8ボーン内スキニングメッシュ ) ]
//	// [ バンプマップの有無( 0:無し 1:有り ) ]
//	// [ フォグタイプ ]
//	void					*MV1_PixelLighting_VertexShaderAddress[2][3][2][4];
//
//	// モデル描画用ピクセル単位ライティングタイプのトゥーン用ピクセルシェーダー( リストは配列の左から )
//	// [ シャドウマップの有無( 0:無し 1:有り ) ]
//	// [ トゥーンレンダリングかどうか( 0:トゥーンレンダリング type 1   1:トゥーンレンダリング Type 2 ) ]
//	// [ トゥーンレンダリングのスフィアマップの有無とブレンドタイプ( 0:スフィアマップは無い   1:MV1_LAYERBLEND_TYPE_MODULATE  2:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ トゥーンレンダリングのディフューズグラデーションのブレンドタイプ( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	// [ トゥーンレンダリングのスペキュラグラデーションのブレンドタイプ( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ スペキュラマップ ( 0:無い 1:ある ) ]
//	// [ バンプマップ ( 0:なし 1:あり ) ]
//	// [ ライトインデックス ]
//	// [ スペキュラの有無( 0:無し 1:有り ) ]
//	void					*MV1_PixelLighting_ToonPixelShaderAddress[2][2][3][2][2][2][2][84][2];
//
//	// モデル描画用ピクセル単位ライティングタイプのピクセルシェーダー( リストは配列の左から )
//	// [ シャドウマップの有無( 0:無し 1:有り ) ]
//	// [ マルチテクスチャのブレンドモード、MV1_LAYERBLEND_TYPE_TRANSLUCENT などに +1 したもの ( 0:マルチテクスチャ無し  1:αブレンド  2:加算ブレンド  3:乗算ブレンド  4:乗算ブレンド×2 ) ]
//	// [ スペキュラマップ ( 0:無い 1:ある ) ]
//	// [ バンプマップ ( 0:なし 1:あり ) ]
//	// [ ライトインデックス ]
//	// [ スペキュラの有無( 0:無し 1:有り ) ]
//	void					*MV1_PixelLighting_PixelShaderAddress[2][5][2][2][84][2];
//
//
//
//
//
//
//	// モデル描画用のトゥーンレンダリングの輪郭線描画用頂点シェーダー
//	// [ メッシュタイプ( 0:剛体メッシュ 1:4ボーン内スキニングメッシュ  2:8ボーン内スキニングメッシュ ) ]
//	// [ フォグタイプ ]
//	void					*MV1_ToonOutLineVertexShaderAddress[3][4];
//
//	// モデル描画用のシャドウマップへのレンダリング用頂点シェーダー
//	// [ メッシュタイプ( 0:剛体メッシュ 1:4ボーン内スキニングメッシュ  2:8ボーン内スキニングメッシュ ) ]
//	void					*MV1_ShadowMapVertexShaderAddress[3];
//
//	// モデル描画用のライティングなし頂点シェーダー
//	// [ メッシュタイプ( 0:剛体メッシュ 1:4ボーン内スキニングメッシュ  2:8ボーン内スキニングメッシュ ) ]
//	// [ フォグタイプ ]
//	void					*MV1_NoLightingVertexShaderAddress[3][4];
//
//	// モデル描画用のライティングあり頂点シェーダー
//	// [ シェーダーモデル( 0:SM2  1:SM3 )
//	// [ シャドウマップの有無( 0:無し 1:有り ) ]
//	// [ メッシュタイプ( 0:剛体メッシュ 1:4ボーン内スキニングメッシュ  2:8ボーン内スキニングメッシュ ) ]
//	// [ バンプマップの有無( 0:無し 1:有り ) ]
//	// [ フォグタイプ ]
//	// [ ライトインデックス ]
//	// [ スペキュラの有無( 0:無し 1:有り ) ]
//	void					*MV1_LightingVertexShaderAddress[2][2][3][2][4][20][2];
//
//
//	// モデル描画用のトゥーンレンダリングの輪郭線描画用ピクセルシェーダー
//	void					*MV1_ToonOutLinePixelShaderAddress;
//
//	// モデル描画用のシャドウマップへのトゥーンレンダリング用ピクセルシェーダー
//	// [ トゥーンレンダリングタイプ( 0:トゥーンレンダリング type 1   1:トゥーンレンダリング type 2 ) ]
//	// [ トゥーンレンダリングのスフィアマップの有無とブレンドタイプ( 0:スフィアマップは無い   1:MV1_LAYERBLEND_TYPE_MODULATE  2:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ トゥーンレンダリングのディフューズグラデーションのブレンドタイプ( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	void					*MV1_ShadowMapToonPixelShaderAddress[2][3][2];
//
//	// モデル描画用のシャドウマップへのレンダリング用ピクセルシェーダー
//	void					*MV1_ShadowMapPixelShaderAddress;
//
//	// モデル描画用のライティングなしトゥーン用ピクセルシェーダー( リストは配列の左から )
//	// [ トゥーンレンダリングタイプ( 0:トゥーンレンダリング type 1   1:トゥーンレンダリング type 2 ) ]
//	// [ トゥーンレンダリングのディフューズグラデーションのブレンドタイプ( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT or トゥーンレンダリングではない  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	void					*MV1_ToonNoLightingPixelShaderAddress[2][2];
//
//	// モデル描画用のライティングなしピクセルシェーダー
//	// [ マルチテクスチャのブレンドモード、MV1_LAYERBLEND_TYPE_TRANSLUCENT などに +1 したもの ( 0:マルチテクスチャ無し  1:αブレンド  2:加算ブレンド  3:乗算ブレンド  4:乗算ブレンド×2 ) ]
//	void					*MV1_NoLightingPixelShaderAddress[5];
//
//	// モデル描画用のライティングありトゥーン用ピクセルシェーダー
//	// [ シェーダーモデル( 0:SM2  1:SM3 )
//	// [ シャドウマップの有無( 0:無し 1:有り ) ]
//	// [ トゥーンレンダリングタイプ( 0:トゥーンレンダリング type 1   1:トゥーンレンダリング type 2 ) ]
//	// [ トゥーンレンダリングのスフィアマップの有無とブレンドタイプ( 0:スフィアマップは無い   1:MV1_LAYERBLEND_TYPE_MODULATE  2:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ トゥーンレンダリングのディフューズグラデーションのブレンドタイプ( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	// [ トゥーンレンダリングのスペキュラグラデーションのブレンドタイプ( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ スペキュラマップ ( 0:無い 1:ある ) ]
//	// [ バンプマップ ( 0:なし 1:あり ) ]
//	// [ ライトインデックス ]
//	// [ スペキュラの有無( 0:無し 1:有り ) ]
//	void					*MV1_ToonLightingPixelShaderAddress[2][2][2][3][2][2][2][2][10][2];
//
//	// モデル描画用のライティングありピクセルシェーダー
//	// [ シェーダーモデル( 0:SM2  1:SM3 )
//	// [ シャドウマップの有無( 0:無し 1:有り ) ]
//	// [ マルチテクスチャのブレンドモード、MV1_LAYERBLEND_TYPE_TRANSLUCENT などに +1 したもの ( 0:マルチテクスチャ無し  1:αブレンド  2:加算ブレンド  3:乗算ブレンド  4:乗算ブレンド×2 ) ]
//	// [ スペキュラマップ ( 0:無い 1:ある ) ]
//	// [ バンプマップ ( 0:なし 1:あり ) ]
//	// [ ライトインデックス ]
//	// [ スペキュラの有無( 0:無し 1:有り ) ]
//	void					*MV1_LightingPixelShaderAddress[2][2][5][2][2][10][2];
//
//#endif // DX_NON_MODEL
#pragma endregion

	GRAPHICS_HARDDATA		Hard;									// ハードウェアアクセラレータを使用する処理に必要な情報
	GRAPHICS_SOFTDATA		Soft;									// ソフトウエアレンダリングを使用する際に必要な情報
};


// グラフィックス管理データ構造体
extern GRAPHICSMANAGE GraphicsManage;

// カメラ関係情報の構造体
struct GRAPHICSSYS_CAMERA
{
	DirectX::XMMATRIX vWorld;//ワールド変換
	DirectX::XMMATRIX vView;//ビュー変換行列
	DirectX::XMMATRIX vProjection;//透視射影変換

    //VECTOR_D				Position;								// カメラの位置
	//VECTOR_D				Target;								// カメラの注視点
	//VECTOR_D				Up;									// カメラのアップベクトル
	//double					HRotate;								// カメラの水平角度
	//double					VRotate;								// カメラの垂直角度
	//double					TRotate;								// カメラの捻り角度
	//MATRIX_D				Matrix;								// ビュー行列
	//double					ScreenCenterX;							// カメラの消失点
	//double					ScreenCenterY;
};

// グラフィクスシステム用データ構造体
struct GRAPHICSSYSTEMDATA
{
	//int								InitializeFlag;						// 初期化フラグ
	//
	//
	//GRAPHICSSYS_SETTINGDATA			Setting;								// 設定関係の情報
	//
	//GRAPHICSSYS_HARDWAREINFO		HardInfo;								// ハードウェアアクセラレータ関係の情報
	//
	//GRAPHICSSYS_SOFTRENDERDATA		SoftRender;							// ソフトウエアレンダリングで使用する情報
	//
	//GRAPHICSSYS_SCREENDATA			Screen;								// 画面関係の情報
	//
	//GRAPHICSSYS_CREATEIMAGEDATA		CreateImage;							// 画像作成関係の情報
	//
	//GRAPHICSSYS_RESOURCE			Resource;								// 処理実行用リソース関係の構造体
	//
	//GRAPHICSSYS_DRAWSETTINGDATA		DrawSetting;							// 描画設定関係の情報
	//
	//GRAPHICSSYS_LIGHTATA			Light;									// ライト関係の情報

	GRAPHICSSYS_CAMERA				Camera;								// カメラ関係の情報

	//int								ChangeSettingFlag;						// 設定が変更されたかどうか
};

// グラフィックス管理データ構造体
extern GRAPHICSSYSTEMDATA GraphicsSysData;

int InitializeDirectX(void);
int TerminateDirectX(void);



// 描画する
int Draw(void);

// バックバッファをフリップする
int Flip(void);

}//namespace Azalea


