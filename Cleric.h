/*
 * Cleric.h
 *
 *  Created on: Jan 22, 2015
 *      Author: bryce14
 */

#ifndef CLERIC_H_
#define CLERIC_H_

#include "Fighter.h"

class Cleric: public Fighter {
public:
	Cleric(string, int, int, int, int);
	virtual ~Cleric();
	void reset();
	void regenerate();
	bool useAbility();
	int getDamage();
private:
	int max_mana;
	int current_mana;

};

#endif /* CLERIC_H_ */
