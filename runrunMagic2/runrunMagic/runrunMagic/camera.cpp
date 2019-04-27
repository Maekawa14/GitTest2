//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "komon.h"
//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Camera::Camera()
{
	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(10.0f, 1200.0f);

	//カメラの座標初期化
	x = 0.0, y = 0.0, z = 0.0;

	// カメラの向きを初期化
	CameraHAngle = 0.0f;
	CameraVAngle = 0.0f;
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Camera::~Camera()
{
	// 処理なし.
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Camera::Update(const Player& player)
{
	// カメラの位置はカメラの水平角度と垂直角度から算出
	CameraLookAtPosition = player.pos;
	CameraLookAtPosition.x += 90;   //中心より右側にずらす
	CameraLookAtPosition.y += CAMERA_LOOK_AT_HEIGHT;

	// 最初に垂直角度を反映した位置を算出
	SinParam = (float)sin(CameraVAngle / 180.0f * DX_PI_F);
	CosParam = (float)cos(CameraVAngle / 180.0f * DX_PI_F);
	TempPosition1.x = 0.0f;
	TempPosition1.y = SinParam * CAMERA_LOOK_AT_DISTANCE;
	TempPosition1.z = -CosParam * CAMERA_LOOK_AT_DISTANCE;

	// 次に水平角度を反映した位置を算出
	SinParam = (float)sin(CameraHAngle / 180.0f * DX_PI_F);
	CosParam = (float)cos(CameraHAngle / 180.0f * DX_PI_F);
	TempPosition2.x = CosParam * TempPosition1.x - SinParam * TempPosition1.z;
	TempPosition2.y = TempPosition1.y + 10;
	TempPosition2.z = (SinParam * TempPosition1.x + CosParam * TempPosition1.z) + 100;

	// 算出した座標に注視点の位置を加算したものがカメラの位置
	CameraPosition = VAdd(TempPosition2, CameraLookAtPosition);
	//ターゲットを見る角度にカメラを設置
	SetCameraPositionAndTarget_UpVecY(CameraPosition, CameraLookAtPosition);

	// 移動した場合は、カメラの水平角度を考慮した方向に座標を移動する
	if (player.moveFlag == TRUE)
	{
		VECTOR TempMoveVector;

		// カメラの角度に合わせて移動ベクトルを回転してから加算
		SinParam = (float)sin(CameraHAngle / 180.0f * DX_PI_F);
		CosParam = (float)cos(CameraHAngle / 180.0f * DX_PI_F);
		TempMoveVector.x = player.angleX * CosParam - player.angleZ * SinParam;
		TempMoveVector.y = 0.0f;
		TempMoveVector.z = player.angleX * SinParam + player.angleZ * CosParam;

		pos = VAdd(pos, TempMoveVector);
	}
}