/*
 * Archer.h
 *
 *  Created on: Jan 22, 2015
 *      Author: bryce14
 */

#ifndef ARCHER_H_
#define ARCHER_H_

#include "Fighter.h"


class Archer: public Fighter {
public:
	Archer(string, int, int, int, int);
	virtual ~Archer();
	void reset();
	bool useAbility();
	int getDamage();
	//int getSpeed();
private:
	int MaxSpeed;
};

#endif /* ARCHER_H_ */
