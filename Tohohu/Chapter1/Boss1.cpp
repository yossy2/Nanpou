#define BOSS1_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Boss1.h"
#include "BossShot1.h"
#include "Enemy1_b.h"
#include <Player.h>
#include <PlayerShot.h>
#include <UiManeger.h>
#include <ResultScene.h>

int bossImg1[BOSS1_ANIM_MAX];		// 画像ID
int bossLifeImg;					// ﾎﾞｽのHPﾊﾞｰ
int atkAngle;						// 攻撃1の弾の発射角度
int slimeCnt;						// 登場時何匹のｽﾗｲﾑをだしたか
void (*boss1AtkFunc)(void);			// 攻撃関数ﾎﾟｲﾝﾀ	

bool blastFlag;							// 爆発ﾌﾗｸﾞ
int blastCnt;							// 爆発ｶｳﾝﾄ
BOSS_LIFE color;

// 初期化
bool BossInit1(void)
{
	// 画像読み込み
	if (LoadDivGraph("image/boss1_anim.png", BOSS1_ANIM_MAX, BOSS1_ANIM_MAX, 1,
		BOSS1_SIZE_X, BOSS1_SIZE_Y, bossImg1) == -1)
	{
		AST();
		return false;
	}

	bossLifeImg = LoadGraph("image/enemyLife2.png");
	if (bossLifeImg == -1)
	{
		AST();
	}

	boss1.pos = { 320.0f,300.0f };
	boss1.life = BOSS1_LIFE_MAX;
	boss1.drawFlag = false;
	boss1.moveCount = 0;
	boss1.moveAngle = 0;
	boss1.animCount = 0;

	bossStartFlag1 = false;
	slimeCnt = 0;
	atkAngle = 90;
	boss1AtkFunc = BossAtk1_1;
	blastFlag = false;
	color = BOSS_LIFE_BLUE;
	blastCnt = 0;

	return true;
}

// ﾎﾞｽの処理
void BossCtl1(void)
{
	// 出現
	if (framCnt == BOSS1_CNT)
	{
		bossStartFlag1 = true;
	}

	if (bossStartFlag1 && !boss1.drawFlag && !blastFlag)
	{
		if (framCnt % 30 == 0 && (slimeCnt < 7))
		{
			for (int i = 0; i < ENEMY1_B_MAX; i++)
			{
				if (!enemy1B[i].drawFlag && !enemy1B[i].blastFlag)
				{
					switch (slimeCnt)
					{
					case 0:
						enemy1B[i].pos = { 310.0f, (float)(-ENEMY1_B_SIZE_Y) };
						enemy1B[i].initData.pos = { 310.0f,320.0f };
						break;
					case 1:
						enemy1B[i].pos = { 330.0f, (float)(-ENEMY1_B_SIZE_Y) };
						enemy1B[i].initData.pos = { 330.0f,320.0f };
						break;
					case 2:
						enemy1B[i].pos = { 300.0f, (float)(-ENEMY1_B_SIZE_Y) };
						enemy1B[i].initData.pos = { 300.0f,300.0f };
						break;
					case 3:
						enemy1B[i].pos = { 340.0f, (float)(-ENEMY1_B_SIZE_Y) };
						enemy1B[i].initData.pos = { 340.0f,300.0f };
						break;
					case 4:
						enemy1B[i].pos = { 310.0f, (float)(-ENEMY1_B_SIZE_Y) };
						enemy1B[i].initData.pos = { 310.0f,280.0f };
						break;
					case 5:
						enemy1B[i].pos = { 330.0f, (float)(-ENEMY1_B_SIZE_Y) };
						enemy1B[i].initData.pos = { 330.0f,280.0f };
						break;
					case 6:
						enemy1B[i].pos = { 320.0f, (float)(-ENEMY1_B_SIZE_Y) };
						enemy1B[i].initData.pos = { 320.0f,300.0f };
						break;
					default:
						break;
					}
					
					enemy1B[i].moveAngle = 90;
					enemy1B[i].initData.movePtn = 3;
					enemy1B[i].moveCount = 0;
					enemy1B[i].drawFlag = true;
					enemy1B[i].animCount = 0;
					slimeCnt++;
					break;
				}
			}
		}

		if (framCnt == (BOSS1_CNT + 400))
		{
			blastFlag = true;
			PlaySoundMem(bigBlastSound, DX_PLAYTYPE_BACK, true);
			//boss1.drawFlag = true;
		}
	}

	if (boss1.drawFlag)
	{
		boss1AtkFunc();

		boss1.moveCount++;
		boss1.animCount++;

		// 弾との当たり判定
		for (int k = 0; k < PSHOT_NUM; k++)
		{
			if (pShot[k].drawFlag && !pShot[k].blastFlag)
			{
				if (CheckHitObj(pShot[k].pos, pShot[k].rad, boss1.pos, (float)BOSS1_SIZE_X / 2.0f))
				{
					if ((boss1.life -= HitShot(&pShot[k])) <= 0)
					{
						ShotDelete();
						boss1.drawFlag = false;
						PlaySoundMem(bigBlastSound, DX_PLAYTYPE_BACK, true);
						blastFlag = true;
						ScoreUpdate(10000);
						break;
					}
				}
			}
		}
	}
}

