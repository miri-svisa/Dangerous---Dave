#include "ElevatorState.h"
#include <Jump.h>
#include <ShotState.h>
#include <WalkingState.h>
#include <FallState.h>
#include <Const.h>
#include"MoveObject.h"
#include <Stend.h>

std::unique_ptr<State> ElevatorState::handleInput(sf::Keyboard::Key  input)
{
	if (input == sf::Keyboard::Up)
	{
		//jumping = true;
		// Other code...
		return std::make_unique<Jump>();
	}
	if (input == sf::Keyboard::RAlt || input == sf::Keyboard::LAlt)
	{
		return std::make_unique<ShotState>();
	}
	if (input == sf::Keyboard::Left || input == sf::Keyboard::Right)
	{
		return std::make_unique<WalkingState>();
	}
	if (input == sf::Keyboard::Down)
	{
		return std::make_unique<FallState>(sf::Vector2f(0,1));
	}
	if (input == sf::Keyboard::Space)
	{
		return std::make_unique<Stend>();
	}

	// Stay in this state.
	return NULL;
}
//---------------------------------------------------------------------------------------
void ElevatorState::enter(MoveObject& gamePlayer)
{
	//mario.setGraphics(PlayerStend);
	//mario.setDirection(sf::Vector2f(0,0));
	//mario.Move( deltaTime);
}