#pragma once

void Bullet_Initialize();     //初期化処理
void Bullet_Update();     //更新処理
void Bullet_Draw();	//描画処理
void Bullet_Vector();     //移動処理
int GetBRC();	//反射回数取得処理
float GetBulletX();		//X座標取得
float GetBulletY();		//Y座標取得
float GetBulletR();		//半径取得
bool GetDelet();		//消滅取得
void SetDelet(int flg);		//消滅フラグ設定処理
bool DeletCheck();		//消滅判定