// 描画
void BossDraw1(void)
{
	if (boss1.drawFlag)
	{
		// ﾎﾞｽ
		DrawRotaGraphF(boss1.pos.x, boss1.pos.y,
			1.0, 0.0, bossImg1[(boss1.animCount / BOSS1_ANIM_SPEED) % BOSS1_ANIM_MAX], true, false);

		// HP
		DrawRectGraph(0, 0, 0, 10 * color, 
			(int)(boss1.life * GAME_SCREEN_SIZE_X / BOSS1_LIFE_MAX), 10, bossLifeImg, true, false);
	}

	if (blastFlag)
	{
		// ﾎﾞｽ
		DrawRotaGraphF(boss1.pos.x, boss1.pos.y,
			3.0, 0.0, bigBlastImg[(blastCnt / 2) % BIG_BLAST_ANIM_MAX], true, false);
		shake = { (float)(rand() % 10) - 10.0f,(float)(rand() % 10) - 10.0f };
		if (++blastCnt >= 2 * BIG_BLAST_ANIM_MAX)
		{
			blastCnt = 0;
			shake = { 0,0 };
			blastFlag = false;
			if (boss1.life <= 0)
			{
				ResultInit(true);
			}
		}
		else if (((blastCnt / 2) % BIG_BLAST_ANIM_MAX) == 7 && (boss1.life > 0))
		{
			boss1.drawFlag = true;
		}
		else
		{

		}
	}
}

// 移動しながら弾を発射
void BossAtk1_1(void)
{
	// 次の攻撃に移るよ
	if (boss1.life <= 1250)
	{
		boss1.moveCount = 0;
		ShotDelete();
		boss1AtkFunc = BossAtk1_2;
		PlaySoundMem(bigBlastSound, DX_PLAYTYPE_BACK, true);
		color = BOSS_LIFE_GREEN;
	}

	if ((boss1.moveCount / 60) % 3 != 1)
	{
		return;
	}
	else if (boss1.moveCount % 60 == 0)
	{
		boss1.moveAngle -= 60;
	}
	boss1.speed = 3.0f - (float)(boss1.moveCount % 60) / 20.0f;

	boss1.move.x = boss1.speed * cosf(DEG_TO_RAD(boss1.moveAngle));
	boss1.move.y = boss1.speed * sinf(DEG_TO_RAD(boss1.moveAngle));

	boss1.pos.x += boss1.move.x;
	boss1.pos.y += boss1.move.y;

	float angle = atan2f(player.pos.y - boss1.pos.y, player.pos.x - boss1.pos.x);

	//if(boss1.moveCount % 10 != 0)
	//{
	//	return;
	//}

	// 弾を一発
	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		if (!bShot1[i].drawFlag)
		{
			bShot1[i].count = 0;
			bShot1[i].moveAngle = RAD_TO_DEG(angle) + ((rand() % 11) - 5);
			bShot1[i].rotaAngle = 0;
			bShot1[i].pos = { boss1.pos.x , boss1.pos.y + BOSS1_SHOT_OFSET };
			bShot1[i].speed = 4.0f;
			bShot1[i].drawFlag = true;
			if (boss1.moveCount % 5 == 0)
			{
				PlaySoundMem(eShotSound, DX_PLAYTYPE_BACK, true);
			}
			return;
		}
	}
}

