#pragma once

#define PSHOT_SIZE_X 24				// ’e‚Ì»²½X
#define PSHOT_SIZE_Y 24				// ’e‚Ì»²½ŞY
#define PSHOT_NUM 50				// ’e‚Ì•`‰æŠm•Û
#define PSHOT_DEF_SPEED 20			// ’e‘¬
#define PSHOT_TIME 5				// ˜AËŠÔŠu
#define PSHOT_HIT_RAD 8				// “–‚½‚è”»’è

struct PlayerShot
{
	Vector2 pos;			// À•W
	Vector2 move;			// ˆÚ“®—Ê
	float speed;			// ‘¬‚³
	float moveAngle;		// “®‚­•ûŒü
	bool flag;				// •`‰æÌ×¸Ş
	float endPos;			// •`‰æI—¹ˆÊ’u
};

// externéŒ¾
#ifdef PSHOT_DEF
#define PSHOT_EX
#else
#define PSHOT_EX extern
#endif

PSHOT_EX PlayerShot pShot[PSHOT_NUM];		// ÌßÚ²Ô°¼®¯Ä‚ÉŠÖ‚·‚é•Ï”‚ÌéŒ¾

// =============ŠÖ”ÌßÛÄÀ²ÌßéŒ¾
void PlayerShotInit(void);		// ‰Šú‰»
void PlayerShotFunc(void);		// ˆ—
void PlayerShotDraw(void);		// •`‰æ
void PlayerShotMove(void);		// ˜AËÉ°ÏÙ
void PShotPtn1(void);			// ˜AËÊßÀ°İ1
