#pragma once

//�T�C�Y
struct Area
{
	float height;
	float width;

};

//���S���W
struct Location
{
	double x;//���S��
	double y;//���S��
};

class Collinder

{
protected:

	Area area;
	Location location;


public:

	bool HitBox(const class Collinder* collider)const;

	//���S���W�̎擾
	Location GetLocation()const;

	//�摜�̂͂񂯂��̎擾
	Area GetArea()const;

	void SetLocation(float y);

};