#include "container.h"

using namespace std;

class Controller {
private:
    int turn;
    Bank* bankLeft;
    Bank* bankRight;
    Boat* boat;
public:
	Controller();
    ~Controller();
	void showMenu() const;
	void embark(string name);
	void disembark(string name);
	void moveBoat();
	void reset();
    void display() const;
    void nextTurn();
};