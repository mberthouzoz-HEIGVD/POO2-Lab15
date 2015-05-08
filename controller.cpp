#include "controller.h"
#include <iostream>

using namespace std;

Controller::Controller() : turn(0), bankLeft(new Bank("Gauche")), bankRight(new Bank("Droite")), boat(new Boat("Bateau", bankLeft)) {

}

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

void Controller::embark(string name) {

}

void Controller::disembark(string name) {

}

void Controller::moveBoat() {

}

void Controller::reset() {

}

void Controller::nextTurn() {

}