#define PL_DEF
#include <math.h>
#include <DxLib.h>
#include "main.h"
#include "Player.h"
#include "PlayerShot.h"

// 自機の初期化
bool PlayerInit(void)
{
	player.pos.x = (float)(GAME_SCREEN_SIZE_X) / 2.0f;
	player.pos.y = (float)(GAME_SCREEN_SIZE_Y - PLAYER_SIZE_Y/2);
	player.speed = PLAYER_DEF_SPEED;
	player.life = PLAYER_DEF_LIFE;
	player.power = 0;
	player.drawFlag = true;
	player.shotPowUp = 1;
	player.animCnt = 0;
	player.shotPtn = PSHOT_NORMAL;

	// ｷｰ設定
	keyList.move[DIR_UP] = KEY_INPUT_UP;
	keyList.move[DIR_RIGHT] = KEY_INPUT_RIGHT;
	keyList.move[DIR_DOWN] = KEY_INPUT_DOWN;
	keyList.move[DIR_LEFT] = KEY_INPUT_LEFT;
	keyList.shot = KEY_INPUT_Z;
	keyList.slow = KEY_INPUT_LCONTROL;

	// ﾌﾟﾚｲﾔｰｼｮｯﾄの初期化
	PlayerShotInit();

	// 画像の読み込み
	if (LoadDivGraph("image/player_anim.png", PLAYER_ANIM_MAX, PLAYER_ANIM_MAX, 1,
		PLAYER_SIZE_X, PLAYER_SIZE_Y, playerImg) == -1)
	{
		AST();
		return false;
	}

	if ((plPowUpSound = LoadSoundMem("se/playerpowerup.mp3")) == -1)
	{
		AST();
		return false;
	}
	return true;
}

// 自機の処理
void PlayerCtl(void)
{
	if (player.power < 100)
	{
		player.shotPowUp = 1;
	}
	else if (player.power >= 100)
	{
		player.shotPowUp = 2;
	}

	PlayerMove();
	PlayerShotFunc();
}

// 自機の描画
void PlayerDraw(void)
{
	PlayerShotDraw();
	if (player.drawFlag)
	{
		DrawRotaGraphF(player.pos.x + GAME_SCREEN_X, player.pos.y + GAME_SCREEN_Y, 1.0, 0.0, playerImg[(++player.animCnt / 5) % PLAYER_ANIM_MAX], true, false);
	}
}

