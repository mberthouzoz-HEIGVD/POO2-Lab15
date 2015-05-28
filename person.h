#include <string>
#include <ostream>

#ifndef PERSON_H
#define	PERSON_H

using namespace std;

class Person {
private:
    const string name;
    Person(const Person& orig);
    Person& operator=(const Person& orig);
public:
    Person(string name) : name(name) {}
    virtual ~Person() {}
    
    string getName() { return name; }
    
    virtual bool canDrive() { return false; }
    
    friend ostream& operator<<(ostream& out, Person p);
    friend ostream& operator<<(ostream& out, Person* p);
    bool operator==(const Person* o) const;
    bool operator==(const string o) const;
    friend bool operator==(Person* p, const string o);
};

class Pere : virtual public Person {
public:
    Pere() : Person("pere") {}
    ~Pere();
    bool canDrive() { return true; }
};

class Mere : virtual public Person {
public:
    Mere() : Person("mere") {}
    ~Mere();
    bool canDrive() { return true; }
};

class Fils : virtual public Person {
public:
    Fils(string name) : Person(name) {}
    ~Fils();
};

class Fille : virtual public Person {
public:
    Fille(string name) : Person(name) {}
    ~Fille();
};

class Policier : virtual public Person {
public:
    Policier() : Person("policier") {}
    ~Policier();
    bool canDrive() { return true; }
};

class Voleur : virtual public Person {
public:
    Voleur() : Person("voleur") {}
    ~Voleur();
};

#endif	