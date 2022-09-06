#include"Game.h"
#include <MyException.h>
Game::Game(std::unique_ptr<Player>& pplayr) : m_level(pplayr), m_player(pplayr)
{
	//std::make_unique<Player>(sf::Vector2f(0, 0));

	pplayr->RegisterObserver(*this);
	m_fileGame.open("gameLevels.txt");
	if (!m_fileGame.is_open())
		throw MyException();

}
//----------------------------------------------
std::string Game::getTheNameofFile()
{
	if (!m_fileGame.eof())
	{
		std::string line;
		std::getline(m_fileGame, line);
		return line;
	}
}
//---------------------------------------------
void Game::returnTellG()
{
	m_fileGame.seekg(0);
}
//----------------------------------------------------
void Game::runGame(sf::RenderWindow& window)
{
	while (!m_fileGame.eof())
	{
		std::string nameoflevel = getTheNameofFile();
		if (m_daves >= 0)
		{
			int daves = m_daves;
			m_level.runLevel(window, nameoflevel);
			while (m_daves < daves && m_daves >= 0)
			{
				daves = m_daves;
				m_level.runLevel(window, nameoflevel);
				if (m_door)
					break;
			}
		}
		else
		{
			actionAtTheAnd(window, GameOver);
			return;
		}
		m_player->NotifyObserverslevel();
	}
	actionAtTheAnd(window, YouWin);
}
//----------------------------------------------------------------------------
void Game::actionAtTheAnd(sf::RenderWindow& window, int index)
{
	m_player.get_deleter();
	sf::Clock gameOverClock;
	gameOverClock.restart();
	auto viewSize = sf::Vector2f(window.getSize().x, window.getSize().y);
	auto view1 = sf::View(sf::Vector2f(WIDTH / 2, LENGTH / 2), viewSize);
	view1.setViewport({ 0.0f, 0.0f, 1.0f, 1.0f });
	while (gameOverClock.getElapsedTime().asSeconds() < 5)
	{
		auto sprite = sf::Sprite();
		sprite.setTexture(Singelton::get_instance().getTexture(index));
		sprite.setPosition(sf::Vector2f(0, 0));
		window.setView(view1);
		window.clear();
		window.draw(sprite);
		window.display();
	}
	returnTellG();
}


