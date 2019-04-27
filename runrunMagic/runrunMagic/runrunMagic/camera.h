#pragma once

#include "komon.h"
class Player;
// カメラの回転速度
#define CAMERA_ANGLE_SPEED		3.0f

// カメラの注視点の高さ
#define CAMERA_LOOK_AT_HEIGHT		55.0f

// カメラと注視点の距離
#define CAMERA_LOOK_AT_DISTANCE		250.0f
class Camera:public Player
{
public:
	Camera();							// コンストラクタ.
	~Camera();							// デストラクタ.

	void Update(const Player& player);	                    // 更新.

	float x, y, z;						//カメラの位置座標

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	VECTOR TempPosition1;
	VECTOR TempPosition2;
	VECTOR CameraPosition;
	VECTOR CameraLookAtPosition;

private:
	VECTOR	pos;			// ポジション.
	int    MoveFlag;
	float  Angle;
	float  CameraHAngle;
	float  CameraVAngle;
	float  SinParam;
	float  CosParam;

};