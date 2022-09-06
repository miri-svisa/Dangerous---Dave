#pragma once
#include "StuticObject.h"
#include <vector>
#include<fstream>
#include <iostream>
#include <experimental/vector>
#include"Const.h"
#include"Player.h"
#include"Monster.h"
#include"Shots.h"
#include <SFML\System\Vector2.hpp>



class Board
{
public:
	Board(std::unique_ptr<Player>& pplayr);
	~Board() = default;
    void Reset();
	void readLine(int numOfLine, std::string line);
	void insertObject(char object, sf::Vector2f location);
	void readFile(std::string nameOfLevel);
	void monsterShots(float deltaTime);
	void creatShots();
	void moveShots(float deltaTime);
	void draw(sf::RenderWindow& window)const;
	void changePlayerState(sf::Keyboard::Key changState);
	bool chackThePlace();
	void movePlayer(float deltaTime);
	void setPlayerDirection(sf::Vector2f direction);
	void checkCollision();
	bool collide(MoveObject& object1, Object& object2);
	void sizeWindow(sf::RenderWindow& window)const;
	void moveMonster(float deltaTime);
	void playerShots(float deltaTime)const;
	void updateObserver();
	void resetMonsters();
	
	

protected:
	std::vector <std::unique_ptr<Monster>> m_monsters;
	std::vector<std::unique_ptr<Object>> m_board;
	std::vector<sf::Vector2f>m_WallLocations;
	//std::unique_ptr<Player> m_player;
	std::unique_ptr<Player> &m_player;
	std::ifstream m_file;
	//int m_rows;
	int m_cols;
	int m_startLevel;
	bool m_onTheWall = false;
	float m_widthBoard;
	//float m_lengthOfObject;
	//float m_wightOfObject;
	bool m_creatShots;
	int m_cuont;
};