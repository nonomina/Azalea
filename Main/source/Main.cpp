#include <windows.h>
#include <tchar.h>
#include "Main.h"
#include "Azalea.h"

using namespace Azalea;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	Azalea_Init();
	//LPCWSTR texPath = TEXT("result\\resource\\example.dds");
	LPCWSTR texPath = TEXT("result\\resource\\example.png");
	SetTexutureFile(texPath);
	ProcessMessage();

	return 0;
}
