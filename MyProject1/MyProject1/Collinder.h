#pragma once

//サイズ
struct Area
{
	float height;
	float width;

};

//中心座標
struct Location
{
	double x;//中心ｘ
	double y;//中心ｙ
};

class Collinder

{
protected:

	Area area;
	Location location;


public:

	bool HitBox(const class Collinder* collider)const;

	//中心座標の取得
	Location GetLocation()const;

	//画像のはんけいの取得
	Area GetArea()const;

	void SetLocation(float y);

};