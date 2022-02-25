//Programmer Ramon Barea
// 5/17/2021
// Final Project, Stand Off at Dark King Raya's Castle, character class

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
using namespace std;


/*
create a character class, in a file named character.h, which will:
have the following variables:
name
race (chosen from a list that you create, like knight, wizard, elf, etc.)
weapon (chosen from a list that you create)
spells (true meaning has the power to cast spells on others)
anything else you want to add

create a default constructor for each class that initializes each argument to a blank or false value
create a second constructor for each class that assigns arguments passed to it to these variables
create the appropriate mutator functions for each class
create the appropriate accessor functions for each class
*/
class character
{
private:
	string name;
	string race;
	string weapon;
	string spells;
	int level;

public:
	character() {
		name = " ";
		race = " ";
		weapon = " ";
		spells = " ";
		level = 0;
	}
	character(string n, string r, string w, string s, int l) {
		name = n;
		race = r;
		weapon = w;
		spells = s;
		level = l;
	}
	void setName(string n) { name = n; }
	void setRace(string r) { race = r; }
	void setWeapon(string w) { weapon = w; }
	void setSpells(string s) { spells = s; }
	void setLevel(int l) { level = l; }

	string getName() { return name; }
	string getRace() { return race; }
	string getWeapon() { return weapon; }
	string getSpells() { return spells; }
	int getLevel() { return level; }
};

#endif // !CHARACTER_H
