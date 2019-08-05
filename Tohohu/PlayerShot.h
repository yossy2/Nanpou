#pragma once

#define PSHOT_SIZE_X 24				// 弾のｻｲｽX
#define PSHOT_SIZE_Y 24				// 弾のｻｲｽﾞY
#define PSHOT_NUM 50				// 弾の描画確保
#define PSHOT_DEF_SPEED 20			// 弾速
#define PSHOT_TIME 5				// 連射間隔
#define PSHOT_HIT_RAD 8				// 当たり判定

#define BEAM_SIZE_X 32				// ﾋﾞｰﾑのｻｲｽﾞX
#define BEAM_SIZE_Y 680				// ﾋﾞｰﾑのｻｲｽﾞY
#define BEAM_ANIM_NUM 4				// ﾋﾞｰﾑのｱﾆﾒｰｼｮﾝ枚数
#define BEAM_HIT 3					// ﾋﾞｰﾑの当たり判定の大きさ

struct PlayerShot
{
	Vector2 pos;			// 座標
	Vector2 move;			// 移動量
	float speed;			// 速さ
	float moveAngle;		// 動く方向
	bool flag;				// 描画ﾌﾗｸﾞ
	float endPos;			// 描画終了位置
};

struct Beam
{
	Vector2 pos;			// 座標
	int animFram;			// ｱﾆﾒｰｼｮﾝのﾌﾚｰﾑ
	int animCnt;			// どのｱﾆﾒｰｼｮﾝを描画するか
	bool drawFlag;			// ﾋﾞｰﾑの描画ﾌﾗｸﾞ
	bool hitFlag;			// 描画が最大になったら当たり判定をするようにする
};

// extern宣言
#ifdef PSHOT_DEF
#define PSHOT_EX
#else
#define PSHOT_EX extern
#endif

PSHOT_EX PlayerShot pShot[PSHOT_NUM];		// ﾌﾟﾚｲﾔｰｼｮｯﾄに関する変数の宣言
PSHOT_EX Beam beam;							// ﾋﾞｰﾑに関する変数の宣言

// =============関数ﾌﾟﾛﾄﾀｲﾌﾟ宣言
void PlayerShotInit(void);		// 初期化
void PlayerShotFunc(void);		// 処理
void PlayerShotDraw(void);		// 描画
void PlayerShotMove(void);		// 連射ﾉｰﾏﾙ
void PShotPtn1(void);			// 連射ﾊﾟﾀｰﾝ1
void PShotPtn2(void);			// 連射ﾊﾟﾀｰﾝ2
bool BeamCheckHit(Vector2 pos, int hitrad);		// ﾋﾞｰﾑの当たり判定
