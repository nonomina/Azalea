#include <windows.h>
#include <tchar.h>
#include "Azalea.h"

using namespace Azalea;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	Azalea_Init();
	ProcessMessage();

	return 0;
}
