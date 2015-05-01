#include <cstdlib>
#include <string>
#include <list>

using namespace std;

class Container {
private:
    string name;
public:
    list<Person*> people;
    Container(string name) : name(name) {}
    Container(string name, list<Person*> people) : name(name), people(people) {}
    ~Container();
};

class Bank : public Container {
public:
    Bank(string name) : Container(name) {}
    ~Bank();
};

class Boat : public Container {
private:
    Bank* current;
public:
    Boat(string name) : Container(name) {}
    ~Boat();
};

class Person {
private:
    string name;
public:
    Person(string name) : name(name) {}
    ~Person();
    virtual bool canDrive() const = 0;
};

class Pere : public Person {
public:
    Pere() : Person("pere") {}
    ~Pere();
    bool canDrive() const { return true; }
};

class Mere : public Person {
public:
    Mere() : Person("mere") {}
    ~Mere();
    bool canDrive() const { return true; }
};

class Fils : public Person {
public:
    Fils(string name) : Person(name) {}
    ~Fils();
    bool canDrive() const { return false; }
};

class Fille : public Person {
public:
    Fille(string name) : Person(name) {}
    ~Fille();
    bool canDrive() const { return false; }
};

class Policier : public Person {
public:
    Policier() : Person("policier") {}
    ~Policier();
    bool canDrive() const { return true; }
};

class Voleur : public Person {
public:
    Voleur() : Person("voleur") {}
    ~Voleur();
    bool canDrive() const { return false; }
};

class Controller {
private:
    int turn;
    Bank* bankLeft;
    Bank* bankRight;
    Boat* boat;
public:
    Controller() : turn(0) {}
    ~Controller();
    void showMenu() const;
    void display() const;
    void nextTurn();
};