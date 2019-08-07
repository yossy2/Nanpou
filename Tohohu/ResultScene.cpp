#include "DxLib.h"
#include "main.h"
#include "GameScene.h"
#include "ResultScene.h"
#include "TitleScene.h"

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
	ClsDrawScreen();
	DrawGraph(GAME_SCREEN_X, GAME_SCREEN_Y, gameScreen, true);

	if (flag)
	{
		DrawGraph(0, 0, gameClearImage, true);
	}
	else
	{
		DrawGraph(0, 0, gameOverImage, true);
	}
	ScreenFlip();
}