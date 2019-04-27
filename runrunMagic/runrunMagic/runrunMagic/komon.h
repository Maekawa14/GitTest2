#pragma once
#define _USE_MATH_DEFINES

#define LINE_GRAPH_RAW 1     // 行
#define LINE_GRAPH_COL 700    // 列
#include <math.h>

#include "DxLib.h"


//開始のカウントダウン
#include "CountDown.h"

//全てのオブジェクトをまとめる
#include "FunctionSummary.h"

//道の管理
#include "ObstructBase.h"
#include "ObstructFloat.h"
#include "ObstructManager.h"
#include "ObstructStatic.h"

//宝石やアイテムの管理
#include "GraphBase.h"
#include "GraphFloat.h"
#include "GraphManager.h"
#include "GraphStatic.h"

#include "DonutBase.h"
#include "DonutFloat.h"
#include "DonutManager.h"
#include "DonutStatic.h"

// 針山の管理
#include "nanji.h"

//プレイヤー管理
#include "player.h"

//カメラの管理
#include "camera.h"

//当たり判定管理
#include "Hitchecker.h"

//キー入力管理
#include "input.h"

//ゲージの管理
#include "gauge.h"



