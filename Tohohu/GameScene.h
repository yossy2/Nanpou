#pragma once

// externéŒ¾
#ifdef GAME_DEF
#define GAME_EX
#else
#define GAME_EX extern
#endif

GAME_EX void(*chapterFunc)(void);		// Í‚ğØ‚è‘Ö‚¦‚éŠÖ”Îß²İÀ

GAME_EX int systemImg;					// ½º±‚È‚Ç‚ğ•\¦‚·‚é‰æ–Ê˜g
GAME_EX int gameScreen;					// ¹Ş°Ñ‰æ–Ê

bool GameInit(void);		// ¹Ş°Ñ¼°İ‰Šú‰»
void GameScene(void);		// ¹Ş°Ñ¼°İˆ—
void GameDraw(void);		// ¹Ş°Ñ¼°İ•`‰æ

bool CheckHitObj(Vector2 aPos, float arad, Vector2 bPos, float brad);		// “–‚½‚è”»’è
