#pragma once

#define MENU_IMAGE_SIZE_X 300
#define MENU_IMAGE_SIZE_Y 64

#define MENUWAKU_SIZE_X 350
#define MENUWAKU_SIZE_Y 75

enum MENU_ID
{
	GAMESTART_ID,
	CONFIG_ID,
	EXIT_ID,
	MENU_ID_MAX
};

bool TitleInit(void);		// ���ټ�ݏ�����
void TitleScene(void);		// ���ټ�ݏ���
void TitleDraw(void);		// ���ټ�ݕ`��
void TitleSound(void);		// ����ލĐ�
