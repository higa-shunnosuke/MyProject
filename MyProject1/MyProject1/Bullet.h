#pragma once

#include"Collinder.h"

class Bullet:public Collinder
{
public:
	double BulletSpeedX;     //バレットのX座標移動距離
	double BulletSpeedY;     //バレットのY座標移動距離
	unsigned int BulletColor;     //バレットの色
	double Radian;			//ラジアン
	int ReflectionCount;	//反射回数

	//コンストラクタ定義
	Bullet(double PlayerX, double PlayerY, double Radian);
	//デストラクタ定義
	~Bullet();

	void Bullet_Update();     //更新処理
	void Bullet_Draw() const;	//描画処理
	

private:
	void Bullet_Vector();     //移動処理

};

