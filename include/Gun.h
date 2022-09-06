#pragma once
#include "StuticObject.h"
#include "Factory.h"

class Gun :public StuticObject
{
public:
	Gun(sf::Vector2f location = sf::Vector2f(0, 0));

protected:
	static bool m_registerit;
};
inline bool Gun::m_registerit = Factory::registerit('g',
	[](sf::Vector2f location) -> std::unique_ptr<Object> { return std::make_unique<Gun>(location); });