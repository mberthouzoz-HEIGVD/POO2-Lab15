#include "controller.h"
#include <iostream>

using namespace std;

Controller::Controller() : quit(false) {
    init();
}

Controller::~Controller() {
    clear();
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
    cout << endl;
    cout << bankLeft;
    cout << boat;
    cout << bankRight;
    cout << endl;
}

void Controller::embark(string name) {
    boat->embark(getPerson(name));
}

void Controller::disembark(string name) {
    boat->disembark(getPerson(name));
}

void Controller::moveBoat() {
    if (!boat->move()) {
        cout << "### personne ne peut conduire le bateau" << endl;
    }
}

void Controller::init() {
    turn = 0;
    bankLeft = new Bank("Gauche");
    bankRight = new Bank("Droite");
    boat = new Boat("Bateau", bankLeft, bankRight);
    
    Pere* pe = new Pere();
    Mere* me = new Mere();
    Fils* p1 = new Fils("paul");
    Fils* p2 = new Fils("pierre");
    Fille* j1 = new Fille("julie");
    Fille* j2 = new Fille("jeanne");
    Voleur* vo = new Voleur();
    Policier* po = new Policier();
    
    people.push_back(pe);
    people.push_back(me);
    people.push_back(p1);
    people.push_back(p2);
    people.push_back(j1);
    people.push_back(j2);
    people.push_back(vo);
    people.push_back(po);
    
    bankLeft->addAll(people);
}

void Controller::clear() {
    while (!people.empty()) {
        delete people.back();
        people.pop_back();
    }
    
    delete bankLeft;
    delete bankRight;
    delete boat;
}

void Controller::reset() {
    clear();
    init();
}

void Controller::start() {
    showMenu();
    display();
    while (!quit) {
        cout << turn++ << "> ";
        string cmd = "";
        getline(cin, cmd);
        
        if (cmd == "p") {
            display();
        } else if (cmd == "m") {
            moveBoat();
            display();
        } else if (cmd == "r") {
            reset();
        } else if (cmd == "q") {
            quit = true;
        } else if (cmd == "h") {
            showMenu();
        } else if (cmd.substr(0, 2) == "e ") {
            embark(cmd.substr(2,string::npos));
            display();
        } else if (cmd.substr(0, 2) == "d ") {
            disembark(cmd.substr(2,string::npos));
            display();
            if (boat->isEmpty() and bankLeft->isEmpty()) {
                cout << "vous avez fini, bravo!" << endl;
                quit = true;
            }
        } else {
            cout << "### commande non reconnue" << endl;
            showMenu();
        }
    }
}

Person* Controller::getPerson(string name) {
    for (Person* p : people) {
        if (p == name) {
            return p;
        }
    }
    return nullptr;
}