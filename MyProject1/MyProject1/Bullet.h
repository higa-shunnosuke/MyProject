#pragma once

void Bullet_Initialize();     //����������
void Bullet_Update();     //�X�V����
void Bullet_Draw();	//�`�揈��
void Bullet_Vector();     //�ړ�����
int GetBRC();	//���ˉ񐔎擾����
float GetBulletX();		//X���W�擾
float GetBulletY();		//Y���W�擾
float GetBulletR();		//���a�擾
bool GetDelet();		//���Ŏ擾
void SetDelet(int flg);		//���Ńt���O�ݒ菈��
bool DeletCheck();		//���Ŕ���