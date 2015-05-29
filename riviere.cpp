#include <stdio.h>
#include <iostream>
#include <string>
#include "controller.h"

/* Eleonore d'Agostino et Michael Berthouzoz
   28-05-2015
   Cette application permet de tenter de faire traverser une riviere à une
   famille accompagnée d'un policier et un voleur, à l'aide d'un bateau
   dont on contrôle le déplacement, l'embarquement et le débarquement.
*/

using namespace std;

int main() {
    Controller ctrl;
    ctrl.start();

    return EXIT_SUCCESS;
}