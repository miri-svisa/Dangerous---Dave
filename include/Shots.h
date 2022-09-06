
#pragma once
#include"MoveObject.h"
#include "Factory.h"

class Shots :public MoveObject
{
public:
	Shots(sf::Vector2f Location, sf::Vector2f direction);
	~Shots() = default;
	void move(float daltaTime);// , sf::Vector2f direction);
	bool ifShotsTime();

protected:
	static bool m_registerit;
	sf::Clock m_shotsClock;
};