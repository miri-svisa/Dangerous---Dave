#include "Shots.h"

Shots::Shots(sf::Vector2f Location, sf::Vector2f direction) :
	MoveObject(Singelton::get_instance().getTexture(shots),  Location, LENGTHOFSHOTS, WIDTHOFSHOTS, direction, SHOTSSPEED)
{
	m_shotsClock.restart();
}
//---------------------------------------------------------------------------------------
void Shots::move(float deltaTime)
{
	MoveObject::move(deltaTime);

	if (((m_location.x - m_Sprite.getPosition().x > WIDTH) && (m_direction.x < 0)) ||
		((m_Sprite.getPosition().x - m_location.x > WIDTH) && (m_direction.x > 0)))
	if(!toBeRemoved())
		removeObject();
}
//---------------------------------------------------------------------------------------
bool Shots::ifShotsTime()
{
	if (m_shotsClock.getElapsedTime().asSeconds() < TIMESHOTSf)
		return true;
	else
		removeObject();
	return false;
}