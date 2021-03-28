#include "Planet.h"
#include "Stormtrooper.h"
#include "Jedi.h"
#include "BattleShip.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    Planet earth("Earth", "Milky way", "Bulgaria", (planetType)5);
    Planet stewjon("Stewjon", "Astronomical object", "no", (planetType)6);
    Stormtrooper Ilia("FN-72061", MasterSergeant, "Black ninja", earth);
    Jedi ObiWan("Obi Wan Kenobi", (jediRank)6, 9999.9, stewjon, "Human", "No data");
    Jedi ObiWan1("Obi Wan", (jediRank)5, 9979.9, earth, "Human", "No data");
    cout << ObiWan << endl;
    ObiWan = ObiWan1;
    BattleShip<Jedi> spaceRunner(1968.5, 55, 1, 555.5, ObiWan1);
    spaceRunner.print();

    cout << ObiWan << endl;
    ObiWan = ObiWan1;
    cout << ObiWan << endl;
    cout << Ilia << endl;
    cout << earth << endl;
    cout << "-----------------------operator '<<' ^ -----------------------" << endl;
    cout << "-----------------------print() \\/ -----------------------" << endl;
    print<Planet>(earth);
    print<Stormtrooper>(Ilia);
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