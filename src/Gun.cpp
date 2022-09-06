#include "Gun.h"


Gun::Gun(sf::Vector2f location) :StuticObject(Singelton::get_instance().getTexture(gun), location)
{}