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

#define BLAST_DIV_NUM_X 4	// �����摜��X�����̕�����
#define BLAST_DIV_NUM_Y 4	// �����摜��Y�����̕�����

#define BLAST_SIZE_X 96		// �����摜�̻���X
#define BLAST_SIZE_Y 96		// �����摜�̻���Y

#define PI 3.14159265359f		// �~����

#define RAD_TO_DEG(rad) ((int)(rad * 180.0f / PI))		// ׼ޱ݂���x���ւ̕ϊ�
#define DEG_TO_RAD(deg) ((float)(deg * PI / 180.0f))	// �x������׼ޱ݂ւ̕ϊ�

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

// �G�̏����z�u���
struct EnemyInit
{
	int count;		// �o�������ڰ�
	int movePtn;	// �ړ������
	Vector2 pos;	// �������W
	int moveAngle;	// �ړ��p�x
};

// �G�̒e
struct EShot
{
	Vector2 pos;	// ���W
	Vector2 move;	// �ړ���
	float speed;	// ����
	int moveAngle;  // �ړ��p�x
	float hitRad;	// �����蔻��̉~�̔��a
	int rotaAngle;	// ��]�p�x(�x)
	int count;		// �ړ��p�̶���
	bool drawFlag;		// �\���׸�
	bool blastFlag;	// �����׸�
};

// �G���G
struct Enemy
{
	Vector2 pos;	// ���W
	Vector2 move;	// �ړ���
	float hitRad;	// �����蔻��̉~�̔��a
	int moveAngle;	// �ړ��p�x(�x)
	int moveCount;	// �ړ����n�߂Ă���̶���
	int animCount;	// ��Ұ��ݶ���
	int life;		// �c��̗�
	bool drawFlag;	// �`���׸�
	bool atkFlag;	// �U���׸�
	bool blastFlag;	// �����׸�
	EnemyInit initData;		// �����z�u���
};

// �޽
struct Boss
{
	Vector2 pos;	// ���W
	Vector2 move;	// �ړ���
	float speed;
	float hitRad;	// �����蔻��̉~�̔��a
	int moveAngle;// �ړ��p�x(�x)
	int moveCount;	// �ړ����n�߂Ă���̶���
	int animCount;	// ��Ұ��ݶ���
	int life;		// �c��̗�
	bool drawFlag;	// �`���׸�
};

// extern�錾
#ifdef MAIN_DEF
#define MAIN_EX
#else
#define MAIN_EX extern
#endif

MAIN_EX void(*sceneFunc)(void);		// ��݊Ǘ��p�֐��߲��
MAIN_EX void(*sceneOldFunc)(void);		// 1�ڰёO��sceneFunc�̏��

MAIN_EX int framCnt;					// ���̼�݂ɂȂ��Ă�����ڰѐ�

MAIN_EX int keyFram[256];				// ���̉�����ԕۑ�

MAIN_EX int blastImg[BLAST_DIV_NUM_X * BLAST_DIV_NUM_Y];	// �����摜ID
MAIN_EX int eShotSound;
MAIN_EX int blastSound;

//=======================�֐��������ߐ錾================================

bool CheckHitObj(Vector2 aPos, float arad, Vector2 bPos, float brad);		// �����蔻��
bool isMoveOut(Vector2 pos);												// ��ʊO����
void UpdateKeyState(void);													// ��������ԍX�V
