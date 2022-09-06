#pragma once
#include"StuticObject.h"
//#include "Factory.h"

class Diamond:public StuticObject
{
public:
	Diamond(sf::Texture& picture, sf::Vector2f location);
	~Diamond() = default;
	
protected:


};