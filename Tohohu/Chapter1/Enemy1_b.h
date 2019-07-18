#pragma once

#define ENEMY1_B_SIZE_X 32		// 敵1_BのｻｲｽﾞX
#define ENEMY1_B_SIZE_Y 32		// 敵1_BのｻｲｽﾞY
#define ENEMY1_B_NUM	50		// 敵1_Bの配列個数
#define ENEMY1_B_SPEED	4.0f	// 敵1_Bの移動量

// 構造体定義
// 敵の配置情報
struct EnemyInit
{
	int count;		// 出現するﾌﾚｰﾑ
	int movePtn;	// 移動ﾊﾟﾀｰﾝ
	Vector2 pos;	// 初期座標
	int moveAng;	// 移動角度
};

// extern宣言
#ifdef ENEMY1_B_DEF
#define ENEMY1_B_EX
#else
#define ENEMY1_B_EX extern
#endif

ENEMY1_B_EX Enemy enemy1B[ENEMY1_B_NUM];

bool EnemyInit1_B(void);				// 初期化
void EnemyCtl1_B(void);					// 更新処理
void DrawEnemy1_B(void);				// 描画