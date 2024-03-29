#pragma once

#define PSHOT_SIZE_X 24				// eÌ»²½X
#define PSHOT_SIZE_Y 24				// eÌ»²½ÞY
#define PSHOT_NUM 50				// eÌ`æmÛ
#define PSHOT_DEF_SPEED 20			// e¬
#define PSHOT_TIME_NORMAL 5			// ÊíUAËÔu
#define PSHOT_TIME_FIRE 20			// @UAËÔu
#define PSHOT_HIT_RAD 8				// ½è»è

struct PlayerShot
{
	Vector2 pos;			// ÀW
	Vector2 move;			// Ú®Ê
	float endPos;			// `æI¹Êu
	float speed;			// ¬³
	float rad;				// ¼a
	int  rotaAngle;			// ñ]p
	int moveAngle;			// ®­ûü
	int damage;				// UÍ
	int blastCnt;			// ­Ì¶³ÝÄ
	PSHOT_ID shotID;		// eÌíÞ
	bool drawFlag;			// `æÌ×¸Þ	
	bool blastFlag;			// ­Ì×¸Þ
};

// externé¾
#ifdef PSHOT_DEF
#define PSHOT_EX
#else
#define PSHOT_EX extern
#endif

PSHOT_EX PlayerShot pShot[PSHOT_NUM];		// ÌßÚ²Ô°¼®¯ÄÉÖ·éÏÌé¾
PSHOT_EX int pShotImage[PSHOT_ID_MAX];		// e

// =============ÖÌßÛÄÀ²Ìßé¾
void PlayerShotInit(void);		// ú»
void PlayerShotDraw(void);		// `æ
void PlayerShotMove(void);		// AËÉ°ÏÙ

int HitShot(PlayerShot * pShot);	// eª½Á½ÌAÔèlÍeÌÀÞÒ°¼Þ
