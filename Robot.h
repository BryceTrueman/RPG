/*
 * Robot.h
 *
 *  Created on: Jan 22, 2015
 *      Author: bryce14
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include "Fighter.h"
#include<cmath>

class Robot: public Fighter {
public:
	Robot(string, int, int, int, int);
	virtual ~Robot();
	void reset();
	bool useAbility();
	int getDamage();
private:
	int max_energy = (MaxMagic * 2);
	int current_energy;
	int bonus_damage = 0;
};

#endif /* ROBOT_H_ */
