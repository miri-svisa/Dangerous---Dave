#pragma once
#include "State.h"
//#include<memory>
//#include"Player.h"
class FallState :public State
{
public:
	FallState(sf::Vector2f direction);
	~FallState() = default;
	virtual std::unique_ptr<State> handleInput(sf::Keyboard::Key  input)override;
	virtual void enter(MoveObject& gamePlayer)override;

protected:
	sf::Vector2f m_direction;
};