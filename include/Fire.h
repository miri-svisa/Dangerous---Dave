#pragma once
#include"StuticObject.h"
#include "Factory.h"

class Fire :public StuticObject
{
public:
	Fire(sf::Vector2f location = sf::Vector2f(0, 0));
	//~Fire() = default;

protected:
	static bool m_registerit;
};
inline bool Fire::m_registerit = Factory::registerit('f',
	[](sf::Vector2f location) -> std::unique_ptr<Object> { return std::make_unique<Fire>(location); });