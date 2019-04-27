#pragma once

class ObstructManager;
class GraphManager;
class DonutManager;
class Nanji;
class Player; 
class Camera;
class HitChecker;
class KeyState;
class Gauge;
class CountDown;

class FunctionSummary
{
public:
	FunctionSummary() {};
	~FunctionSummary() {};

	void Update(ObstructManager& obstructManager, GraphManager& graphManager, DonutManager& donutManager, Nanji& nanji,
		Player& player, Camera& camera, HitChecker& hitChecker, KeyState& keyState,
		Gauge& gauge, CountDown& countDown);

};