#pragma once

#include"Collinder.h"
#include"Bullet.h"

class Player:public Collinder
{
public:
	double Radian;			//ラジアン
	double Degree;			//角度

public:
	Bullet* playerBullet;
	//コンストラクタ定義
	Player();
	//デストラクタ定義
	~Player();

	void PlayerUpdate();     //更新処理
	void PlayerDraw() const;     //描画処理
private:
	void Bullet_Control();     //角度操作処理

};

