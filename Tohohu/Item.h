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

// ===========================関数ﾌﾟﾛﾄﾀｲﾌﾟ宣言============================

void ItemInit(void);			// 初期化
void ItemDrop(Vector2 ePos);	// ｱｲﾃﾑ出現
void ItemCtl(void);				// ｱｲﾃﾑ出現
void ItemDraw(void);			// 描画
