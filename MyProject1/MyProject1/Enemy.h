#pragma once

void Enemy_Initialize();//‰Šú‰»ˆ—
void Enemy_Update();	//XVˆ—
void Enemy_Draw();		//•`‰æˆ—
float GetEnemyX(int i);		//XÀ•Wæ“¾
float GetEnemyY(int i);		//YÀ•Wæ“¾
float GetEnemyR(int i);		//”¼Œaæ“¾
//bool GetDeth();		//€–Sæ“¾
void DamageCheck();		//€–S”»’è
void Deth(int i);			//€–Sˆ—
bool HitCheck(int i);
