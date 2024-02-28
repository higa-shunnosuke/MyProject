#pragma once

#include"Collinder.h"

class Bullet:public Collinder
{
public:
	double BulletSpeedX;     //�o���b�g��X���W�ړ�����
	double BulletSpeedY;     //�o���b�g��Y���W�ړ�����
	unsigned int BulletColor;     //�o���b�g�̐F
	double Radian;			//���W�A��
	int ReflectionCount;	//���ˉ�

	//�R���X�g���N�^��`
	Bullet(double PlayerX, double PlayerY, double Radian);
	//�f�X�g���N�^��`
	~Bullet();

	void Bullet_Update();     //�X�V����
	void Bullet_Draw() const;	//�`�揈��
	

private:
	void Bullet_Vector();     //�ړ�����

};

