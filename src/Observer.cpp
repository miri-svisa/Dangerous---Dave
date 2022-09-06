#include "Observer.h"

Observer::Observer():m_key(false),m_door(false), m_gun(false), m_scores(0), m_daves(LIVES), m_levels(1)
{}
//-----------------------------------
void Observer::keyUpdate(bool key)
{
	m_key = key;
}
//-----------------------------------------
void Observer::doorUpdate(bool door)
{
	m_door = door;
}
//-----------------------------------------
void Observer::gunUpdate(bool gun)
{
	m_gun = gun;
}
//-----------------------------------------
void Observer::davesUpdate()
{
	m_gun = false;
	m_key = false;
	m_daves--;
}
//--------------------------------------------
void Observer::levelUpdate()
{
	m_levels++;
}
//----------------------------------------
void Observer::scoresUpdate()
{
	m_scores += 50;
}
//--------------------------------------
void Observer::UpdatedavesPlus()
{
	m_daves++;
}