// 弾を円状に発射
void BossAtk1_2(void)
{
	// 次の攻撃に移るよ
	if (boss1.life <= 1000)
	{
		boss1.moveCount = 0;
		ShotDelete();
		boss1AtkFunc = BossAtk1_3;
		PlaySoundMem(bigBlastSound, DX_PLAYTYPE_BACK, true);
		color = BOSS_LIFE_YELLOW;
	}

	if (fabs((int)(boss1.pos.x - (float)GAME_SCREEN_SIZE_X / 2.0f)) > 0 ||
		fabs((int)(boss1.pos.y - (float)GAME_SCREEN_SIZE_Y / 2.0f)) > 0)
	{
		MoveCenter();
		boss1.moveCount = 0;
		return;
	}

	if ((boss1.moveCount / 60) % 2 == 0)
	{
		atkAngle = rand() % 10;
		return;
	}
	else if (boss1.moveCount % 10 != 0)
	{
		return;
	}
	else
	{

	}

	int cnt = 0;
	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		if (!bShot1[i].drawFlag)
		{
			bShot1[i].count = 0;
			bShot1[i].moveAngle = atkAngle + cnt * 10;
			bShot1[i].rotaAngle = 0;
			bShot1[i].pos = { boss1.pos.x , boss1.pos.y + BOSS1_SHOT_OFSET };
			bShot1[i].speed = 2.0f;
			bShot1[i].drawFlag = true;
			cnt++;
			if (cnt >= 36)
			{
				atkAngle += 5;
				PlaySoundMem(eShotSound, DX_PLAYTYPE_BACK, true);
				return;
			}
		}
	}
}

// 回転
void BossAtk1_3(void)
{
	// 次の攻撃に移るよ
	if (boss1.life <= 500)
	{
		boss1.moveCount = 0;
		ShotDelete();
		boss1AtkFunc = BossAtk1_4;
		PlaySoundMem(bigBlastSound, DX_PLAYTYPE_BACK, true);
		color = BOSS_LIFE_RED;
	}

	if (boss1.moveCount < 180 || boss1.moveCount % 2 != 0)
	{
		return;
	}

	int cnt = 0;
	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		if (!bShot1[i].drawFlag)
		{
			bShot1[i].count = 0;
			bShot1[i].moveAngle = atkAngle;
			bShot1[i].rotaAngle = 0;
			bShot1[i].pos = { boss1.pos.x , boss1.pos.y + BOSS1_SHOT_OFSET };
			bShot1[i].speed = 2.0f;
			bShot1[i].drawFlag = true;
			atkAngle += 120;
			cnt++;
			if (cnt >= 3)
			{
				atkAngle += 13;
				if (boss1.moveCount % 5 == 0)
				{
					PlaySoundMem(eShotSound, DX_PLAYTYPE_BACK, true);
				}
				return;
			}
		}
	}
}

// ｽﾗｲﾑ大行進
void BossAtk1_4(void)
{
	if (boss1.moveCount < 180 || boss1.moveCount % 10 != 0)
	{
		return;
	}

	for (int i = 0; i < ENEMY1_B_MAX; i++)
	{
		if (!enemy1B[i].drawFlag && !enemy1B[i].blastFlag)
		{
			enemy1B[i].pos = { (float)(rand() % GAME_SCREEN_SIZE_X), 0.0f };
			enemy1B[i].initData.movePtn = 2;
			enemy1B[i].moveCount = rand() % 180;
			enemy1B[i].drawFlag = true;
			enemy1B[i].animCount = 0;
			break;
		}
	}

	if (boss1.moveCount % 120 != 0)
	{
		return;
	}

	int cnt = 0;
	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		if (!bShot1[i].drawFlag)
		{
			bShot1[i].count = 0;
			bShot1[i].moveAngle = atkAngle + cnt * 20;
			bShot1[i].rotaAngle = 0;
			bShot1[i].pos = { boss1.pos.x , boss1.pos.y + BOSS1_SHOT_OFSET };
			bShot1[i].speed = 2.0f;
			bShot1[i].drawFlag = true;
			cnt++;
			if (cnt >= 18)
			{
				atkAngle += 10;
				PlaySoundMem(eShotSound, DX_PLAYTYPE_BACK, true);
				return;
			}
		}
	}
}

// 中央に移動
void MoveCenter(void)
{
	Vector2 length = { (float)(GAME_SCREEN_SIZE_X / 2 - boss1.pos.x),(float)(GAME_SCREEN_SIZE_Y / 2 - boss1.pos.y) };
	boss1.moveAngle = RAD_TO_DEG(atan2f(length.y, length.x));

	boss1.speed = (length.x+ length.y) / 20.0f;

	boss1.pos.x += boss1.speed * cosf(DEG_TO_RAD(boss1.moveAngle));
	boss1.pos.y += boss1.speed * sinf(DEG_TO_RAD(boss1.moveAngle));

}

// 攻撃ﾊﾟﾀｰﾝがかわるとき弾を一旦消す
void ShotDelete(void)
{
	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		if (bShot1[i].drawFlag)
		{
			bShot1[i].count = 0;
			bShot1[i].drawFlag = false;
			bShot1[i].blastFlag = true;
		}
	}
}



