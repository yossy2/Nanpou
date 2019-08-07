#include "DxLib.h"
#include "main.h"
#include "GameScene.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "UiManeger.h"
#include "Player.h"

// =============�Ұ�ޗp=====================
int gameClearImage;		// �ްѸر��ۺ�
int gameOverImage;			// �ްѵ��ް��ۺ�
int lifeLogoImg;			// ײ�ۺ�
int powLogoImg;			// ��ܰۺ�
int symbImg[2];				// ����
int totalImg;				// İ��ۺ�

bool CheckClear;			// �ްѸر���ǂ�����ްѼ�݂���󂯎��

// ������
void ResultInit(bool flag)
{
	// ================�Ұ�ޓo�^
	// �ްѸرۺ�
	if ((gameClearImage = LoadGraph("image/gameclear.png")) == -1)
	{
		AST();
		return;
	}
	// �ްѵ��ްۺ�
	if ((gameOverImage = LoadGraph("image/gameover.png")) == -1)
	{
		AST();
		return;
	}
	// ײ�
	if ((lifeLogoImg = LoadGraph("image/life.png")) == -1)
	{
		AST();
		return;
	}
	// ��ܰ
	if ((powLogoImg = LoadGraph("image/power.png")) == -1)
	{
		AST();
		return;
	}
	// ����
	if (LoadDivGraph("image/symbol.png", 2, 2, 1, 30, 40, symbImg) == -1)
	{
		AST();
		return;
	}
	// İ��ۺ�
	if ((totalImg = LoadGraph("image/total.png")) == -1)
	{
		AST();
		return;
	}

	CheckClear = flag;
	sceneFunc = ResultScene;
}

// ����
void ResultScene(void)
{
	ResultSceDraw(CheckClear);
	if (keyFram[KEY_INPUT_Z] == 1)
	{
		TitleInit();
	}
}

// �`��
void ResultSceDraw(bool flag)
{
	GraphFilter(gameScreen, DX_GRAPH_FILTER_GAUSS, 16, 100);
	ClsDrawScreen();
	
	DrawGraph(0, 0, systemImg, true);
	DrawGraphF(GAME_SCREEN_X, GAME_SCREEN_Y, gameScreen, true);

	if (flag)
	{
		DrawGraphF(GAME_SCREEN_X + (GAME_SCREEN_SIZE_X - RESULT_LOGO_SIZE_X) / 2, GAME_SCREEN_Y + 80, gameClearImage, true);
	}
	else
	{
		DrawGraphF(GAME_SCREEN_X + (GAME_SCREEN_SIZE_X - RESULT_LOGO_SIZE_X) / 2, GAME_SCREEN_Y + 80, gameOverImage, true);
	}

	DrawGraphF(GAME_SCREEN_X + 80, GAME_SCREEN_Y + 270, scoreImage, true);

	int tmpNum = (score >= 10000000000 ? 9999999999 : score);

	for (int i = 0; i < SCORE_NUM; i++)
	{
		int drawNum = tmpNum % 10;
		DrawGraphF((GAME_SCREEN_SIZE_X - 50) - SCORE_NUM_SIZE_X - (SCORE_NUM_SIZE_X * i), GAME_SCREEN_Y + 300, scoreNumImage[drawNum], true);
		tmpNum = (tmpNum - drawNum) / 10;
	}

	if (framCnt >= 180)
	{
		DrawGraphF(GAME_SCREEN_X + 70, GAME_SCREEN_Y + 400, lifeLogoImg, true);
		DrawGraphF(GAME_SCREEN_X + 200, GAME_SCREEN_Y + 400, scoreNumImage[player.life], true);
	}
	if (framCnt >= 210)
	{
		DrawGraphF(GAME_SCREEN_X + 250, GAME_SCREEN_Y + 400, symbImg[0], true);
		// ��Z�̊��\��
		tmpNum = 1000;
		for (int i = 0; i < 4; i++)
		{
			int drawNum = tmpNum % 10;
			DrawGraphF(((GAME_SCREEN_X + 280) + SCORE_NUM_SIZE_X * 4) - (SCORE_NUM_SIZE_X * i), GAME_SCREEN_Y + 400, scoreNumImage[drawNum], true);
			tmpNum = (tmpNum - drawNum) / 10;
		}
	}
	if (framCnt >= 270)
	{
		DrawGraphF(GAME_SCREEN_X + 400, GAME_SCREEN_Y + 450, symbImg[1], true);
		// ���Z���齺���\��
		tmpNum = 1000 * player.life;
		for (int i = 0; i < 4; i++)
		{
			int drawNum = tmpNum % 10;
			DrawGraphF(((GAME_SCREEN_X + 450) + SCORE_NUM_SIZE_X * 4) - (SCORE_NUM_SIZE_X * i), GAME_SCREEN_Y + 450, scoreNumImage[drawNum], true);
			tmpNum = (tmpNum - drawNum) / 10;
		}
	}
	if (framCnt >= 330)
	{
		tmpNum = player.power;
		// ��ܰۺނ̕\��
		DrawGraphF(GAME_SCREEN_X + 70, GAME_SCREEN_Y + 500, powLogoImg, true);
		for (int i = 0; i < 3; i++)
		{
			int drawNum = tmpNum % 10;
			DrawGraphF(((GAME_SCREEN_X + 230) + SCORE_NUM_SIZE_X * 3) - (SCORE_NUM_SIZE_X * i), 
				GAME_SCREEN_Y + 500, scoreNumImage[drawNum], true);
			tmpNum = (tmpNum - drawNum) / 10;
		}
	}
	if (framCnt >= 360)
	{
		DrawGraphF(GAME_SCREEN_X + 390, GAME_SCREEN_Y + 500, symbImg[0], true);
		// ���Z�̊��\��
		tmpNum = 100;
		for (int i = 0; i < 3; i++)
		{
			int drawNum = tmpNum % 10;
			DrawGraphF(((GAME_SCREEN_X + 420) + SCORE_NUM_SIZE_X * 3) - (SCORE_NUM_SIZE_X * i), 
				GAME_SCREEN_Y + 500, scoreNumImage[drawNum], true);
			tmpNum = (tmpNum - drawNum) / 10;
		}
	}
	if (framCnt >= 420)
	{
		DrawGraphF(GAME_SCREEN_X + 304, GAME_SCREEN_Y + 550, symbImg[1], true);
		tmpNum = 100 * player.power;
		for (int i = 0; i < 7; i++)
		{
			int drawNum = tmpNum % 10;
			DrawGraphF(((GAME_SCREEN_X + 354) + SCORE_NUM_SIZE_X * 7) - (SCORE_NUM_SIZE_X * i), GAME_SCREEN_Y + 550, scoreNumImage[drawNum], true);
			tmpNum = (tmpNum - drawNum) / 10;
		}
	}
	if (framCnt >= 510)
	{

	}

	DrawScore();

	ScreenFlip();
}