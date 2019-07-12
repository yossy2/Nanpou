#pragma once

// ���ޯ��ү���ޗp��`
#ifdef _DEBUG
#define AST(){\
	CHAR ast_mes[256];\
	wsprintf(ast_mes,"%s %d�s��\0",__FILE__,__LINE__);\
	MessageBox(0,ast_mes,"���ĕ\��", MB_OK);\
	}
#else
#define AST()
#endif

// enum��`


// define��`
#define SCREEN_SIZE_X 1080		// ����޳����X
#define SCREEN_SIZE_Y 720		// ����޳����Y

#define GAME_SCREEN_SIZE_X 640	// �ްщ�ʻ���X
#define GAME_SCREEN_SIZE_Y 680	// �ްщ�ʻ���Y

#define GAME_SCREEN_X 20.0f		// �ްщ�ʂ̵̾��X
#define GAME_SCREEN_Y 20.0f		// �ްщ�ʂ̵̾��Y

#define PI 3.14159265359f		// �~����

// enum��`
// ����
enum DIR
{
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_MAX,
};

// �\����
// �񎟌����W
struct Vector2
{
	float x;
	float y;
};

// �G�̒e
struct EShot
{
	Vector2 pos;	// ���W
	Vector2 speed;	// �ړ���
	float moveAngle;// �ړ��p�x(׼ޱ�)
	float count;	// �ړ��p�̶���
	float hitRad;	// �����蔻��̉~�̔��a
	int rotaAngle;	// ��]�p�x(�x)
	bool flag;		// �\���׸�
};

// �G���G
struct Enemy
{
	Vector2 pos;	// ���W
	Vector2 move;	// �ړ���
	float hitRad;	// �����蔻��̉~�̔��a
	float moveCount;// �ړ����n�߂Ă���̶���
	int life;		// �c��̗�
	bool drawFlag;	// �`���׸�
	bool atkFlag;	// �U���׸�
};

// extern�錾
#ifdef MAIN_DEF
#define MAIN_EX
#else
#define MAIN_EX extern
#endif

MAIN_EX void(*sceneFunc)(void);		// ��݊Ǘ��p�֐��߲��
MAIN_EX void(*sceneOldFunc)(void);	// 1�ڰёO��sceneFunc�̏��

MAIN_EX int flamCnt;				// ���̼�݂ɂȂ��Ă�����ڰѐ