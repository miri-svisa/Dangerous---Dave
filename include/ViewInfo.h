#pragma once
#include"Const.h"
#include"Singelton.h"
#include"Observer.h"
#include"Player.h"
class ViewInfo:public Observer
{
public:
	ViewInfo(std::unique_ptr<Player>& pplayr);
	~ViewInfo() = default;
	//virtual void keyUpdate(bool key);
	void draw(sf::RenderWindow& window);
	void drawTheValues( sf::RenderWindow& window);
	void sizeWindow(sf::RenderWindow& window)const;
protected:
	//Level& m_level;
	//bool m_key;
	sf::Text m_score;
	sf::Text m_lives;
	sf::Text m_level;
	sf::Color m_color = sf::Color::Green;


};