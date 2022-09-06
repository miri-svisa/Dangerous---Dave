#pragma once
#include<string>
#include"Board.h"
//#include "Player.h"
#include"Singelton.h"
#include"Key.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include"ViewInfo.h"
class Level :public Observer
{
public:
	Level(std::unique_ptr<Player>& pplayr);
	//void readboard(std::string nameOfLevel);
	//virtual void keyUpdate(bool key);
	void runLevel(sf::RenderWindow& window, std::string nameOfLevel);//, bool& finishLevel, bool& levelagain);
	void showTheBoard(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	//void changePlayerState(sf::Keyboard::Key keys);
	//void drawTheBoard(sf::RenderWindow& window);
	~Level()=default;

protected:
	Board m_Board;
	ViewInfo m_information;
	//std::unique_ptr<Player> m_player;
	//std::unique_ptr<Key> m_key;
	sf::Clock m_levelClock;
	//bool m_key;
	//ViewInfo 
	
};
