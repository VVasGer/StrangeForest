#pragma once
#include <iostream>
//#include "mainMenu.cpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int numberOfStories = 2; //this is for develop


int welcomeCatcher{}; //theese are servise variables for game proceeding
int mainMenuCatcher{};
int lastCatcher{};
int answerCatcher{};
int storyChooser{};
int storyOrder{};


string answerVariants = "\n\n \t (1)_Yes.\t\t (2)_Do nothing... \t\t (3)_No!\n"; //servise strings
string universalAnswerYes;
string universalAnswerNothing;
string universalAnswerNo;
string enterErrorMessage = "You entered something unexpected. Enter 1 for 'Yes.', 2 for 'Do nothing...', 3 for 'No!' OR 9 for quit.";
string happySurvive = "Now you can leave us. You survived. So sad. CYA. \n But we wont forget you... and wont let you forget us.";
string unhappyDie = "All fade away. Relax. It is nearly over. Sit here, under that beatiful tree. \nSleep well, my darling, we'll look after you... \t\t You died.";


bool dead = false; //servise bools for game endings
bool end = false;
bool storyDone = false;
bool welcomeDone = false;
bool mainMenuDone = false;
bool quit = false;

void welcome()
{
	string welcome1 = "Welcome to the Strange forest! It's my first text game, which was wrote for fun and as a training in C++. \n";
	string welcome2 = "For interacting within this game - choose one of three decisions and enter its' number. \n";
	string welcome3 = "Good luck in this journey! And have fun. \n\n Type anything to start.\n";

	cout << welcome1 << welcome2 << welcome3;

	cin >> welcomeCatcher;

	if (welcomeCatcher) {
		welcomeDone = true;
		welcomeCatcher = 0;
		}
	return;
};

void mainMenu() 
{

	string menu1 = "\n\nYou just entered nearby forest. Why? Ofc because you can! Finally summer heat leave you. Here feels humid forest air.\n";
	string menu2 = "It seems here is a three way to go: \n";
	string menu3 = "\t left footpath is looking pretty familiar somehow, but you never been here before for shure, \n";
	string menu4 = "\t straight way is straight, he-he, but you can't see far enough because of trees, \n";
	string menu5 = "\t right trailway darker than others, tree crowns catch all the sunlight leaning against each other \n";
	string menu6 = "\n \t\t\t\t Where are we going to walk today?\n \t\t\t\t Type (1) for left, (2) for straight or (3) for right. Type 9 to quit.\n";

	string choosedL = "Hmm... This is definetly impossible, but you have feel like you know what wait you round the corner...";
	string choosedS = "This path winds slightly around the trees. Soon enough, you will not be able to see where you went into this forest.";
	string choosedR = "As you move forward on the path, here become darker and colder. That's feels especially nice in these hot summer days.";


	cout << menu1 << menu2 << menu3 << menu4 << menu5 << menu6 << endl;

	cin >> mainMenuCatcher;

	if (mainMenuCatcher) {

		if (mainMenuCatcher == 1) {

			cout << choosedL << endl;
			mainMenuDone = true;


		}
		else if (mainMenuCatcher == 2) {

			cout << choosedS << endl;
			mainMenuDone = true;


		}
		else if (mainMenuCatcher == 3) {

			cout << choosedR << endl;
			mainMenuDone = true;


		}
		else if (mainMenuCatcher == 9) {
			cout << "Quit..." << endl;
			quit = true;
			mainMenuDone = true;

		}
		/*else {
			cout << menu1 << menu2 << menu3 << menu4 << menu5 << menu6;
			cin >> mainMenuCatcher;
			return;
		}*/
	}
	return;
};

void answerHandler(int x) {
	switch (x) {
	case 1:
		cout << universalAnswerYes << endl;
		answerCatcher = 0;
		//return;
		break;
	case 2:
		cout << universalAnswerNothing << endl;
		answerCatcher = 0;
		//return;
		break;
	case 3:
		cout << universalAnswerNo << endl;
		answerCatcher = 0;
		//return;
		break;
	case 9:
		cout << "Quit..." << endl;
		quit = true;
		return;
		break;
	}
	return;
};



void story1() {
	string localStory = "You found a rotten dog's corpse. He is probably nice to meet you. \n But his tail fell apart from body few days ago. Wanna play with the Goodboy?";

	string localAnswYes = "It's bite you somehow. Probably you will die soon. Are you happy now? Leave poor dog alone!";
	string localAnswNothing = "It's just a died dog. Nothing intresting here.";
	string localAnswNo = "It would be very strange if you started pretending to play with the dog's corpse.";

	universalAnswerYes = localAnswYes;
	universalAnswerNothing = localAnswNothing;
	universalAnswerNo = localAnswNo;

	cout << "\n\n" << localStory << endl;
	cout << answerVariants << "\n" << endl;
	cin >> answerCatcher;

	if (answerCatcher == 1) {
		dead = true;
		return;
	}

	answerHandler(answerCatcher);
	storyDone = true;
	return;
};

void story2() {

};







void deadEnd() {
	cout << unhappyDie << endl;
	return;
};

void happyEnd() {
	cout << happySurvive << endl;
	return;
};

void storyTeller() {
	if (storyDone == true) {
		storyOrder++;
		storyDone = false;
		return;
	}

	if (storyOrder > numberOfStories) {
		end = true;
		return;
	}

	switch (storyOrder) {
	case 1:
		story1();
		return;
		break;
	case 2:
		story2();
		return;
		break;
	}
};