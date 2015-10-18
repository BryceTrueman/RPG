/*
 * Arena.h
 *
 *  Created on: Jan 22, 2015
 *      Author: bryce14
 */

#ifndef ARENA_H_
#define ARENA_H_

#include "ArenaInterface.h"
#include <sstream>
#include "Fighter.h"

class Arena: public ArenaInterface {
public:
	Arena();
	virtual ~Arena();
	bool addFighter(string info);
	bool removeFighter(string name);
	string getName();
	FighterInterface* getFighter(string name);
	int getSize();
protected:
	vector<FighterInterface*> fighters;
	string name;
	string info;
};

#endif /* ARENA_H_ */

