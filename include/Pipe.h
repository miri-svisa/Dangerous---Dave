#pragma once
#include "Factory.h"
#include"StuticObject.h"

class Pipe:public StuticObject
{
public:
	//Pipe();
	Pipe(sf::Vector2f location = sf::Vector2f(0, 0));
	//~Pipe();

private:
	static bool m_registerit;
};
inline bool Pipe::m_registerit = Factory::registerit('^',
	[](sf::Vector2f location) -> std::unique_ptr<Object> { return std::make_unique<Pipe>(location); });

