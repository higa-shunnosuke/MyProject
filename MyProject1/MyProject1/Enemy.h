#pragma once

void Enemy_Initialize();//初期化処理
void Enemy_Update();	//更新処理
void Enemy_Draw();		//描画処理
float GetEnemyX(int i);	//X座標取得
float GetEnemyY(int i);	//Y座標取得
float GetEnemyR(int i);	//半径取得
void DamageCheck();		//死亡判定
void Deth(int i);		//死亡処理
bool HitCheck(int i);	//ヒットチェック
void SetHit(int i);		//ヒット設置処理
