#pragma once

#define PSHOT_SIZE_X 24
#define PSHOT_SIZE_Y 24
#define PSHOT_NUM 50
#define PSHOT_DEF_SPEED 15

struct PlayerShot
{
	Vector2 pos;			// ���W
	Vector2 move;			// �ړ���
	float speed;			// ����
	float moveAngle;		// ��������
	bool flag;				// �`���׸�
	float endPos;			// �`��I���ʒu
};

// =============�֐�����ݐ錾
void PlayerShotInit(void);		// ������
void PlayerShotFunc(void);		// ����
void PlayerShotDraw(void);		// �`��

void PlayerShotMove(void);		// �ړ�����
