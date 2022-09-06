#pragma once



//------------------------------------


#include "Object.h"
#include"MoveObject.h"
#include <iostream>
#include <typeinfo>

// Sample struct for exception throwing
struct UnknownCollision : public std::runtime_error
{
	UnknownCollision(Object& a, Object& b)
		: std::runtime_error(std::string("Unknown collision of ") + typeid(a).name() + " and " + typeid(b).name())
	{

	}
};

void processCollision(MoveObject& object1, Object& object2);
