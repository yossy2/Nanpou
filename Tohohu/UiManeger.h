#pragma once

#define SCORE_NUM 10				// ｽｺｱ数字の数
#define SCORE_NUM_SIZE_X 32			// ｽｺｱ数字のｻｲｽﾞX
#define SCORE_NUM_SIZE_Y 40			// ｽｺｱ数字のｻｲｽﾞY
#define PLAYER_LIFE_STATS 2			// 残機の表示状態
#define PLLIFE_SIZE_X 24			// 残機(ﾊｰﾄ)のｻｲｽﾞX
#define PLLIFE_SIZE_Y 24			// 残機(ﾊｰﾄ)のｻｲｽﾞY
#define POWGARGE_POS_X 670			// ﾊﾟﾜｰｹﾞｰｼﾞの座標
#define HIGHSCORE_DEF 5000			// ﾊｲｽｺｱのﾃﾞﾌｫﾙﾄ

// =======================関数ﾌﾟﾛﾄﾀｲﾌﾟ宣言=========================
void UiInit(void);				// 初期化
void ScoreUpdate(int addScr);			// 処理
void DrawScore(void);			// 描画

// =======================変数ｴｸｽﾀﾝ宣言============================
extern int highScoreImage;					// ﾊｲｽｺｱ用
extern int scoreImage;						// ｽｺｱ用
extern int scoreNumImage[SCORE_NUM];			// ｽｺｱ数字用
extern int lifeImage[PLAYER_LIFE_STATS];		// 残機ﾊｰﾄ用
extern int powGaugeImage;						// ﾊﾟﾜｰｹﾞｰｼﾞ
extern int powGaugeFrameImage;				// ﾊﾟﾜｰｹﾞｰｼﾞのﾌﾚｰﾑ
extern int powLevelImage;						// ﾚﾍﾞﾙ文字
extern int highScore;							// ﾊｲｽｺｱ
extern int score;								// ｽｺｱ
