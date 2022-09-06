#include"Level.h"

//-------------------------------------------------------------------------------
Level::Level(std::unique_ptr<Player>& pplayr) :m_Board(pplayr), m_information(pplayr)//, m_key(false)
{
	pplayr->RegisterObserver(*this);
}
//-----------------------------------------------------------------------------------
void Level::runLevel(sf::RenderWindow& window, std::string nameOfLevel)//, bool& finishLevel, bool& levelagain)
{
	int lives = m_daves;
	m_Board.resetMonsters();
	m_Board.readFile(nameOfLevel);
	while (window.isOpen())
	{
		auto deltaTime = m_levelClock.restart().asSeconds();
		showTheBoard(window);
		srand(time(0));
		auto event = sf::Event{};
		m_Board.movePlayer(deltaTime);
		m_Board.moveMonster(deltaTime);
		m_Board.monsterShots(deltaTime);
		m_Board.checkCollision();
		if (m_door)
		{
			 m_Board.updateObserver();
			return;
		}
		if (m_daves < lives)
		{
			return;
		}
			
		while ( window.pollEvent(event))
		{
				switch (event.type)
				{
				case sf::Event::Closed:
				{
					window.close();
					break;
				}
				case sf::Event::KeyPressed:
				{
					if (event.key.code == sf::Keyboard::LControl || event.key.code == sf::Keyboard::RControl)
					{
						if (m_gun)
						{
							m_Board.playerShots(deltaTime);
						}
					}
					m_Board.changePlayerState(event.key.code);
				}
				default:
					break;
				}
		}
	}
}
//---------------------------------------------------------------------------------------------
void Level::showTheBoard(sf::RenderWindow& window)
{
	window.clear();
	m_Board.sizeWindow(window);
	draw(window);
	m_information.sizeWindow(window);
	draw(window);
	window.display();
}
//-----------------------------------------------------------------------------------------
void Level::draw(sf::RenderWindow& window)
{
	m_Board.draw(window);
	m_information.draw(window);
	m_information.drawTheValues( window);
}

