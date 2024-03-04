#pragma once

void Bullet_Initialize(float x, float y);     //初期化処理
void Bullet_Update(double r,int type);     //更新処理
void Bullet_Draw(int type);	//描画処理
void Bullet_Vector(double  Degree);     //移動処理
void Fall();		//落下処理
int GetBRC();	//反射回数取得処理


