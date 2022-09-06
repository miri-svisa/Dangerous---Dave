#include"Monster.h"
#include"Level.h"
#include "Const.h"

//------------------------------------------------------------------------------------
Monster::Monster(sf::Vector2f Location) :m_lengthBoard(0),
	ShootObjects(Singelton::get_instance().getTexture(monster), Location, MONSTERSPEED, sf::Vector2f(1, 0))
{
}
//------------------------------------------------------------------------------
void Monster::move(float deltaTime, float lengthBoard)
{
	m_lengthBoard = lengthBoard;
		switch (rand() % 2)
		{
		case 0:
		{
			m_direction = sf::Vector2f(1,0);
			break;
		}
		case 1:
		{
			m_direction = sf::Vector2f(-1,0);
			break;
		}
		}
	MoveObject::move(deltaTime);
}
//-------------------------------------------------------------------------------------
float Monster::getLengthBoard()
{
	return m_lengthBoard;
}