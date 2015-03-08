#include "types.h"
#include "Window.h"

//���C���E�C���h�E�̃N���X��
#define AZALEA_DEFAULT_CLASSNAME		TEXT( "AZALEA123987AZALEA" )


namespace Azalea
{

//�E�C���h�E�̃f�[�^
WINDATA WinData;

//���C���E�C���h�E�̃��b�Z�[�W�R�[���o�b�N�֐�
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

	// ������
	::SecureZeroMemory(&WinData, sizeof(WinData));

	::lstrcpy(WinData.CurrentDirectory, CurrentDirectory);
	::lstrcpy(WinData.WindowText, WindowText);
	::lstrcpy(WinData.ClassName, ClassName);
	WinData.MainWindow = MainWindow;


	// �C���X�^���X�n���h���̎擾
	WinData.Instance = ::GetModuleHandle(NULL);

	// �N���X���������ݒ肳��Ă��Ȃ��ꍇ�̓E�C���h�E�^�C�g���܂��̓f�t�H���g�̖��O��ݒ肷��
	if (WinData.ClassName[0] == TEXT('\0'))
	{
		// �E�C���h�E�^�C�g�����ݒ肳��Ă���ꍇ�͂����ݒ肷��
		if (WinData.WindowText[0] != TEXT('\0'))
		{
			::lstrcpy(WinData.ClassName, WinData.WindowText);
		}
		else
		{
			::lstrcpy(WinData.ClassName, AZALEA_DEFAULT_CLASSNAME);
		}
	}


	//�E�B���h�E�N���X��o�^
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


	//�E�B���h�E���쐬
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

// �\���Ɏg�p����E�C���h�E�̃n���h�����擾����
HWND GetDisplayWindowHandle(void)
{
	return WinData.MainWindow;
}



}//namespace Azalea

