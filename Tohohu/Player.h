#pragma once

#define PLAYER_SIZE_X 48
#define PLAYER_SIZE_Y 48

#define PLAYER_DEF_SPEED 6

// enum��`
// ��ڲ԰ID
enum PL_ID
{
	PL_ID_SLIME,
	PL_ID_MAX
};

// �\���̒�`
// ���@
struct Player
{
	Vector2 pos;		// ���W
	Vector2 move;		// �ړ���
	float speed;		// ����
	float moveAngle;	// �ړ��p�x
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
PL_EX int playerImg;

PL_EX KeyList keyList;

bool PlayerInit(void);		// ���@�̏�����
void PlayerCtl(void);		// ���@�̏���
void PlayerDraw(void);		// ���@�̕`��
	
void PlayerMove(void);		// ���@�̈ړ�����
