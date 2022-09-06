#include "ShootObjects.h"
#include <CollisionHandling.h>

ShootObjects::ShootObjects(sf::Texture& Picture, sf::Vector2f Location, int speed,sf::Vector2f direction)
	:MoveObject(Picture, Location, LENGTHOFCELL, WIDTHOFCELL, direction, speed)
{
	m_clockShots.restart();
}
//--------------------------------------------------------------------------------------
void ShootObjects::shots(sf::Vector2f direction)
{
	m_shots.emplace_back(std::make_unique<Shots>(m_Sprite.getPosition(), direction));
}
//----------------------------------------------------------------------------
void ShootObjects::moveShots(float deltaTime)
{
	for (int i = 0; i < m_shots.size(); i++)
	{
		if (m_shots[i]->ifShotsTime())
			m_shots[i]->move(deltaTime);
	}
}
//-------------------------------------------------------------------------------------
void ShootObjects::removeShots()
{
	std::experimental::erase_if(m_shots, [](const auto& item)
		{
				return item->toBeRemoved();
		});
}
//-------------------------------------------------------------------------------
void ShootObjects::drawTheShots(sf::RenderWindow& window)const
{
	for (int i = 0; i < m_shots.size(); i++)
	{
		if (m_shots[i] != nullptr)
			m_shots[i]->draw(window);
	}
}
//-------------------------------------------------------------------------------------
ShootObjects::~ShootObjects()
{
}
//-------------------------------------------------------------------------------------
void ShootObjects::chackCollisionShots(MoveObject& object1)
{
	for (auto shot = m_shots.begin(); shot != m_shots.end(); ++shot)
	{
		if(collide(object1,**shot))
			processCollision(object1, **shot);
	}
}
//-------------------------------------------------------------------
bool ShootObjects::collide(MoveObject& object1, Object& object2) {
	if (object1.getGlobalBounds().intersects(object2.getGlobalBounds()))
		return true;
	return false;
}