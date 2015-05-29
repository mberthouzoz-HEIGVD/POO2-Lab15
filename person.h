#include <string>
#include <ostream>

#ifndef PERSON_H
#define	PERSON_H

/* Eleonore d'Agostino et Michael Berthouzoz
   28-05-2015
   Ce fichier contient la structure de la classe Person et de toutes ses
   sous-classes (Pere, Mere, Fils, Fille, Voleur et Policier)
*/

using namespace std;

class Person {
private:
    const string name;
    Person(const Person& orig);
    Person& operator=(const Person& orig);
public:
    Person(string name) : name(name) {}
    
    string getName() { return name; }
    
    virtual bool canDrive() { return false; }
    
    friend ostream& operator<<(ostream& out, Person* p);
    bool operator==(const Person* o) const;
    bool operator==(const string o) const;
    friend bool operator==(Person* p, const string o);
};

class Pere : virtual public Person {
public:
    Pere() : Person("pere") {}
    bool canDrive() { return true; }
};

class Mere : virtual public Person {
public:
    Mere() : Person("mere") {}
    bool canDrive() { return true; }
};

class Fils : virtual public Person {
public:
    Fils(string name) : Person(name) {}
};

class Fille : virtual public Person {
public:
    Fille(string name) : Person(name) {}
};

class Policier : virtual public Person {
public:
    Policier() : Person("policier") {}
    bool canDrive() { return true; }
};

class Voleur : virtual public Person {
public:
    Voleur() : Person("voleur") {}
};

#endif	