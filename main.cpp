#include "Planet.h"
#include "Stormtrooper.h"
#include "Jedi.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    Planet earth("Earth", "Milky way", "Bulgaria", (planetType)5);
    Planet stewjon("Stewjon", "Astronomical object", "no", (planetType)6);
    Stormtrooper Ilia("FN-72061", MasterSergeant, "Black ninja", earth);
    Jedi ObiWan("Obi Wan Kenobi", (jediRank)6, 9999.9, stewjon, "Human", "No data");
    Ilia.print();
    cout << endl << endl;
    ObiWan.print();
    cout << endl;
    earth.print();
    return 0;
}