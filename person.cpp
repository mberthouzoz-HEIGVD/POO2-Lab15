#include "person.h"

// Eleonore d'Agostino et Michael Berthouzoz
// 28-05-2015

// affichage d'une personne - son nom
ostream& operator<<(ostream& out, Person* p) {
	return (out << p->name);
}

bool Person::operator==(const Person* o) const {
	return name == o->name;
}

// methodes utilitaires pour pouvoir vérifier l'égalité d'une personne
// d'après son nom seulement
bool Person::operator==(const string o) const {
	return name == o;
}
bool operator==(Person* p, const string o) {
	return o == p->name;
}