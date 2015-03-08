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


//���͔��Œ�l
//const int TYOUTEN = 3;	//�|���S���̒��_��
//const int TYOUTEN = 4;	//�|���S���̒��_��
//const int TYOUTEN = 5;	//�|���S���̒��_��
const int TYOUTEN = 4;	//�|���S���̒��_��

// �n�[�h�E�G�A�A�N�Z�����[�^���g�p����O���t�B�b�N�X�����Ŏg�p������̍\����
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

	//���X�^���C�U�ݒ�
	ID3D11RasterizerState* hpRasterizerState;
	D3D11_RASTERIZER_DESC hRasterizerDesc;

	//�w�i�F�ݒ�
	float BackColor[4];;//R,G,B,?

	//�e�N�X�`���ݒ�
	ID3D11Resource* hpResource;
	ID3D11ShaderResourceView* hpShaderResourceView;


	int TYOUTEN;

#pragma region HIDE
//	int						NotUseDirect3D9Ex;						// Direct3D9Ex ���g�p���Ȃ����ǂ���
//	int						UseMultiThread;						// �}���`�X���b�h�Ή��t���O���g�����ǂ���
//	int						ValidAdapterNumber;					// UseAdapterNumber ���L�����ǂ���( TRUE:�L��  FALSE:���� )
//	int						UseAdapterNumber;						// �g�p����f�o�C�X�A�_�v�^�ԍ�
//	int						NonUseVertexHardwareProcess;			// �����I�ɒ��_���Z���n�[�h�E�G�A�ŏ������Ȃ����ǂ���( TRUE:�������Ȃ�  FALSE:�������� )
//	int						UsePixelLightingShader;				// �s�N�Z���P�ʂŃ��C�e�B���O���s���^�C�v�̃V�F�[�_�[���g�p���邩�ǂ���( TRUE:�g�p����  FALSE:�g�p���Ȃ� )
//	int						VertexHardwareProcess;					// ���_���Z���n�[�h�E�G�A�ŏ������邩�ǂ���( TRUE:��������  FALSE:�������Ȃ� )
//	int						ValidVertexShader;						// ���_�V�F�[�_�[���g�p�\���ǂ���( TRUE:�g�p�\  FALSE:�s�\ )
//	int						ValidPixelShader;						// �s�N�Z���V�F�[�_�[���g�p�\���ǂ���( TRUE:�g�p�\  FALSE:�s�\ )
//	int						ValidVertexShader_SM3;					// Shader Model 3.0 �̒��_�V�F�[�_�[���g�p�\���ǂ���( TRUE:�g�p�\  FALSE:�s�\ )
//	int						ValidPixelShader_SM3;					// Shader Model 3.0 �̃s�N�Z���V�F�[�_�[���g�p�\���ǂ���( TRUE:�g�p�\  FALSE:�s�\ )
//	int						DisableAeroFlag;						// Aero �𖳌��ɂ��邩�ǂ����̃t���O( TRUE:�����ɂ���  FALSE:�����ɂ��Ȃ� )
//	DWORD					NativeVertexShaderVersion;				// �G�~�����[�V���������̒��_�V�F�[�_�[�̃o�[�W����
//
//	int						UseBaseVertexShaderIndex;				// �g�p���钸�_�V�F�[�_�[�̃��C�g�E�t�H�O�E�t�H���V�F�[�f�B���O�̗L���̂ݐݒ肵���l
//	int						UseBasePixelShaderIndex;				// �g�p����s�N�Z���V�F�[�_�[�̃��C�g�E�t�H���V�F�[�f�B���O�̗L���̂ݐݒ肵���l
//	int						UseBaseVertexShaderIndex_PL;			// �s�N�Z���P�ʃ��C�e�B���O�^�C�v�Ŏg�p���钸�_�V�F�[�_�[�̃��C�g�E�t�H�O�E�t�H���V�F�[�f�B���O�̗L���̂ݐݒ肵���l
//	int						UseBasePixelShaderIndex_PL;			// �s�N�Z���P�ʃ��C�e�B���O�^�C�v�Ŏg�p����s�N�Z���V�F�[�_�[�̃��C�g�E�t�H���V�F�[�f�B���O�̗L���̂ݐݒ肵���l
//	int						UseOnlyPixelLightingTypeCode;			// �s�N�Z���P�ʃ��C�e�B���O�^�C�v�̃V�F�[�_�[�R�[�h���g�p����w��ɂȂ��Ă��邩�ǂ���
//
//	D_D3DMULTISAMPLE_TYPE	FSAAMultiSampleType;					// FSAA�p�}���`�T���v�����O�^�C�v
//	int						FSAAMultiSampleQuality;				// FSAA�p�}���`�T���v�����O�N�I���e�B
//	int						MipMapCount;							// �����ō쐬����~�b�v�}�b�v�̐�( -1:�ő僌�x���܂ō쐬���� )
//	int						FullScreenEmulation320x240;			// �t���X�N���[�����[�h�� 320x240 ���w�肳��Ă��邩�ǂ���( TRUE:�w�肳��Ă���  FALSE:�w�肳��Ă��Ȃ� )
//	int						UseRenderTargetLock;					// �`���T�[�t�F�X�̃��b�N���s�����ǂ���( TRUE:�s��  FALSE:�s��Ȃ� )
//
//	int						ValidAdapterInfo;						// �A�_�v�^�̏�񂪗L�����ǂ���( TRUE:�L��  FALSE:���� )
//	int						AdapterInfoNum;						// �A�_�v�^���̐�
//	D_D3DADAPTER_IDENTIFIER9	AdapterInfo[MAX_DEVICE_LISTUP];	// �A�_�v�^�̏��
//
//	D_D3DFORMAT				ScreenFormat;										// ��ʃJ���[�t�H�[�}�b�g
//	D_D3DFORMAT				TextureFormat[DX_GRAPHICSIMAGE_FORMAT_3D_NUM];	// �e�N�X�`���t�H�[�}�b�g
//	D_D3DFORMAT				MaskColorFormat;									// �}�X�N�J���[�o�b�t�@�p�t�H�[�}�b�g
//	D_D3DFORMAT				MaskAlphaFormat;									// �}�X�N�A���t�@�`�����l���p�t�H�[�}�b�g
//	D_D3DFORMAT				ZBufferFormat[ZBUFFER_FORMAT_NUM];				// �y�o�b�t�@�t�H�[�}�b�g
//
//	IMAGEDATA2_SYSMEMTEXTURE SysMemTexture[SYSMEMTEXTURE_NUM];	// ��Ǘ��e�N�X�`���ւ̃f�[�^�]���p�V�X�e���������z�u�e�N�X�`��
//	int						SysMemTextureInitNum;					// �������ς݂̃V�X�e���������e�N�X�`���̐�
//
//	IMAGEDATA2_SYSMEMSURFACE SysMemSurface[SYSMEMSURFACE_NUM];	// ��Ǘ��e�N�X�`���ւ̃f�[�^�]���p�V�X�e���������z�u�T�[�t�F�X
//	int						SysMemSurfaceInitNum;					// �������ς݂̃V�X�e���������T�[�t�F�X�̐�
//
//	int						UserMaxTextureSize;					// ���[�U�[�w��̃e�N�X�`���ő�T�C�Y
//	int						NotUseDivFlag;							// �摜�������s��Ȃ����ǂ���( TRUE:�s��Ȃ�  FALSE:�s�� )
//	int						UseOldDrawModiGraphCodeFlag;			// �ȑO�� DrawModiGraph �֐��R�[�h���g�p���邩�ǂ����̃t���O
//
//	int						FlipRunScanline[2];					// ScreenFlip �����s�����Ƃ��̃X�L�������C���l
//	DWORD					FlipRunTime[2];						// ScreenFlip �����s�����Ƃ��� timeGetTime �̒l
//	int						FlipSkipFlag;							// Flip�X�L�b�v�����A�t���O( TRUE:�X�L�b�v��  FALSE:�X�L�b�v���ł͂Ȃ� )
//
//	int						ValidTexTempRegFlag;					// �e�N�X�`���X�e�[�W�̃e���|�������W�X�^���g�p�ł��邩�ǂ����̃t���O
//
//	DX_DIRECT3DSURFACE9		*BackBufferSurface;					// �f�o�C�X�����o�b�N�o�b�t�@�T�[�t�F�X
//	DX_DIRECT3DSURFACE9		*SubBackBufferSurface;					// ScreenCopy �� GetDrawScreen ���������邽�߂Ɏg�p����`��\�T�[�t�F�X
//	DX_DIRECT3DSURFACE9		*ZBufferSurface;						// ���C���Ŏg�p����y�o�b�t�@
//	int						ZBufferSizeX, ZBufferSizeY;			// �y�o�b�t�@�T�[�t�F�X�̃T�C�Y
//	int						UserZBufferSizeSet;					// �O������y�o�b�t�@�T�C�Y�̎w�肪���������ǂ���
//	int						ZBufferBitDepth;						// �y�o�b�t�@�T�[�t�F�X�̃r�b�g�[�x
//	int						UserZBufferBitDepthSet;				// �����y�o�b�t�@�̃r�b�g�[�x�w�肪���������ǂ���
//
//	IMAGEFORMATDESC			*DrawPrepFormat;						// �O�� DrawPreparation �ɓ������Ƃ��� Format �p�����[�^
//	DX_DIRECT3DTEXTURE9		*DrawPrepTexture;						// �O�� DrawPreparation �ɓ������Ƃ��� Texture �p�����[�^
//	int						DrawPrepParamFlag;						// �O�� DrawPreparation �ɓ������Ƃ��� ParamFlag �p�����[�^
//	int						DrawPrepAlwaysFlag;					// �K�� DrawPreparation ���s�����ǂ����̃t���O
//
//	D_D3DCAPS9				DeviceCaps;							// �f�o�C�X���
//	int						TextureSizePow2;						// �e�N�X�`���̃T�C�Y���Q�̂���ł���K�v�����邩�ǂ���
//	int						TextureSizeNonPow2Conditional;			// �����t�Ńe�N�X�`���̃T�C�Y���Q�̂���łȂ��Ă����v���ǂ���
//	int						MaxTextureSize;						// �ő�e�N�X�`���T�C�Y
//	int						ValidDestBlendOp;						// D3DBLENDOP_ADD �ȊO���g�p�\���ǂ���( TRUE:�g�p�\  FALSE:�g�p�s�\ )
//	int						WhiteTexHandle;						// 8x8�̔����e�N�X�`���̃n���h��
//	int						MaxPrimitiveCount;						// ��x�ɕ`��ł���v���~�e�B�u�̍ő吔
//
//	DX_DIRECT3DSURFACE9		*TargetSurface[DX_RENDERTARGET_COUNT];	// �`��Ώۂ̃T�[�t�F�X
//	int						RenderTargetNum;						// �����ɐݒ�ł��郌���_�����O�^�[�Q�b�g�̐�
//
//	D_D3DVIEWPORT9			Viewport;								// �r���[�|�[�g���
//	RECT					ScissorRect;							// �V�U�[��`
//	int						ScissorTestEnable;						// �V�U�[��`�̗L���A����( TRUE:�L�� FALSE:���� )
//
//	BYTE					*VertexBufferPoint[2][3];				// �e���_�o�b�t�@�ւ̃|�C���^( [ �R�c���_���ǂ��� ][ ���_�^�C�v ] )
//	int						Use3DVertex;							// �R�c���_���g�p���Ă��邩�ǂ���( 1:�g�p���Ă���  0:�g�p���Ă��Ȃ� )
//	int						VertexNum; 							// ���_�o�b�t�@�Ɋi�[����Ă��钸�_�̐�
//	int						VertexType;							// ���_�o�b�t�@�Ɋi�[����Ă��钸�_�f�[�^( 0:�e�N�X�`���Ȃ�  1:�e�N�X�`������  2:�u�����h�e�N�X�`������ )
//	D_D3DPRIMITIVETYPE		PrimitiveType;							// ���_�o�b�t�@�Ɋi�[����Ă��钸�_�f�[�^�̃v���~�e�B�u�^�C�v
//
//	float					BlendTextureWidth;						// �u�����h�e�N�X�`���̕�
//	float					BlendTextureHeight;					// �u�����h�e�N�X�`���̍���
//	float					InvBlendTextureWidth;					// �u�����h�e�N�X�`���̕��̋t��
//	float					InvBlendTextureHeight;					// �u�����h�e�N�X�`���̍����̋t��
//	DWORD					DiffuseColor;							// �f�B�t���[�Y�J���[
//
//	int						GaussPass1_VS;							// �K�E�X�t�B���^�V�F�[�_�[�̂P�p�X�ڂ̒��_�V�F�[�_�[
//	int						GaussPass1_PS;							// �K�E�X�t�B���^�V�F�[�_�[�̂P�p�X�ڂ̃s�N�Z���V�F�[�_�[
//	int						GaussPass2_VS;							// �K�E�X�t�B���^�V�F�[�_�[�̂Q�p�X�ڂ̒��_�V�F�[�_�[
//	int						GaussPass2_PS;							// �K�E�X�t�B���^�V�F�[�_�[�̂Q�p�X�ڂ̃s�N�Z���V�F�[�_�[
//
//	BYTE					*VertexBufferNextAddress;				// ���̃f�[�^���i�[���ׂ����_�o�b�t�@���̃A�h���X
//	BYTE					NoTexVertexBuffer[D3DDEV_NOTEX_VERTBUFFERSIZE];	// �e�N�X�`�����g�p���Ȃ����_�o�b�t�@
//	BYTE					TexVertexBuffer[D3DDEV_TEX_VERTBUFFERSIZE];	// �e�N�X�`�����g�p���钸�_�o�b�t�@
//	BYTE					BlendTexVertexBuffer[D3DDEV_BLENDTEX_VERTBUFFERSIZE];	// �u�����h�e�N�X�`�����g�p���钸�_�o�b�t�@
//	BYTE					Vertex3DBuffer[D3DDEV_NOTEX_3D_VERTBUFFERSIZE];	// �R�c�p���_�o�b�t�@
//
//	void					*CommonBuffer[COMMON_BUFFER_NUM];	// �ėp�o�b�t�@
//	DWORD					CommonBufferSize[COMMON_BUFFER_NUM];	// �ėp�o�b�t�@�̃������m�ۃT�C�Y
//
//	RECT					DrawRect;							// �`��͈�
//
//	DX_DIRECT3DTEXTURE9		*RenderTexture;					// �`�掞�Ɏg�p����e�N�X�`���[
//	DX_DIRECT3DTEXTURE9		*BlendTexture;						// �`�掞�ɕ`��e�N�X�`���[�ƃu�����h���郿�`�����l���e�N�X�`���[
//	DX_DIRECT3DTEXTURE9		*RenderTargetTexture;				// �`��ΏۂƂȂ��Ă���e�N�X�`���[
//	DX_DIRECT3DSURFACE9		*RenderTargetSurface;				// �`��ΏۂƂȂ��Ă���e�N�X�`���[�̃T�[�t�F�X
//	DX_DIRECT3DSURFACE9		*RenderTargetCopySurface;			// �`��ΏۂƂȂ��Ă���e�N�X�`���[�̃R�s�[�T�[�t�F�X
//	float					RenderTargetTextureInvWidth;		// �`��ΏۂƂȂ��Ă���e�N�X�`���[�̕���1.0f������������
//	float					RenderTargetTextureInvHeight;		// �`��ΏۂƂȂ��Ă���e�N�X�`���[�̍�����1.0f������������
//#ifndef DX_NON_MODEL
//	DX_DIRECT3DVOLUMETEXTURE9	*RGBtoVMaxRGBVolumeTexture;	// RGB�J���[���P�x���ő�ɂ���RGB�l�ɕϊ����邽�߂̃{�����[���e�N�X�`��
//#endif // DX_NON_MODEL
//
//	DIRECT3DBLENDINFO		BlendInfo;							// Direct3DDevice �̃u�����h�Ɋ֌W����ݒ�l
//	float					FactorColorPSConstantF[4];		// �s�N�Z���V�F�[�_�[���g�����c�w���C�u�����W�������p�� FactorColor �̒l
//	DIRECT3DBLENDINFO		UserBlendInfo;						// Direct3D �Ǘ��v���O�����O����ݒ肳���u�����h�Ɋ֌W����ݒ�l
//	int						UserBlendInfoFlag;					// UserBlendInfo ���L�����ǂ����t���O( TRUE:�L��  FALSE:���� )
//	int						UserBlendInfoTextureStageIsTextureAndTextureCoordOnlyFlag;	// UserBlendInfo.TextureStageInfo �̒��ŗL���ȃp�����[�^�� Texture �� TextureCoordIndex �������ǂ���( TRUE:���̒ʂ�  FALSE:�Ⴄ )
//
//	int						DrawMode;							// �`�惂�[�h
//	int						MaxAnisotropy;						// �ő�ٕ���
//	int						MaxAnisotropyDim[8];				// �e�T���v���̍ő�ٕ���
//	DX_D3DTEXFILTER_TYPE	MagFilter[8];					// �e�T���v���̊g��t�B���^
//	DX_D3DTEXFILTER_TYPE	MinFilter[8];					// �e�T���v���̏k���t�B���^
//	DX_D3DTEXFILTER_TYPE	MipFilter[8];					// �e�T���v���̃~�b�v�}�b�v�t�B���^
//	int						EnableZBufferFlag;					// �y�o�b�t�@�̗L���t���O
//	int						WriteZBufferFlag;					// �y�o�b�t�@�̍X�V���s�����A�t���O
//	int						ZBufferCmpType;					// �y�l�̔�r���[�h
//	int						ZBias;								// �y�o�C�A�X
//	int						TextureTransformUse[8];				// �e�N�X�`�����W�ϊ��s����g�p���邩�ǂ���( TRUE:�g�p����  FALSE:�g�p���Ȃ� )
//	MATRIX					TextureTransformMatrix[8];			// �e�N�X�`�����W�ϊ��s��
//	int						TextureTransformMatrixDirectChange;	// �e�N�X�`�����W�ϊ��s��𒼐ڕύX���ꂽ���ǂ���( TRUE:���ꂽ  FALSE:����ĂȂ� )
//
//	int						ShadowMapDrawSetupRequest;			// �V���h�E�}�b�v�ɑ΂���`�揀�����N�G�X�g
//	int						ShadowMapDraw;						// �V���h�E�}�b�v�ɑ΂���`�悩�ǂ����̃t���O
//	int						ShadowMapDrawHandle;				// �V���h�E�}�b�v�ɑ΂���`��̍ۂ́A�V���h�E�}�b�v�n���h��
//	int						NormalizeNormals;					// �@���������K�����s�����ǂ���
//	int						ShadeMode;							// �V�F�[�f�B���O���[�h
//	int						FillMode;							// �t�B�����[�h
//	int						CullMode;							// �J�����O���[�h
//	int						TexAddressModeU[USE_TEXTURESTAGE_NUM];	// �e�N�X�`���A�h���X���[�h�t
//	int						TexAddressModeV[USE_TEXTURESTAGE_NUM];	// �e�N�X�`���A�h���X���[�h�u
//	int						TexAddressModeW[USE_TEXTURESTAGE_NUM];	// �e�N�X�`���A�h���X���[�h�v
//	int						FogEnable;							// �t�H�O���L�����ǂ���( TRUE:�L��  FALSE:���� )
//	int						FogMode;							// �t�H�O���[�h
//	DWORD					FogColor;							// �t�H�O�J���[
//	float					FogStart, FogEnd;					// �t�H�O�J�n�A�h���X�ƏI���A�h���X
//	float					FogDensity;						// �t�H�O���x
//	int						PerspectiveFlag;					// �p�[�X�y�N�e�B�u�␳�L���t���O
//
//	int						LightFlag;							// ���C�g���g�p���邩�t���O
//	int						LightEnableMaxIndex;				// �L���ȃ��C�g�̍ő�C���f�b�N�X
//	int						LightEnableFlag[256];			// ���C�g���L�����ǂ����t���O( TRUE:�L��  FALSE:���� )
//	LIGHT					LightParam[256];					// ���C�g�̃p�����[�^
//
//	COLOR					GlobalAmbientLightColor;			// �O���[�o���A���r�G���g���C�g�J���[
//	MATERIAL				Material;							// �f�o�C�X�ɃZ�b�g����Ă���}�e���A��
//	int						MaterialUseVertexDiffuseColor;		// ���_�̃f�B�t���[�Y�J���[���}�e���A���̃f�B�t���[�Y�J���[�Ƃ��Ďg�p���邩�ǂ���
//	int						MaterialUseVertexSpecularColor;	// ���_�̃X�y�L�����J���[���}�e���A���̃X�y�L�����J���[�Ƃ��Ďg�p���邩�ǂ���
//	int						UseSpecular;						// �X�y�L�������g�p���邩�ǂ���
//
//	int						UseDiffuseRGBColor;				// �f�B�t���[�Y�J���[�̂q�f�a�l���g�p���邩�A�t���O
//	int						UseDiffuseAlphaColor;				// �f�B�t���[�Y�J���[�̃��l���g�p���邩�A�t���O
//	int						BeginSceneFlag;					// BeginScene �����s���Ă��邩�ǂ���
//
//	int						IgnoreGraphColorFlag;				// �`�悷��摜�̐F�����𖳎����邩�ǂ����̃t���O
//
//	int						UseAlphaChDrawShader;				// �`���ɐ��������l���������ވׂ̃V�F�[�_�[���g�p���邩�ǂ���( TRUE:�g�p����  FALSE:�g�p���Ȃ� )
//	int						BlendMode;							// �u�����h���[�h
//	int						BlendGraphType;					// �u�����h�摜�^�C�v
//	int						BlendGraphFadeRatio;				// �u�����h�摜�̃t�F�[�h�p�����[�^
//	int						BlendGraphBorderParam;				// �u�����h�摜�̋��E�p�����[�^(�O(�u�����h�摜�̉e���O)�@���@(�u�����h�摜�̉e�����Ȃ�)�@���@�P�Q�W(�u�����h�摜�̉e���P�O�O��)�@���@(�u�����h�摜�̉e���𒴂��Ĕ�`�敔����������)�@���Q�T�T(�S���`�悳��Ȃ�) )
//	int						BlendGraphBorderRange;				// �u�����h�摜�̋��E��(�O�`�Q�T�T�@�����`�L���@�������S�i�K)
//	int						AlphaChannelValidFlag;				// ���`�����l���L���t���O
//
//	int						AlphaTestMode;						// �A���t�@�e�X�g���[�h
//	int						AlphaTestParam;					// �A���t�@�e�X�g�p�����[�^
//
//	int						AlphaTestValidFlag;				// ���e�X�g�L���t���O( Func �͕K�� D_D3DCMP_GREATEREQUAL )
//	int						ChangeBlendParamFlag;				// �u�����h�ݒ�Ɋւ�镔���̕ύX�����������A�t���O
//	int						ChangeTextureFlag;					// �e�N�X�`�����ύX���ꂽ���A�t���O
//	int						BlendMaxNotDrawFlag;				// �u�����h�l���ő�ł��邱�Ƃɂ��`����s��Ȃ����ǂ����A�t���O
//	int						EdgeFontDrawFlag;					// ���t���t�H���g��`�悷�邩�ǂ����̃t���O
//
//
//	int						DrawScreenBufferLockFlag;			// �o�b�N�o�b�t�@�����b�N���Ă��邩�ǂ����t���O
//	DX_DIRECT3DSURFACE9		*DrawScreenBufferLockSMSurface;	// �o�b�N�o�b�t�@�����b�N�����ۂɒ��ڃ��b�N�ł��Ȃ��ꍇ�Ɏg�p����T�[�t�F�X�̃|�C���^
//	int						DrawScreenBufferLockSMSurfaceIndex;// �o�b�N�o�b�t�@�����b�N�����ۂɒ��ڃ��b�N�ł��Ȃ��ꍇ�Ɏg�p����T�[�t�F�X�L���b�V���̃C���f�b�N�X
//	DX_DIRECT3DSURFACE9		*DrawScreenBufferLockSurface;		// ���b�N�����o�b�N�o�b�t�@
//
//	void(*DeviceRestoreCallbackFunction)(void *Data);	// �f�o�C�X���X�g���畜�A�����Ƃ��ɌĂԊ֐�
//	void					*DeviceRestoreCallbackData;		// �f�o�C�X���X�g���畜�A�����Ƃ��ɌĂԊ֐��ɓn���|�C���^
//
//	void(*DeviceLostCallbackFunction)(void *Data);	// �f�o�C�X���X�g���畜�A����O�ɌĂԊ֐�
//	void					*DeviceLostCallbackData;			// �f�o�C�X���X�g���畜�A����O�ɌĂԊ֐��ɓn���|�C���^
//
//	int						UseShader;							// �v���O���}�u���V�F�[�_�[���g�p���邩�ǂ���( TRUE:�g�p����  FALSE:�g�p���Ȃ� )
//	int						NormalDraw_NotUseShader;			// �ʏ�`��ɃV�F�[�_�[���g�p���Ȃ����ǂ���( TRUE:�g�p���Ȃ�  FALSE:�g�p���� )
//#ifndef DX_NON_FILTER
//	int						ValidRenderTargetInputTexture;		// �`������̓e�N�X�`���Ƃ��Ďg�p�ł��邩�ǂ���( TRUE:�g�p�ł���  FALSE:�g�p�ł��Ȃ� )
//#endif // DX_NON_FILTER
//
//	DX_DIRECT3DVERTEXSHADER9		*SetVS;					// ���� Direct3DDevice9 �ɃZ�b�g���Ă��钸�_�V�F�[�_�[
//	DX_DIRECT3DPIXELSHADER9			*SetPS;					// ���� Direct3DDevice9 �ɃZ�b�g���Ă���s�N�Z���V�F�[�_�[
//	int								NormalPS;					// �ʏ�`��p�s�N�Z���V�F�[�_�[���Z�b�g����Ă��邩�ǂ���
//	DX_DIRECT3DVERTEXDECLARATION9	*SetVD;					// ���� Direct3DDevice9 �ɃZ�b�g���Ă��钸�_�V�F�[�_�錾
//	DWORD							SetFVF;					// ���� Direct3DDevice9 �ɃZ�b�g���Ă��� FVF �R�[�h
//	DX_DIRECT3DVERTEXBUFFER9		*SetVB;					// ���� Direct3DDevice9 �ɃZ�b�g���Ă��钸�_�o�b�t�@
//	DX_DIRECT3DINDEXBUFFER9			*SetIB;					// ���� Direct3DDevice9 �ɃZ�b�g���Ă���C���f�b�N�X�o�b�t�@
//
//	// �Œ�@�\�p�C�v���C���݊��̃V�F�[�_�[( �e�N�X�`���Ȃ� )
//	// [ �������( 0:�ʏ�`��  1:��Z�`��  2:RGB���]  3:�`��P�x�S�{  4:��Z�ς݃��u�����h���[�h�̒ʏ�`��  5:��Z�ς݃��u�����h���[�h��RGB���]  6:��Z�ς݃��u�����h���[�h�̕`��P�x4�{ ) ]
//	// [ ���`�����l���l���ł��ǂ���( 0:�l�����Ȃ�  1:�l������ ) ]
//	// [ ��Z�ς݃��u�����h�p���ǂ���( 0:��Z�ς݃��u�����h�p�ł͂Ȃ�  1:��Z�ς݃��u�����h�p ) ]
//	DX_DIRECT3DPIXELSHADER9          *BaseNoneTexPixelShader[7][2];
//
//	// �Œ�@�\�p�C�v���C���݊��̃V�F�[�_�[( �e�N�X�`������ )
//	// [ �u�����h�摜�Ƃ̃u�����h�^�C�v( 0:�Ȃ�  1:DX_BLENDGRAPHTYPE_NORMAL  2:DX_BLENDGRAPHTYPE_WIPE  3:DX_BLENDGRAPHTYPE_ALPHA ) ]
//	// [ �������( 0:�ʏ�`��  1:��Z�`��  2:RGB���]  3:�`��P�x�S�{  4:��Z�ς݃��u�����h���[�h�̒ʏ�`��  5:��Z�ς݃��u�����h���[�h��RGB���]  6:��Z�ς݃��u�����h���[�h�̕`��P�x4�{ ) ]
//	// [ �e�N�X�`��RGB����( 0:�������Ȃ�  1:�������� ) ]
//	// [ �e�N�X�`��Alpha����( 0:�������Ȃ�  1:�������� ) ]
//	// [ ���`�����l���l���ł��ǂ���( 0:�l�����Ȃ�  1:�l������ ) ]
//	DX_DIRECT3DPIXELSHADER9          *BaseUseTexPixelShader[4][7][2][2][2];
//
//	// �}�X�N�����p�̃V�F�[�_�[
//	DX_DIRECT3DPIXELSHADER9          *MaskEffectPixelShader;
//
//#ifndef DX_NON_MODEL
//	// ���f���`��p�s�N�Z���P�ʃ��C�e�B���O�^�C�v�̒��_�V�F�[�_�[( ���X�g�͔z��̍����� )
//	// [ �V���h�E�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ ���b�V���^�C�v( 0:���̃��b�V�� 1:4�{�[�����X�L�j���O���b�V�� 2:8�{�[�����X�L�j���O���b�V�� ) ]
//	// [ �o���v�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ �t�H�O�^�C�v ]
//	DX_DIRECT3DVERTEXSHADER9         *MV1_PixelLighting_VertexShader[2][3][2][4];
//
//	// ���f���`��p�s�N�Z���P�ʃ��C�e�B���O�^�C�v�̃g�D�[���p�s�N�Z���V�F�[�_�[( ���X�g�͔z��̍����� )
//	// [ �V���h�E�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ �g�D�[�������_�����O�^�C�v( 0:�g�D�[�������_�����O type 1   1:�g�D�[�������_�����O Type 2 ) ]
//	// [ �g�D�[�������_�����O�̃X�t�B�A�}�b�v�̗L���ƃu�����h�^�C�v( 0:�X�t�B�A�}�b�v�͖���   1:MV1_LAYERBLEND_TYPE_MODULATE  2:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ �g�D�[�������_�����O�̃f�B�t���[�Y�O���f�[�V�����̃u�����h�^�C�v( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	// [ �g�D�[�������_�����O�̃X�y�L�����O���f�[�V�����̃u�����h�^�C�v( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ �X�y�L�����}�b�v ( 0:���� 1:���� ) ]
//	// [ �o���v�}�b�v ( 0:�Ȃ� 1:���� ) ]
//	// [ ���C�g�C���f�b�N�X ]
//	// [ �X�y�L�����̗L��( 0:���� 1:�L�� ) ]
//	DX_DIRECT3DPIXELSHADER9         *MV1_PixelLighting_ToonPixelShader[2][2][3][2][2][2][2][84][2];
//
//	// ���f���`��p�s�N�Z���P�ʃ��C�e�B���O�^�C�v�̃s�N�Z���V�F�[�_�[( ���X�g�͔z��̍����� )
//	// [ �V���h�E�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ �}���`�e�N�X�`���̃u�����h���[�h�AMV1_LAYERBLEND_TYPE_TRANSLUCENT �Ȃǂ� +1 �������� ( 0:�}���`�e�N�X�`������  1:���u�����h  2:���Z�u�����h  3:��Z�u�����h  4:��Z�u�����h�~2 ) ]
//	// [ �X�y�L�����}�b�v ( 0:���� 1:���� ) ]
//	// [ �o���v�}�b�v ( 0:�Ȃ� 1:���� ) ]
//	// [ ���C�g�C���f�b�N�X ]
//	// [ �X�y�L�����̗L��( 0:���� 1:�L�� ) ]
//	DX_DIRECT3DPIXELSHADER9         *MV1_PixelLighting_PixelShader[2][5][2][2][84][2];
//
//
//
//
//
//	// ���f���`��p�̃g�D�[�������_�����O�̗֊s���`��p���_�V�F�[�_�[
//	// [ ���b�V���^�C�v( 0:���̃��b�V�� 1:4�{�[�����X�L�j���O���b�V��  2:8�{�[�����X�L�j���O���b�V�� ) ]
//	// [ �t�H�O�^�C�v ]
//	DX_DIRECT3DVERTEXSHADER9         *MV1_ToonOutLineVertexShader[3][4];
//
//	// ���f���`��p�̃V���h�E�}�b�v�ւ̃����_�����O�p���_�V�F�[�_�[
//	// [ ���b�V���^�C�v( 0:���̃��b�V�� 1:4�{�[�����X�L�j���O���b�V��  2:8�{�[�����X�L�j���O���b�V�� ) ]
//	DX_DIRECT3DVERTEXSHADER9         *MV1_ShadowMapVertexShader[3];
//
//	// ���f���`��p�̃��C�e�B���O�Ȃ����_�V�F�[�_�[
//	// [ ���b�V���^�C�v( 0:���̃��b�V�� 1:4�{�[�����X�L�j���O���b�V��  2:8�{�[�����X�L�j���O���b�V�� ) ]
//	// [ �t�H�O�^�C�v ]
//	DX_DIRECT3DVERTEXSHADER9         *MV1_NoLightingVertexShader[3][4];
//
//	// ���f���`��p�̃��C�e�B���O���蒸�_�V�F�[�_�[
//	// [ �V�F�[�_�[���f��( 0:SM2  1:SM3 )
//	// [ �V���h�E�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ ���b�V���^�C�v( 0:���̃��b�V�� 1:4�{�[�����X�L�j���O���b�V��  2:8�{�[�����X�L�j���O���b�V�� ) ]
//	// [ �o���v�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ �t�H�O�^�C�v ]
//	// [ ���C�g�C���f�b�N�X ]
//	// [ �X�y�L�����̗L��( 0:���� 1:�L�� ) ]
//	DX_DIRECT3DVERTEXSHADER9         *MV1_LightingVertexShader[2][2][3][2][4][20][2];
//
//
//	// ���f���`��p�̃g�D�[�������_�����O�̗֊s���`��p�s�N�Z���V�F�[�_�[
//	DX_DIRECT3DPIXELSHADER9         *MV1_ToonOutLinePixelShader;
//
//	// ���f���`��p�̃V���h�E�}�b�v�ւ̃g�D�[�������_�����O�p�s�N�Z���V�F�[�_�[
//	// [ �g�D�[�������_�����O�^�C�v( 0:�g�D�[�������_�����O type 1   1:�g�D�[�������_�����O type 2 ) ]
//	// [ �g�D�[�������_�����O�̃X�t�B�A�}�b�v�̗L���ƃu�����h�^�C�v( 0:�X�t�B�A�}�b�v�͖���   1:MV1_LAYERBLEND_TYPE_MODULATE  2:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ �g�D�[�������_�����O�̃f�B�t���[�Y�O���f�[�V�����̃u�����h�^�C�v( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	DX_DIRECT3DPIXELSHADER9         *MV1_ShadowMapToonPixelShader[2][3][2];
//
//	// ���f���`��p�̃V���h�E�}�b�v�ւ̃����_�����O�p�s�N�Z���V�F�[�_�[
//	DX_DIRECT3DPIXELSHADER9         *MV1_ShadowMapPixelShader;
//
//	// ���f���`��p�̃��C�e�B���O�Ȃ��g�D�[���p�s�N�Z���V�F�[�_�[( ���X�g�͔z��̍����� )
//	// [ �g�D�[�������_�����O�^�C�v( 0:�g�D�[�������_�����O type 1   1:�g�D�[�������_�����O type 2 ) ]
//	// [ �g�D�[�������_�����O�̃f�B�t���[�Y�O���f�[�V�����̃u�����h�^�C�v( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	DX_DIRECT3DPIXELSHADER9         *MV1_ToonNoLightingPixelShader[2][2];
//
//	// ���f���`��p�̃��C�e�B���O�Ȃ��s�N�Z���V�F�[�_�[
//	// [ �}���`�e�N�X�`���̃u�����h���[�h�AMV1_LAYERBLEND_TYPE_TRANSLUCENT �Ȃǂ� +1 �������� ( 0:�}���`�e�N�X�`������  1:���u�����h  2:���Z�u�����h  3:��Z�u�����h  4:��Z�u�����h�~2 ) ]
//	DX_DIRECT3DPIXELSHADER9         *MV1_NoLightingPixelShader[5];
//
//	// ���f���`��p�̃��C�e�B���O����g�D�[���p�s�N�Z���V�F�[�_�[
//	// [ �V�F�[�_�[���f��( 0:SM2  1:SM3 )
//	// [ �V���h�E�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ �g�D�[�������_�����O�^�C�v( 0:�g�D�[�������_�����O type 1   1:�g�D�[�������_�����O type 2 ) ]
//	// [ �g�D�[�������_�����O�̃X�t�B�A�}�b�v�̗L���ƃu�����h�^�C�v( 0:�X�t�B�A�}�b�v�͖���   1:MV1_LAYERBLEND_TYPE_MODULATE  2:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ �g�D�[�������_�����O�̃f�B�t���[�Y�O���f�[�V�����̃u�����h�^�C�v( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	// [ �g�D�[�������_�����O�̃X�y�L�����O���f�[�V�����̃u�����h�^�C�v( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ �X�y�L�����}�b�v ( 0:���� 1:���� ) ]
//	// [ �o���v�}�b�v ( 0:�Ȃ� 1:���� ) ]
//	// [ ���C�g�C���f�b�N�X ]
//	// [ �X�y�L�����̗L��( 0:���� 1:�L�� ) ]
//	DX_DIRECT3DPIXELSHADER9         *MV1_ToonLightingPixelShader[2][2][2][3][2][2][2][2][10][2];
//
//	// ���f���`��p�̃��C�e�B���O����s�N�Z���V�F�[�_�[
//	// [ �V�F�[�_�[���f��( 0:SM2  1:SM3 )
//	// [ �V���h�E�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ �}���`�e�N�X�`���̃u�����h���[�h�AMV1_LAYERBLEND_TYPE_TRANSLUCENT �Ȃǂ� +1 �������� ( 0:�}���`�e�N�X�`������  1:���u�����h  2:���Z�u�����h  3:��Z�u�����h  4:��Z�u�����h�~2 ) ]
//	// [ �X�y�L�����}�b�v ( 0:���� 1:���� ) ]
//	// [ �o���v�}�b�v ( 0:�Ȃ� 1:���� ) ]
//	// [ ���C�g�C���f�b�N�X ]
//	// [ �X�y�L�����̗L��( 0:���� 1:�L�� ) ]
//	DX_DIRECT3DPIXELSHADER9         *MV1_LightingPixelShader[2][2][5][2][2][10][2];
//
//
//
//
//	// ���_�V�F�[�_�錾( ���X�g�͔z��̍����� )
//	// [ �o���v�}�b�v���t�����ǂ���( 1:�o���v�}�b�v�t�� 0:�t���ĂȂ� ) ]
//	// [ �X�L�j���O���b�V�����ǂ���( 0:���̃��b�V�� 1:4�{�[�����X�L�j���O���b�V�� 2:8�{�[�����X�L�j���O���b�V�� ) ]
//	// [ UV�̐� ]
//	DX_DIRECT3DVERTEXDECLARATION9    *DefaultVertexDeclaration[2][3][9];
//
//#endif // DX_NON_MODEL
//
//	int						InitializeFlag;					// ���̃t���O�������Ă��鎞�͌��݂̃X�e�[�^�X�ƕύX
//	// �w��̃X�e�[�^�X�������ł��K�����s�����
//	int						DisplayModeNum;					// �ύX�\�ȃf�B�X�v���C���[�h�̐�
//	DISPLAYMODEDATA			*DisplayMode;						// �f�B�X�v���C���[�h���X�g
//
//	SHADERCONSTANTINFOSET	ShaderConstantInfo;				// �V�F�[�_�[�̒萔���
//
//	DX_DIRECT3DVERTEXDECLARATION9	*UserShaderDeclaration[DX_VERTEX_TYPE_NUM];	// ���[�U�[�V�F�[�_���[�h�Ŏg�p���钸�_�f�[�^�t�H�[�}�b�g
//
//	USERRENDERINFO			UserShaderRenderInfo;				// SetUseTextureToShader �Őݒ肳�ꂽ�e�X�e�[�W�̃e�N�X�`������A���[�U�[�ݒ�̃V�F�[�_�[�萔���Ȃ�
//
//	int						WorkDrawValidGrHandle[2][16][2];	// �t�B���^�[������Ɨp�`��\�e�N�X�`��[ 0:�����e�N�X�`�� 1:���������_�e�N�X�`�� ][ �Q�̂��� ][ ��Ɨp�Q�� ]
//#ifndef DX_NON_FILTER
//	SHADERCODE_HANDLE		ShaderCode;						// ���C�u�������p�ӂ���V�F�[�_�[�R�[�h
//#endif // DX_NON_FILTER
#pragma endregion 
};

