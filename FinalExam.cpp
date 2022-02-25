 //Programmer Ramon Barea
// 5/17/2021
// Final Project, Stand Off at Dark King Raya's Castle, Main

#include <iostream>
#include <string>
#include <ctime>
#include "castle.h"
#include "character.h"
using namespace std;

void ChoiceVerification(char& choice);// Used all over the code to verify the users choice
void ChangeCharacter(character& CurrentChanges);//allows for changes of the character design, created to reduce the size of main
void ChangeCastle(castle& currentCahnges);// allows for changes of castle design, created to reduce size of main
void introStory();// an introductory story 
void chosenCharacter(int diceNumber, character& Gaurdian);// recieves dice rolls and creates the dark kings gaurdians
int DiceRoll(int minValue, int maxValue);// will be the randomizer source for dies
int castleEntranceQuiz();// runs the gaurdians questions
int TreasureRoomEntranceQuiz(character& TreasureGaurdian);
int endingStory(int, int, character& UserCharacter ); // a twist ending
string chosenRoom(int diceRoll, castle& treasureSetUp);// recieved Dice Rolls and returns set treasure room

int main()
{
	castle DarkKingRayaCastle{ "Main Hall", "The Dungeon", "Hidden Room", "Treasure Room", true };
	character Partner("Kronk The Brave", "Berserker", "Divine Axe of the chaos flame", "Physical Enhancement", 80);
	character UserCharacter;
	character theTraveler("Hisoka the Mysterious", "Wizard", "Twin Blades", "Unknown", 100);
	character TreasureGaurdian;// will hold the result of the dice roll
	character OutsideGaurdian;// this will hold a result of the dice roll but will not be the same as the treasure gaurdian

	// these strings are used to update character info but were initialized with the main character to show mutator functionality
	string name = "Diana of the Sacred Forest";
	string race = "Elf";
	string weapon = "Blessed Elvin Dagger";
	string spells = "World Tree magic";
	string treasureRoom; // will hold the result of the dice roll

	char choice = 'Y';// the choice variable for every letter decision in the game, including the main while loop
	unsigned seed = time(0);// randimzer necessity
	srand(seed);// randomizer necessity

	int level = 65;
	int acceptedRoll1 = DiceRoll(1, 4);// to hold the value for the castles random room
	int acceptedRoll2 = DiceRoll(1, 4);// to hold the value for the gaurdian of the treasure
	int acceptedRoll3 = DiceRoll(1, 4);// to hold the value for the gaurdian standing outside
	int gameOver; // used throughout code to end the game when needed, wasn't sure how diverse this would be from the start so made an int
	// not a bool incase I wanted to do some form of second chance option

	UserCharacter.setName(name);
	UserCharacter.setRace(race);
	UserCharacter.setWeapon(weapon);
	UserCharacter.setSpells(spells);
	UserCharacter.setLevel(level);
	
	introStory();

	while (toupper(choice) == 'Y')
	{

		cout << "\n\nThis game is from the perspective of " << UserCharacter.getName() << "\nRace: " << UserCharacter.getRace()
			<< "\nWeapon: " << UserCharacter.getWeapon() << "\nSpells: " << UserCharacter.getSpells()
			<< "\nLevel: " << UserCharacter.getLevel() << endl
			<< "\nDo you wish to change any information ? Enter Y if yes or N if no" << endl;
		cin >> choice;
		ChoiceVerification(choice);

		if (choice == 'Y' || choice == 'y') {
			ChangeCharacter(UserCharacter);
		}

		cout << "\nYour Partner is currently named " << Partner.getName() << "\nRace: " << Partner.getRace()
			<< "\nWeapon: " << Partner.getWeapon() << "\nSpells: " << Partner.getSpells() << "\nLevel: " << Partner.getLevel()
			<< "\nDo you wish to change any information ? Enter Y if yes or N if no" << endl;
		cin >> choice;
		ChoiceVerification(choice);

		if (choice == 'Y' || choice == 'y') {
			ChangeCharacter(UserCharacter);
		}
		cout << "\nDark King Raya's Castle's data is as followed. \nRoom 1: " << DarkKingRayaCastle.getRoom1() << "\nRoom 2" << DarkKingRayaCastle.getRoom2()
			<< "\nRoom 3: " << DarkKingRayaCastle.getRoom3() << "\nRoom 4: " << DarkKingRayaCastle.getRoom4() << "\nMoat?: " << DarkKingRayaCastle.getMoat()
			<< endl << "Do you wish to change any information ? Enter Y if yes or N if no" << endl;
		cin >> choice;
		ChoiceVerification(choice);

		if (choice == 'Y' || choice == 'y') {
			ChangeCastle(DarkKingRayaCastle);
		}

		cout << "\n**************************************************\n"
			<< "\nHisoka's Mysterious ways are beyond human control...\n"
			<< "\nRace: " << theTraveler.getRace() << "\nWeapons:" << theTraveler.getWeapon()
			<< "\nSpells: " << theTraveler.getSpells() << "\nlevel: " << theTraveler.getLevel() << endl << endl;
		system("PAUSE"); // paused for dramatic effect and to cout things properly since there are so many words

		cout << "\nTwo dice rolls will now be attempted...\nYour numbers are: " << acceptedRoll1 << " and " << acceptedRoll2 << endl;
		treasureRoom = chosenRoom(acceptedRoll1, DarkKingRayaCastle);
		chosenCharacter(acceptedRoll2, TreasureGaurdian);


		if (acceptedRoll3 != acceptedRoll2) { chosenCharacter(acceptedRoll3, OutsideGaurdian); }// This makes sure that the gaurdians aren't the same person
		else if (acceptedRoll3 == acceptedRoll2) { // by default If the servant isn't in the treasure room then hes outside if the dice rolls match
			if (acceptedRoll2 != 1)// else, if they do match but the servant is in the room then the unholy knight is outside
			{
				acceptedRoll3 = 1;
			}
			else { acceptedRoll3 = 2; }
			chosenCharacter(acceptedRoll3, OutsideGaurdian);
		}

		cout << "The treasure is in " << treasureRoom << ", gaurded by " << TreasureGaurdian.getName()
			<< "\nRace: " << TreasureGaurdian.getRace() << "\nWeapon: " << TreasureGaurdian.getWeapon()
			<< "\nSpell: " << TreasureGaurdian.getSpells() << endl
			<< "\nBEWARE, he is level " << TreasureGaurdian.getLevel() << "!" << endl;

		if (DarkKingRayaCastle.getMoat() != 0) {
			cout << "\nThis castle has a moat" << endl
				<< "Suddenly, upon crossing the moat to the castle a trap triggered \na magic circle beneath hisoka swallows him whole as he cries for help"
				<< endl << "The now frightened travelers decide to keep going, they can't stop now" << endl << endl;
		}
		else {
			cout << "\nThis castle does not have a moat" << endl
				<< "Suddenly, upon getting to close to the castle a trap triggered \na magic circle beneath hisoka swallows him whole as he cries for help"
				<< endl << "The now frightened travelers decide to keep going, they can't stop now" << endl << endl;

		}
		cout << "There's a gaurdian outside of the castle... \n\nit's " << OutsideGaurdian.getName() << "!" << endl
			<< "\nRace: " << OutsideGaurdian.getRace() << "\nWeapon: " << OutsideGaurdian.getWeapon()
			<< "\nSpell: " << OutsideGaurdian.getSpells() << endl
			<< "\nBEWARE, his current level is " << OutsideGaurdian.getLevel() << endl;
		system("PAUSE");
		cout << "\n****************************************************************\n\n";

		gameOver = castleEntranceQuiz();
		if (gameOver != 1) {

			gameOver = TreasureRoomEntranceQuiz(TreasureGaurdian);
		}
		if (gameOver != 1) {

			gameOver = endingStory(acceptedRoll2, acceptedRoll3, UserCharacter);
		}
		if (gameOver != 1) {

			cout << "\n**********************************\n"
				<< "You pay respects to your fallen friend and head back to the guild" << endl << endl;
		}

		cout << "Play Again? Y for Yes, N for No" << endl;
		cin >> choice;
		ChoiceVerification(choice);
	}
	
	cout << "Thanks for playing Stand Off at Dark King Raya's Castle! \n" 
		<< UserCharacter.getName() << ", " << Partner.getName() << " and " << theTraveler.getName() 
		<< "\nsend their regards :)" << endl;
	return 0;
}

void ChoiceVerification(char &choice) {
	while (choice != 'y' && choice != 'Y' && choice != 'N' && choice != 'n')
	{
		cout << "Invalid Entry please enter Y for yes or n for no" << endl;
		cin >> choice;
	}
}
void ChangeCharacter(character& CurrentChanges) {
	string name = "Diana of the Sacred Forest";
	string race = "Elf";
	string weapon = "Blessed Elvin Dagger";
	string spells = "World Tree magic";
	int level = 65;
	char choice;
	
	
		cout
			<< "\n**************************************************************\n"
			<< "All Answers of character editing must be answers with Y for Yes or N for No" << endl
			<< "Do you wish to change the name?" << endl;
		cin >> choice;
		ChoiceVerification(choice);

		if ((choice == 'Y' || choice == 'y')) {
			cin.ignore();
			cout << "Enter the new name" << endl;
			getline(cin, name);
			CurrentChanges.setName(name);
			cout << "The name has been changed!" << endl << endl;
		}

		cout << "Do You wish to change the race? " << endl;
		cin >> choice;
		ChoiceVerification(choice);

		if ((choice == 'Y' || choice == 'y')) {
			cin.ignore();
			cout << "Enter the new race" << endl;
			getline(cin, race);
			CurrentChanges.setRace(race);
			cout << "The race has been changed!" << endl << endl;
		}
		cout << "Do You wish to change the weapon? " << endl;
		cin >> choice;
		ChoiceVerification(choice);

		if ((choice == 'Y' || choice == 'y')) {
			cin.ignore();
			cout << "Enter the new weapon" << endl;
			getline(cin, weapon);
			CurrentChanges.setWeapon(weapon);
			cout << "The weapon has been changed!" << endl << endl;
		}
		cout << "Do You wish to change the Spells? " << endl;
		cin >> choice;
		ChoiceVerification(choice);

		if ((choice == 'Y' || choice == 'y')) {
			cin.ignore();
			cout << "Enter the new spells" << endl;
			getline(cin, spells);
			CurrentChanges.setSpells(spells);
			cout << "The spells has been changed!" << endl << endl;
		}
		cout << "Do You wish to change the level? " << endl;
		cin >> choice;
		ChoiceVerification(choice);

		if ((choice == 'Y' || choice == 'y')) {
			cout << "Enter the new level, must be a number between 1 and 90" << endl;
			cin >> level;

				if (cin >> level) {
					while (level <= 0 || level > 90)
					{
						cout << "Levels must be between 1 and 90, your not a master in your class yet, please try again" << endl;
						cin >> level;
					}
					CurrentChanges.setLevel(level);
					cout << "The level has been changed!" << endl << endl;
				}
				else if (!cin.eof()) {
					cin.clear();
					cout << "Value entered must be a number... the default level will be used..." << endl;
					cin.ignore();
				}

			
			
		}

}
void ChangeCastle(castle& CurrentChanges) {
	string room1;
	string room2;
	string room3;
	string room4;
	bool moat;
	char choice;

	cout
		<< "\n**************************************************************\n"
		<< "All Answers of castling editing must be answers with Y for Yes or N for No" << endl
		<< "Do you wish to change room 1?" << endl;
	cin >> choice;
	ChoiceVerification(choice);

	if ((choice == 'Y' || choice == 'y')) {
		cin.ignore();
		cout << "Enter the new name" << endl;
		getline(cin, room1);
		CurrentChanges.setRoom1(room1);
		cout << "The name has been changed!" << endl << endl;
	}

	cout << "Do you wish to change room 2?" << endl;
	cin >> choice;
	ChoiceVerification(choice);

	if ((choice == 'Y' || choice == 'y')) {
		cin.ignore();
		cout << "Enter the new name" << endl;
		getline(cin, room2);
		CurrentChanges.setRoom1(room2);
		cout << "The name has been changed!" << endl << endl;
	}

	cout << "Do you wish to change room 3?" << endl;
	cin >> choice;
	ChoiceVerification(choice);

	if ((choice == 'Y' || choice == 'y')) {
		cin.ignore();
		cout << "Enter the new name" << endl;
		getline(cin, room3);
		CurrentChanges.setRoom1(room3);
		cout << "The name has been changed!" << endl << endl;
	}
	cout << "Do you wish to change room 4?" << endl;
	cin >> choice;
	ChoiceVerification(choice);

	if ((choice == 'Y' || choice == 'y')) {
		cin.ignore();
		cout << "Enter the new name" << endl;
		getline(cin, room4);
		CurrentChanges.setRoom1(room4);
		cout << "The name has been changed!" << endl << endl;
	}

	cout << "Do you wish to add/remove the moat?" << endl;
	cin >> choice;
	ChoiceVerification(choice);

	if ((choice == 'Y' || choice == 'y')) {
		cout << "Is there a moat? Y for yes N for No" << endl;
		cin >> choice;
		ChoiceVerification(choice);

		if ((choice == 'Y' || choice == 'y')) {
			moat = true;
		}
		else { moat = false; }

		CurrentChanges.setMoat(moat);
		cout << "The moat setting has been changed!" << endl << endl;
	}

}
void chosenCharacter(int diceNumber, character& Gaurdian) {
	if (diceNumber == 1) {
		Gaurdian.setName("Dark Kings Servant");
		Gaurdian.setRace("Demon");
		Gaurdian.setWeapon("Long Sword");
		Gaurdian.setSpells("HellFire");
		Gaurdian.setLevel(70);
	}
	else if (diceNumber == 2) {
		Gaurdian.setName("Dark Kings UnHoly Knight");
		Gaurdian.setRace("Demon Warrior");
		Gaurdian.setWeapon("Broad Sword");
		Gaurdian.setSpells("Dark Lightning Sword Enhancement");
		Gaurdian.setLevel(80);
	}
	else if (diceNumber == 3) {
		Gaurdian.setName("Dark Kings talking dragon");
		Gaurdian.setRace("Dragon");
		Gaurdian.setWeapon("Claws and Teeth");
		Gaurdian.setSpells("Flame Breath");
		Gaurdian.setLevel(90);
	}
	else if (diceNumber == 4) {
		Gaurdian.setName("Dark Kings Jester");
		Gaurdian.setRace("Wizard");
		Gaurdian.setWeapon("Twin Swords");
		Gaurdian.setSpells("Misdirection Magic");
		Gaurdian.setLevel(100);
	}
}
void introStory() {
	cout << "Welcome! You have a chance to gain a fortune that most races would betray each other over..." << endl
		<< "Some would assume it was merely gold but in a world of magic and possibilty this legendary treasure " << endl
		<< "could set you above the rest!" << endl
		<< "\n\nTwo well known adventurers are at a guild where overhear another group who failed their quest..." << endl
		<< "They talked about how their crew all lacked the power level and the c++ knowledge to invade Dark King Raya's castle." << endl
		<< "A traveler approached them, Hisoka was his name, the man had a mysterious aura but was clearly powerful" << endl
		<< "\n\nHe offers an alliance for he also wants to see what this fabled treasure is about" << endl
		<< "The Adventurers went on their way........"
		<< "\n**************************************************\n";
}
int DiceRoll(int minValue, int maxValue) {//random number engine
	return (rand() % (maxValue - minValue + 1)) + minValue;
}
int castleEntranceQuiz() {
	char choice;
	char rightChoice = 'B';
	int gameOver;
	
	cout << "If you wish to enter the castle you must first enter you must first answer the following question" << endl
		<< "What is the difference between using a vector and an array" << endl
		<< "\nA Vector? I thought that was only in physics class..." << endl
		<< "\nB Vectors are dynamic in size" << endl
		<< "\nC Vectors have a grow_to_fit() member function to resize it" << endl
		<< "\nD Vectors are the same as arrays so nothing" << endl
		<< "Choose which letter is correct" << endl;
	cin >> choice;

	if (toupper(choice) != rightChoice) {
		cout << "Your wrong! \nMagic circles appear all around you, suddenly all the gaurdians appear..." << endl
			<< "The duo was annihilated....\n*******GAME OVER********\n" << endl;
			gameOver = 1;
	}
	else if(toupper(choice) == rightChoice){ 
		cout << "\n*********************************************************\n\n"
			 << "You have defeated me but I shall be avenged!...." << endl
			<< "The gaurdian collapsed....\nYou are now inside the castle." << endl;
		gameOver = 2;
	}
	return gameOver;
}
int TreasureRoomEntranceQuiz(character &TreasureGaurdian) {
	int gameOver;
	
	cout << "The duo walks down to the treasure room. They run into the " << TreasureGaurdian.getName()
		<< "\nA new question must be asked in order to pass...\nThe gaurdian wields a stone that must be powered with magic" << endl
		<< "\n\nHe says: Channel your magic into it, should you be lucky the answer will come out correct,\nif not your journey ends here!" << endl
		<< "\n!?!?!?!?!!??!??!?!?!?!?!?!?!?!?!??!\n\n";
	system("PAUSE");
	cout
		<< "The light and magic envelopes the room as the stone displays the following..." << endl
		<< "A dynamic stack is built of an array, true or false" << endl;

	int stoneQuiz = DiceRoll(1, 2);
	int right = 2;
	int wrong = 1;
	gameOver = (stoneQuiz == right) ? right : wrong;

	if (gameOver == 1)
	{
		cout << "Your wrong! A dynamic stack is built on a linked list instead of an array! " << endl
			<< "\nMagic circles appear all around you, suddenly all the gaurdians appear..." << endl
			<< "The Duo was annihilated....\n*******GAME OVER********\n" << endl;
	}
	else
	{		
		cout << "\n*********************************************************\n\n"
			<< "Your right! A dynamic stack is built on a linked list instead of an array! " << endl << endl
			<< "You have defeated " << TreasureGaurdian.getName() << "! " << endl
			<< "As you step over the fallen gaurdian, you hold the treasure in your hands..." << endl
			<< "Unimaginable power can be felt from it... it's a priceless magic sword... \n\nIts wielder can achieve a level higher than 100!" << endl;
	}
	system("PAUSE");
	return gameOver;
}
int endingStory(int acceptedRoll1, int acceptedRoll2, character& UserCharacter) {
	char guess;
	int gameOver;
	UserCharacter.setLevel(120);
	cout << "\n***************************************************\n"
		<< UserCharacter.getName() << " leveled up to " <<UserCharacter.getLevel()<< "!" << endl
		<< "\n\nAs the duo exists the castle they feel an ominous aura filled with malice outside..." << endl
		<< "They run into the dark king jester!" << endl;
	
	if (acceptedRoll1 == 4 || acceptedRoll2 == 4)
	{
		cout << "But how!? We defeated you! they proclaimed" << endl
			<< "Apologies, I'm told I'm quite good at misdirection. he replies" << endl << endl;

	}
	cout << "He starts laughing as he removed his mask, it's Hisoka! He begins to speak...." << endl << endl
		<< "I've joined the other gaurdians in an attempt to take the sword for myself" << endl
		<< "Yet wherever I walked in the castle the other gaurdians knew of my whereabouts, perhaps they always suspected me :)" << endl
		<< "I needed a pair of fools like you, strong enough to get passed the gaurds" << endl
		<< "weak enough to take out along with the remaining gaurdian if need be." << endl << endl
		<< "Now that your weakened from your battles BEHOLD MY MISDRECTION MAGIC" << endl
		<< "His original twin swords have become four, which ones are the real ones?" << endl
		<< "\nA) swords 1 and 2 B) swords 3 and 4" << endl;
	cin >> guess;

	if (toupper(guess) == 'A') { cout << "\nYou've been hit by 1 out of two swords!" << endl; }
	else if (toupper(guess) == 'B') { cout << "\nYou blocked his attack!" << endl; }
	else { cout << "\nBoth swords hit you!" << endl; }

	cout << "\nA good attempt! he proclaims... But what about swords five and six" << endl
		<< "You turn to your partner and see two swords skewered him from behind..." << endl
		<< "I told you I'm quite the trickster :) He laughs as now twice as many swords appear! Is this the end?" << endl
		<< "\n\nThis can't be, you fought hard to get here!" << endl
		<< "Suddenly it feels as though the magic of the swords is speaking to you..." << endl
		<< "It said if you want the power to win this battle you must recall your first programming class" << endl
		<< "call the name of the person who started the computer age for their name is mine!" << endl
		<< "\n\nWho is accredited for starting the computer age?" << endl
		<< "A) Alan Turing B) Michael Englander C) Margaret Hamilton" << endl;
	cin >> guess;

	if(toupper(guess) != 'A'){
		cout << "The blades overwhelm you as your wrong answer was your downfall..." << endl
			<< "As your vision fades to black you see Hisoka grab the blade and smile" << endl
			<< "Hisoka's level is now 150! No one can stop him now...." << endl
			<< "\n*****GAME OVER*****\n" << endl;
			gameOver = 1;
	}
	else
	{
		UserCharacter.setLevel(200);
		cout << "The sacred turing blade achieves it's final form upon hearing it's name!" << endl
			<< UserCharacter.getName() << " is now level " << UserCharacter.getLevel() << "!" << endl
			<< "It's light enveloped the kingdom and all of Hisoka's swords all fall... " << endl
			<< "But how ! He screams in defeat" << endl
			<< "Perhaps your not as clever as you thought you yell as you finish him with a single swing of the sword" << endl;
		gameOver = 2;
	}
	
	return gameOver;
}
string chosenRoom(int diceRoll, castle& treasureSetUp) {
	string treasureRoom;
	if (diceRoll == 1) { treasureRoom = treasureSetUp.getRoom1(); }
	else if (diceRoll == 2) { treasureRoom = treasureSetUp.getRoom2(); }
	else if (diceRoll == 3) { treasureRoom = treasureSetUp.getRoom3(); }
	else if (diceRoll == 4) { treasureRoom = treasureSetUp.getRoom4(); }
	return treasureRoom;
}