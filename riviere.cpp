#include <stdio.h>
#include <iostream>
#include <string>
#include "controller.h"

using namespace std;

int main() {
	Controller* ctrl = new Controller();
	string cmd = "";
	bool quit = false;
	ctrl->showMenu();
	while (!quit) {
		getline(cin, cmd);
		
		if (cmd == "p") {

		}
		else if (cmd == "m") {

		}
		else if (cmd == "r") {

		}
		else if (cmd == "q") {

		}
		else if (cmd == "h") {

		}
		else if (cmd.substr(0, 2) == "e ") {

		}
		else if (cmd.substr(0, 2) == "d ") {

		}
		else {
			cout << "Commande non reconnue" << endl;
			ctrl->showMenu();
		}
		
	}

	system("PAUSE");

    return EXIT_SUCCESS;
}