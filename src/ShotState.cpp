#include "ShotState.h"
#include <Jump.h>
#include"MoveObject.h"
#include <Stend.h>

std::unique_ptr<State> ShotState::handleInput(sf::Keyboard::Key input)
{
		if (input == sf::Keyboard::Up)
		{
			return std::make_unique<Jump>();
		}
		if (input == sf::Keyboard::RAlt || input == sf::Keyboard::LAlt)
		{
			return std::make_unique<ShotState>();
		}
		if (input == sf::Keyboard::Space)
		{
			return std::make_unique<Stend>();
		}

		// Stay in this state.
		return NULL;
	
}
void ShotState::enter(MoveObject& gamePlayer)
{
}