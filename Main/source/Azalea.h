#pragma once

#pragma once

#include <tchar.h>
#include <Windows.h>

/// ���C�u�����֐��̐錾�������B���[�U���͂����Œ񋟂����֐����g���B
namespace Azalea{

//���C�u�������������s��
int	Azalea_Init(void);

void SetTexutureFile(LPCWSTR texPath);

//���b�Z�[�W���[�v�������肷��
int	ProcessMessage(void);

}//namespace Azalea
