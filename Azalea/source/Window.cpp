#include "types.h"
#include "Window.h"

//メインウインドウのクラス名
#define AZALEA_DEFAULT_CLASSNAME		TEXT( "AZALEA123987AZALEA" )


namespace Azalea
{

//ウインドウのデータ
WINDATA WinData;

//メインウインドウのメッセージコールバック関数
static LRESULT CALLBACK Azalea_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message){
	case WM_CLOSE:
		::PostMessage(hWnd, WM_DESTROY, 0, 0);
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
	}

	return(::DefWindowProc(hWnd, message, wParam, lParam));
}


int InitializeWindow(void)
{
	TCHAR CurrentDirectory[MAX_PATH];
	TCHAR WindowText[MAX_PATH];
	TCHAR ClassName[256];
	HWND MainWindow = WinData.MainWindow;

	::lstrcpy(CurrentDirectory, WinData.CurrentDirectory);
	::lstrcpy(WindowText, WinData.WindowText);
	::lstrcpy(ClassName, WinData.ClassName);

	// 初期化
	::SecureZeroMemory(&WinData, sizeof(WinData));

	::lstrcpy(WinData.CurrentDirectory, CurrentDirectory);
	::lstrcpy(WinData.WindowText, WindowText);
	::lstrcpy(WinData.ClassName, ClassName);
	WinData.MainWindow = MainWindow;


	// インスタンスハンドルの取得
	WinData.Instance = ::GetModuleHandle(NULL);

	// クラス名が何も設定されていない場合はウインドウタイトルまたはデフォルトの名前を設定する
	if (WinData.ClassName[0] == TEXT('\0'))
	{
		// ウインドウタイトルが設定されている場合はそれを設定する
		if (WinData.WindowText[0] != TEXT('\0'))
		{
			::lstrcpy(WinData.ClassName, WinData.WindowText);
		}
		else
		{
			::lstrcpy(WinData.ClassName, AZALEA_DEFAULT_CLASSNAME);
		}
	}


	//ウィンドウクラスを登録
	WNDCLASS wcex;
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = Azalea_WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = WinData.Instance;
	wcex.hIcon = NULL;
	wcex.hCursor = NULL;
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = WinData.ClassName;
	::RegisterClass(&wcex);


	//ウィンドウを作成
	WinData.MainWindow = ::CreateWindow(WinData.ClassName,
		TEXT("3D Disp Pg"),
		WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		0,
		0,
		1920,
		1080,
		NULL,
		NULL,
		WinData.Instance,
		NULL);

	return 0;
}

// 表示に使用するウインドウのハンドルを取得する
HWND GetDisplayWindowHandle(void)
{
	return WinData.MainWindow;
}



}//namespace Azalea

