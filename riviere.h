#include <string>

class Container {
private:
    string name;
    list<Person*> people;
public:
    Container(string name, list<Person*> people) : name(name), people(people) {}
    ~Container();
};

class Boat : public Container {
private:
    Bank* current;
public:
    Boat(string name) : Container(name) {}
    ~Boat();
};

class Bank : public Container {
public:
    Bank(string name) : Container(name) {}
    ~Bank();
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