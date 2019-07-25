#include <DxLib.h>
#include "main.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "Player.h"
#include "Item.h"

// �Ұ�ޗp
int titleBgImage;					// ���ق̔w�i
int menuImage[MENU_ID_MAX];		// �ƭ��ꗗ
int menuWakuImage[MENU_ID_MAX];	// �ƭ��̘g
int configImage;					// ����̨��(�������)

// ����ޗp
int titleBgm;						// ���ٗpBGM

// �Ұ�ނ̊g��p
float rate;
bool rateFlag;

// �ƭ��֘A
MENU_ID menuID;						// �ƭ��̊Ǘ�
bool configFlag;

// ���ټ�ݏ�����
bool TitleInit(void)
{
	bool rtnFlag = true;

	// �w�i
	if ((titleBgImage = LoadGraph("image/titlebg.png")) == -1)
	{
		AST();
		rtnFlag = false;
	}

	// �ƭ��摜
	for (int i = 0; i < MENU_ID_MAX; i++)
	{
		if (LoadDivGraph("image/menu.png", MENU_ID_MAX, 1, MENU_ID_MAX, MENU_IMAGE_SIZE_X, MENU_IMAGE_SIZE_Y, menuImage) == -1)
		{
			AST();
			rtnFlag = false;
		}
	}

	// �ƭ��̘g
	for (int i = 0; i < MENU_ID_MAX; i++)
	{
		if (LoadDivGraph("image/menuwaku.png", MENU_ID_MAX, 1, MENU_ID_MAX, MENUWAKU_SIZE_X, MENUWAKU_SIZE_Y, menuWakuImage) == -1)
		{
			AST();
			rtnFlag = false;
		}
	}

	// ��̨��
	if ((configImage = LoadGraph("image/config.png")) == -1)
	{
		AST();
		rtnFlag = false;
	}

	// ==================����ޗp
	if ((titleBgm = LoadSoundMem("bgm/titlebgm.mp3")) == -1)
	{
		AST();
		rtnFlag = false;
	}

	configFlag = false;

	PlayerInit();
	ItemInit();
	rate = 1.0f;
	rateFlag = true;

	return rtnFlag;
}

// ���ټ�ݏ���
void TitleScene(void)
{
	if (!configFlag)
	{
		if (keyFram[KEY_INPUT_UP] == 1)
		{
			menuID = (MENU_ID)(menuID - 1);
			if (menuID < 0)
			{
				menuID = EXIT_ID;
			}
			rate = 1.0f;
		}
		else if (keyFram[KEY_INPUT_DOWN] == 1)
		{
			menuID = (MENU_ID)(menuID + 1);
			if (menuID >= MENU_ID_MAX)
			{
				menuID = GAMESTART_ID;
			}
			rate = 1.0f;
		}
	}

	TitleSound();
	TitleDraw();

	if (keyFram[keyList.shot] == 1)
	{
		switch (menuID)
		{
		case GAMESTART_ID:
			GameInit();
			StopSoundMem(titleBgm);
			break;
		case CONFIG_ID:
			configFlag = true;
			break;
		case EXIT_ID:
			keyFram[KEY_INPUT_ESCAPE] = 1;
			break;
		default:
			AST();
			break;
		}

	}
}

// ���ټ�ݕ`��
void TitleDraw(void)
{
	if (framCnt % 4 == 0 && rateFlag)
	{
		rate -= 0.01;
		if (rate <= 0.8)
		{
			rateFlag = false;
		}
	}
	else if (framCnt % 4 == 0 && !rateFlag)
	{
		rate += 0.01;
		if (rate >= 1.0)
		{
			rateFlag = true;
		}
	}

	ClsDrawScreen();

	DrawGraph(0, 0, titleBgImage, false);

	for (int i = 0; i < MENU_ID_MAX; i++)
	{
		DrawGraph((SCREEN_SIZE_X - MENU_IMAGE_SIZE_X) / 2 - (MENUWAKU_SIZE_X - MENU_IMAGE_SIZE_X) / 2, 400 + ((MENU_IMAGE_SIZE_Y + 20) * i) - ((MENUWAKU_SIZE_Y - MENU_IMAGE_SIZE_Y) / 2), menuWakuImage[i], true);
		if (menuID != i)
		{
			DrawGraph((SCREEN_SIZE_X - MENU_IMAGE_SIZE_X) / 2, 400 + ((MENU_IMAGE_SIZE_Y + 20) * i), menuImage[i], true);
		}
	}

	DrawRotaGraph(SCREEN_SIZE_X / 2, 400 + MENU_IMAGE_SIZE_Y / 2 + ((MENU_IMAGE_SIZE_Y + 20) * menuID), rate, 0.0f, menuImage[menuID], true, false);

	if (configFlag)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawGraph(0, 0, configImage, true);
		if (keyFram[KEY_INPUT_X] == 1)
		{
			configFlag = false;
		}
	}

	ScreenFlip();
}

// ����ލĐ�
void TitleSound(void)
{
	if (CheckSoundMem(titleBgm) == 0)
	{
		PlaySoundMem(titleBgm, DX_PLAYTYPE_BACK, true);
	}
}