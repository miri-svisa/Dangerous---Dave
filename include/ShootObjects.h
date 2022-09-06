#pragma once
#include <experimental/vector>

#include "MoveObject.h"
#include "Shots.h"

class ShootObjects :public MoveObject
{
public:
	ShootObjects(sf::Texture& Picture, sf::Vector2f Location,int speed, sf::Vector2f direction);
	void shots(sf::Vector2f direction);
	void drawTheShots(sf::RenderWindow& window)const;
	void moveShots(float deltaTime);
	void removeShots();
	~ShootObjects();
	void chackCollisionShots(MoveObject& object1);
	bool collide(MoveObject& object1, Object& object2);

private:
	std::vector<std::unique_ptr<Shots>> m_shots;
	sf::Clock m_clockShots;
	//sf::Vector2f m_prevDirection;
};