/*
 * Arena.cpp
 *
 *  Created on: Jan 22, 2015
 *      Author: bryce14
 */

#include "Arena.h"
#include "Fighter.h"
#include "Archer.h"
#include "Robot.h"
#include "Cleric.h"
#include <vector>

Arena::Arena() {
	// TODO Auto-generated constructor stub
	int speed = speed;
}

Arena::~Arena() {
	// TODO Auto-generated destructor stub
}

int Arena::getSize() {
	return fighters.size();
}

string Arena::getName() {
	return name;
}

FighterInterface* Arena::getFighter(string name) {
	for (int i = 0; i < fighters.size(); i++) {
		if (fighters[i]->getName() == name) {
			return fighters[i];
		}
	}
	return NULL;
}

bool Arena::removeFighter(string name) {
	bool removed = false;
	for (int i = 0; i < fighters.size(); i++) {
		if (fighters[i]->getName() == name) {
			fighters.erase(fighters.begin() + i);
			removed = true;
		}
	}
	return removed;
}

bool Arena::addFighter(string info) {
	string fighter_object;
	string fighter_name;
	string fighter_type;
	int hitpoints = 0;
	int strength = 0;
	int speed = 0;
	int magic = 0;
	stringstream ss;
	ss << info;
	if (ss >> fighter_name >> fighter_type >> hitpoints >> strength >> speed
			>> magic) {
		if (!ss.fail() && ss.eof()) {
			if (getFighter(fighter_name) == NULL) {
				if (fighter_type == "A") {
					if (hitpoints > 0) {
						if (strength > 0) {
							if (speed > 0) {
								if (magic > 0) {
									Fighter* bob = new Archer(fighter_name,
											hitpoints, strength,
											speed, magic);
									fighters.push_back(bob);
									return true;
								}
							}
						}
					}
				} else if (fighter_type == "R") {
					if (hitpoints > 0) {
						if (strength > 0) {
							if (speed > 0) {
								if (magic > 0) {
									Fighter* bob = new Robot(fighter_name,
											 hitpoints, strength,
											speed, magic);
									fighters.push_back(bob);
									return true;
								}
							}
						}
					}
				} else if (fighter_type == "C") {
					if (hitpoints > 0) {
						if (strength > 0) {
							if (speed > 0) {
								if (magic > 0) {
									Fighter* bob = new Cleric(fighter_name,
											hitpoints, strength,
											speed, magic);
									fighters.push_back(bob);
									return true;
								}
							}
						}
					}
				}
			}
		}
	} else {
		return false;
	}
	return false;
}


