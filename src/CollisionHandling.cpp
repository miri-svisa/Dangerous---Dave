#include"CollisionHandling.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "Player.h"
#include "AddLives.h"
#include "AddScore.h"
#include "Door.h"
#include "Elevator.h"
#include "Fire.h"
#include "Gun.h"
#include "Key.h"
#include "Monster.h"
#include "Pipe.h"
#include "Shots.h"
#include "Wall.h"
#include "Water.h"


namespace
{
	// primary collision-processing functions
	void playerShots(MoveObject& player, Object& Shots)
	{
		sf::Clock fireClock;
		fireClock.restart();
		Player& playe = static_cast<Player&>(player);
		player.returnlocation();
		player.setDirection(sf::Vector2f(0, 0));
		Shots.removeObject();
		playe.NotifyObserversdaves();
	}
	void playerFire(MoveObject& player, Object& Fire)
	{
		Player& playe = static_cast<Player&>(player);
		player.returnlocation();
		player.setDirection(sf::Vector2f(0, 0));
		player.setGraphics(fire);
		playe.NotifyObserversdaves();
	}

	void playerWater(MoveObject& playere, Object& Water)
	{
		Player& playe = static_cast<Player&>(playere);
		playe.returnlocation();
		playe.setDirection(sf::Vector2f(0, 0));
		playe.setGraphics(fire);
		playe.NotifyObserversdaves();
	}

	void playerBlueDiamond(MoveObject& player, Object& BlueDiamond)
	{
		Player& playe = static_cast<Player&>(player);
		BlueDiamond.removeObject();
		playe.NotifyObserversscores();
	}

	void playerRedDiamond(MoveObject& player, Object& RedDiamond)
	{
		Player& playe = static_cast<Player&>(player);
		RedDiamond.removeObject();
		playe.NotifyObserversdavesplus();
	}

	void playerElevator(MoveObject& player, Object& Elevator)
	{
		std::cout << "player and Elevator collision!" << std::endl;
	}

	void playerGun(MoveObject& player, Object& Gan)
	{
		Gan.removeObject();
		Player& playe = static_cast<Player&>(player);
		playe.gunUpdate(true);
	}

	void playerKey(MoveObject& player, Object& key)
	{
		key.removeObject();
		Player& playe = static_cast<Player&>(player);
		playe.keyUpdate(true);
	}
	void playerWall(MoveObject& player, Object& wall)
	{
		if (((player.getLocation().y + LENGTHOFCELLPLAYER) - wall.getLocation().y) < LENGTHOFCELLPLAYER)
		{
			if (wall.getLocation().x - (player.getLocation().x - WIDTHOFCELLPLAYER) < 1 || (player.getLocation().x + WIDTHOFCELLPLAYER) - wall.getLocation().x < 1)
			{
				//player.returnlocation();
				player.handleInput(sf::Keyboard::Down);
			}
			else
			{
				player.returnlocation();
				player.handleInput(sf::Keyboard::Space);
			}
		}
		else
		{
			player.returnlocation();
			player.handleInput(sf::Keyboard::Down);
		}
	}
	void playerPipe(MoveObject& player, Object& pipe)
	{
		if ((player.getLocation().x - WIDTHOFCELLPLAYER) - pipe.getLocation().x > LENGTHOFCELLPLAYER)
		{
			player.handleInput(sf::Keyboard::Down);
		}
		player.returnlocation();
		player.handleInput(sf::Keyboard::Space);
	}

	void playerDoor(MoveObject& player, Object& Door)
	{
		Player& playe = static_cast<Player&>(player);
		playe.setDirection(sf::Vector2f(0, 0));
		if (playe.getTheKey())
			playe.doorUpdate(true);
	}

	void playerMonster(MoveObject& player, Object& monster)
	{
		Player& playe = static_cast<Player&>(player);
		Monster& mon = static_cast<Monster&>(monster);
		playe.returnlocation();
		playe.setDirection(sf::Vector2f(0, 0));
		playe.setGraphics(fire);
		playe.NotifyObserversdaves();
	}

	void monsterShots(MoveObject& monster, Object& Shots)
	{
		monster.setGraphics(fire);
		monster.removeObject();
		Shots.removeObject();
		monster.setDirection(sf::Vector2f(0,0));
	}
	void monsterwall(MoveObject& monster, Object& wall)
	{
		Monster& mon = static_cast<Monster&>(monster);
				 if (mon.getLocation().x + LENGTHOFCELL > wall.getLocation().x || wall.getLocation().x + LENGTHOFCELL > mon.getLocation().x )
				 {
					 //std::cout << "monster and wall collision!" << std::endl;
					 mon.returnlocation();
					 mon.setDirection(sf::Vector2f((-1) * mon.getDirection().x, 0));
				 }
	}
	void shotsWall(MoveObject& Shots, Object& Wall)
	{
		Shots.removeObject();
		std::cout << "Shots and Wall collision!" << std::endl;
	}

	void shotsPipe(MoveObject& Shots, Object& pipe)
	{
		Shots.removeObject();
		std::cout << "Shots and pipe collision!" << std::endl;
	}

	using HitFunctionPtr = void (*)(MoveObject&, Object&);
	using Kay = std::pair<std::type_index, std::type_index>;
	using HitMap = std::map<Kay, HitFunctionPtr>;

	HitMap initializeCollisionMap()
	{
		HitMap phm;
		phm[Kay(typeid(Player), typeid(AddLives))] = &playerRedDiamond;
		phm[Kay(typeid(Player), typeid(AddScore))] = &playerBlueDiamond;
		phm[Kay(typeid(Player), typeid(Door))] = &playerDoor;
		phm[Kay(typeid(Player), typeid(Elevator))] = &playerElevator;
		phm[Kay(typeid(Player), typeid(Fire))] = &playerFire;
		phm[Kay(typeid(Player), typeid(Gun))] = &playerGun;
		phm[Kay(typeid(Player), typeid(Key))] = &playerKey;
		phm[Kay(typeid(Player), typeid(Monster))] = &playerMonster;
		phm[Kay(typeid(Player), typeid(Pipe))] = &playerPipe;
		phm[Kay(typeid(Player), typeid(Shots))] = &playerShots;
		phm[Kay(typeid(Player), typeid(Wall))] = &playerWall;
		phm[Kay(typeid(Player), typeid(Water))] = &playerWater;
		phm[Kay(typeid(Shots), typeid(Wall))] = &shotsWall;
		phm[Kay(typeid(Shots), typeid(Pipe))] = &shotsPipe;
		//phm[Key(typeid(Monster), typeid(Player))] = &monsterPlayer;
		phm[Kay(typeid(Monster), typeid(Shots))] = &monsterShots;
		phm[Kay(typeid(Monster), typeid(Wall))] = &monsterwall;
		return phm;
	}


	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
	{
		static HitMap collisionMap = initializeCollisionMap();
		auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
		if (mapEntry == collisionMap.end())
		{
			return nullptr;
		}
		return mapEntry->second;
	}
}
void processCollision(MoveObject& object1, Object& object2)
{
	auto phf = lookup(typeid(object1), typeid(object2));
	//if (!phf)
	//{
	   // throw UnknownCollision(object1, object2);
	//}
	if (phf != nullptr)
		phf(object1, object2);
}
