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
    cout << Ilia << endl;
    cout << ObiWan << endl;
    cout << earth << endl;
    cout << "-----------------------operator '<<' ^ -----------------------" << endl;
    cout << "-----------------------print() \\/ -----------------------" << endl;
    print<Planet>(earth);
    print<Stormtrooper>(Ilia);
    cout << ObiWan << endl;
    cin >> earth;
    cout << earth;
    cin >> Ilia;
    cout << Ilia;
    cin >> ObiWan;
    cout << ObiWan;
    read<Planet>(stewjon);
    print<Planet>(stewjon);

    read<Stormtrooper>(Ilia);
    print<Stormtrooper>(Ilia);

    read<Jedi>(ObiWan);
    cout << ObiWan;
    return 0;
}