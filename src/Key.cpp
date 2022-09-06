#include "Key.h"

Key::Key(sf::Vector2f location) :StuticObject(Singelton::get_instance().getTexture(key), location)
{}