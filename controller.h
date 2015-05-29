#include "container.h"

#ifndef CONTROLLER_H
#define	CONTROLLER_H

using namespace std;

class Controller {
private:
    int turn;
    Bank* bankLeft;
    Bank* bankRight;
    Boat* boat;
    list<Person*> people;
    bool quit;
public:
    Controller();
    ~Controller();
    void showMenu() const;
    
    bool embark(string name);
    bool disembark(string name);
    bool moveBoat();
    
    void init();
    void clear();
    void reset();
    
    void display() const;
    void start();
    
    Person* getPerson(string name);
};

#endif