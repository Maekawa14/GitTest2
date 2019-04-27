//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "komon.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Enemy::Enemy()
{

	//スライムの読み込み
	modelHandle = MV1LoadModel("img/slime/slime.pmd");

	//スライムの初期向きの値
	angleX = 0.0f, angleY = 0.0f, angleZ = 0.0f;

	//スライムの初期座標の値
	pos.x = 0.0f, pos.y = 0.0f, pos.z = 150.0f;

	//スライムの大きさ
	MV1SetScale(modelHandle, VGet(2.5f, 2.5f, 2.5f));

	//スライムの初期位置
	pos = VGet(pos.x, pos.y, pos.z);
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Enemy::~Enemy()
{
	// 処理なし.
}

//--------
//更新
//--------
void Enemy::Updata(const Player& player)
{

	//プレイヤーを追いかける
	if (pos.x > player.pos.x)
	{
		pos.x--;
	}
	else if(pos.x < player.pos.x)
	{
		pos.x++;
	}

	if (pos.z > player.pos.z)
	{
		pos.z--;
	}
	else if (pos.z < player.pos.z)
	{
		pos.z++;
	}
}

//---------------
// @brief  描画
//---------------
void Enemy::Draw()
{
	//3Dモデルの向き
	MV1SetRotationXYZ(modelHandle, VGet(angleX, angleY, angleZ));

	// ３Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);

	// ３Ｄモデルの描画
	MV1DrawModel(modelHandle);
}