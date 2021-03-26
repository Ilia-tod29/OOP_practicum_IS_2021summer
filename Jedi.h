#include "Planet.h"
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

enum jediRank {
    Youngling = 0, Padawan, Knight, Consular, Guardian, Sentinel, Master
};

class Jedi {
private:
    char* name;
    jediRank rank;
    float midiChlorian;
    Planet planet;
    char* species;
    char* militaryRank;

    void cpy(const Jedi& _jedi);

    void vanish();

public:
    Jedi();

    Jedi(const char* _name, const jediRank _rank, const float _midiChlorian, const Planet _planet, const char* _species, const char* _militaryRank);

    Jedi& operator = (const Jedi& jedi);

    ~Jedi();

    void setName(const char* _name);
    void setRank(const jediRank _rank);
    void setMidiChlorian(float _midiChlorian);
    void setPlanet(const Planet _planet);
    void setSpecies(const char* _species);
    void setMilitaryRank(const char* _militaryRank);

    char* getName() const;
    jediRank getRank() const;
    char* getMidiChlorian() const;
    Planet getPlanet() const;
    char* getSpecies() const;
    char* getMilitaryRank() const;

    friend std::ostream& operator<<(std::ostream& os, const Jedi& jedi);
    friend std::istream& operator>>(std::istream& is, Jedi& jedi);
   // void print();
};