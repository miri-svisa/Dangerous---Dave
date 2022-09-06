#pragma once
#include<vector>
#include <SFML/Graphics.hpp>
//class vector;
class Singelton
{
public:
	
	sf::Texture& getTexture(int index);
	sf::Font& getFont();
	static Singelton& get_instance();
//	static void initializeInstance();
private:
	sf::Font m_font;
	 std::vector<sf::Texture> m_Textures;
	 Singelton(const Singelton&) = default;

	//std::vector<Monster*>m_monsters;
	 Singelton();
	
};