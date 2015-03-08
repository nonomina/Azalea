#pragma once

#include "types.h"

namespace Azalea
{

// ウインドウ系データ構造体
struct WINDATA
{
    HINSTANCE  Instance;                        //ソフトのインスタンスハンドル
    TCHAR      WindowText[256];                 // メインウインドウテキスト
    TCHAR      ClassName[256];                  // メインウインドウのクラス名
    TCHAR      CurrentDirectory[MAX_PATH];      // 起動時のカレントディレクトリ

    HWND       MainWindow;                      //メインウインドウハンドル
};

//ウインドウのデータ
extern WINDATA WinData;

//ウィンドウデータの初期化
int InitializeWindow(void);

//ウィンドウデータのハンドルを取得する
HWND GetDisplayWindowHandle(void);


}//namespace Azalea


