/*
 * Archer.cpp
 *
 *  Created on: Jan 22, 2015
 *      Author: bryce14
 */

#include "Archer.h"

Archer::Archer(string fighter_name_in, int hitpoints_in, int strength_in, int speed_in, int magic_in)
: Fighter(fighter_name_in, hitpoints_in, strength_in, speed_in, magic_in, CurrentHP){
	name = fighter_name_in;
	MaxHP = hitpoints_in;
	MaxStrength = strength_in;
	MaxMagic = magic_in;
	MaxSpeed = speed_in;

	// TODO Auto-generated constructor stub
}



Archer::~Archer() {
	// TODO Auto-generated destructor stub
}



void Archer::reset() {
	CurrentHP = MaxHP;
	Speed = MaxSpeed;
}

int Archer::getDamage() {
	damage = Speed;
	return damage;
}

/*Archer: Quickstep
		 *	Increases the Archer's speed by one point each time the ability is used.
		 *	This bonus lasts until the reset() method is used.
		 *	This ability always works; there is no maximum bonus speed.
		 *	*/
bool Archer::useAbility() {
	Speed++;
	return true;
}

/*
int Archer::getSpeed() {//make this better!!!#^%^%^#^*&
	int temp_speed = 5;
	return temp_speed;
}
*/
