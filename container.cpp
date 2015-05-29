#include <iostream>
#include <typeinfo>
#include "container.h"

using namespace std;

bool Container::contains(Person* p) {
    for (Person* t : people) {
        if (t == p) {
            return true;
        }
    }
    return false;
}

bool Container::hasDriver() {
    for (Person* p : people) {
        if (p->canDrive()) {
            return true;
        }
    }
    return false;
}

bool Container::addPerson(Person* p) {
    if (canChange(p, nullptr)) {
        people.push_back(p);
        return true;
    } else {
        return false;
    }
}

bool Container::canRemove(Person* p) {
    return canChange(nullptr, p);
}

bool Container::canChange(Person* add, Person* rmv) {
    bool aPere = false;
    bool aMere = false;
    bool aFils = false;
    bool aFill = false;
    bool aFami = false;
    bool aPoli = false;
    bool aVolr = false;
    
    if (add != nullptr) {
        if (typeid(add) == typeid(Pere)) {
            aFami = true;
            aPere = true;
        } else if (typeid(add) == typeid(Mere)) {
            aFami = true;
            aMere = true;
        } else if (typeid(add) == typeid(Fils)) {
            aFami = true;
            aFils = true;
        } else if (typeid(add) == typeid(Fille)) {
            aFami = true;
            aFill = true;
        } else if (typeid(add) == typeid(Policier)) {
            aPoli = true;
        } else if (typeid(add) == typeid(Voleur)) {
            aVolr = true;
        } else {
            // ceci ne devrait jamais arriver
            cout << "### ERREUR DE TYPEID" << endl;
        }
    }
    
    for (Person* p : people) {
        if (p == rmv) {
            continue;
        } else if (typeid(p) == typeid(Pere)) {
            aFami = true;
            aPere = true;
        } else if (typeid(p) == typeid(Mere)) {
            aFami = true;
            aMere = true;
        } else if (typeid(p) == typeid(Fils)) {
            aFami = true;
            aFils = true;
        } else if (typeid(p) == typeid(Fille)) {
            aFami = true;
            aFill = true;
        } else if (typeid(p) == typeid(Policier)) {
            aPoli = true;
        } else if (typeid(p) == typeid(Voleur)) {
            aVolr = true;
        } else {
            // ceci ne devrait jamais arriver
            cout << "### ERREUR DE TYPEID" << endl;
        }
    }
    
    if (aVolr and aFami and !aPoli) {
        cout << "### voleur et membre de la famille seuls sans policier" << endl;
        return false;
    } else if (aFils and aMere and !aPere) {
        cout << "### mere et fils seuls sans pere" << endl;
        return false;
    } else if (aFill and aPere and !aMere) {
        cout << "### pere et filles seuls sans mere" << endl;
        return false;
    }
    
    return true;
}

void Container::addAll(list<Person*> l) {
    for (Person* p : l) {
        addPerson(p);
    }
}

void Container::removePerson(Person* p) {
    people.remove(p);
}

string Container::getPeople() {
    string t = "";
    for (Person* p : people) {
        t += p->getName() + " ";
    }
    return t;
}

ostream& operator<<(ostream& out, Bank* b) {
    out << "----------------------------------------------------------" << endl;
    out << b->getName() << ": " << b->getPeople() << endl;
    out << "----------------------------------------------------------" << endl;
    return out;
}

bool Boat::embark(Person* p) {
    if (p == nullptr) {
        cout << "### personne invalide" << endl;
    } else if (fill >=2) {
        cout << "### le bateau est déjà plein" << endl;
        return false;
    } else if (contains(p)) {
        cout << "### " << p->getName() << " est dèjà sur le bateau" << endl;
        return false;
    } else if (!current->contains(p)) {
        cout << "### " << p->getName() << " n'est pas sur cette rive" << endl;
        return false;
    }
    
    if (current->canRemove(p)){
        if (addPerson(p)) {
            current->removePerson(p);
            return true;
        }
    }
    return false;
}

bool Boat::disembark(Person* p) {
    if (p == nullptr) {
        cout << "### personne invalide" << endl;
    } else if (fill == 0) {
        cout << "### le bateau est vide..." << endl;
        return false;
    } else if (!contains(p)) {
        cout << "### " << p->getName() << "n'est pas sur le bateau" << endl;
        return false;
    }
    
    if (canRemove(p)) {
        if (current->addPerson(p)) {
            this->removePerson(p);
            return true;
        }
    }
    return false;
}

bool Boat::move() {
    if (hasDriver()) {
        Bank* tmp = current;
        current = other;
        other = tmp;
        side = !side;
        return true;
    } else {
        cout << "### personne ne peut conduire le bateau" << endl;
        return false;
    }
}

ostream& operator<<(ostream& out, Boat* b) {
    if (b->side) {
        out << b->getName() << ": < " << b->getPeople() << ">" << endl;
        out << "==========================================================" << endl;
        out << endl;
    } else {
        out << endl;
        out << "==========================================================" << endl;
        out << b->getName() << ": < " << b->getPeople() << ">" << endl;
    }
    return out;
}