// 自機の移動
void PlayerMove(void)
{
	// ========== 低速ﾓｰﾄﾞ判定
	if (keyFram[keyList.slow])
	{
		player.speed = PLAYER_DEF_SPEED / 2;
	}
	else
	{
		player.speed = PLAYER_DEF_SPEED;
	}

	// ==========移動角度決定
	// 右移動
	if (keyFram[keyList.move[DIR_RIGHT]])
	{
		if (keyFram[keyList.move[DIR_UP]] && keyFram[keyList.move[DIR_DOWN]] == 0)
		{
			// 上下ｷｰの内上だけ押されていた場合
			if (keyFram[keyList.move[DIR_LEFT]] == 0)
			{
				// 左が押されていなかったら右上移動
				player.moveAngle = -PI / 4.0f;
			}
			else
			{
				// 左が押されていたら上移動
				player.moveAngle = -PI / 2.0f;
			}
		}
		else if (keyFram[keyList.move[DIR_DOWN]])
		{
			// 下が押されていた時
			if (keyFram[keyList.move[DIR_LEFT]] == 0)
			{
				// 左が押されていなかったら右下移動
				player.moveAngle = PI / 4.0f;
			}
			else
			{
				// 左が押されていたら下移動
				player.moveAngle = PI / 2.0f;
			}
		}
		else if (keyFram[keyList.move[DIR_LEFT]] == 0)
		{
			// 右だけ押されていた時右移動（2π）
			player.moveAngle = PI * 2.0f;
		}
		else
		{
			// 左も押されていた時は移動しない()
			player.moveAngle = 0.0f;
		}
	}
	// 左移動
	else if (keyFram[keyList.move[DIR_LEFT]])
	{
		if (keyFram[keyList.move[DIR_UP]] && keyFram[keyList.move[DIR_DOWN]] == 0)
		{
			// 上下ｷｰの内上だけ押されていた場合左上移動
			player.moveAngle = -PI * 3.0f / 4.0f;
		}
		else if (keyFram[keyList.move[DIR_DOWN]])
		{
			// 下が押されていた時左下移動
			player.moveAngle = PI * 3.0f / 4.0f;
		}
		else
		{
			// 左だけ押されていた場合左移動
			player.moveAngle = PI;
		}
	}
	// 上移動
	else if (keyFram[keyList.move[DIR_UP]])
	{
		if (keyFram[keyList.move[DIR_DOWN]] == 0)
		{
			//上だけ押されていたら上移動
			player.moveAngle = -PI / 2.0f;
		}
		else
		{
			// 下も押されていたら移動しない
			player.moveAngle = 0.0f;
		}
	}
	// 下移動
	else if (keyFram[keyList.move[DIR_DOWN]])
	{
		// 下だけ押されていたら下移動
		player.moveAngle = PI / 2.0f;
	}
	else
	{
		//何も押されてなかったら移動しない
		player.moveAngle = 0.0f;
	}

	// ===========移動量決定
	if (player.moveAngle)
	{
		player.move.x = player.speed * cosf(player.moveAngle);
		player.move.y = player.speed * sinf(player.moveAngle);
	}
	else
	{
		player.move.x = 0.0f;
		player.move.y = 0.0f;
	}

	// ==========画面外判定
	// 左右
	if (player.pos.x + player.move.x < (float)(PLAYER_SIZE_X / 2))
	{
		// 左
		if ((int)player.move.y < 0)
		{
			player.moveAngle = -PI / 2.0f;
			
		}
		else if ((int)player.move.y > 0)
		{
			player.moveAngle = PI / 2.0f;
		}
		player.move.y = player.speed * sinf(player.moveAngle);
		player.move.x = 0.0f;
		player.pos.x = (float)(PLAYER_SIZE_X / 2);
	}
	else if (player.pos.x + player.move.x > (float)(GAME_SCREEN_SIZE_X - PLAYER_SIZE_X / 2))
	{
		// 右
		if ((int)player.move.y < 0)
		{
			player.moveAngle = -PI / 2.0f;

		}
		else if ((int)player.move.y > 0)
		{
			player.moveAngle = PI / 2.0f;
		}
		player.move.y = player.speed * sinf(player.moveAngle);
		player.move.x = 0.0f;
		player.pos.x = (float)(GAME_SCREEN_SIZE_X - PLAYER_SIZE_X / 2);
	}

	//上下
	if (player.pos.y + player.move.y < (float)(PLAYER_SIZE_Y / 2))
	{
		// 上
		if ((int)player.move.x < 0)
		{
			player.moveAngle = PI;

		}
		else if ((int)player.move.x > 0)
		{
			player.moveAngle = PI * 2.0f;
		}
		player.move.x = player.speed * cosf(player.moveAngle);
		player.move.y = 0.0f;
		player.pos.y = (float)(PLAYER_SIZE_Y / 2);
	}
	else if ((player.pos.y + player.move.y) > (float)(GAME_SCREEN_SIZE_Y - PLAYER_SIZE_Y / 2))
	{
		// 下
		if ((int)player.move.x < 0)
		{
			player.moveAngle = PI;

		}
		else if ((int)player.move.x > 0)
		{
			player.moveAngle = PI * 2.0f;
		}
		player.move.x = player.speed * cosf(player.moveAngle);
		player.move.y = 0.0f;
		player.pos.y = (float)(GAME_SCREEN_SIZE_Y - PLAYER_SIZE_Y / 2);
	}

	// ==========移動
	if (player.moveAngle != 0)
	{
		player.pos.x += player.move.x;
		player.pos.y += player.move.y;
	}
}

// ﾀﾞﾒｰｼﾞを受けたときの処理
void PlayerDamage(void)
{
	if (--player.life <= 0 && player.drawFlag)
	{
		player.drawFlag = false;
	}
}

// ﾌﾟﾚｲﾔｰｼｮｯﾄの強化
void PlayerPowUp(void)
{
	player.power += 10;
	if (player.power >= PLAYER_POWER_MAX)
	{
		player.power = PLAYER_POWER_MAX;
	}
}