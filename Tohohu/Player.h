#pragma once

#define PLAYER_SIZE_X 48			// ｲﾒｰｼﾞのｻｲｽﾞX
#define PLAYER_SIZE_Y 48			// ｲﾒｰｼﾞのｻｲｽﾞY
#define PLAYER_DEF_SPEED 6			// ﾃﾞﾌｫﾙﾄの速さ
#define PLAYER_HIT_RAD 3.0f			// 当たり判定の範囲
#define PLAYER_DEF_LIFE 5			// ﾃﾞﾌｫﾙﾄの残機数
#define PLAYER_POWER_MAX 400		// ﾊﾟﾜｰの最大値

// enum定義
// ﾌﾟﾚｲﾔｰID
enum PL_ID
{
	PL_ID_SLIME,
	PL_ID_MAX
};

// 構造体定義
// 自機
struct Player
{
	Vector2 pos;		// 座標
	Vector2 move;		// 移動量
	float speed;		// 速さ
	float moveAngle;	// 移動角度
	bool flag;			// 描画管理
	int life;			// 残機
	int power;			// ﾊﾟﾜｰの増加
	int shotPowUp;		// ｼｮｯﾄの状態
};

struct KeyList
{
	int move[DIR_MAX];	// 移動ｷｰ
	int shot;			// ｼｮｯﾄ、決定
	int bomb;			// ﾎﾞﾑ、ｷｬﾝｾﾙ
	int pause;			// ﾎﾟｰｽﾞ
	int slow;			// 低速
};

// extern宣言
#ifdef PL_DEF
#define PL_EX
#else
#define PL_EX extern
#endif

PL_EX Player player;
PL_EX int playerImg;

PL_EX KeyList keyList;

bool PlayerInit(void);		// 自機の初期化
void PlayerCtl(void);		// 自機の処理
void PlayerDraw(void);		// 自機の描画
	
void PlayerMove(void);		// 自機の移動処理
void PlayerDamage(void);	// ﾀﾞﾒｰｼﾞを受けたときの処理

void PlayerPowUp(void);		// ﾌﾟﾚｲﾔｰｼｮｯﾄの強化

