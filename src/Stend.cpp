#include "Stend.h"
#include <Jump.h>
#include <WalkingState.h>
#include <ShotState.h>
#include"MoveObject.h"
//-------------------------------------------------------------------------------------------
std::unique_ptr<State> Stend::handleInput(sf::Keyboard::Key input)
{
	if (input == sf::Keyboard::Up)
	{
		return std::make_unique<Jump>(sf::Vector2f(0,-1));
	}
	else if (input == sf::Keyboard::Right )
	{
		return std::make_unique<WalkingState>(sf::Vector2f(1, 0));
	}
	else if ( input == sf::Keyboard::Left)
	{
		return std::make_unique<WalkingState>(sf::Vector2f(-1, 0));
	}
	// Stay in this state.
	return NULL;
}
//-------------------------------------------------------------------------
void Stend::enter(MoveObject& gamePlayer)
{
	gamePlayer.setDirection(sf::Vector2f(0, 0));
	gamePlayer.setGraphics(player);
}