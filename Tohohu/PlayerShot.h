#pragma once

#define PSHOT_SIZE_X 24
#define PSHOT_SIZE_Y 24
#define PSHOT_NUM 50
#define PSHOT_DEF_SPEED 15

struct PlayerShot
{
	Vector2 pos;			// À•W
	Vector2 move;			// ˆÚ“®—Ê
	float speed;			// ‘¬‚³
	float moveAngle;		// “®‚­•ûŒü
	bool flag;				// •`‰æÌ×¸Ş
	float endPos;			// •`‰æI—¹ˆÊ’u
};

// =============ŠÖ”´¸½ÀİéŒ¾
void PlayerShotInit(void);		// ‰Šú‰»
void PlayerShotFunc(void);		// ˆ—
void PlayerShotDraw(void);		// •`‰æ

void PlayerShotMove(void);		// ˆÚ“®ˆ—
