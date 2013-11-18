#pragma once
#include "Game.h"
#include <iostream>
#include <conio.h>
#include <sstream>

using namespace std;

void PressEnterToContinue()
{
	std::cout << "Press ENTER to continue... " << flush;
	std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
}

void intro()
{
	cout << "\n\n\t\t\tWelcome to TRICOLOR CHECKERS\n" << endl;
	cout << "\n\n\t\t\t A Game By:\n" << endl;
	cout << "\t\t\t Christopher Brown\n" << endl;
	cout << "\t\t\t Melinda Jenner\n" << endl;
	cout << "\t\t\t Nancy Le\n" << endl;
}
void menu()
{
	cout << "\t\t\t\tMenu Options" << endl;
	cout << "\t\t---------------------------------------------" << endl;
	cout << "\t\t\t\tp: Play" << endl;
	cout << "\t\t\t\tq: Quit" << endl;

	cout << "\n\t\t\tPlease enter a choice: ";
}
void play(Game game) {
	cout << string(100, '\n');
	cout << "\t\t\tGame Info" << endl;
	cout << "\t\t---------------------------------------------" << endl;
	cout << "\tThe play order will be Green, Black, Red.\n\n" << endl;
	cout << "\tRows are the numbers on the left of the screen.\n\n" << endl;
	cout << "\tColumns are the numbers on the bottom of the screen.\n\n" << endl;
	cout << "\tRows are the numbers on the left of the screen.\n\n" << endl;
	cout << "\tRed/Black specials are inherent, only Green has a command option.\n\n\n\n" << endl;

	PressEnterToContinue();
	game.play();
}
void menu_selection(Game game, char option)
{
	switch (option)
	{
	case 'p':
		play(game);
		break;

	case 'q':
		// main loop will take care of this.
		break;

	default:
		cout << "Error: Invalid Input.  Please try again..." << endl;
		break;
	}
}
void dump_key_buffer()
{
	int c = getchar();

	while (c != '\n' && c != EOF)
		c = getchar();
}

int get_input()
{
	int myInt;
	string input;

	while (true){
		getline(cin, input);
		stringstream myStream(input);
		if (myStream >> myInt)
			break;
		cout << "Please enter an integer only:";
	}
	return myInt;
}


//General testing scripts
void main() {

	char input_buffer;
	Game game;
	
	intro();
	
	do
	{
		menu();

		input_buffer = tolower(getchar());
		dump_key_buffer();
		menu_selection(game, input_buffer);
	} while (input_buffer != 'q');

};