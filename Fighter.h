/*
 * Fighter.h
 *
 *  Created on: Jan 22, 2015
 *      Author: bryce14
 */

#ifndef FIGHTER_H_
#define FIGHTER_H_

#include "FighterInterface.h"

class Fighter: public FighterInterface {
public:
	Fighter(string fighter_name_in, int hitpoints_in, int strength_in, int speed_in, int magic_in, int CurrentHP);
	virtual ~Fighter();
	string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getSpeed();
	int getMagic();
	virtual void regenerate();
	virtual void reset() = 0;
	virtual int getDamage() = 0;
	virtual void takeDamage(int damage_taken);
protected:
	string name;
	int MaxHP;
	int MaxStrength;
	int Speed;
	int MaxMagic;
	int CurrentHP;
	int damage;

};

#endif /* FIGHTER_H_ */
