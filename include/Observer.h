#pragma once
#include"Const.h"
class Observer
{
	
public:
	Observer();
	virtual ~Observer()= default;
	virtual void keyUpdate(bool key) ;
	virtual void doorUpdate(bool door);
	virtual void gunUpdate(bool gun);
	void davesUpdate();
	void levelUpdate();
	void scoresUpdate();
	void UpdatedavesPlus();
protected:
	bool m_key;
	bool m_door;
	bool m_gun;
	int m_scores;
	int m_daves;
	int m_levels;
};