#include"Controller.h"

//------------------------------------------------------------------------------------------
Controller::Controller() : m_window(sf::VideoMode(WIDTH, LENGTH), "Dave")
{
}
//----------------------------------------------------------------------------------------
void Controller::run()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_window.setFramerateLimit(60);
		m_sprite.setTexture(Singelton::get_instance().getTexture(OpenScreen));
		m_sprite.setPosition(sf::Vector2f(0, 0));
		m_window.draw(m_sprite);
		m_window.display();
		auto event = sf::Event{};
		if ( m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				m_window.close();
				break;
			}
			case sf::Event::KeyPressed:
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Key::Enter:
				{
					std::unique_ptr <Player> p = std::make_unique<Player>(sf::Vector2f(0, 0));
					Game m_game(p);
					m_game.runGame(m_window);
					p.release();
					break;
				}
				case sf::Keyboard::Key::F1:
				{
					help();
					break;
				}
				case sf::Keyboard::Key::Escape:
				{
					m_window.close();
					break;
				}
				default:
					break;
				}
				break;
			}
			}
		}
		//break;
	}
}

void Controller::help()
{
	int i = 0, index = help1;
	m_window.clear();
	m_sprite.setTexture(Singelton::get_instance().getTexture(help1));
	m_sprite.setPosition(sf::Vector2f(0, 0));
	m_window.draw(m_sprite);
	m_window.display();
	auto event = sf::Event{};
	while (m_window.waitEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			m_window.close();
			break;
		}
		case sf::Event::KeyPressed:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Key::Escape:
			{
				return;
			}
			case sf::Keyboard::Key::Space:
			{
				if (i < 2)
				{
					index++;
					m_window.clear();
					m_sprite.setTexture(Singelton::get_instance().getTexture(index));
					m_sprite.setPosition(sf::Vector2f(0, 0));
					m_window.draw(m_sprite);
					m_window.display();
					i++;
					break;
				}
				return;
			}
			default:
				break;
			}
		}
		}

	}
}
