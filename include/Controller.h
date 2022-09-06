#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include "Const.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include"Singelton.h"
#include<fstream>
class Controller
{
public:
	Controller();
	void run();
	void help();
	~Controller() = default;

protected:

	sf::Sprite m_sprite;
	sf::RenderWindow m_window;

};