// �\�t�g�E�G�A�����_�����O�Ŏg�p������̍\����
struct GRAPHICS_SOFTDATA
{
#pragma region HIDE
	//MEMIMG					MainBufferMemImg;					// ���C����ʗp MEMIMG
	//MEMIMG					FontScreenMemImgNormal;			// �������`��Ȃǂ̎��Ɏg���t�H���g�p MEMIMG ( �A���t�@�Ȃ� )
	//MEMIMG					FontScreenMemImgAlpha;				// �������`��Ȃǂ̎��Ɏg���t�H���g�p MEMIMG ( �A���t�@�� )
	//MEMIMG					*TargetMemImg;						// �`��Ώۂ� MEMIMG
	//MEMIMG					*BlendMemImg;						// �u�����h�`��p MEMIMG
#pragma endregion
};

// �O���t�B�b�N�����Ǘ��f�[�^�\����
struct GRAPHICSMANAGE
{
#pragma region HIDE
//	int						InitializeFlag;						// �������t���O
//
//	int						MainScreenSizeX, MainScreenSizeY;		// ���C����ʂ̃T�C�Y
//	int						MainScreenSizeX_Result, MainScreenSizeY_Result;	// GetDrawScreenSize �̕Ԃ�l�ɂȂ�T�C�Y
//	int						MainScreenColorBitDepth;				// ���C����ʂ̃J���[�r�b�g�[�x
//	int						MainScreenRefreshRate;					// ���C����ʂ̃��t���b�V�����[�g
//	RECT					OriginalDrawRect;						// �E�C���h�E�̈ʒu�ɂ���ĉ��ς����O�̎g�p�҂��Ӑ}���鐳�����`���`
//	int						UseChangeDisplaySettings;				// ChangeDisplaySettings ���g�p���ĉ�ʃ��[�h��ύX�������ǂ���( TRUE:ChangeDisplaySettings ���g�p����  FALSE:ChangeDisplaySettings �͎g�p���Ă��Ȃ� )
//	int						ChangeGraphModeFlag;					// ChangeGraphMode �����s�����ǂ����̃t���O
//
//	int						ValidGraphDisplayArea;					// GraphDisplayArea �ɗL���Ȓl�������Ă��邩�ǂ���
//	RECT					GraphDisplayArea;						// �\��ʂɓ]�����闠��ʂ̗̈�
//	RECT					LastCopySrcRect;						// �Ō�Ƀt�B�b�g�]�������Ƃ��̃R�s�[����`
//	RECT					LastCopyDestRect;						// �Ō�Ƀt�B�b�g�]�������Ƃ��̃R�s�[���`
//	int						EnableBackgroundColor;					// �o�b�N�O���E���h�h��ׂ��p�J���[���L�����ǂ����̃t���O
//	int						BackgroundRed, BackgroundGreen, BackgroundBlue;	// �o�b�N�O���E���h�h��ׂ��p�J���[
//
//	LONGLONG				VSyncWaitTime;							// �O��u�r�x�m�b�҂������Ă��玟�Ƀ`�F�b�N����܂łɑ҂���
//	LONGLONG				VSyncTime;								// �O��u�r�x�m�b�҂�����������
//
//	int						ValidHardWare;							// �n�[�h�E�G�A�`�悪�\���ǂ���( TRUE:�\  FALSE:�s�\ )
//	int						NotUseHardWare;						// �n�[�h�E�G�A�`��̋@�\���g�p���Ȃ����ǂ���( TRUE:�g�p���Ȃ�  FALSE:�g�p���� )
//	int						ChangeScreenModeNotGraphicsSystemFlag;	// ��ʃ��[�h�̕ύX���ɉ摜�n���h�����폜���Ȃ����ǂ���( TRUE:���Ȃ�  FALSE:���� )
//
//
//	int						ShaderInitializeFlag;					// �V�F�[�_�[�o�C�i���̃Z�b�g�A�b�v���������Ă��邩�ǂ����̃t���O( TRUE:�������Ă���  FALSE:�������Ă��Ȃ� )
//
//	DXARC					BaseShaderBinDxa;						// ��{�V�F�[�_�[�I�u�W�F�N�g�t�@�C���c�w�`�\����
//	void					*BaseShaderBinDxaImage;				// ��{�V�F�[�_�[�I�u�W�F�N�g�t�@�C���c�w�`�̃o�C�i���C���[�W
//
//#ifndef DX_NON_FILTER
//	DXARC					FilterShaderBinDxa;					// �t�B���^�[�V�F�[�_�[�I�u�W�F�N�g�t�@�C���c�w�`�\����
//	void					*FilterShaderBinDxaImage;				// �t�B���^�[�V�F�[�_�[�I�u�W�F�N�g�t�@�C���c�w�`�̃o�C�i���C���[�W
//
//	void					*RGBAMixS_ShaderPackImage;				// RGBAMix �� S �����̑g�ݍ��킹�Q�T�U�̃V�F�[�_�[�p�b�P�[�W�o�C�i���C���[�W
//
//	// RGBAMix �� S �����̑g�ݍ��킹�Q�T�U�̃V�F�[�_�[[ R ][ G ][ B ][ A ]
//	void					*RGBAMixS_ShaderAddress[4][4][4][4];
//	short					RGBAMixS_ShaderSize[4][4][4][4];
//#endif // DX_NON_FILTER
//
//	// ���C�g�C���f�b�N�X���X�g
//	short					LightIndexList84[4][4][4][4][4][4];
//	short					LightIndexList20[4][4][4];
//
//	short					LightIndexList10[3][3][3];
//
//#ifndef DX_NON_MODEL
//	void					*ModelShaderPackImage;					// �R�c���f���p�V�F�[�_�[�p�b�P�[�W�o�C�i���C���[�W
//
//	// ���f���`��p�s�N�Z���P�ʃ��C�e�B���O�^�C�v�̒��_�V�F�[�_�[( ���X�g�͔z��̍����� )
//	// [ �V���h�E�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ ���b�V���^�C�v( 0:���̃��b�V�� 1:4�{�[�����X�L�j���O���b�V�� 2:8�{�[�����X�L�j���O���b�V�� ) ]
//	// [ �o���v�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ �t�H�O�^�C�v ]
//	void					*MV1_PixelLighting_VertexShaderAddress[2][3][2][4];
//
//	// ���f���`��p�s�N�Z���P�ʃ��C�e�B���O�^�C�v�̃g�D�[���p�s�N�Z���V�F�[�_�[( ���X�g�͔z��̍����� )
//	// [ �V���h�E�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ �g�D�[�������_�����O���ǂ���( 0:�g�D�[�������_�����O type 1   1:�g�D�[�������_�����O Type 2 ) ]
//	// [ �g�D�[�������_�����O�̃X�t�B�A�}�b�v�̗L���ƃu�����h�^�C�v( 0:�X�t�B�A�}�b�v�͖���   1:MV1_LAYERBLEND_TYPE_MODULATE  2:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ �g�D�[�������_�����O�̃f�B�t���[�Y�O���f�[�V�����̃u�����h�^�C�v( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	// [ �g�D�[�������_�����O�̃X�y�L�����O���f�[�V�����̃u�����h�^�C�v( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ �X�y�L�����}�b�v ( 0:���� 1:���� ) ]
//	// [ �o���v�}�b�v ( 0:�Ȃ� 1:���� ) ]
//	// [ ���C�g�C���f�b�N�X ]
//	// [ �X�y�L�����̗L��( 0:���� 1:�L�� ) ]
//	void					*MV1_PixelLighting_ToonPixelShaderAddress[2][2][3][2][2][2][2][84][2];
//
//	// ���f���`��p�s�N�Z���P�ʃ��C�e�B���O�^�C�v�̃s�N�Z���V�F�[�_�[( ���X�g�͔z��̍����� )
//	// [ �V���h�E�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ �}���`�e�N�X�`���̃u�����h���[�h�AMV1_LAYERBLEND_TYPE_TRANSLUCENT �Ȃǂ� +1 �������� ( 0:�}���`�e�N�X�`������  1:���u�����h  2:���Z�u�����h  3:��Z�u�����h  4:��Z�u�����h�~2 ) ]
//	// [ �X�y�L�����}�b�v ( 0:���� 1:���� ) ]
//	// [ �o���v�}�b�v ( 0:�Ȃ� 1:���� ) ]
//	// [ ���C�g�C���f�b�N�X ]
//	// [ �X�y�L�����̗L��( 0:���� 1:�L�� ) ]
//	void					*MV1_PixelLighting_PixelShaderAddress[2][5][2][2][84][2];
//
//
//
//
//
//
//	// ���f���`��p�̃g�D�[�������_�����O�̗֊s���`��p���_�V�F�[�_�[
//	// [ ���b�V���^�C�v( 0:���̃��b�V�� 1:4�{�[�����X�L�j���O���b�V��  2:8�{�[�����X�L�j���O���b�V�� ) ]
//	// [ �t�H�O�^�C�v ]
//	void					*MV1_ToonOutLineVertexShaderAddress[3][4];
//
//	// ���f���`��p�̃V���h�E�}�b�v�ւ̃����_�����O�p���_�V�F�[�_�[
//	// [ ���b�V���^�C�v( 0:���̃��b�V�� 1:4�{�[�����X�L�j���O���b�V��  2:8�{�[�����X�L�j���O���b�V�� ) ]
//	void					*MV1_ShadowMapVertexShaderAddress[3];
//
//	// ���f���`��p�̃��C�e�B���O�Ȃ����_�V�F�[�_�[
//	// [ ���b�V���^�C�v( 0:���̃��b�V�� 1:4�{�[�����X�L�j���O���b�V��  2:8�{�[�����X�L�j���O���b�V�� ) ]
//	// [ �t�H�O�^�C�v ]
//	void					*MV1_NoLightingVertexShaderAddress[3][4];
//
//	// ���f���`��p�̃��C�e�B���O���蒸�_�V�F�[�_�[
//	// [ �V�F�[�_�[���f��( 0:SM2  1:SM3 )
//	// [ �V���h�E�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ ���b�V���^�C�v( 0:���̃��b�V�� 1:4�{�[�����X�L�j���O���b�V��  2:8�{�[�����X�L�j���O���b�V�� ) ]
//	// [ �o���v�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ �t�H�O�^�C�v ]
//	// [ ���C�g�C���f�b�N�X ]
//	// [ �X�y�L�����̗L��( 0:���� 1:�L�� ) ]
//	void					*MV1_LightingVertexShaderAddress[2][2][3][2][4][20][2];
//
//
//	// ���f���`��p�̃g�D�[�������_�����O�̗֊s���`��p�s�N�Z���V�F�[�_�[
//	void					*MV1_ToonOutLinePixelShaderAddress;
//
//	// ���f���`��p�̃V���h�E�}�b�v�ւ̃g�D�[�������_�����O�p�s�N�Z���V�F�[�_�[
//	// [ �g�D�[�������_�����O�^�C�v( 0:�g�D�[�������_�����O type 1   1:�g�D�[�������_�����O type 2 ) ]
//	// [ �g�D�[�������_�����O�̃X�t�B�A�}�b�v�̗L���ƃu�����h�^�C�v( 0:�X�t�B�A�}�b�v�͖���   1:MV1_LAYERBLEND_TYPE_MODULATE  2:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ �g�D�[�������_�����O�̃f�B�t���[�Y�O���f�[�V�����̃u�����h�^�C�v( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	void					*MV1_ShadowMapToonPixelShaderAddress[2][3][2];
//
//	// ���f���`��p�̃V���h�E�}�b�v�ւ̃����_�����O�p�s�N�Z���V�F�[�_�[
//	void					*MV1_ShadowMapPixelShaderAddress;
//
//	// ���f���`��p�̃��C�e�B���O�Ȃ��g�D�[���p�s�N�Z���V�F�[�_�[( ���X�g�͔z��̍����� )
//	// [ �g�D�[�������_�����O�^�C�v( 0:�g�D�[�������_�����O type 1   1:�g�D�[�������_�����O type 2 ) ]
//	// [ �g�D�[�������_�����O�̃f�B�t���[�Y�O���f�[�V�����̃u�����h�^�C�v( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT or �g�D�[�������_�����O�ł͂Ȃ�  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	void					*MV1_ToonNoLightingPixelShaderAddress[2][2];
//
//	// ���f���`��p�̃��C�e�B���O�Ȃ��s�N�Z���V�F�[�_�[
//	// [ �}���`�e�N�X�`���̃u�����h���[�h�AMV1_LAYERBLEND_TYPE_TRANSLUCENT �Ȃǂ� +1 �������� ( 0:�}���`�e�N�X�`������  1:���u�����h  2:���Z�u�����h  3:��Z�u�����h  4:��Z�u�����h�~2 ) ]
//	void					*MV1_NoLightingPixelShaderAddress[5];
//
//	// ���f���`��p�̃��C�e�B���O����g�D�[���p�s�N�Z���V�F�[�_�[
//	// [ �V�F�[�_�[���f��( 0:SM2  1:SM3 )
//	// [ �V���h�E�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ �g�D�[�������_�����O�^�C�v( 0:�g�D�[�������_�����O type 1   1:�g�D�[�������_�����O type 2 ) ]
//	// [ �g�D�[�������_�����O�̃X�t�B�A�}�b�v�̗L���ƃu�����h�^�C�v( 0:�X�t�B�A�}�b�v�͖���   1:MV1_LAYERBLEND_TYPE_MODULATE  2:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ �g�D�[�������_�����O�̃f�B�t���[�Y�O���f�[�V�����̃u�����h�^�C�v( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_MODULATE ) ]
//	// [ �g�D�[�������_�����O�̃X�y�L�����O���f�[�V�����̃u�����h�^�C�v( 0:MV1_LAYERBLEND_TYPE_TRANSLUCENT  1:MV1_LAYERBLEND_TYPE_ADDITIVE ) ]
//	// [ �X�y�L�����}�b�v ( 0:���� 1:���� ) ]
//	// [ �o���v�}�b�v ( 0:�Ȃ� 1:���� ) ]
//	// [ ���C�g�C���f�b�N�X ]
//	// [ �X�y�L�����̗L��( 0:���� 1:�L�� ) ]
//	void					*MV1_ToonLightingPixelShaderAddress[2][2][2][3][2][2][2][2][10][2];
//
//	// ���f���`��p�̃��C�e�B���O����s�N�Z���V�F�[�_�[
//	// [ �V�F�[�_�[���f��( 0:SM2  1:SM3 )
//	// [ �V���h�E�}�b�v�̗L��( 0:���� 1:�L�� ) ]
//	// [ �}���`�e�N�X�`���̃u�����h���[�h�AMV1_LAYERBLEND_TYPE_TRANSLUCENT �Ȃǂ� +1 �������� ( 0:�}���`�e�N�X�`������  1:���u�����h  2:���Z�u�����h  3:��Z�u�����h  4:��Z�u�����h�~2 ) ]
//	// [ �X�y�L�����}�b�v ( 0:���� 1:���� ) ]
//	// [ �o���v�}�b�v ( 0:�Ȃ� 1:���� ) ]
//	// [ ���C�g�C���f�b�N�X ]
//	// [ �X�y�L�����̗L��( 0:���� 1:�L�� ) ]
//	void					*MV1_LightingPixelShaderAddress[2][2][5][2][2][10][2];
//
//#endif // DX_NON_MODEL
#pragma endregion

