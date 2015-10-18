/*
 * Fighter.cpp
 *
 *  Created on: Jan 22, 2015
 *      Author: bryce14
 */

#include "Fighter.h"

Fighter::Fighter(string fighter_name_in, int hitpoints_in, int strength_in, int speed_in, int magic_in, int CurrentHP) {
	name = fighter_name_in;
	MaxHP = hitpoints_in;
	MaxStrength = strength_in;
	Speed = speed_in;
	MaxMagic = magic_in;

	// TODO Auto-generated constructor stub

}

Fighter::~Fighter() {
	// TODO Auto-generated destructor stub
}

string Fighter::getName() {
	return name;
}

int Fighter::getMaximumHP() {
	return MaxHP;
}

int Fighter::getCurrentHP() {
	return CurrentHP;
}

int Fighter::getStrength() {
	return MaxStrength;
}

int Fighter::getSpeed() {
	return Speed;
}

int Fighter::getMagic() {
	return MaxMagic;
}

void Fighter::takeDamage(int damage) {
	int temp_damage = (damage - (Speed / 4));
	if (temp_damage < 1) {
		CurrentHP -= 1;
	}
	else
	{
		CurrentHP = CurrentHP - temp_damage;
	}
}

void Fighter::regenerate() {
		int regeneration = (MaxStrength / 6);
		if (regeneration >= 1) {
			CurrentHP += regeneration;
		} else {
			CurrentHP++;
		}
		if (CurrentHP > MaxHP) {
			CurrentHP = MaxHP;
		}
}


