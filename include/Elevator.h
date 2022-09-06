#pragma once
#include"MoveObject.h"
#include "Factory.h"

class Elevator :public MoveObject
{
public:
	Elevator(sf::Vector2f location = sf::Vector2f(0, 0));
	//~Elevator() = default;

protected:	
	static bool m_registerit;
};
inline bool Elevator::m_registerit = Factory::registerit('e',
	[](sf::Vector2f location) -> std::unique_ptr<Object> { return std::make_unique<Elevator>(location); });