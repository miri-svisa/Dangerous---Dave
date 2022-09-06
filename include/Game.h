#pragma once
#include<fstream>
#include <iostream>
#include <string>
#include"Level.h"
#include"Const.h"
#include"Singelton.h"
#include <SFML\Graphics\RenderWindow.hpp>
class Game :public Observer
{
public:
	Game(std::unique_ptr<Player>& pplayr);
	~Game()= default;
	std::string getTheNameofFile();
	//virtual void keyUpdate(bool key);
	void returnTellG();
	void runGame(sf::RenderWindow& window);
	void actionAtTheAnd(sf::RenderWindow& window, int index);
protected:
	Level m_level;
	std::ifstream m_fileGame;
	std::unique_ptr<Player>& m_player;
	
	//bool m_key;
	//int m_startLevel;
};
