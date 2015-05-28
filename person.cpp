#include "person.h"


ostream& operator<<(ostream& out, Person p) {
	return (out << p.name);
}

ostream& operator<<(ostream& out, Person* p) {
	return (out << p->name);
}

bool Person::operator==(const Person* o) const {
	return name == o->name;
}
bool Person::operator==(const string o) const {
	return name == o;
}
bool operator==(Person* p, const string o) {
	return o == p->name;
}