	GRAPHICS_HARDDATA		Hard;									// �n�[�h�E�F�A�A�N�Z�����[�^���g�p���鏈���ɕK�v�ȏ��
	GRAPHICS_SOFTDATA		Soft;									// �\�t�g�E�G�A�����_�����O���g�p����ۂɕK�v�ȏ��
};


// �O���t�B�b�N�X�Ǘ��f�[�^�\����
extern GRAPHICSMANAGE GraphicsManage;

// �J�����֌W���̍\����
struct GRAPHICSSYS_CAMERA
{
	DirectX::XMMATRIX vWorld;//���[���h�ϊ�
	DirectX::XMMATRIX vView;//�r���[�ϊ��s��
	DirectX::XMMATRIX vProjection;//�����ˉe�ϊ�

    //VECTOR_D				Position;								// �J�����̈ʒu
	//VECTOR_D				Target;								// �J�����̒����_
	//VECTOR_D				Up;									// �J�����̃A�b�v�x�N�g��
	//double					HRotate;								// �J�����̐����p�x
	//double					VRotate;								// �J�����̐����p�x
	//double					TRotate;								// �J�����̔P��p�x
	//MATRIX_D				Matrix;								// �r���[�s��
	//double					ScreenCenterX;							// �J�����̏����_
	//double					ScreenCenterY;
};

