#include "Window.h"
#include "Graphics.h"

namespace Azalea
{

// ���C�u�����̏�����
int Azalea_Init(void)
{
	::GetCurrentDirectory(MAX_PATH, WinData.CurrentDirectory);

	InitializeWindow();//WinData�������A�E�B���h�E�̍쐬
	//InitiaLizeCom()//CoInitializeEx()
	//InitializeGraphics2()//CreateDevice
		InitializeDirectX();//DirectX������
	//InitiLizeLog()

	return 0;
}

// �E�B���h�E�̃��b�Z�[�W���[�v��������
int ProcessMessage(void)
{
	//ProcessMessage
	//	NS_ScreenCopy = ScreenCopy
	//	ScreenFlipBase
	//	GraphicsDevice_Present
	//	Direct3DSwapChain9Object->Present


	//���C�����[�v
	MSG hMsg;
	while (true){
		while (::PeekMessage(&hMsg, NULL, 0, 0, PM_REMOVE)){
			if (hMsg.message == WM_QUIT){
				return 0;
			}
			::TranslateMessage(&hMsg);
			::DispatchMessage(&hMsg);
		}

		//�`��
		Draw();

		//�o�b�N�o�b�t�@���X���b�v
		Flip();
	}


	return 0;
}

}//namespace Azalea