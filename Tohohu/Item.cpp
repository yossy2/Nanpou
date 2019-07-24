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
			break;
		}
	}
}

// ���я���
void ItemCtl()
{
	// �`�撆�̏���
	for (int i = 0; i < ITEM_NUM; i++)
	{
		if (powUpItem[i].flag)
		{
			powUpItem[i].pos.y += powUpItem[i].speed;
			powUpItem[i].speed += 0.01f;
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
			DrawRotaGraphF(powUpItem[i].pos.x, powUpItem[i].pos.y, 1.0f, 0.0f, powUpItemImage, true, false);
		}
	}
}