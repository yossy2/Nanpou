#include "DxLib.h"
#include "main.h"
#include "Player.h"
#include "Item.h"

int powUpItemImage;
Item powUpItem[ITEM_NUM];

// 初期化
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

// ｱｲﾃﾑ出現
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

// ｱｲﾃﾑ処理
void ItemCtl(void)
{
	// 描画中の処理
	for (int i = 0; i < ITEM_NUM; i++)
	{
		if (powUpItem[i].flag)
		{
			if (CheckHitObj(powUpItem[i].pos, ITEM_HIT_RAD, player.pos, PLAYER_SIZE_X / 2) && player.drawFlag)
			{
				PlayerPowUp();
				powUpItem[i].flag = false;
			}
			powUpItem[i].pos.y += powUpItem[i].speed;
			powUpItem[i].speed += 0.01f;
			powUpItem[i].rotaAngle++;
		}

		// 画面外
		if (isMoveOut(powUpItem[i].pos))
		{
			powUpItem[i].flag = false;
		}
	}
}

// 描画
void ItemDraw(void)
{
	for (int i = 0; i < ITEM_NUM; i++)
	{
		if (powUpItem[i].flag)
		{
			DrawRotaGraphF(powUpItem[i].pos.x, powUpItem[i].pos.y, 1.0f, (double)((float)powUpItem[i].rotaAngle * PI / 180.0f), powUpItemImage, true, false);
		}
	}
}