#include "WalkingState.h"
#include <Jump.h>
#include <ShotState.h>
#include"MoveObject.h"
#include <Stend.h>
#include <FallState.h>
WalkingState::WalkingState()
{
}
//----------------------------------------------------------------
WalkingState::WalkingState(sf::Vector2f dir):m_direction(dir)
{
	m_walkingClock.restart();
}
//--------------------------------------------------------------------
std::unique_ptr<State> WalkingState::handleInput(sf::Keyboard::Key  input)
{
	if (input == sf::Keyboard::Up)
	{
		return std::make_unique<Jump>(sf::Vector2f(-1,0));
	}
	else if (input == sf::Keyboard::Right)
	{
		return std::make_unique<WalkingState>(sf::Vector2f(1,0));
	}
	else if (input == sf::Keyboard::Down)
	{
		return std::make_unique<FallState>(sf::Vector2f(0,1));
	}
	else if (input == sf::Keyboard::Left)
	{
		return std::make_unique<WalkingState>(sf::Vector2f(-1,0));
	}
	if (input == sf::Keyboard::Space)
	{
		return std::make_unique<Stend>();
	}
	return NULL;
}
//---------------------------------------------------------------------
void WalkingState::enter(MoveObject& gamePlayer)
{
	gamePlayer.setDirection(m_direction);
	gamePlayer.setGraphics(PlayerGo);
	if (m_walkingClock.getElapsedTime().asSeconds() > 0.09f)
	{
		gamePlayer.handleInput(sf::Keyboard::Down);
	}
}