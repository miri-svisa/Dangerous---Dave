#include "Factory.h"


std::unique_ptr<Object> Factory::create(const char& name, sf::Vector2f Location)
{
	auto it = getMap().find(name);
	if (it == getMap().end())
		return nullptr;
	return it->second(Location);
}

bool Factory::registerit(const char& name, std::unique_ptr<Object>(*f)(sf::Vector2f location))
{
	getMap().emplace(name, f);
	return true;
}

