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
    earth.print<Planet>(earth);
    earth.print(Ilia);
//    earth.print(ObiWan);// -> throws: Process finished with exit code -1073740940 (0xC0000374)
    cout << ObiWan << endl;
    cin >> earth;
    cout << earth;
    cin >> Ilia;
    cout << Ilia;
    cin >> ObiWan;
    cout << ObiWan;
    earth.read<Planet>(stewjon);
    earth.print<Planet>(stewjon);

    earth.read<Stormtrooper>(Ilia);
    earth.print<Stormtrooper>(Ilia);

//    earth.read<Jedi>(ObiWan);// -> throws: Process finished with exit code -1073740940 (0xC0000374)
//    cout << ObiWan;

    cin >> ObiWan;
    cout << ObiWan;
    return 0;
}