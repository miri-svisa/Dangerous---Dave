#include "Water.h"

Water::Water(sf::Vector2f location) :StuticObject(Singelton::get_instance().getTexture(SmallWater), location)
{}