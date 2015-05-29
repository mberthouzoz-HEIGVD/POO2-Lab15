#include "controller.h"
#include <iostream>

// Eleonore d'Agostino et Michael Berthouzoz

using namespace std;

Controller::Controller() : quit(false) {
    init();
}

Controller::~Controller() {
    clear();
}

// affichage du menu
void Controller::showMenu() const {
    cout << "p      : afficher" << endl;
    cout << "e <nom>: embarquer <nom>" << endl;
    cout << "d <nom>: debarquer <nom>" << endl;
    cout << "m      : deplacer bateau" << endl;
    cout << "r      : reinitialiser" << endl;
    cout << "q      : quitter" << endl;
    cout << "h      : menu" << endl;    
}

// affichage de la rivière et des rives
void Controller::display() const {
    cout << endl;
    cout << bankLeft;
    cout << boat;
    cout << bankRight;
}

// tente d'embarquer, retourne false s'il y a eu un problème
bool Controller::embark(string name) {
    return boat->embark(getPerson(name));
}

// tente de débarquer, retourne false s'il y a eu un problème
bool Controller::disembark(string name) {
    return boat->disembark(getPerson(name));
}

// tente déplacer le bateau, retourne false s'il y a eu un problème
bool Controller::moveBoat() {
    return boat->move();
}

// initialisation des gens, des rives et du bateau aux positions correctes
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

// destructeur des champs, dans une méthode séparée pour pouvoir reset
void Controller::clear() {
    while (!people.empty()) {
        delete people.back();
        people.pop_back();
    }
    
    delete bankLeft;
    bankLeft = nullptr;
    delete bankRight;
    bankRight = nullptr;
    delete boat;
    boat = nullptr;
}

// on delete nos champs et on réinitialise
void Controller::reset() {
    clear();
    init();
}

// boucle du jeu
void Controller::start() {
    showMenu();
    display();
    while (!quit) {
        cout << endl << turn++ << "> ";
        string cmd = "";
        getline(cin, cmd);
        
        if (cmd == "p") {
            display();
        } else if (cmd == "m") {
            if (moveBoat()) {
                display();
            }
        } else if (cmd == "r") {
            reset();
        } else if (cmd == "q") {
            quit = true;
        } else if (cmd == "h") {
            showMenu();
        } else if (cmd.substr(0, 2) == "e ") {
            if (embark(cmd.substr(2,string::npos))) {
                display();
            }
        } else if (cmd.substr(0, 2) == "d ") {
            if (disembark(cmd.substr(2,string::npos))) {
                display();
                if (boat->isEmpty() and bankLeft->isEmpty()) {
                    cout << "vous avez fini, bravo!" << endl;
                    quit = true;
                }
            }
        } else {
            cout << "### commande non reconnue" << endl;
            showMenu();
        }
    }
}

// retourne un objet Person à partir de son nom
Person* Controller::getPerson(string name) {
    for (Person* p : people) {
        if (p == name) {
            return p;
        }
    }
    return nullptr;
}