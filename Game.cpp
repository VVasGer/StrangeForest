#include <iostream>
#include "Header.h"

int main() {
	if (welcomeDone == false)
	welcome();

	
	if (mainMenuDone == false)
	mainMenu();



	do {
		storyTeller();
	} while (dead != true || end != true);
	
	if (dead) {
		deadEnd();
		return 1;
	} 

	if (end) {
		happyEnd();
		return 1;
	}

	cout << "\n\n Probably you never return AGAIN. Type anything to quit." << endl;
	cin >> lastCatcher;

	if (quit == true||lastCatcher != 0)
	return 0;
	

	return 0;
}
