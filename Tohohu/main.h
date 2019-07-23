#pragma once

// ﾃﾞﾊﾞｯｸﾞﾒｯｾｰｼﾞ用定義
#ifdef _DEBUG
#define AST(){\
	CHAR ast_mes[256];\
	wsprintf(ast_mes,"%s %d行目\0",__FILE__,__LINE__);\
	MessageBox(0,ast_mes,"ｱｻｰﾄ表示", MB_OK);\
	}
#else
#define AST()
#endif

// enum定義


// define定義
#define SCREEN_SIZE_X 1080		// ｳｲﾝﾄﾞｳｻｲｽﾞX
#define SCREEN_SIZE_Y 720		// ｳｲﾝﾄﾞｳｻｲｽﾞY

#define GAME_SCREEN_SIZE_X 640	// ｹﾞｰﾑ画面ｻｲｽﾞX
#define GAME_SCREEN_SIZE_Y 680	// ｹﾞｰﾑ画面ｻｲｽﾞY

#define GAME_SCREEN_X 20.0f		// ｹﾞｰﾑ画面のｵﾌｾｯﾄX
#define GAME_SCREEN_Y 20.0f		// ｹﾞｰﾑ画面のｵﾌｾｯﾄY

#define PI 3.14159265359f		// 円周率

#define RAD_TO_DEG(rad) ((int)(rad * 180.0f / PI))		// ﾗｼﾞｱﾝから度数への変換
#define DEG_TO_RAD(deg) ((float)(deg * PI / 180.0f))	// 度数からﾗｼﾞｱﾝへの変換

// enum定義
// 方向
enum DIR
{
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_MAX,
};

// 構造体
// 二次元座標
struct Vector2
{
	float x;
	float y;
};

// 敵の初期配置情報
struct EnemyInit
{
	int count;		// 出現するﾌﾚｰﾑ
	int movePtn;	// 移動ﾊﾟﾀｰﾝ
	Vector2 pos;	// 初期座標
	int moveAngle;	// 移動角度
};

// 敵の弾
struct EShot
{
	Vector2 pos;	// 座標
	Vector2 move;	// 移動量
	float speed;	// 速さ
	int moveAngle;  // 移動角度
	float hitRad;	// 当たり判定の円の半径
	int rotaAngle;	// 回転角度(度)
	int count;		// 移動用のｶｳﾝﾄ
	bool flag;		// 表示ﾌﾗｸﾞ
};

// 雑魚敵
struct Enemy
{
	Vector2 pos;	// 座標
	Vector2 move;	// 移動量
	float hitRad;	// 当たり判定の円の半径
	int moveAngle;	// 移動角度(度)
	int moveCount;	// 移動し始めてからのｶｳﾝﾄ
	int animCount;	// ｱﾆﾒｰｼｮﾝｶｳﾝﾄ
	int life;		// 残り体力
	bool drawFlag;	// 描画ﾌﾗｸﾞ
	bool atkFlag;	// 攻撃ﾌﾗｸﾞ
	EnemyInit initData;		// 初期配置情報
};

// ﾎﾞｽ
struct Boss
{
	Vector2 pos;	// 座標
	Vector2 move;	// 移動量
	float speed;
	float hitRad;	// 当たり判定の円の半径
	float moveAngle;// 移動角度(度)
	int moveCount;	// 移動し始めてからのｶｳﾝﾄ
	int animCount;	// ｱﾆﾒｰｼｮﾝｶｳﾝﾄ
	int life;		// 残り体力
	bool drawFlag;	// 描画ﾌﾗｸﾞ
};

// extern宣言
#ifdef MAIN_DEF
#define MAIN_EX
#else
#define MAIN_EX extern
#endif

MAIN_EX void(*sceneFunc)(void);		// ｼｰﾝ管理用関数ﾎﾟｲﾝﾀ
MAIN_EX void(*sceneOldFunc)(void);		// 1ﾌﾚｰﾑ前のsceneFuncの状態

MAIN_EX int framCnt;					// そのｼｰﾝになってからのﾌﾚｰﾑ数

MAIN_EX int keyFram[256];				// ｷｰの押下状態保存

//=======================関数ﾌﾟﾛﾄﾀｲﾌﾟ宣言================================

bool CheckHitObj(Vector2 aPos, float arad, Vector2 bPos, float brad);		// 当たり判定
bool isMoveOut(Vector2 pos);												// 画面外判定
void UpdateKeyState(void);													// ｷｰ押下状態更新
