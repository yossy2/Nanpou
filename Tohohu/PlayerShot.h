#pragma once

#define PSHOT_SIZE_X 24				// �e�̻��X
#define PSHOT_SIZE_Y 24				// �e�̻���Y
#define PSHOT_NUM 50				// �e�̕`��m��
#define PSHOT_DEF_SPEED 20			// �e��
#define PSHOT_TIME 5				// �A�ˊԊu
#define PSHOT_HIT_RAD 8				// �����蔻��

struct PlayerShot
{
	Vector2 pos;			// ���W
	Vector2 move;			// �ړ���
	float endPos;			// �`��I���ʒu
	float speed;			// ����
	float rotaAngle;		// ��]�p
	int moveAngle;			// ��������
	bool flag;				// �`���׸�	
};

// extern�錾
#ifdef PSHOT_DEF
#define PSHOT_EX
#else
#define PSHOT_EX extern
#endif

PSHOT_EX PlayerShot pShot[PSHOT_NUM];		// ��ڲ԰���ĂɊւ���ϐ��̐錾

// =============�֐��������ߐ錾
void PlayerShotInit(void);		// ������
void PlayerShotFunc(void);		// ����
void PlayerShotDraw(void);		// �`��
void PlayerShotMove(void);		// �A��ɰ��
void PShotPtn1(void);			// �A�������1
