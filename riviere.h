#include <cstdlib>
#include <string>
#include <list>
#include "person.h"

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
    void embark(const Person &p);
    void disembark(const Person &p);
};