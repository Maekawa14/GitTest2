//-----------------------------------------------------------------------------
// @brief  プレイヤークラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "komon.h"

const float Player::COLIDE_DECEL_FAC = 0.4f;			// 障害物にぶつかったときの減速率.

//当たり判定のelseが全範囲になっている

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Player::Player() : modelHandle(-1)
, hitRadius(10.0f)
{

	//3Dモデルの読み込み
	modelHandle = MV1LoadModel("img/レアv1_12/レアv1_12.pmd");

	//3Dモデルの大きさ
	MV1SetScale(modelHandle, VGet(2.0f, 2.0f, 2.0f));

	//3Dモデルで使用しているマテリアルの数を取得する
	MaterialNum = MV1GetMaterialNum(modelHandle);

	for (int i = 0; i < MaterialNum; i++)
	{
		// マテリアルの輪郭線の太さを取得  
		float dotwidth = MV1GetMaterialOutLineDotWidth(modelHandle, i);
		// マテリアルの輪郭線の太さを拡大した分小さくする  
		MV1SetMaterialOutLineDotWidth(modelHandle, i, dotwidth / 50.0f);
	}

	// アタッチしたアニメーションの総再生時間を取得する
	TotalTime = MV1GetAttachAnimTotalTime(modelHandle, AttachIndex);

	// 再生時間の初期化
	PlayTime = 0.0f;

	//プレイヤーの初期位置  
	pos = VGet(-4300.0f, 53.0f, 0.0);
	velocity = VGet(0.0f, 0.0f, 0.0f);

	//プレイヤーのスピード値
	speed = 2.0f;

	//プレイヤーの初期向き
	angleX = 0.0f, angleY = 4.5f, angleZ = 0.0f;

	// ジャンプフラグ
	jumpFlag = false;

	// 落ちたときキー入力を無効
	dropFlag = false;

	// マジックポイント
	magicPoint = 0;

	// Y座標を保管する
	prevY = 0;
	tempY = 0;

	// 当たり半径
    radius = 4.0;

	// 待機中モーション
	waitFlag = true;

	// 走るモーションをoff
	runFlag = false;

	// フィーバータイムのフラグ
	feverFlag = false;

	//3Dモデルの向き
	MV1SetRotationXYZ(modelHandle, VGet(angleX, angleY, angleZ));
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ
//-----------------------------------------------------------------------------
Player::~Player()
{
	// モデルのアンロード
	MV1DeleteModel(modelHandle);
}

//-----------------------------------------------------------------------------
// @brief  更新
//-----------------------------------------------------------------------------
void Player::Update(KeyState& keyState)
{
	//スペースキーの状態
	switch (getKey(KEY_INPUT_SPACE))
	{
	case KEY_STATE_OFF:
		DrawFormatString(550, 0, GetColor(255, 255, 255), "OFF");
		break;
	case KEY_STATE_PUSHDOWN:     //押した瞬間ジャンプ
		if (jumpFlag == false)
		{
			dropFlag = false;
			jumpFlag = true;
			prevY = pos.y;
			pos.y = pos.y + 6.5f;
		}
		DrawFormatString(550, 0, GetColor(255,255,255), "pushdown");
		break;
	case KEY_STATE_PRESSED:
		DrawFormatString(550, 0, GetColor(255, 255, 255), "PRESSED");
		break;
	case KEY_STATE_PULLUP:
		DrawFormatString(550, 0, GetColor(255, 255, 255), "PULLUP");
		break;
	}
}

void Player::Move()
{
	//printfDx("player.x : %f\n", pos.y);

	// キー入力取得
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//プレイヤーが65より下に落ちた場合操作できないようにする
	if (pos.y < 65)
	{
		dropFlag = true;
	}

	//プレイヤーの移動制限
	if (pos.x < 3750.0f)
	{
		//プレイヤーの移動速度
		pos.x += 83.5f;

		//走るモーション再生
		runFlag = true;
		waitFlag = false;
	}
	else
	{
		runFlag = false;
		waitFlag = true;
		DrawFormatString(550, 140, GetColor(252, 255, 0), "GAME CLEAR!");
	}
}

void Player::Jump()
{
	//ジャンプ処理

	if (jumpFlag == true)
	{
		tempY = pos.y;   //今のY座標をtempYに保存する
		pos.y += (pos.y - prevY) - 0.5f;
		prevY = tempY;
		if (pos.y <= 53)
		{
			jumpFlag = false;
		}
	}
}

//プレイヤーのモーション
void Player::Motion()
{
	// 今までアタッチしていたアニメーションをデタッチ
	MV1DetachAnim(modelHandle, AttachIndex);

	if(runFlag == true)
	{
		//３Ｄモデルの1番目のアニメーションをアタッチする
		AttachIndex = MV1AttachAnim(modelHandle, 1, -1, FALSE);
		// 再生時間を進める
		PlayTime += 0.5f;
	}
	else if (waitFlag == true)
	{
		// ３Ｄモデルの1番目のアニメーションをアタッチする
		AttachIndex = MV1AttachAnim(modelHandle, 0, -1, FALSE);
		// 再生時間を進める
		PlayTime += 0.7f;
	}

	// アニメーションの総時間を取得しておく
	TotalTime = MV1GetAttachAnimTotalTime(modelHandle, AttachIndex);

	// アニメーション再生時間を初期化
	//PlayTime = 0.0f;
	MV1SetAttachAnimTime(modelHandle, AttachIndex, PlayTime);

	//3Dモデルの向き
	MV1SetRotationXYZ(modelHandle, VGet(angleX, angleY, angleZ));

	// ３Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);

	// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if (PlayTime >= TotalTime) {
		PlayTime = 0.0f;
	}

	// 再生時間をセットする
	MV1SetAttachAnimTime(modelHandle, AttachIndex, PlayTime);
}

void Player::Fever(Gauge& gauge)
{
	if (feverFlag)
	{
		gauge.stopDecrease = true;
		gauge.MPGX2 -= 0.1;
		DrawFormatString(500, 100, GetColor(0, 255, 255), "Fever!!");

		if (gauge.MPGX2 < 0)
		{
			gauge.stopDecrease = false;
			feverFlag = false;
		}
	}
}


//-----------------------------------------------------------------------------
// @brief  描画
//-----------------------------------------------------------------------------
void Player::Draw(HitChecker& hitChecker)
{
	// ３Ｄモデルの描画
	MV1DrawModel(modelHandle);


	// デバッグあたり判定
	//DrawSphere3D(pos, hitRadius, 5, 0x00ffff, 0x00ffff, false);

}

//-----------------------------------------------------------------------------
// @brief  衝突処理
//-----------------------------------------------------------------------------
void Player::OnHitObstruct(ObstructBase& obstruct)
{
	//あたったときポイントを加算する
	magicPoint++;
}