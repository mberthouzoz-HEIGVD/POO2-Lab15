#include <stdio.h>
#include <iostream>
#include "riviere.h"

using namespace std;

void Controller::showMenu() const {
    cout << "p      : afficher" << endl;
    cout << "e <nom>: embarquer <nom>" << endl;
    cout << "d <nom>: debarquer <nom>" << endl;
    cout << "m      : deplacer bateau" << endl;
    cout << "r      : reinitialiser" << endl;
    cout << "q      : quitter" << endl;
    cout << "h      : menu" << endl;    
}

void Controller::display() const {
    cout << "----------------------------------------------------------" << endl;
    cout << "Gauche:" << endl; // etc
    cout << "----------------------------------------------------------" << endl;
    //if bank 1
    cout << "==========================================================" << endl;
    //if bank 2
    cout << "----------------------------------------------------------" << endl;
    cout << "Droite:" << endl; // etc
    cout << "----------------------------------------------------------" << endl;
}

int main() {
    return EXIT_SUCCESS;
}