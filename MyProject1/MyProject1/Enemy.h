#pragma once

void Enemy_Initialize();//初期化処理
void Enemy_Update();	//更新処理
void Enemy_Draw();		//描画処理
float GetEnemyX();		//X座標取得
float GetEnemyY();		//Y座標取得
float GetEnemyR();		//半径取得
bool GetDeth();		//死亡取得
bool DethCheck();		//死亡判定
void Deth();			//死亡処理
bool HitCheck();
