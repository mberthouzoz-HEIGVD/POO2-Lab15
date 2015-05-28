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
    ~Person();
    virtual bool canDrive() const = 0;
	friend ostream& operator<<(ostream& out, Person p);
	friend ostream& operator<<(ostream& out, Person* p);
	bool operator==(const Person* o) const;
	bool operator==(const string o) const;
	friend bool operator==(Person* p, const string o);
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

#endif	