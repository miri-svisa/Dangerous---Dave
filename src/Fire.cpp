#include "Fire.h"

Fire::Fire(sf::Vector2f location) :StuticObject(Singelton::get_instance().getTexture(fire), location)
{}