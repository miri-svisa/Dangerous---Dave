#include "FallState.h"
#include <Jump.h>
#include"MoveObject.h"
#include <WalkingState.h>
#include <Stend.h>
FallState::FallState(sf::Vector2f direction):m_direction(direction)
{
}
std::unique_ptr<State> FallState::handleInput(sf::Keyboard::Key  input)
{
	if (input == sf::Keyboard::Space)
	{
		return std::make_unique<Stend>();
	}
	if (input == sf::Keyboard::Left)
	{
		return std::make_unique<WalkingState>(sf::Vector2f(-1, 0));
	}
	if (input == sf::Keyboard::Right)
	{
		return std::make_unique<WalkingState>(sf::Vector2f(1, 0));
	}
	return NULL;
}
void FallState::enter(MoveObject& gamePlayer)
{
	gamePlayer.setDirection(m_direction);
}