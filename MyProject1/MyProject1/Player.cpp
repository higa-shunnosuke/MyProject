#include "Player.h"
#include "DxLib.h"
#include "math.h"
#include "Common.h"
#include "InputControl.h"

//コンストラクタ
Player::Player()
{
	location.x = 640.0f;
	location.y = 480.0f;
	area.height = 50.0f;
	area.width = 50.0f;
	Degree = 0;
	Radian = 0;
	playerBullet = nullptr;
}

//デストラクタ
Player::~Player() {}

//プレイヤー更新処理
void Player::PlayerUpdate()
{

	Bullet_Control();

	if (CheckHitKey(KEY_INPUT_SPACE) != 0)
	{
		if (playerBullet == nullptr)
		{
			playerBullet = new Bullet(location.x, location.y, Radian);
		}
	}

	if (playerBullet != nullptr)
	{
		playerBullet->Bullet_Update();

		if (5 <= playerBullet->ReflectionCount)
		{
			playerBullet->ReflectionCount = 0;
			delete playerBullet;
			playerBullet = nullptr;
		}
	}
}

//プレイヤー描画処理
void Player::PlayerDraw() const
{
	if (playerBullet != nullptr)
	{
		playerBullet->Bullet_Draw();
	}

	DrawCircleAA(location.x, location.y, 25, 100, 0xffffff, TRUE);
	DrawFormatString(450, 100, GetColor(255, 255, 255), "θ ：%f", Degree);
	DrawFormatString(450, 150, GetColor(255, 255, 255), "cos：%f", cos(Radian));
	DrawFormatString(450, 200, GetColor(255, 255, 255), "sin：%f", sin(Radian));
	DrawFormatString(450, 250, GetColor(255, 255, 255), "rad：%f", Radian);
}


void Player::Bullet_Control()
{
	if (CheckHitKey(KEY_INPUT_W) != 0)
	{
		if (Degree >= 360)
		{
			Degree = 0;
		}
		else
		{
			Degree++;
		}
	}
	if (CheckHitKey(KEY_INPUT_S) != 0)
	{
		if (Degree <= 0)
		{
			Degree = 359;
		}
		else
		{
			Degree--;
		}
	}
	Radian = Degree * (M_PI / 180);
}
