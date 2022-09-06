#pragma once
#include "State.h"
//#include"Jump.h"
//#include <SFML\Window\Keyboard.hpp>

class Stend:public State
{
public:
	~Stend() {};
	virtual std::unique_ptr<State> handleInput(sf::Keyboard::Key  input)override ;
	virtual void enter(MoveObject& gamePlayer)override;


protected:

};