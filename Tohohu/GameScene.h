#pragma once

// extern宣言
#ifdef GAME_DEF
#define GAME_EX
#else
#define GAME_EX extern
#endif

GAME_EX void(*chapterFunc)(void);		// 章を切り替える関数ﾎﾟｲﾝﾀ

GAME_EX int systemImg;					// ｽｺｱなどを表示する画面枠

bool GameInit(void);		// ｹﾞｰﾑｼｰﾝ初期化
void GameScene(void);		// ｹﾞｰﾑｼｰﾝ処理
void GameDraw(void);		// ｹﾞｰﾑｼｰﾝ描画

bool CheckHitObj(Vector2 aPos, Vector2 bPos);		// 当たり判定
