#include"Singelton.h"
#include <iostream>
//--------------------------------------------------------------------------
Singelton::Singelton()
{
	sf::Texture picture;
	picture.loadFromFile("BlueDiamond.png");
	m_Textures.push_back(picture);//0
	picture.loadFromFile("Crown.png");
	m_Textures.push_back(picture);//1
	picture.loadFromFile("Door.png");
	m_Textures.push_back(picture);//2
	picture.loadFromFile("Explosion.png");
	m_Textures.push_back(picture);//3
	picture.loadFromFile("Fire.png");
	m_Textures.push_back(picture);//4
	picture.loadFromFile("Key.png");
	m_Textures.push_back(picture);//5
	picture.loadFromFile("Live.png");
	m_Textures.push_back(picture);//6
	picture.loadFromFile("Pipe.png");
	m_Textures.push_back(picture);//7
	picture.loadFromFile("PlayerFalls.png");
	m_Textures.push_back(picture);//8
	picture.loadFromFile("Player.png");
	m_Textures.push_back(picture);//9
	picture.loadFromFile("PlayerGo.png");
	m_Textures.push_back(picture);//10
	picture.loadFromFile("PlayerJump.png");
	m_Textures.push_back(picture);//11
	picture.loadFromFile("PlayerStend.png");
	m_Textures.push_back(picture);//12
	picture.loadFromFile("PurpleFire1.png");
	m_Textures.push_back(picture);//13
	picture.loadFromFile("PurpleFire2.png");
	m_Textures.push_back(picture);//14
	picture.loadFromFile("PurpleFire3.png");
	m_Textures.push_back(picture);//15
	picture.loadFromFile("PurpleFire4.png");
	m_Textures.push_back(picture);//16
	picture.loadFromFile("RedDiamond.png");
	m_Textures.push_back(picture);//17
	picture.loadFromFile("RedWall.png");
	m_Textures.push_back(picture);//18
	picture.loadFromFile("SmallWater.png");
	m_Textures.push_back(picture);//19
	picture.loadFromFile("OpenScreen.png");
	m_Textures.push_back(picture);//20
	picture.loadFromFile("GameOver.jpg");
	m_Textures.push_back(picture);//21
	picture.loadFromFile("YouWin.jpg");
	m_Textures.push_back(picture);//22
	picture.loadFromFile("help1.png");
	m_Textures.push_back(picture);
	picture.loadFromFile("help2.png");
	m_Textures.push_back(picture);
	picture.loadFromFile("help3.png");
	m_Textures.push_back(picture);
	picture.loadFromFile("Monster.png");
	m_Textures.push_back(picture);
	picture.loadFromFile("Shots.png");
	m_Textures.push_back(picture);
	picture.loadFromFile("gun.png");
	m_Textures.push_back(picture);
	picture.loadFromFile("dave.png");
	m_Textures.push_back(picture);
	m_font.loadFromFile("C:/Windows/Fonts/Gabriola.ttf");
	//throw std::invalid_argument("Image not found");
}
//-------------------------------------------------------------------------
Singelton& Singelton::get_instance()
{
	static Singelton m_instence;
	return m_instence;
}
//--------------------------------------------------------------------
 sf::Texture& Singelton::getTexture(int index)
 {
	 //static LoadTextures m_loader;
	 return (m_Textures[index]);
 }
 //--------------------------------------------------------------------
 sf::Font& Singelton::getFont()
 {
	 return m_font;
 }
 //------------------------------------------------------------------