#include "Elevator.h"


Elevator::Elevator(sf::Vector2f location) :MoveObject(Singelton::get_instance().getTexture(RedDiamond), location, LENGTHOFCELL, WIDTHOFSHOTS,sf::Vector2f(), PLAYERSPEED)
{}