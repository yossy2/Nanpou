#pragma once
/*
 * 1章敵Aの弾関連
 */
#define ESHOT1_A_SIZE_X 16		// 画像ｻｲｽﾞX
#define ESHOT1_A_SIZE_Y 16		// 画像ｻｲｽﾞY
#define ESHOT1_A_NUM 250		// 配列の個数
#define ESHOT1_A_DEF_SPEED 4.0f	// 基本移動量
#define ESHOT1_A_MAX_SPEED 8.0f	// 最大移動量
#define ESHOT1_A_CNT_MAX 10		// ｶｳﾝﾄの最大値

 // extern宣言
#ifdef ESHOT1_A_DEF
#define ESHOT1_A_EX
#else
#define ESHOT1_A_EX extern
#endif

ESHOT1_A_EX EShot eShot1A[ESHOT1_A_NUM];

bool EShotInit1_A(void);		// 初期化
void EShotCtl1_A(void);			// 更新処理
void DrawEShot1_A(void);		// 描画
