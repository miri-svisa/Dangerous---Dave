#pragma once
#include "State.h"
//#include"Const.h"
//#include "ShotState.h"
//#include"FallState.h"
//#include <memory>
//#include"Player.h"
class WalkingState :public State
{
public:
	WalkingState();
	WalkingState(sf::Vector2f dir);
	~WalkingState() = default;
	virtual std::unique_ptr<State> handleInput(sf::Keyboard::Key  input)override;
	virtual void enter(MoveObject& gamePlayer)override;

protected:
	sf::Vector2f m_direction;
	sf::Clock m_walkingClock;
};