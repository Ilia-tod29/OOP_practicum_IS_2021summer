#include "Jedi.h"
#include "Planet.h"

void Jedi::cpy(const Jedi& _jedi) {
    this->name = new char[strlen(_jedi.name) + 1];
    strcpy(this->name, _jedi.name);
    this->rank = _jedi.rank;
    this->planet = _jedi.planet;
    this->species= new char[strlen(_jedi.species) + 1];
    strcpy(this->species, _jedi.species);
    this->militaryRank = new char[strlen(_jedi.militaryRank) + 1];
    strcpy(this->militaryRank, _jedi.militaryRank);
}

void Jedi::vanish() {
    delete[] this->name;
    delete[] this->species;
    delete[] this->militaryRank;
}

Jedi::Jedi() {
    this->name = nullptr;
    this->rank = (jediRank)0;
    this->midiChlorian = 0.0;
    this->planet = {};
    this->species = nullptr;
    this->militaryRank = nullptr;
}

Jedi::Jedi(const char* _name, const jediRank _rank, const float _midiChlorian, const Planet _planet, const char* _species, const char* _militaryRank) {
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
    this->rank = _rank;
    this->midiChlorian = _midiChlorian;
    this->planet = _planet;
    this->species = new char[strlen(_species) + 1];
    strcpy(this->species, _species);
    this->militaryRank = new char[strlen(_militaryRank) + 1];
    strcpy(this->militaryRank, _militaryRank);
}

Jedi& Jedi::operator = (const Jedi& jedi) {
    if (this != &jedi) {
        vanish();
        cpy(jedi);
    }
    return *this;
}

Jedi::~Jedi(){
    vanish();
}

void Jedi::setName(const char* _name) {
    delete[] this->name;
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}
void Jedi::setRank(const jediRank _rank) {
    this->rank = _rank;
}
void Jedi::setMidiChlorian(float _midiChlorian) {
    this->midiChlorian = _midiChlorian;
}
void Jedi::setPlanet(const Planet _planet) {
    this->planet = _planet;
}
void Jedi::setSpecies(const char* _species) {
    delete[] this->species;
    this->species = new char[strlen(_species) + 1];
    strcpy(this->species, _species);
}
void Jedi::setMilitaryRank(const char* _militaryRank) {
    delete[] this->militaryRank;
    this->militaryRank = new char[strlen(_militaryRank) + 1];
    strcpy(this->militaryRank, _militaryRank);
}

char* Jedi::getName() {return this->name;}
jediRank Jedi::getRank() {return this->rank;}
char* Jedi::getMidiChlorian() {return this->militaryRank;}
Planet Jedi::getPlanet() {return this->planet;}
char* Jedi::getSpecies() {return this->species;}
char* Jedi::getMilitaryRank() {return this->militaryRank;}


std::ostream& operator<<(std::ostream& os, Jedi& jedi) {
    os << jedi.name << endl;
    switch (jedi.rank) {
        case (jediRank)0: os << "Youngling" << endl; break;
        case (jediRank)1: os << "Padawan" << endl; break;
        case (jediRank)2: os << "Knight" << endl; break;
        case (jediRank)3: os << "Consular" << endl; break;
        case (jediRank)4: os << "Guardian" << endl; break;
        case (jediRank)5: os << "Sentinel" << endl; break;
        case (jediRank)6: os << "Master" << endl; break;
        default: os << "Invalid rank" << endl; break;
    }
    os << jedi.midiChlorian << endl;
    os << jedi.planet.getName() << endl;
    os << jedi.species << endl;
    os << jedi.militaryRank << endl;
    return os;
}

//void Jedi::print() {
//    cout << "Jedi name: " << this->name << endl;
//    switch (this->rank) {
//        case Youngling:
//            cout << "Jedi rank: Cadet" << endl;
//            break;
//        case Padawan:
//            cout << "Jedi rank: Padawan" << endl;
//            break;
//        case Knight:
//            cout << "Jedi rank: Jedi Knight" << endl;
//            break;
//        case Consular:
//            cout << "Jedi rank: Jedi Consular" << endl;
//            break;
//        case Guardian:
//            cout << "Jedi rank: Jedi Guardian" << endl;
//            break;
//        case Sentinel:
//            cout << "Jedi rank: Jedi Sentinel" << endl;
//            break;
//        case Master:
//            cout << "Jedi rank: Jedi Master" << endl;
//            break;
//        default:
//            cout << "Jedi rank: Cadet" << endl;
//            break;
//    }
//    cout << "Jedi midi-chlorian: " << this->midiChlorian << endl;
//    cout << "Jedi's planet: " << endl;
//    this->planet.print();
//    cout << endl;
//    cout << "Jedi species: " << this->species << endl;
//    cout << "Jedi military rank: " << this->militaryRank << endl;
//}