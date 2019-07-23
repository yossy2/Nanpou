#pragma once

#define BOSS1_CNT 2500		// ﾎﾞｽが出現するﾌﾚｰﾑ
#define BOSS1_ANIM_MAX 4	// ﾋﾞｯｸﾞｽﾗｲﾑのｱﾆﾒｰｼｮﾝ数

#define BOSS1_SIZE_X 96		// ﾋﾞｯｸﾞｽﾗｲﾑのｻｲｽﾞX
#define BOSS1_SIZE_Y 96		// ﾋﾞｯｸﾞｽﾗｲﾑのｻｲｽﾞY

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

void BossAtk1_1(void);		// 攻撃ﾊﾟﾀｰﾝその1、回転
