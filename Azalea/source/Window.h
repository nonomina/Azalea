#pragma once

#include "types.h"

namespace Azalea
{

// �E�C���h�E�n�f�[�^�\����
struct WINDATA
{
    HINSTANCE  Instance;                        //�\�t�g�̃C���X�^���X�n���h��
    TCHAR      WindowText[256];                 // ���C���E�C���h�E�e�L�X�g
    TCHAR      ClassName[256];                  // ���C���E�C���h�E�̃N���X��
    TCHAR      CurrentDirectory[MAX_PATH];      // �N�����̃J�����g�f�B���N�g��

    HWND       MainWindow;                      //���C���E�C���h�E�n���h��
};

//�E�C���h�E�̃f�[�^
extern WINDATA WinData;

//�E�B���h�E�f�[�^�̏�����
int InitializeWindow(void);

//�E�B���h�E�f�[�^�̃n���h�����擾����
HWND GetDisplayWindowHandle(void);


}//namespace Azalea


