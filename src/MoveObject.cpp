#include"MoveObject.h"
#include <iostream>
//----------------------------------------------------------------------------------------
MoveObject::MoveObject(sf::Texture& Picture, sf::Vector2f Location, int length, int width, sf::Vector2f direction, int speed)
	:m_speed(speed),m_direction(direction), Object(Location, Picture,length, width)
{
	
}
//----------------------------------------------------------------------------------------
sf::Vector2f MoveObject::getDirection()
{
	return m_direction;
}
//----------------------------------------------------------------------------------------
void MoveObject::move(float deltaTime)
{
	m_Sprite.move(m_direction * (deltaTime * m_speed));
}
//----------------------------------------------------------------------------------
void MoveObject::setState()
{
	m_state->enter(*this);
}
//------------------------------------------------------------------------------------
void MoveObject::saveTheLastLocation()
{
	m_lastLocation = m_Sprite.getPosition();
}
//----------------------------------------------------------------------------------------
void MoveObject::returnlocation()
{
	m_Sprite.setPosition(m_lastLocation);
}
//-----------------------------------------------------------------------------------------
void MoveObject::failure()
{
	failureClock.restart();
	if (failureClock.getElapsedTime().asSeconds() > 6)
		return;
}
//----------------------------------------------------------------------------------------
void MoveObject::handleInput(sf::Keyboard::Key input)
{
	std::unique_ptr<State> state_ = m_state->handleInput(input);
	if (state_)
	{
		m_state = std::move(state_);
	}
}
//-----------------------------------------------------------------------------------------
void MoveObject::setGraphics(typeOfObject pic)
{
	m_Sprite.setTexture(Singelton::get_instance().getTexture(pic));
}
//-------------------------------------------------------------------------------------------
void MoveObject::setDirection(sf::Vector2f dir)
{
	m_direction = dir;
}
//---------------------------------------------------------------------------------------

