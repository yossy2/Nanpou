#pragma once

#define PSHOT_SIZE_X 24
#define PSHOT_SIZE_Y 24
#define PSHOT_NUM 50
#define PSHOT_DEF_SPEED 20
#define PSHOT_TIME 5

struct PlayerShot
{
	Vector2 pos;			// 座標
	Vector2 move;			// 移動量
	float speed;			// 速さ
	float moveAngle;		// 動く方向
	bool flag;				// 描画ﾌﾗｸﾞ
	float endPos;			// 描画終了位置
};

// =============関数ｴｸｽﾀﾝ宣言
void PlayerShotInit(void);		// 初期化
void PlayerShotFunc(void);		// 処理
void PlayerShotDraw(void);		// 描画

void PlayerShotMove(void);		// 移動処理
