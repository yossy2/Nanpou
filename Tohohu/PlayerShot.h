#pragma once

#define PSHOT_SIZE_X 24
#define PSHOT_SIZE_Y 24
#define PSHOT_NUM 50
#define PSHOT_DEF_SPEED 20
#define PSHOT_TIME 5

struct PlayerShot
{
	Vector2 pos;			// À•W
	Vector2 move;			// ˆÚ“®—Ê
	float speed;			// ‘¬‚³
	int moveAngle;			// “®‚­•ûŒü
	bool flag;				// •`‰æÌ×¸Ş
	float endPos;			// •`‰æI—¹ˆÊ’u
};

// =============ŠÖ”ÌßÛÄÀ²ÌßéŒ¾
void PlayerShotInit(void);		// ‰Šú‰»
void PlayerShotFunc(void);		// ˆ—
void PlayerShotDraw(void);		// •`‰æ

void PlayerShotMove(void);		// ˆÚ“®ˆ—
