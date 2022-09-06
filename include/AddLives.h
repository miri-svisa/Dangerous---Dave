#pragma once
#include"Diamond.h"
#include "Factory.h"


class AddLives:public Diamond
{
public:
	AddLives(sf::Vector2f location= sf::Vector2f(0,0));

protected:
	static bool m_registerit;
};
inline bool AddLives::m_registerit = Factory::registerit('+',
	[](sf::Vector2f location) -> std::unique_ptr<Object> { return std::make_unique<AddLives>(location); });