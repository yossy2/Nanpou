#include "DxLib.h"
#include "main.h"
#include "GameScene.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "UiManeger.h"

int gameClearImage;		// �ްѸر��ۺ�
int gameOverImage;			// �ްѵ��ް��ۺ�

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
	DrawGraph(GAME_SCREEN_X, GAME_SCREEN_Y, gameScreen, true);
	DrawScore();

	if (flag)
	{
		DrawGraph(GAME_SCREEN_X + (GAME_SCREEN_SIZE_X - RESULT_LOGO_SIZE_X) / 2, GAME_SCREEN_Y + 100, gameClearImage, true);
	}
	else
	{
		DrawGraph(GAME_SCREEN_X + (GAME_SCREEN_SIZE_X - RESULT_LOGO_SIZE_X) / 2, GAME_SCREEN_Y + 100, gameOverImage, true);
	}

	ScreenFlip();
}