#pragma once

#define PLAYER_SIZE_X 48			// �Ұ�ނ̻���X
#define PLAYER_SIZE_Y 48			// �Ұ�ނ̻���Y
#define PLAYER_DEF_SPEED 6			// ��̫�Ă̑���
#define PLAYER_HIT_RAD 3.0f			// �����蔻��͈̔�
#define PLAYER_DEF_LIFE 5			// ��̫�Ă̎c�@��
#define PLAYER_POWER_MAX 400		// ��ܰ�̍ő�l
#define PLAYER_ANIM_MAX 4			// ��ڲ԰�̱�Ұ��ݐ�
#define PLAYER_REVIVAL_CNT 60		// ��ڲ԰���������Ă���ĕ\�������܂ł̎���

// enum��`
// ��ڲ԰ID
enum PL_ID
{
	PL_ID_SLIME,
	PL_ID_MAX
};

//���@�̒e�̎��
enum PSHOT_ID
{
	PSHOT_ID_NORMAL,
	PSHOT_ID_FIRE,
	PSHOT_ID_MAX,
};

// �\���̒�`
// ���@
struct Player
{
	Vector2 pos;		// ���W
	Vector2 move;		// �ړ���
	float speed;		// ����
	float moveAngle;	// �ړ��p�x
	bool drawFlag;		// �`��Ǘ�
	bool blastFlag;		// �����׸�
	bool revivalFlag;	// �����׸�
	int animCnt;		// ��Ұ��ݶ���
	int life;			// �c�@
	int power;			// ��ܰ�̑���
	int shotPowUp;		// ���Ă̏��
	PSHOT_ID shotPtn;	// ���Ă������
};

struct KeyList
{
	int move[DIR_MAX];	// �ړ���
	int shot;			// ���āA����
	int bomb;			// ��сA��ݾ�
	int pause;			// �߰��
	int slow;			// �ᑬ
};

// extern�錾
#ifdef PL_DEF
#define PL_EX
#else
#define PL_EX extern
#endif

PL_EX Player player;
PL_EX int playerImg[PLAYER_ANIM_MAX];

PL_EX KeyList keyList;
PL_EX int plPowUpSound;

bool PlayerInit(void);		// ���@�̏�����
void PlayerCtl(void);		// ���@�̏���
void PlayerDraw(void);		// ���@�̕`��
	
void PlayerMove(void);		// ���@�̈ړ�����
void PlayerDamage(void);	// ��Ұ�ނ��󂯂��Ƃ��̏���
void PlayerPowUp(void);		// ��ڲ԰���Ă̋���
void PlayerAttack1(void);	// �ʏ�U��
void PlayerAttack2(void);	// �����@�U��

