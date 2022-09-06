#pragma once

#include <SFML/Graphics.hpp>

//const int RATE = 150;
const int LENGTHOFINFOVIEW = 50;
const int LENGTH =550;
const int WIDTH = 950;
const int LIVES = 3;
const int NUMOFROWS = 10;
const int NUMOFCOLS = 19;
const float WIDTHOFCELL = WIDTH / NUMOFCOLS;
const float LENGTHOFCELL = (LENGTH - LENGTHOFINFOVIEW) / NUMOFROWS;
const int WIDTHOFSHOTS = WIDTHOFCELL;// / 3;
const int LENGTHOFSHOTS = LENGTHOFCELL;
const int PLAYERSPEED = 250;
const float WIDTHOFCELLPLAYER = WIDTHOFCELL - 15;
const int RATEOFSHOTS = 80;
const float TIMESHOTSf = 2.9;
const float LENGTHOFCELLPLAYER = LENGTHOFCELL - 15;
const int MONSTERSPEED = 150;
const int SHOTSSPEED = 250;


//const auto AnimationTime = sf::seconds(0.3f);
//const int APPROXIMATION = 10;
//const float EPSILON = 0.005;
//const int SIZEOFOBJECT = 6;
//const float WIDTHOFMENU = 133;

enum  typeOfObject
{
BlueDiamond,
Crown,
door,
explosion,
fire,
key,
Live,
pipe,
PlayerFalls,
player,
PlayerGo,
PlayerJump,
PlayerStend,
PurpleFire1,
PurpleFire2,
PurpleFire3,
PurpleFire4,
RedDiamond,
RedWall,
SmallWater,
OpenScreen,
GameOver,
YouWin,
help1,
help2,
help3,
monster,
shots,
gun,
dave,
};
//enum  typeOfPresent
/*{
};*/
//enum  typeOfMonster
/*{
};*/
/*enum  direction
{
	up,
	doun,
	right,
	left,
};*/
//const auto DIAMOND = 'D';
//const auto MONSTER = '!';
//const auto DIGGER = '/';
//const auto STONE = '@';
//const auto WALL = '#';
//const auto SPACE = ' ';
//const auto PRESENT = '+';
enum Input
{
	PRESS_UP,
	PRESS_RIGHT,
	PRESS_LEFT,
	ALT,
	FALL,
};
enum Objects
{
	RedGhost,
	Pacman,
	Max,
};