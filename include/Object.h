#pragma once
#include <SFML/Graphics.hpp>
#include "Const.h"
#include "Singelton.h"

class Object
{
public:
	Object(sf::Vector2f Location, sf::Texture& Picture,int length,int width);
	void draw(sf::RenderWindow& window);
	void setLocition(sf::Vector2f Location);
	sf::Vector2f getLocation();
	sf::FloatRect getGlobalBounds();
	virtual~Object() = default;
	bool toBeRemoved();
	void removeObject();
	 
protected:
	bool m_rm = false;
	sf::Texture& m_picture;
	sf::Sprite m_Sprite;
	int m_height;
	int m_widht;
	sf::Vector2f m_location;
};