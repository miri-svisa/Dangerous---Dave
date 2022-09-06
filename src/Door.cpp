#include "Door.h"

Door::Door(sf::Vector2f location) :StuticObject(Singelton::get_instance().getTexture(door), location)
{
}


	