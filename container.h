#include <cstdlib>
#include <string>
#include <list>
#include "person.h"

#ifndef CONTAINER_H
#define	CONTAINER_H

using namespace std;

class Container {
private:
    string name;
    list<Person*> people;
protected:
    int fill;
public:
    bool contains(Person* p);
    bool hasDriver();
    bool isEmpty() { return fill == 0; }
    
    bool canAdd(Person* p);
    bool canRemove(Person* p);
    bool canChange(Person* add, Person* rmv);
    
    void addAll(list<Person*> l);
    void addPerson(Person* p);
    void removePerson(Person* p);
    
    string getName() { return name; }
    string getPeople();
    
    Container(string name) : name(name), fill(0) {}
    Container(string name, list<Person*> people) : name(name), people(people), fill(0) {}
};

class Bank : public Container {
public:
    Bank(string name) : Container(name) {}
    
    friend ostream& operator<<(ostream& out, Bank* b);
};

class Boat : public Container {
private:
    Bank* current;
    Bank* other;
    bool side;
public:
    Boat(string name, Bank* start, Bank* end) : Container(name), current(start), other(end), side(1) {}
    bool embark(Person* p);
    bool disembark(Person* p);
    bool move();
    
    friend ostream& operator<<(ostream& out, Boat* b);
};

#endif