#pragma once

#define BOSS1_CNT 2500		// ﾎﾞｽが出現するﾌﾚｰﾑ
#define BOSS1_ANIM_MAX 4	// ﾋﾞｯｸﾞｽﾗｲﾑのｱﾆﾒｰｼｮﾝ数

#define BOSS1_SIZE_X 96		// ﾋﾞｯｸﾞｽﾗｲﾑのｻｲｽﾞX
#define BOSS1_SIZE_Y 96		// ﾋﾞｯｸﾞｽﾗｲﾑのｻｲｽﾞY

#define BOSS1_SHOT_OFSET 20.0f	// 弾が出る位置を口の位置に調節

// extern宣言
#ifdef BOSS1_DEF
#define BOSS1_EX
#else
#define BOSS1_EX extern
#endif

BOSS1_EX Boss boss1;			// 1章ﾎﾞｽﾋﾞｯｸﾞｽﾗｲﾑ

bool BossInit1(void);		// 初期化
void BossCtl1(void);		// ﾎﾞｽの処理
void BossDraw1(void);		// 描画

void BossAtk1_1(void);		// 回転
void BossAtk1_2(void);		// 弾を円状に発射して追尾
void BossAtk1_3(void);		// 移動しながら弾を発射
void BossAtk1_4(void);		// ｽﾗｲﾑ大行進
