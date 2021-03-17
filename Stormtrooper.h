#include "Planet.h"
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

enum stormtrooperRank {
    Cadet = 0, Private, LanceCorporal, Corporal, Sergeant, StaffSergeant, MasterSergeant
};

class Stormtrooper {
private:
    char* id;
    stormtrooperRank rank;
    char* type;
    Planet planet;

    void cpy(const Stormtrooper& _stormtrooper);

    void vanish();

public:
    Stormtrooper();

    Stormtrooper(const char* _id, const stormtrooperRank _rank, const char* _type, const Planet _planet);

    Stormtrooper(const Stormtrooper& _stormtrooper);

    Stormtrooper& operator = (const Stormtrooper& stormtrooper);

    ~Stormtrooper();

    void setId(const char* _id);
    void setRank(const stormtrooperRank _rank);
    void setType(const char* _type);
    void setPlanet(const Planet _planet);

    char* getId();
    stormtrooperRank getRank();
    char* getType();
    Planet getPlanet();

    friend std::ostream& operator<<(std::ostream& os, Stormtrooper& stormtrooper);
   // void print() const;
};