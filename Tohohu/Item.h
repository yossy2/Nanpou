#pragma once

#define ITEM_NUM 50
#define ITEM_SIZE_X 28
#define ITEM_SIZE_Y 28
#define ITEM_HIT_RAD 14
#define ITEM_DEF_SPEED 2

struct Item
{
	bool flag;
	Vector2 pos;
	float speed;
	int rotaAngle;
};

// ===========================ŠÖ”ÌßÛÄÀ²ÌßéŒ¾============================

void ItemInit(void);			// ‰Šú‰»
void ItemDrop(Vector2 ePos);	// ±²ÃÑoŒ»
void ItemCtl(void);				// ±²ÃÑoŒ»
void ItemDraw(void);			// •`‰æ
