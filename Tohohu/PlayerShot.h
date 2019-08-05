#pragma once

#define PSHOT_SIZE_X 24				// ’e‚Ì»²½X
#define PSHOT_SIZE_Y 24				// ’e‚Ì»²½ŞY
#define PSHOT_NUM 50				// ’e‚Ì•`‰æŠm•Û
#define PSHOT_DEF_SPEED 20			// ’e‘¬
#define PSHOT_TIME 5				// ˜AËŠÔŠu
#define PSHOT_HIT_RAD 8				// “–‚½‚è”»’è

#define BEAM_SIZE_X 32				// ËŞ°Ñ‚Ì»²½ŞX
#define BEAM_SIZE_Y 680				// ËŞ°Ñ‚Ì»²½ŞY
#define BEAM_ANIM_NUM 4				// ËŞ°Ñ‚Ì±ÆÒ°¼®İ–‡”

struct PlayerShot
{
	Vector2 pos;			// À•W
	Vector2 move;			// ˆÚ“®—Ê
	float speed;			// ‘¬‚³
	float moveAngle;		// “®‚­•ûŒü
	bool flag;				// •`‰æÌ×¸Ş
	float endPos;			// •`‰æI—¹ˆÊ’u
};

struct Beam
{
	Vector2 pos;			// À•W
	int animFram;			// ±ÆÒ°¼®İ‚ÌÌÚ°Ñ
	int animCnt;			// ‚Ç‚Ì±ÆÒ°¼®İ‚ğ•`‰æ‚·‚é‚©
	bool drawFlag;			// ËŞ°Ñ‚Ì•`‰æÌ×¸Ş
	bool hitFlag;			// •`‰æ‚ªÅ‘å‚É‚È‚Á‚½‚ç“–‚½‚è”»’è‚ğ‚·‚é‚æ‚¤‚É‚·‚é
};

// externéŒ¾
#ifdef PSHOT_DEF
#define PSHOT_EX
#else
#define PSHOT_EX extern
#endif

PSHOT_EX PlayerShot pShot[PSHOT_NUM];		// ÌßÚ²Ô°¼®¯Ä‚ÉŠÖ‚·‚é•Ï”‚ÌéŒ¾
PSHOT_EX Beam beam;							// ËŞ°Ñ‚ÉŠÖ‚·‚é•Ï”‚ÌéŒ¾

// =============ŠÖ”ÌßÛÄÀ²ÌßéŒ¾
void PlayerShotInit(void);		// ‰Šú‰»
void PlayerShotFunc(void);		// ˆ—
void PlayerShotDraw(void);		// •`‰æ
void PlayerShotMove(void);		// ˆÚ“®ˆ—
void PShotPtn1(void);			// ˜AËÊßÀ°İ1
void PShotPtn2(void);			// ˜AËÊßÀ°İ2
