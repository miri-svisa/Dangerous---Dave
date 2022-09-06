#pragma once
#include"StuticObject.h"
#include "Factory.h"


//class Factory;
class Door :public StuticObject
{
public:
	Door(sf::Vector2f location = sf::Vector2f(0, 0));
	//~Door() = default;

protected:
	static bool m_registerit;
};
inline bool Door::m_registerit = Factory::registerit('d',
	[](sf::Vector2f location) -> std::unique_ptr<Object> { return std::make_unique<Door>(location); });