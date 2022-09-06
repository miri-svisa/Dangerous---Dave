#pragma once
#include"StuticObject.h"
#include "Factory.h"

class Wall :public StuticObject
{
public:
	Wall(sf::Vector2f location = sf::Vector2f(0, 0));
	~Wall() = default;
	
protected:
	static bool m_registerit;
};
inline bool Wall::m_registerit = Factory::registerit('|',
	[](sf::Vector2f location) -> std::unique_ptr<Object> { return std::make_unique<Wall>(location); });