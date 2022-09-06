#pragma once
#include <memory>
//#include "Player.h"
#include <SFML/Graphics.hpp>
//s#include"CollisionHandling.h"

class MoveObject;
class State 
{
public:
	State();
	~State() = default;
	virtual std::unique_ptr<State>	handleInput(sf::Keyboard::Key  input) = 0;
	virtual void enter(MoveObject& gamePlayer) = 0;


protected:

};