#pragma once
#include "Object.h"
#include "State.h"

class MoveObject:public Object
{
public:
	MoveObject(sf::Texture& Picture, sf::Vector2f Location, int length, int width, sf::Vector2f direction, int speed);
	sf::Vector2f getDirection();
	void setDirection(sf::Vector2f dir);
	void setGraphics(typeOfObject pic);
	void move(float deltaTime);
	void handleInput(sf::Keyboard::Key input);
	void returnlocation();
	void setState();
	void saveTheLastLocation();
	
	void failure();
	~MoveObject() = default;
	
protected:
	int m_speed;
	sf::Vector2f m_direction;
	sf::Vector2f m_lastLocation;
	std::unique_ptr<State>m_state;
	sf::Clock failureClock;
	
};