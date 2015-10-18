/*
 * Cleric.cpp
 *
 *  Created on: Jan 22, 2015
 *      Author: bryce14
 */

#include "Cleric.h"
#include <iostream>

Cleric::Cleric(string fighter_name_in, int hitpoints_in, int strength_in,
		int speed_in, int magic_in) :
		Fighter(fighter_name_in, hitpoints_in, strength_in, speed_in, magic_in,
				CurrentHP) {
	name = fighter_name_in;
	MaxHP = hitpoints_in;
	MaxStrength = strength_in;
	MaxMagic = magic_in;
	max_mana = (MaxMagic * 5);
	current_mana = max_mana;

	// TODO Auto-generated constructor stub

}

Cleric::~Cleric() {
	// TODO Auto-generated destructor stub
}

void Cleric::reset() {
	CurrentHP = MaxHP;
	current_mana = max_mana; //max mana = 5*magic
}

void Cleric::regenerate() {
	Fighter::regenerate();
	int mana_regen = (MaxMagic / 5);
	if (mana_regen >= 1) {
		current_mana += mana_regen;
	} else {
		current_mana++;
	}
	if (current_mana > max_mana) {
		current_mana = max_mana;
	}
}

int Cleric::getDamage() {
	damage = MaxMagic;
	return damage;
}

/*Cleric: Healing Light
		 *	Increases the Cleric's current hit points by an amount equal to one third of its magic.
		 *	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
		 *	Will be used even if the Cleric's current HP is equal to their maximum HP.
		 *	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
		 *	Cleric Note:
		 *	This ability, when successful, must increase the Cleric's current hit points
		 *	by at least one.  Do not allow the current hit points to exceed the maximum
		 *	hit points.
		 *
		 *	Return true if the ability was used; false otherwise.
		 *	*/
bool Cleric::useAbility() {
	int cleric_regen = MaxMagic / 3;
	if (current_mana >= CLERIC_ABILITY_COST) {
		current_mana -= CLERIC_ABILITY_COST;
		if ((CurrentHP + cleric_regen) > MaxHP) {
			CurrentHP = MaxHP;
			return true;
		}
		if (cleric_regen >= 1) {
			CurrentHP += cleric_regen;
			return true;
		}
		else {
			CurrentHP++;
			return true;
		}
	} else {
		return false;
	}
}

