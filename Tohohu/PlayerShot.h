#pragma once

#define PSHOT_SIZE_X 24				// ’e‚Ì»²½X
#define PSHOT_SIZE_Y 24				// ’e‚Ì»²½ŞY
#define PSHOT_NUM 50				// ’e‚Ì•`‰æŠm•Û
#define PSHOT_DEF_SPEED 20			// ’e‘¬
#define PSHOT_TIME_NORMAL 5			// ’ÊíUŒ‚˜AËŠÔŠu
#define PSHOT_TIME_FIRE 20			// ‰Š–‚–@UŒ‚˜AËŠÔŠu
#define PSHOT_HIT_RAD 8				// “–‚½‚è”»’è

struct PlayerShot
{
	Vector2 pos;			// À•W
	Vector2 move;			// ˆÚ“®—Ê
	float endPos;			// •`‰æI—¹ˆÊ’u
	float speed;			// ‘¬‚³
	float rad;				// ”¼Œa
	int  rotaAngle;			// ‰ñ“]Šp
	int moveAngle;			// “®‚­•ûŒü
	int damage;				// UŒ‚—Í
	int blastCnt;			// ”š”­‚Ì¶³İÄ
	PSHOT_ID shotID;		// ’e‚Ìí—Ş
	bool drawFlag;			// •`‰æÌ×¸Ş	
	bool blastFlag;			// ”š”­Ì×¸Ş
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
void PlayerShotDraw(void);		// •`‰æ
void PlayerShotMove(void);		// ˜AËÉ°ÏÙ

int HitShot(PlayerShot * pShot);	// ’e‚ª“–‚½‚Á‚½‚Ìˆ—A•Ô‚è’l‚Í’e‚ÌÀŞÒ°¼Ş