// �O���t�B�N�X�V�X�e���p�f�[�^�\����
struct GRAPHICSSYSTEMDATA
{
	//int								InitializeFlag;						// �������t���O
	//
	//
	//GRAPHICSSYS_SETTINGDATA			Setting;								// �ݒ�֌W�̏��
	//
	//GRAPHICSSYS_HARDWAREINFO		HardInfo;								// �n�[�h�E�F�A�A�N�Z�����[�^�֌W�̏��
	//
	//GRAPHICSSYS_SOFTRENDERDATA		SoftRender;							// �\�t�g�E�G�A�����_�����O�Ŏg�p������
	//
	//GRAPHICSSYS_SCREENDATA			Screen;								// ��ʊ֌W�̏��
	//
	//GRAPHICSSYS_CREATEIMAGEDATA		CreateImage;							// �摜�쐬�֌W�̏��
	//
	//GRAPHICSSYS_RESOURCE			Resource;								// �������s�p���\�[�X�֌W�̍\����
	//
	//GRAPHICSSYS_DRAWSETTINGDATA		DrawSetting;							// �`��ݒ�֌W�̏��
	//
	//GRAPHICSSYS_LIGHTATA			Light;									// ���C�g�֌W�̏��

	GRAPHICSSYS_CAMERA				Camera;								// �J�����֌W�̏��

	//int								ChangeSettingFlag;						// �ݒ肪�ύX���ꂽ���ǂ���
};

// �O���t�B�b�N�X�Ǘ��f�[�^�\����
extern GRAPHICSSYSTEMDATA GraphicsSysData;

int InitializeDirectX(void);
int TerminateDirectX(void);



// �`�悷��
int Draw(void);

// �o�b�N�o�b�t�@���t���b�v����
int Flip(void);

}//namespace Azalea


