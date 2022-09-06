#pragma once
#include"StuticObject.h"
#include "Factory.h"

class Key :public StuticObject
{
public:
	Key(sf::Vector2f location = sf::Vector2f(0, 0));
	~Key() = default;

protected:
	static bool m_registerit;
};
inline bool Key::m_registerit = Factory::registerit('k',
	[](sf::Vector2f location) -> std::unique_ptr<Object> { return std::make_unique<Key>(location); });