#pragma once
#include"StuticObject.h"
#include "Factory.h"

class Water :public StuticObject
{
public:
	Water(sf::Vector2f location = sf::Vector2f(0,0));
	~Water() = default;

protected:
	static bool m_registerit;
};
inline bool Water::m_registerit = Factory::registerit('w',
	[](sf::Vector2f location)-> std::unique_ptr<Object> { return std::make_unique<Water>(location); });