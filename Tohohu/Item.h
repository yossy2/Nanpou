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
	int Angel;
};

// ===========================�֐��������ߐ錾============================

void ItemInit(void);			// ������
void ItemDrop(Vector2 ePos);	// ���яo��
void ItemCtl(void);		// ���яo��
void ItemDraw(void);			// �`��
