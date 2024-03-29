// MonsterHunter.cpp
//
#include <cstdlib>
#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>

// RPG Formula - Attack and Defense:  (2 * Attack - Defense ) * 0.5 

/* for next update:
 * Adding 2 more monsters for each class
 * Adding more attacking moves
 * Allowing access to use all items
 * Adding boss battle at end of each class play through
 * You will be able to collect items(health potions) from monsters when you kill them
 * everytime you kill a boss you will be given 10 health potions
 */

using namespace std;

void Menu() {
	printf("|########################################|\n");
	printf("|    1 = Attack   |    3 = Items         |\n");
	printf("|    2 = Flee     |    4 = Use Potion    |\n");
	printf("|########################################|\n");
}

int main()
{
start:
	int random = rand() % 2;
	int FleeChance = random;
	// Class items
	string Archer_items = "[ Arrows, Health potions, Cocaine ]"; // next update: Arrows Buff attack damage by 5 ; Cocaine Buffs Speed 6 
	string Knight_items = "[ Shield, Health potions, Heroin ]"; // next update: Shield Buffs defense by 5 ; Heroin Buffs Speed by 6
	string Assassin_items = "[ Throwing knives, Health potions, Meth ]"; // next update: Throwing knives Buff attack damage by 5 ; Meth Buffs Speed by 6
	string fight;
	string flee;
	int attack;
	int defense;
	int speed;
	int health;
	string sleep;
	string name;
	string decision;
	string decision2;
	int classes;
	printf("Welcome, Enter you name: ");
	cin >> name;
	printf("\n");
	// Menu System Installation Animation ascii
	printf("Installing MenuSystem...\n");
	printf("The Archer and Assassin aren't complete yet\n");
	//loading bar
	float progress = 0.0;
	while (progress < 1.0) {
		int barWidth = 70;
		cout << "[";
		int pos = barWidth * progress;
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos) cout << "=";
			else if (i == pos) cout << ">";
			else cout << " ";

		}
		cout << "] " << int(progress * 100.0) << " %\r";
		cout.flush();
		progress += 0.16;
		printf("[\n");
	}
	// end of loading bar
	cout << endl;
	printf("\n");
	cout << "Welcome " << name << endl;
	printf("You may choose from one of three Classes.\n");
	printf("1 - Knight\n");
	printf("2 - Archer\n");
	printf("3 - Assassin\n");
	printf("Choose a class: \n");
	cin >> classes;
	if (classes == 1) {
		// The Knight
		// Attack: 23
		// Defense : 13
		// Speed : 6
		// Health : 60
		printf("You have chosen to become a Knight\n");
		printf("Attack  :   23\n"); attack  =  23;
		printf("Defense :   13\n"); defense =  13; // reduce 4 from monster attack damage
		printf("Speed   :    6\n"); speed   =   6;
		printf("Health  :   60\n"); health  =  60;
		printf("\n\n");
		int potions = 10;
		int Spider_health = 76;
		int Snake_health = 80;
	fork1:
		printf("You come across a fork in the road, you see a cave to the right, and a forest to the left.\n");
		printf("(left | right)\n");
		printf("(level2)\n");
		cin >> decision;
		if (decision == "right") { //  ---------- Decision
			if (Snake_health <= 0) {
				printf("\nyou have already killed this monster\n");
				goto fork1;
			}
			printf("as you enter the Cave you stumble upon a Giant two headed Snake with sabre cat like fangs\n");
			printf("\n");

			for (int i = 0; i < 15; ++i) {
				int input;
			input1:
				cout << "Your HP: " << health << endl;
				// Ascii Menu
				Menu();
				cin >> input;
				if (input == 1) {
					printf("you attacked the Snake\n");
					cout << "you did " << attack << " damage to the Snake\n";
					cout << "the Snake did 16 damage to you\n";
					health -= 12; //- 4
					cout << "The Snake had " << Snake_health << endl;
					Snake_health -= attack;
					cout << "Snake's health: " << Snake_health << endl;
				}
				else if (input == 2) {
					printf("\nyou chose to flee...\n");
					goto fork1;

				}
				else if (input == 3) {
					cout << Knight_items << endl;
				}
				else if (input == 4) {
					if (potions <= 0) {
						printf("you have run out of health potions\n");
						goto input1;
					}
					printf("using potion...\n");
					health += 10;
					potions -= 1;
					cout << "potions left: " << potions << endl;
				}
				else if (input == 0) {
					printf("you tripped and landed on your own weapon\n");
					health -= 100;
				}
				else {
					printf("invalid command\n");
				}
				if (Snake_health <= 0) {
					printf("you have killed the Giant Snake\n\n");
					potions += 5;
					goto fork1;
				}
				if (health <= 0) {
					printf("you have died\n");
					goto start;
				}
			}
		}
		else if (decision == "left") { //  ---------- Decision 
			if (Spider_health <= 0) {
				printf("\nyou have already killed this monster\n");
				goto fork1;
			}
			printf("as you enter the Forest you stumble upon a Huge poisonous Spider with 10 feet long legs\n");
			printf("\n");

			for (int i = 0; i < 15; ++i) {
				int input;
				input2:
				cout << "Your HP: " << health << endl;
				// Ascii Menu
				Menu();
				cin >> input;
				if (input == 1) {
					printf("you attacked the Spider\n");
					cout << "you did " << attack << " damage to the Spider\n";
					cout << "the Spider did 13 damage to you\n";
					health -= 13 - 5 ;
					cout << "The Spider had " << Spider_health << endl;
					Spider_health -= attack;
					cout << "Spider's health: " << Spider_health << endl;
				}
				else if (input == 2) {
					printf("\nyou chose to flee...\n");
					goto fork1;
				}
				else if (input == 3) {
					cout << Knight_items << endl;
				}
				else if (input == 4) {
					if (potions <= 0) {
						printf("you have run out of health potions\n");
						goto input2;
					}
					printf("using potion...\n");
					health += 10;
					potions -= 1;
					cout << "potions left: " << potions << endl;
				}
				else if (input == 0) {
					printf("you tripped and landed on your own weapon\n");
					health -= 100;
				}
				else {
					printf("invalid command\n");
				}
				if (Spider_health <= 0) {
					printf("you have killed the Huge Spider\n\n");
					potions += 5;
					goto fork1;
				}
				if (health <= 0) {
					printf("you have died\n");
					goto start;
				}
			}
		}
		else if (decision == "level2") { //  ---------- Decision
			if (Spider_health > 1) {
				printf("you have to defeat the Spider first\n");
				goto fork1;
			}
			if (Snake_health > 1) {
				printf("you have to defeat the Snake first\n");
				goto fork1;
			}
			printf("entering the next gate...\n\n");
			// Bug: If you seem to run out of potions the application crashes for some reason; still working on this.
			// Bug: If you choose to flee they regen all their health back, also if they are dead they come back from the dead.
			// Note: These bugs are currently only affecting the knight 
		fork1_b: // <-- This call statement is the reason for a bug #Error C2362
			int Necromorph_health = 93;
			int Golem_health = 90;
			printf("You come across a bridge leading two ways, you see a castle to the right, and a dungeon to the left.\n");
			printf("(left | right)\n");
			cin >> decision2;
			if (decision2 == "right") {
				if (Necromorph_health <= 0) {
					printf("\nyou have already killed this monster\n");
					goto fork1_b;
				}
				printf("as you enter the Castle you stumble upon a Necromorph \n");
				printf("\n");

				for (int i = 0; i < 15; ++i) {
					int input;
				input1_b:
					cout << "Your HP: " << health << endl;
					// Ascii Menu
					Menu();
					cin >> input;
					if (input == 1) {
						printf("you attacked the Necromorph\n");
						cout << "you did " << attack << " damage to the Necromorph\n";
						cout << "the Necromorph did 16 damage to you\n";
						health -= 12; //- 4
						cout << "The Necromorph had " << Necromorph_health << endl;
						Necromorph_health -= attack;
						cout << "Necromorph's health: " << Necromorph_health << endl;
					}
					else if (input == 2) {
						printf("\nyou chose to flee...\n");
						goto fork1_b;

					}
					else if (input == 3) {
						cout << Knight_items << endl;
					}
					else if (input == 4) {
						if (potions <= 0) {
							printf("you have run out of health potions\n");
							goto input1_b;
						}
						printf("using potion...\n");
						health += 10;
						potions -= 1;
						cout << "potions left: " << potions << endl;
					}
					else if (input == 0) {
						printf("you tripped and landed on your own weapon\n");
						health -= 100;
					}
					else {
						printf("invalid command\n");
					}
					if (Necromorph_health <= 0) {
						printf("you have killed the Necromorph\n\n");
						potions += 5;
						goto fork1_b;
					}
					if (health <= 0) {
						printf("you have died\n");
						goto start;
					}
				}
			}
			else if (decision2 == "left") {
				if (Golem_health <= 0) {
					printf("\nyou have already killed this monster\n");
					goto fork1_b;
				}
				printf("as you enter the Dungeon you stumble upon a Golem\n");
				printf("\n");

				for (int i = 0; i < 15; ++i) {
					int input;
				input2_b:
					cout << "Your HP: " << health << endl;
					// Ascii Menu
					Menu();
					cin >> input;
					if (input == 1) {
						printf("you attacked the Golem\n");
						cout << "you did " << attack << " damage to the Golem\n";
						cout << "the Golem did 13 damage to you\n";
						health -= 13 - 5;
						cout << "The Golem had " << Golem_health << endl;
						Golem_health -= attack;
						cout << "Golem's health: " << Golem_health << endl;
					}
					else if (input == 2) {
						printf("\nyou chose to flee...\n");
						goto fork1_b;
					}
					else if (input == 3) {
						cout << Knight_items << endl;
					}
					else if (input == 4) {
						if (potions <= 0) {
							printf("you have run out of health potions\n");
							goto input2_b;
						}
						printf("using potion...\n");
						health += 10;
						potions -= 1;
						cout << "potions left: " << potions << endl;
					}
					else if (input == 0) {
						printf("you tripped and landed on your own weapon\n");
						health -= 100;
					}
					else {
						printf("invalid command\n");
					}
					if (Golem_health <= 0) {
						printf("you have killed the Golem\n\n");
						potions += 5;
						goto fork1_b;
					}
					if (health <= 0) {
						printf("you have died\n");
						goto start;
					}
				}
			}
		}
		else {
			printf("that decision is invalid...\n");
			goto fork1_b;
		}
	} // under this no work has been added ---------------------------------------------------------------------------------------------
	else if (classes == 2) {
		// The Archer
		// Attack: 15
		// Defense : 11
		// Speed : 9
		// Health : 50
		printf("You have chosen to become a Archer\n");
		printf("Attack  :   15\n"); attack =  15;
		printf("Defense :   11\n"); defense = 11; // reduce 3 from monster attack damage
		printf("Speed   :    9\n"); speed =    9;
		printf("Health  :   50\n"); health =  50;
		printf("\n\n");
		int potions2 = 10;
		int Behemoth_health = 80;
		int Mummy_health = 70;
	fork2:
		printf("You come across a fork in the road, you see a cave to the right, and a forest to the left.\n");
		printf("(left | right)\n");
		cin >> decision;
		if (decision == "right") { //  ---------- Decision
			if (Behemoth_health <= 0) {
				printf("\nyou have already killed this monster\n");
				goto fork2;
			}
			printf("as you enter the Cave you stumble upon a Gigantic Behemoth with a two huge horns on the center of it's head\n");
			printf("\n");

			for (int i = 0; i < 15; ++i) {
				int input;
			input3:
				cout << "Your HP: " << health << endl;
				// Ascii Menu
				Menu();
				cin >> input;
				if (input == 1) {
					printf("you attacked the Behemoth\n");
					cout << "you did " << attack << " damage to the Behemoth\n";
					cout << "the Behemoth did 16 damage to you\n";
					health -= 13; //- 3
					cout << "The Behemoth had " << Behemoth_health << endl;
					Behemoth_health -= attack;
					cout << "Behemoth's health: " << Behemoth_health << endl;
				}
				else if (input == 2) {
					printf("\nyou chose to flee...\n");
					goto fork2;
				}
				else if (input == 3) {
					cout << Knight_items << endl;
				}
				else if (input == 4) {
					if (potions2 <= 0) {
						printf("you have run out of health potions\n");
						goto input3;
					}
					printf("using potion...\n");
					health += 10;
					potions2 -= 1;
					cout << "potions left: " << potions2 << endl;
				}
				else if (input == 0) {
					printf("you tripped and landed on your own weapon\n");
					health -= 100;
				}
				else {
					printf("invalid command\n");
				}
				if (Behemoth_health <= 0) {
					printf("you have killed the Giant Behemoth\n\n");
					potions2 += 5;
					goto fork2;
				}
				if (health <= 0) {
					printf("you have died\n");
					goto start;
				}
			}
		}
		else if (decision == "left") { //  ---------- Decision
			if (Mummy_health <= 0) {
				printf("\nyou have already killed this monster\n");
				goto fork2;
			}
			printf("as you enter the Forest you stumble upon a Mummy with a war axe\n");
			printf("\n");

			for (int i = 0; i < 15; ++i) {
				int input;
				input4:
				cout << "Your HP: " << health << endl;
				// Ascii Menu
				Menu();
				cin >> input;
				if (input == 1) {
					printf("you attacked the Mummy\n");
					cout << "you did " << attack << " damage to the Mummy\n";
					cout << "the Mummy did 15 damage to you\n";
					health -= 15;
					cout << "The Mummy had " << Mummy_health << endl;
					Mummy_health -= attack;
					cout << "Mummy's health: " << Mummy_health << endl;
				}
				else if (input == 2) {
					printf("\nyou chose to flee...\n");
					goto fork2;
				}
				else if (input == 3) {
					cout << Knight_items << endl;
				}
				else if (input == 4) {
					if (potions2 <= 0) {
						printf("you have run out of health potions\n");
						goto input4;
					}
					printf("using potion...\n");
					health += 10;
					potions2 -= 1;
					cout << "potions left: " << potions2 << endl;
				}
				else if (input == 0) {
					printf("you tripped and landed on your own weapon\n");
					health -= 100;
				}
				else {
					printf("invalid command\n");
				}
				if (Mummy_health <= 0) {
					printf("you have killed the Mummy\n\n");
					potions2 += 5;
					goto fork2;
				}
				if (health <= 0) {
					printf("you have died\n");
					goto start;
				}
			}
		}
		else {
			printf("that decision is invalid...\n");
			goto fork2;
		}
	}
	else if (classes == 3) {
		// The Assassin
		// Attack: 20
		// Defense : 9
		// Speed : 15
		// Health : 45
		printf("You have chosen to become a Assassin\n");
		printf("Attack  :  20\n"); attack = 20;
		printf("Defense :   9\n"); defense = 9; // reduce 3 from monster attack damage
		printf("Speed   :  15\n"); speed =  15;
		printf("Health  :  45\n"); health = 45;
		printf("\n\n");
		int potions3 = 10;
		int Turtle_health = 77;
		int Alien_health = 80;
	fork3:
		printf("You come across a fork in the road, you see a cave to the right, and a forest to the left.\n");
		printf("(left | right)\n");
		cin >> decision;
		if (decision == "right") { //  ---------- Decision
			if (Turtle_health <= 0) {
				printf("\nyou have already killed this monster\n");
				goto fork3;
			}
			printf("as you enter the Cave you stumble upon a Giant Turtle with big Spikes on the back of it's shell \n");
			printf("\n");

			for (int i = 0; i < 15; ++i) {
				int input;
				input5:
				cout << "Your HP: " << health << endl;
				// Ascii Menu
				Menu();
				cin >> input;
				if (input == 1) {
					printf("you attacked the Turtle\n");
					cout << "you did " << attack << " damage to the Turtle\n";
					cout << "the Turtle did 18 damage to you\n";
					health -= 15; //- 3
					cout << "The Turtle had " << Turtle_health << endl;
					Turtle_health -= attack;
					cout << "Turtle's health: " << Turtle_health << endl;
				}
				else if (input == 2) {
					printf("\nyou chose to flee...\n");
					goto fork3;
				}
				else if (input == 3) {
					cout << Knight_items << endl;
				}
				else if (input == 4) {
					if (potions3 <= 0) {
						printf("you have run out of health potions\n");
						goto input5;
					}
					printf("using potion...\n");
					health += 10;
					potions3 -= 1;
					cout << "potions left: " << potions3 << endl;
					
				}
				else if (input == 0) {
					printf("you tripped and landed on your own weapon\n");
					health -= 100;
				}
				else {
					printf("invalid command\n");
				}
				if (Turtle_health <= 0) {
					printf("you have killed the Giant Turtle\n\n");
					potions3 += 5;
					goto fork3;
				}
				if (health <= 0) {
					printf("you have died\n");
					goto start;
				}
			}
		}
		else if (decision == "left") { //  ---------- Decision
			if (Alien_health <= 0) {
				printf("\nyou have already killed this monster\n");
				goto fork3;
			}
			printf("as you enter the Forest you stumble upon an Alien with an Energy blaster\n");
			printf("\n");

			for (int i = 0; i < 15; ++i) {
				int input;
				input6:
				cout << "Your HP: " << health << endl;
				// Ascii Menu
				Menu();
				cin >> input;
				if (input == 1) {
					printf("you attacked the Alien\n");
					cout << "you did " << attack << " damage to the Alien\n";
					cout << "the Alien did 17 damage to you\n";
					health -= 17;
					cout << "The Alien had " << Alien_health << endl;
					Alien_health -= attack;
					cout << "Alien's health: " << Alien_health << endl;
				}
				else if (input == 2) {
					printf("\nyou chose to flee...\n");
					goto fork3;
				}
				else if (input == 3) {
					cout << Knight_items << endl;

				}
				else if (input == 4) {
					if (potions3 <= 0) {
						printf("you have run out of health potions\n");
						goto input6;
					}
					printf("using potion...\n");
					health += 10;
					potions3 -= 1;
					cout << "potions left: " << potions3 << endl;
					
				}
				else if (input == 0) {
					printf("you tripped and landed on your own weapon\n");
					health -= 100;
				}
				else {
					printf("invalid command\n");
				}
				if (Alien_health <= 0) {
					printf("you have killed the Alien\n\n");
					potions3 += 5;
					goto fork3;
				}
				if (health <= 0) {
					printf("you have died\n");
					goto start;
				}
			}
		}
		else {
			printf("that decision is invalid...\n");
			goto fork3;
		}
	}
	return 0;
}


