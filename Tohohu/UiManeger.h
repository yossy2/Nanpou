#pragma once

#define SCORE_NUM 10				// ｽｺｱ数字の数
#define SCORE_NUM_SIZE_X 32			// ｽｺｱ数字のｻｲｽﾞX
#define SCORE_NUM_SIZE_Y 32			// ｽｺｱ数字のｻｲｽﾞY

// =======================関数ﾌﾟﾛﾄﾀｲﾌﾟ宣言=========================
void UiInit(void);				// 初期化
void ScoreUpdate(void);			// 処理
void DrawScore(void);			// 描画
