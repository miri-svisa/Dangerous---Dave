#pragma once

#include "State.h"
//#include"Const.h"
//#include"Player.h"
//#include "WalkingState.h"

class Jump :public State
{
public:
	Jump();
	Jump(sf::Vector2f dir) ;
	~Jump() { /* ... */ }
	virtual std::unique_ptr<State> handleInput(sf::Keyboard::Key  input)  override;
	virtual void enter(MoveObject& gamePlayer)override;

protected:
	sf::Clock m_jumpingClock;
	sf::Vector2f m_direction;
};