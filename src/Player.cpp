#include"Player.h"
#include"Board.h"

Player::Player(sf::Vector2f Location) : m_door(false),m_key(false),m_gun(false),
	m_prevDirection(sf::Vector2f(1,0)),ShootObjects(Singelton::get_instance().getTexture(player), Location, PLAYERSPEED, sf::Vector2f(0, 0))
{	
	m_state=std::make_unique<Stend>();
}
//--------------------------------------------------------------
Player::~Player()
{
	for (int i = 0; i < m_vecPObserver.size(); i++)
		delete(m_vecPObserver[i]);
}
//-------------------------------------------------------------
sf::Vector2f Player::getPrevDirection()
{
	return m_prevDirection;
}
//-------------------------------------------------------------
void Player::setPrevDirection(sf::Vector2f prevDirection)
{
	m_prevDirection = prevDirection;
}
//-----------------------------------------------------------------------
void Player::setValues(sf::Vector2f location)
{
	m_location = location;
	m_Sprite = sf::Sprite(m_picture);
	auto texSize = m_picture.getSize();
	auto newTexSize = sf::Vector2u(WIDTHOFCELLPLAYER, LENGTHOFCELLPLAYER);
	auto scaleX = newTexSize.x * 1.00f / texSize.x;
	auto scaleY = newTexSize.y * 1.00f / texSize.y;
	m_Sprite.scale(scaleX, scaleY);
	m_Sprite.setPosition(location);
}
//-------------------------------------------------------------------------
void Player::keyUpdate(bool key)
{
	m_key = key;
	NotifyObserverskey();
}
//------------------------------------------------------------------------
void Player::doorUpdate(bool door)
{
	m_door = door;
	NotifyObserversdoor();
}
void Player::gunUpdate(bool gun)
{
	m_gun = gun;
	NotifyObserversgun();
}
//--------------------------------------------------------------------------
bool Player::getTheKey()
{
	return m_key;
}
//----------------------------------------------------------------------------
void Player::NotifyObserverskey()
{
	std::vector<Observer*>::iterator iter;
	for (iter = m_vecPObserver.begin(); iter != m_vecPObserver.end(); ++iter)
	{
		(*iter)->keyUpdate(m_key);
	}
}
//-------------------------------------------------------------------------
void Player::NotifyObserverslevel()
{
	std::vector<Observer*>::iterator iter;
	for (iter = m_vecPObserver.begin(); iter != m_vecPObserver.end(); ++iter)
	{
		(*iter)->levelUpdate();
	}
}
//-----------------------------------------------------------------------
void Player::NotifyObserversdaves()
{
	std::vector<Observer*>::iterator iter;
	for (iter = m_vecPObserver.begin(); iter != m_vecPObserver.end(); ++iter)
	{
		(*iter)->davesUpdate();
	}
}
//--------------------------------------------------------------------------
void Player::NotifyObserversscores()
{
	std::vector<Observer*>::iterator iter;
	for (iter = m_vecPObserver.begin(); iter != m_vecPObserver.end(); ++iter)
	{
		(*iter)->scoresUpdate();
	}
}
//------------------------------------------------------------------------
void Player::NotifyObserversdavesplus()
{
	std::vector<Observer*>::iterator iter;
	for (iter = m_vecPObserver.begin(); iter != m_vecPObserver.end(); ++iter)
	{
		(*iter)->UpdatedavesPlus();
	}
}
//----------------------------------------------------------------------
void Player::NotifyObserversgun()
{
	std::vector<Observer*>::iterator iter;
	for (iter = m_vecPObserver.begin(); iter != m_vecPObserver.end(); ++iter)
	{
		(*iter)->gunUpdate(m_gun);
	}
}
//----------------------------------------------------------------------------
void Player::NotifyObserversdoor()
{
	std::vector<Observer*>::iterator iter;
	for (iter = m_vecPObserver.begin(); iter != m_vecPObserver.end(); ++iter)
	{
		(*iter)->doorUpdate(m_door);
	}
}
//-----------------------------------------------------------------------------
void Player::RegisterObserver(Observer& pObserver)
{
	m_vecPObserver.push_back(&pObserver);
}

