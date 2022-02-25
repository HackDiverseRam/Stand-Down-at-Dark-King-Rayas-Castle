//Programmer Ramon Barea
// 5/17/2021
// Final Project, Stand Off at Dark King Raya's Castle, castle class

#ifndef CASTLE_H
#define CASTLE_H

#include <iostream>
using namespace std;

/*
the treasure will be hidden in one of the rooms in a castle
create a castle class, in a file named castle.h, that will:
have these variables:
at least four rooms named room1, room2, etc.
moat (which is a lagoon surrounding a castle) which boolean (not all castles have them)
anything else you want to add

create a default constructor for each class that initializes each argument to a blank or false value
create a second constructor for each class that assigns arguments passed to it to these variables
create the appropriate mutator functions for each class
create the appropriate accessor functions for each class
*/

class castle
{
private:
	string room1;
	string room2;
	string room3;
	string room4;
	bool moat;

public:
	castle() {
		room1 = " ";
		room2 = " ";
		room3 = " ";
		room4 = " ";
		moat = false;
	}

	castle(string r1, string r2, string r3, string r4, bool m) {
		room1 = r1;
		room2 = r2;
		room3 = r3;
		room4 = r4;
		moat = m;
	}

	void setRoom1(string r1) { room1 = r1; }
	void setRoom2(string r2) { room2 = r2; }
	void setRoom3(string r3) { room3 = r3; }
	void setRoom4(string r4) { room4 = r4; }
	void setMoat(bool m) { moat = m; }

	string getRoom1() { return room1; }
	string getRoom2() { return room2; }
	string getRoom3() { return room3; }
	string getRoom4() { return room4; }
	bool getMoat() { return moat; }

};

#endif // !CASTLE_H