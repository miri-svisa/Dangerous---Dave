#pragma once
#include"ShootObjects.h"
#include "Factory.h"

#include "Const.h"

//#include"Direction.h"
//#include "Animation.h"
//#include"Resources.h"
#include <iostream>
#include <optional>
#include"State.h"
#include"Observer.h"
#include "Stend.h"

class Board;
class Player:public ShootObjects
{
public:
	Player( sf::Vector2f Location = sf::Vector2f(0, 0));
	void setValues( sf::Vector2f location);
	
	~Player() ;
	
	void keyUpdate(bool key);
	void doorUpdate(bool door);
	void gunUpdate(bool gun);
	void NotifyObserverskey();
	void NotifyObserverslevel();
	void NotifyObserversdaves();
	void NotifyObserversscores();
	void NotifyObserversdavesplus();
	void NotifyObserversgun();
	void NotifyObserversdoor();
	bool getTheKey();
	void RegisterObserver(Observer& pObserver);
	sf::Vector2f getPrevDirection();
	void setPrevDirection(sf::Vector2f prevDirection);
	//virtual void keyUpdate(int key);

protected:
	std::vector <Observer*> m_vecPObserver;
	//bool m_
	//std::unique_ptr<State>m_state;
	static bool m_registerit;
	bool m_key;
	bool m_door;
	bool m_gun;
	sf::Vector2f m_prevDirection;
	
	//sf::Sprite m_sprite;
	//Direction m_dir = Direction::Stay;
	//Animation m_animation;
};
//inline bool Player::m_registerit = Factory::registerit('p',
	//[](sf::Vector2f location) -> std::unique_ptr<Object> { return std::make_unique<Player>(location); });