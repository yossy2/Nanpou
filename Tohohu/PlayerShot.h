#pragma once

#define PSHOT_SIZE_X 24				// �e�̻��X
#define PSHOT_SIZE_Y 24				// �e�̻���Y
#define PSHOT_NUM 50				// �e�̕`��m��
#define PSHOT_DEF_SPEED 20			// �e��
#define PSHOT_TIME 5				// �A�ˊԊu
#define PSHOT_HIT_RAD 8				// �����蔻��

#define BEAM_SIZE_X 32				// �ްт̻���X
#define BEAM_SIZE_Y 680				// �ްт̻���Y
#define BEAM_ANIM_NUM 4				// �ްт̱�Ұ��ݖ���

struct PlayerShot
{
	Vector2 pos;			// ���W
	Vector2 move;			// �ړ���
	float speed;			// ����
	float moveAngle;		// ��������
	bool flag;				// �`���׸�
	float endPos;			// �`��I���ʒu
};

struct Beam
{
	Vector2 pos;			// ���W
	int animFram;			// ��Ұ��݂��ڰ�
	int animCnt;			// �ǂ̱�Ұ��݂�`�悷�邩
	bool drawFlag;			// �ްт̕`���׸�
	bool hitFlag;			// �`�悪�ő�ɂȂ����瓖���蔻�������悤�ɂ���
};

// extern�錾
#ifdef PSHOT_DEF
#define PSHOT_EX
#else
#define PSHOT_EX extern
#endif

PSHOT_EX PlayerShot pShot[PSHOT_NUM];		// ��ڲ԰���ĂɊւ���ϐ��̐錾
PSHOT_EX Beam beam;							// �ްтɊւ���ϐ��̐錾

// =============�֐��������ߐ錾
void PlayerShotInit(void);		// ������
void PlayerShotFunc(void);		// ����
void PlayerShotDraw(void);		// �`��
void PlayerShotMove(void);		// �ړ�����
void PShotPtn1(void);			// �A�������1
void PShotPtn2(void);			// �A�������2
