#pragma once

#include"Collinder.h"
#include"Bullet.h"

class Player:public Collinder
{
public:
	double Radian;			//���W�A��
	double Degree;			//�p�x

public:
	Bullet* playerBullet;
	//�R���X�g���N�^��`
	Player();
	//�f�X�g���N�^��`
	~Player();

	void PlayerUpdate();     //�X�V����
	void PlayerDraw() const;     //�`�揈��
private:
	void Bullet_Control();     //�p�x���쏈��

};

