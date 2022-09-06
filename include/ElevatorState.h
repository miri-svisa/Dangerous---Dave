#pragma once
#include "State.h"
//#include<memory>
//#include"Player.h"

class ElevatorState :public State
{
public:
	~ElevatorState() = default;
	virtual std::unique_ptr<State> handleInput(sf::Keyboard::Key  input)override;
	virtual void enter(MoveObject& gamePlayer)override;

protected:

};