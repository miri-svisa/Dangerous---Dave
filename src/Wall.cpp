#include"Wall.h"

Wall::Wall(sf::Vector2f location) :StuticObject(Singelton::get_instance().getTexture(RedWall), location)
{
}
//-------------------------------------------------------------------
