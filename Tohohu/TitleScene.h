#pragma once

#define TITLE_LOGO_SIZE_X 900
#define TITLE_LOGO_SIZE_Y 300

#define MENU_IMAGE_SIZE_X 300
#define MENU_IMAGE_SIZE_Y 64

#define MENUWAKU_SIZE_X 350
#define MENUWAKU_SIZE_Y 75

enum MENU_ID
{
	GAMESTART_ID,
	CONFIG_ID,
	EXIT_ID,
	MENU_ID_MAX
};

bool TitleInit(void);		// ﾀｲﾄﾙｼｰﾝ初期化
void TitleScene(void);		// ﾀｲﾄﾙｼｰﾝ処理
void TitleDraw(void);		// ﾀｲﾄﾙｼｰﾝ描画
void TitleSound(void);		// ｻｳﾝﾄﾞ再生
