#pragma once

#define PLAYER_SIZE_X 48			// ｲﾒｰｼﾞのｻｲｽﾞX
#define PLAYER_SIZE_Y 48			// ｲﾒｰｼﾞのｻｲｽﾞY
#define PLAYER_DEF_SPEED 6			// ﾃﾞﾌｫﾙﾄの速さ
#define PLAYER_HIT_RAD 3.0f			// 当たり判定の範囲
#define PLAYER_DEF_LIFE 5			// ﾃﾞﾌｫﾙﾄの残機数
#define PLAYER_POWER_MAX 400		// ﾊﾟﾜｰの最大値
#define PLAYER_ANIM_MAX 4			// ﾌﾟﾚｲﾔｰのｱﾆﾒｰｼｮﾝ数
#define PLAYER_REVIVAL_CNT 60		// ﾌﾟﾚｲﾔｰが爆発してから再表示されるまでの時間

// enum定義
// ﾌﾟﾚｲﾔｰID
enum PL_ID
{
	PL_ID_SLIME,
	PL_ID_MAX
};

//自機の弾の種類
enum PSHOT_ID
{
	PSHOT_ID_NORMAL,
	PSHOT_ID_FIRE,
	PSHOT_ID_MAX,
};

// 構造体定義
// 自機
struct Player
{
	Vector2 pos;		// 座標
	Vector2 move;		// 移動量
	float speed;		// 速さ
	float moveAngle;	// 移動角度
	bool drawFlag;		// 描画管理
	bool blastFlag;		// 爆発ﾌﾗｸﾞ
	bool revivalFlag;	// 復活ﾌﾗｸﾞ
	int animCnt;		// ｱﾆﾒｰｼｮﾝｶｳﾝﾄ
	int life;			// 残機
	int power;			// ﾊﾟﾜｰの増加
	int shotPowUp;		// ｼｮｯﾄの状態
	PSHOT_ID shotPtn;	// ｼｮｯﾄのﾊﾟﾀｰﾝ
};

struct KeyList
{
	int move[DIR_MAX];	// 移動ｷｰ
	int shot;			// ｼｮｯﾄ、決定
	int bomb;			// ﾎﾞﾑ、ｷｬﾝｾﾙ
	int pause;			// ﾎﾟｰｽﾞ
	int slow;			// 低速
	int change;			// 魔法ﾁｪﾝｼﾞ
};

// extern宣言
#ifdef PL_DEF
#define PL_EX
#else
#define PL_EX extern
#endif

PL_EX Player player;
PL_EX int playerImg[PLAYER_ANIM_MAX];

PL_EX KeyList keyList;
PL_EX int plPowUpSound;

bool PlayerInit(void);		// 自機の初期化
void PlayerCtl(void);		// 自機の処理
void PlayerDraw(void);		// 自機の描画
	
void PlayerMove(void);		// 自機の移動処理
void PlayerDamage(void);	// ﾀﾞﾒｰｼﾞを受けたときの処理
void PlayerPowUp(void);		// ﾌﾟﾚｲﾔｰｼｮｯﾄの強化
void PlayerAttack1(void);	// 通常攻撃
void PlayerAttack2(void);	// 炎魔法攻撃

