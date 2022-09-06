#pragma once
//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <string>

#include "Object.h"

typedef std::map<char, std::unique_ptr<Object>(*)(sf::Vector2f location)> mymap;

//class object;
class Factory
{
public:
	static std::unique_ptr<Object> create(const char& name, sf::Vector2f Location);
	static bool registerit(const char& name, std::unique_ptr<Object>(*f)(sf::Vector2f location));
	
private:
	static mymap& getMap()
	{
		static mymap m_map;
		return m_map;
	}
};


