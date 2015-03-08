#include "Window.h"
#include "Graphics.h"

namespace Azalea
{

// ライブラリの初期化
int Azalea_Init(void)
{
	::GetCurrentDirectory(MAX_PATH, WinData.CurrentDirectory);

	InitializeWindow();//WinData初期化、ウィンドウの作成
	//InitiaLizeCom()//CoInitializeEx()
	//InitializeGraphics2()//CreateDevice
		InitializeDirectX();//DirectX初期化
	//InitiLizeLog()

	return 0;
}

// ウィンドウのメッセージループを肩代わり
int ProcessMessage(void)
{
	//ProcessMessage
	//	NS_ScreenCopy = ScreenCopy
	//	ScreenFlipBase
	//	GraphicsDevice_Present
	//	Direct3DSwapChain9Object->Present


	//メインループ
	MSG hMsg;
	while (true){
		while (::PeekMessage(&hMsg, NULL, 0, 0, PM_REMOVE)){
			if (hMsg.message == WM_QUIT){
				return 0;
			}
			::TranslateMessage(&hMsg);
			::DispatchMessage(&hMsg);
		}

		//描画
		Draw();

		//バックバッファをスワップ
		Flip();
	}


	return 0;
}

}//namespace Azalea