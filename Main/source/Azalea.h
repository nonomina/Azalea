#pragma once

#pragma once

#include <tchar.h>
#include <Windows.h>

/// ライブラリ関数の宣言を示す。ユーザ側はここで提供される関数を使う。
namespace Azalea{

//ライブラリ初期化を行う
int	Azalea_Init(void);

void SetTexutureFile(LPCWSTR texPath);

//メッセージループを肩代わりする
int	ProcessMessage(void);

}//namespace Azalea
