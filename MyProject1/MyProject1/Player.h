#pragma once

void Player_Initialize();     //初期化処理
void Player_Update();     //更新処理
void Player_Draw();     //描画処理
void Player_Control();     //角度操作処理
void SetBullet(bool flg);		//バレットフラグ設定処理
int GetType();		//タイプ受け取り処理
float GetPlayerX();		//X座標取得
float GetPlayerY();		//Y座標取得
float GetPlayerR();		//半径取得
float GetRadian();		//角度取得



