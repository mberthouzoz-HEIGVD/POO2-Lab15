#include <iostream>
#include <typeinfo>
#include "container.h"

/* Eleonore d'Agostino et Michael Berthouzoz
   28-05-2015
   Ce fichier contient les implémentations des méthodes pour Container et ses
   sous-classes
*/

using namespace std;

// verifie si une personne est presente dans ce container
bool Container::contains(Person* p) {
    for (Person* t : people) {
        if (t == p) {
            return true;
        }
    }
    return false;
}

// verifie si ce container contient un conducteur
bool Container::hasDriver() {
    for (Person* p : people) {
        if (p->canDrive()) {
            return true;
        }
    }
    return false;
}

// ajoute une personne au container, sans vérification
void Container::addPerson(Person* p) {
    people.push_back(p);
    fill++;
}

// vérification de s'il est possible d'ajouter cette personne à ce container
bool Container::canAdd(Person* p) {
    return canChange(p, nullptr);
}

// vérification de s'il est possible d'enlever cette personne à ce container
bool Container::canRemove(Person* p) {
    return canChange(nullptr, p);
}

/* vérification de si une personne peut être ajoutée ou enlevée suivant
   les règles définies dans la donnée.
   on utilise des typeid pour éviter de briser l'ocp dans Person et ses
   sous-classes - il serait préférable de ne pas utiliser de typeid du tout,
   mais utiliser d'autres méthodes reviendrait à briser l'ocp ou avoir une
   redondance de données non-négligeable.
*/
bool Container::canChange(Person* add, Person* rmv) {
    bool aPere = false;
    bool aMere = false;
    bool aFils = false;
    bool aFill = false;
    bool aFami = false;
    bool aPoli = false;
    bool aVolr = false;
    
    if (add != nullptr) {
        if (typeid(*add) == typeid(Pere)) {
            aFami = true;
            aPere = true;
        } else if (typeid(*add) == typeid(Mere)) {
            aFami = true;
            aMere = true;
        } else if (typeid(*add) == typeid(Fils)) {
            aFami = true;
            aFils = true;
        } else if (typeid(*add) == typeid(Fille)) {
            aFami = true;
            aFill = true;
        } else if (typeid(*add) == typeid(Policier)) {
            aPoli = true;
        } else if (typeid(*add) == typeid(Voleur)) {
            aVolr = true;
        } else {
            // ceci ne devrait jamais arriver
            cout << "### ERREUR DE TYPEID" << endl;
        }
    }
    
    for (Person* p : people) {
        if (p == rmv) {
            continue;
        } else if (typeid(*p) == typeid(Pere)) {
            aFami = true;
            aPere = true;
        } else if (typeid(*p) == typeid(Mere)) {
            aFami = true;
            aMere = true;
        } else if (typeid(*p) == typeid(Fils)) {
            aFami = true;
            aFils = true;
        } else if (typeid(*p) == typeid(Fille)) {
            aFami = true;
            aFill = true;
        } else if (typeid(*p) == typeid(Policier)) {
            aPoli = true;
        } else if (typeid(*p) == typeid(Voleur)) {
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

// methode utilitaire pour ajouter plusieurs personnes à la fois,
// sans vérification
void Container::addAll(list<Person*> l) {
    for (Person* p : l) {
        addPerson(p);
    }
}

// retire une personne au container, sans vérification
void Container::removePerson(Person* p) {
    people.remove(p);
    fill--;
}

// retourne une string contenant la liste des gens de ce container
string Container::getPeople() {
    string t = "";
    for (Person* p : people) {
        t += p->getName() + " ";
    }
    return t;
}

// affichage de la rive
ostream& operator<<(ostream& out, Bank* b) {
    out << "----------------------------------------------------------" << endl;
    out << b->getName() << ": " << b->getPeople() << endl;
    out << "----------------------------------------------------------" << endl;
    return out;
}

/* methode pour tenter d'embarquer le bateau
   - si on a réussi à embarquer, retourne true
   - sinon, affiche l'erreur et retourne false
*/
bool Boat::embark(Person* p) {
    if (p == nullptr) {
        cout << "### personne invalide" << endl;
        return false;
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
    
    if (current->canRemove(p) && canAdd(p)){
        addPerson(p);
        current->removePerson(p);
        return true;
    }
    return false;
}

/* methode pour tenter de debarquer le bateau
   - si on a réussi à débarquer, retourne true
   - sinon, affiche l'erreur et retourne false
*/
bool Boat::disembark(Person* p) {
    if (p == nullptr) {
        cout << "### personne invalide" << endl;
        return false;
    } else if (fill == 0) {
        cout << "### le bateau est vide..." << endl;
        return false;
    } else if (!contains(p)) {
        cout << "### " << p->getName() << " n'est pas sur le bateau" << endl;
        return false;
    }
    
    if (canRemove(p) && current->canAdd(p)) {
        current->addPerson(p);
        this->removePerson(p);
        return true;
    }
    return false;
}

/* methode pour tenter de déplacer le bateau
   - si on a réussi à se déplacer, retourne true
   - sinon, affiche l'erreur et retourne false
*/
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

// affichage du bateau et de la rivière
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