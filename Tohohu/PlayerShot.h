#pragma once

#define PSHOT_SIZE_X 24				// �e�̻��X
#define PSHOT_SIZE_Y 24				// �e�̻���Y
#define PSHOT_NUM 50				// �e�̕`��m��
#define PSHOT_DEF_SPEED 20			// �e��
#define PSHOT_TIME_NORMAL 5			// �ʏ�U���A�ˊԊu
#define PSHOT_TIME_FIRE 10			// �����@�U���A�ˊԊu
#define PSHOT_HIT_RAD 8				// �����蔻��

struct PlayerShot
{
	Vector2 pos;			// ���W
	Vector2 move;			// �ړ���
	float endPos;			// �`��I���ʒu
	float speed;			// ����
	float rad;				// ���a
	int  rotaAngle;			// ��]�p
	int moveAngle;			// ��������
	int damage;				// �U����
	PSHOT_ID shotID;		// �e�̎��
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
void PlayerShotDraw(void);		// �`��
void PlayerShotMove(void);		// �A��ɰ��

int HitShot(PlayerShot * pShot);	// �e�������������̏����A�Ԃ�l�͒e����Ұ��
