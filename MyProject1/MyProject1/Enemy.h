#pragma once

void Enemy_Initialize();//����������
void Enemy_Update();	//�X�V����
void Enemy_Draw();		//�`�揈��
float GetEnemyX(int i);		//X���W�擾
float GetEnemyY(int i);		//Y���W�擾
float GetEnemyR(int i);		//���a�擾
//bool GetDeth();		//���S�擾
void DamageCheck();		//���S����
void Deth(int i);			//���S����
bool HitCheck(int i);
