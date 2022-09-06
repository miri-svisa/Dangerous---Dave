#include"Board.h"
#include"Level.h"
#include "Factory.h"
#include "Wall.h"
#include "CollisionHandling.h"
#include <MyException.h>
//---------------------------------------------------------------
Board::Board(std::unique_ptr<Player>& pplayr) :m_creatShots(true),m_cuont(0),m_board(),m_cols(),m_startLevel(),m_player(pplayr), m_widthBoard(WIDTH)
{
}
//---------------------------------------------------------------------
void Board::readFile(std::string nameOfLevel)
{
	std::ifstream m_file;
	m_file.open(nameOfLevel);
	if (!m_file.is_open())
		throw MyException();

	m_startLevel = m_file.tellg();
	m_file >> m_cols;
	Reset();
	std::string line;
	std::getline(m_file, line);
	m_widthBoard = m_cols * WIDTHOFCELL;
	for (int i = 0; i <= NUMOFROWS; ++i)
	{
		std::getline(m_file, line);
		readLine(i, line);
	}
	m_file.seekg(0);
}
//--------------------------------------------------------------------------------
void Board::readLine(int i, std::string line)
{
	sf::Vector2f location;
	for (int j = 0; j < line.size(); ++j)
	{
		location.x = (WIDTHOFCELL)*j; 
		location.y = (LENGTHOFCELL)*i + 50;
		insertObject(line[j], location);
	}
}
//------------------------------------------------------------------
bool Board::chackThePlace()
{
	sf::Vector2f dounLocation = sf::Vector2f(m_player->getLocation().x, m_player->getLocation().y + LENGTHOFCELL);
	for (int i = 0; i < m_WallLocations.size();i++)
	{
		if (m_WallLocations[i] == dounLocation)
		{
			return true;
		}
	}
	return false;
}
//-------------------------------------------------------------------
void Board::changePlayerState(sf::Keyboard::Key changState)
{
	if (changState == sf::Keyboard::Down|| changState == sf::Keyboard::Space
		|| changState== sf::Keyboard::LControl || changState == sf::Keyboard::RControl)
		return;
	m_player->handleInput(changState);
}
//------------------------------------------------------------------
void Board::insertObject(char object, sf::Vector2f location)
{
	if (object != ' ')
	{
		if (object == 'p')
			m_player->setValues(location);
		else if (object == 'm')
			m_monsters.emplace_back(dynamic_cast<Monster*>(Factory::create(object, location).release()));
		else
		{
			auto p = (std::move(Factory::create(object, location)));///להוסיף את המיקומים
			if (p != nullptr)
				m_board.push_back(std::move(p));
			if (object == '|')
				m_WallLocations.push_back(location);
		}
	}
}
//--------------------------------------------------------------------
//פונקציה שמאפסת את הלוח
void Board::Reset()
{
	m_board.resize(m_board.size());
}
//-----------------------------------------------------------------
void Board::draw(sf::RenderWindow& window)const
{
	for (int i = 0; i < m_board.size(); i++)
			if (m_board[i] !=nullptr)
				m_board[i]->draw(window);

	m_player->draw(window);
	m_player->drawTheShots(window);

	for (int i = 0; i < m_monsters.size(); i++)
	{
		if (m_monsters[i] != nullptr)
		{
			m_monsters[i]->draw(window);
			m_monsters[i]->drawTheShots(window);
		}
	}
}
//-----------------------------------------------------------------
void Board::movePlayer(float deltaTime)
{
	m_player->saveTheLastLocation();
	m_player->setState();
	if ((m_player->getDirection() != (sf::Vector2f(0, 0))
		&& (m_player->getDirection() != (sf::Vector2f(0, 1)))
		&& (m_player->getDirection() != (sf::Vector2f(0, -1))))
		&& (m_player->getDirection() != (sf::Vector2f(1, -1)))
		&& (m_player->getDirection() != (sf::Vector2f(-1, -1))))
	{
		m_player->setPrevDirection(m_player->getDirection());
	}
	m_player->move(deltaTime);
	m_player->moveShots(deltaTime);
	m_player->removeShots();

	std::experimental::erase_if(m_board, [](const auto& item)
		{
			return item->toBeRemoved();
		});
	std::experimental::erase_if(m_monsters, [](const auto& item)
		{
			return item->toBeRemoved();
		});
}
//-----------------------------------------------------------------------
void Board::playerShots(float deltaTime)const
{
	m_player->shots(m_player->getPrevDirection());
	
}
//--------------------------------------------------------------------------
void Board::setPlayerDirection(sf::Vector2f direction)
{
	m_player->setDirection(direction);
}
//------------------------------------------------------------------------
void Board::checkCollision()
{
	bool colide = false;

	for (auto obj = m_board.begin(); obj != m_board.end(); ++obj)
	{
		if (collide(*m_player, **obj))
		{
			colide = true;
			processCollision(*m_player, **obj);
		}
		for (auto monster = m_monsters.begin(); monster != m_monsters.end(); ++monster)
		{
			if (collide(**monster, **obj))
				processCollision(**monster, **obj);
		}
	}
	for (auto monster = m_monsters.begin(); monster != m_monsters.end(); ++monster)
	{
		if (collide(*m_player, **monster))
			processCollision(*m_player, **monster);
		monster->get()->chackCollisionShots(*m_player);
		m_player->chackCollisionShots(**monster);
	}
	if (!colide && !m_onTheWall)
	{
		m_onTheWall = true;
		m_player->handleInput(sf::Keyboard::Down);
	}
}
//------------------------------------------------------------------------
void Board::updateObserver()
{
	m_player->doorUpdate(false);
	m_player->keyUpdate(false);
}
//-------------------------------------------------------------------------
bool Board::collide(MoveObject& object1, Object& object2) {
	if (object1.getGlobalBounds().intersects(object2.getGlobalBounds()))
		return true;
	return false;
}
//-----------------------------------------------------------------------
void Board::sizeWindow(sf::RenderWindow& window)const
{
	float endBoard = m_widthBoard - (WIDTH / 2);
	auto viewSize = sf::Vector2f(window.getSize().x, window.getSize().y - LENGTHOFINFOVIEW);
	auto view0 = sf::View(sf::Vector2f(m_player->getLocation().x, LENGTH / 2 + LENGTHOFINFOVIEW / 2), viewSize);
	auto view1 = sf::View(sf::Vector2f(WIDTH / 2, LENGTH / 2 + LENGTHOFINFOVIEW / 2), viewSize);
	auto view2 = sf::View(sf::Vector2f(endBoard, LENGTH / 2 + LENGTHOFINFOVIEW / 2), viewSize);
	view0.setViewport({ 0.f, 0.1f, 1.f, 0.9f });
	view1.setViewport({ 0.f, 0.1f, 1.f, 0.9f });
	view2.setViewport({ 0.f, 0.1f, 1.f, 0.9f });
	if (m_player->getLocation().x < WIDTH / 2)
		window.setView(view1);
	else if (m_player->getLocation().x > endBoard)
		window.setView(view2);
	else
		window.setView(view0);
}
//----------------------------------------------------------
void Board::monsterShots(float deltaTime)
{
	creatShots();
	moveShots(deltaTime);
}
//----------------------------------------------------------------
void Board::creatShots()
{
	if (m_monsters.size() > 0)
	{
		int num = rand() % (m_monsters.size());
		if (m_creatShots == true)
		{
			m_creatShots = false;
			m_monsters[num]->shots(m_monsters[num]->getDirection());
		}
		else
			m_cuont++;
		if (m_cuont == RATEOFSHOTS)
		{
			m_cuont = 0;
			m_creatShots = true;
		}
	}
}
//------------------------------------------------------------- 
void Board::moveShots(float deltaTime)
{
	for (int i = 0; i < m_monsters.size(); i++)
	{
		m_monsters[i]->moveShots(deltaTime);
		m_monsters[i]->removeShots();
	}
}
//----------------------------------------------------------------
void Board::moveMonster(float deltaTime)
{
	for (int i = 0; i < m_monsters.size(); i++)
	{
		m_monsters[i]->saveTheLastLocation();
		m_monsters[i]->move(deltaTime,m_widthBoard);
	}
}
//-----------------------------------------------------------------
void Board::resetMonsters()
{
	if (m_monsters.size() > 0)
	{
		for (auto monster = m_monsters.begin(); monster != m_monsters.end(); ++monster)
		{
			monster->get()->removeObject();
		}
		std::experimental::erase_if(m_monsters, [](const auto& item)
			{
				return item->toBeRemoved();
			});
	}
}


