#include"Pipe.h"

Pipe::Pipe(sf::Vector2f location):StuticObject(Singelton::get_instance().getTexture(pipe), location)
{
}
