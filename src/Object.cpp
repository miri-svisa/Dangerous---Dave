#include"Object.h"


Object::Object(sf::Vector2f Location, sf::Texture& Picture, int length, int width) :m_picture(Picture), m_height(length), m_widht(width), m_location(Location)
{
	m_Sprite = sf::Sprite(m_picture);
	auto texSize = m_picture.getSize();
	auto newTexSize = sf::Vector2u(m_widht, m_height);
	auto scaleX = newTexSize.x * 1.00f / texSize.x;
	auto scaleY = newTexSize.y * 1.00f / texSize.y;
	m_Sprite.scale(scaleX, scaleY);
	m_Sprite.setPosition(Location);
}
//----------------------------------------------------------
void Object::draw(sf::RenderWindow & window)
{
	window.draw(m_Sprite);
}
//----------------------------------------------------------
void Object::setLocition(sf::Vector2f Location)
{
	m_Sprite.setPosition(Location);
}
//-----------------------------------------------------------
sf::Vector2f Object::getLocation()
{
	return(m_Sprite.getPosition());
}
//----------------------------------------------------------
sf::FloatRect Object::getGlobalBounds()
{
	return m_Sprite.getGlobalBounds();
}
//--------------------------------------------------------------
bool Object::toBeRemoved()
{
	return m_rm;
}
//-----------------------------------------------------------
void Object::removeObject()
{
	m_rm = true;
}
