#pragma once
#include"ShootObjects.h"
#include "Factory.h"

class Level;
class Monster:public ShootObjects
{
public:
	Monster(sf::Vector2f Location=sf::Vector2f(0,0));
	//~Monster() ;
	void move(float deltaTime, float lengthBoard);
	float getLengthBoard();
protected:
	static bool m_registerit;
	float m_lengthBoard;
};
inline bool Monster::m_registerit = Factory::registerit('m',
	[](sf::Vector2f location) -> std::unique_ptr<Object> { return std::make_unique<Monster>(location); });
