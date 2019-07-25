#pragma once

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

bool TitleInit(void);		// ю╡ды╪╟щ▐┴┼З┴╩
void TitleScene(void);		// ю╡ды╪╟щ▐┬≈²
void TitleDraw(void);		// ю╡ды╪╟щ∙`┴Ф
void TitleSound(void);		// ╩Ёщдч█д░╤
