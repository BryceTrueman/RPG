/*
 * Robot.cpp
 *
 *  Created on: Jan 22, 2015
 *      Author: bryce14
 */

#include "Robot.h"

Robot::Robot(string fighter_name_in, int hitpoints_in, int strength_in,
		int speed_in, int magic_in) :
		Fighter(fighter_name_in, hitpoints_in, strength_in, speed_in, magic_in,
				CurrentHP) {
	name = fighter_name_in;
	MaxHP = hitpoints_in;
	MaxStrength = strength_in;
	MaxMagic = magic_in;

	// TODO Auto-generated constructor stub

}

Robot::~Robot() {
	// TODO Auto-generated destructor stub
}

void Robot::reset() {
	CurrentHP = MaxHP;
	current_energy = max_energy;
}

int Robot::getDamage() {
	damage = MaxStrength + bonus_damage;
	bonus_damage = 0;
	return damage;
}

/*
Robot: Shockwave Punch
		 *	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
		 *	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
		 *	Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
		 *		Examples:
		 *		strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
		 *		strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
		 *		strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
		 *		strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
		 *	Robot Note:
		 *	The bonus damage formula should be computed using double arithmetic, and only
		 *	the final result should be cast into an integer.
		 *	//((double) current energy)*/

bool Robot::useAbility() {
	if (current_energy >= ROBOT_ABILITY_COST) {
		bonus_damage = MaxStrength * (((double)current_energy) / max_energy)*(((double)current_energy) / max_energy)*(((double)current_energy) / max_energy)*(((double)current_energy) / max_energy);
		current_energy -= ROBOT_ABILITY_COST;
		return true;
	} else {
		return false;
	}
}


