#include "riviere.h"

using namespace std;

class Controller {
private:
    int turn;
    Bank* bankLeft;
    Bank* bankRight;
    Boat* boat;
public:
    Controller() : turn(0) {}
    ~Controller();
    void showMenu() const;
    void display() const;
    void nextTurn();
};