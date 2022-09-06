#include <Jump.h>
#include <ShotState.h>
#include <WalkingState.h>
#include"MoveObject.h"
#include <FallState.h>
#include <Stend.h>
Jump::Jump()
{
}
Jump::Jump(sf::Vector2f dir) :m_direction(dir)
{
	m_jumpingClock.restart();
}
std::unique_ptr<State> Jump::handleInput(sf::Keyboard::Key  input)
{
	if (input == sf::Keyboard::Left)
	{
		return std::make_unique<Jump>(sf::Vector2f(-1,-1));
	}
	if ( input == sf::Keyboard::Right)
	{
		return std::make_unique<Jump>(sf::Vector2f(1,-1));
	}
	if (input == sf::Keyboard::Space)
	{
		return std::make_unique<Stend>();
	}
	if (input == sf::Keyboard::Down)
	{
		return std::make_unique<FallState>(sf::Vector2f(0,1));
	}
	// Stay in this state.
	return NULL;
}
void Jump::enter(MoveObject& gamePlayer)
{
	gamePlayer.setGraphics(PlayerJump);
	gamePlayer.setDirection(m_direction);
	if (m_jumpingClock.getElapsedTime().asSeconds() > 0.5f)
	{
		gamePlayer.handleInput(sf::Keyboard::Key::Down);
	}
}