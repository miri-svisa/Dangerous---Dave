#pragma once
#include "State.h"
//#include<memory>
//#include"Const.h"
//#include "ShotState.h"
//#include"FallState.h"
//#include"Player.h"
class ShotState :public State
{
public:
	~ShotState() = default;
	virtual std::unique_ptr<State> handleInput(sf::Keyboard::Key  input)override;
	virtual void enter(MoveObject& gamePlayer)override;

protected:

};