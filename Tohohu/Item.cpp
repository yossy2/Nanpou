#include "DxLib.h"
#include "main.h"
#include "Player.h"
#include "Item.h"

int powUpItemImage;
Item powUpItem[ITEM_NUM];

// ������
void ItemInit(void)
{
	if ((powUpItemImage = LoadGraph("image/powupitem.png")) == -1)
	{
		AST();
	}
	for (int i = 0; i < ITEM_NUM; i++)
	{
		powUpItem[i].flag = false;
		powUpItem[i].pos = { 0 , 0 };
	}
}

// ���яo��
void ItemDrop(Vector2 ePos)
{
	for (int i = 0; i < ITEM_NUM; i++)
	{
		if (!powUpItem[i].flag)
		{
			powUpItem[i].flag = true;
			powUpItem[i].pos = { ePos.x , ePos.y };
			powUpItem[i].speed = ITEM_DEF_SPEED;
			powUpItem[i].rotaAngle = 0;
			break;
		}
	}
}

// ���я���
void ItemCtl(void)
{
	// �`�撆�̏���
	for (int i = 0; i < ITEM_NUM; i++)
	{
		if (powUpItem[i].flag)
		{
			powUpItem[i].pos.y += powUpItem[i].speed;
			powUpItem[i].speed += 0.01f;
			powUpItem[i].rotaAngle++;
		}

		if (CheckHitObj(powUpItem[i].pos, ITEM_HIT_RAD, player.pos, PLAYER_SIZE_X / 2))
		{
			powUpItem[i].flag = false;
		}

		// ��ʊO
		if (isMoveOut(powUpItem[i].pos))
		{
			powUpItem[i].flag = false;
		}
	}
}

// �`��
void ItemDraw(void)
{
	for (int i = 0; i < ITEM_NUM; i++)
	{
		if (powUpItem[i].flag)
		{
			DrawRotaGraphF(powUpItem[i].pos.x + GAME_SCREEN_X, powUpItem[i].pos.y + GAME_SCREEN_Y, 1.0f, (double)((float)powUpItem[i].rotaAngle * PI / 180.0f), powUpItemImage, true, false);
		}
	}
}