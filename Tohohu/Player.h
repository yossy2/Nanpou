#pragma once

#define PLAYER_SIZE_X 48
#define PLAYER_SIZE_Y 48

#define PLAYER_DEF_SPEED 6

#define PLAYER_HIT_RAD 3

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
