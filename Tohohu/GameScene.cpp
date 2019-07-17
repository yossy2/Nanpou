#define GAME_DEF
#include <time.h>
#include <DxLib.h>
#include <main.h>
#include <GameScene.h>
#include <Player.h>
#include <Chapter1/Chapter1.h>

// �ްѼ�ݏ�����
bool GameInit(void)
{
	bool rtnFlag = true;

	srand((unsigned int)time(NULL));
	PlayerInit();
	ChapterInit1();

	// �摜�ǂݍ���
	systemImg = LoadGraph("image/system.png");
	if (systemImg == -1)
	{
		AST();
		rtnFlag = false;
	}

	return rtnFlag;
}

// �ްѼ�ݏ���
void GameScene(void)
{
	PlayerCtl();
	chapterFunc();
}

// �ްѼ�ݕ`��
void GameDraw(void)
{
	// �ްщ�ʘg
	DrawGraph(0, 0, systemImg, true);
}

// �����蔻��
bool CheckHitObj(Vector2 aPos, float arad, Vector2 bPos, float brad)
{
	bool hitFlag = false;
	float x_Len = aPos.x - bPos.x;
	float y_Len = aPos.y - bPos.y;
	float Renge = (x_Len * x_Len) + (y_Len * y_Len);			// ��_�̒��S�̋���

	if (Renge < (arad + brad) * (arad + brad))
	{
		hitFlag = true;
	}

	return hitFlag;
}