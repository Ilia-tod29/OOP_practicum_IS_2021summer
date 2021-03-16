#include "Planet.h"

void Planet::cpy(const Planet& _planet) {
    this->name = new char[strlen(_planet.name) + 1];
    strcpy(this->name, _planet.name);

    this->planetSystem = new char[strlen(_planet.planetSystem) + 1];
    strcpy(this->planetSystem, _planet.planetSystem);

    this->republic = new char[strlen(_planet.republic) + 1];
    strcpy(this->republic, _planet.republic);

    this->type = _planet.type;
}

void Planet::vanish() {
    delete[] this->name;
    delete[] this->planetSystem;
    delete[] this->republic;
}

Planet::Planet(){
    this->name = nullptr;
    this->planetSystem = nullptr;
    this->republic = nullptr;
    this->type = (planetType)0;
}

Planet::Planet(const char* _name, const char* _planetSystem, const char* _republic, const planetType _type){
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);

    this->planetSystem = new char[strlen(_planetSystem) + 1];
    strcpy(this->planetSystem, _planetSystem);

    this->republic = new char[strlen(_republic) + 1];
    strcpy(this->republic, _republic);

    this->type = _type;
}

Planet::Planet(const Planet& _planet) {
    cpy(_planet);
}

Planet& Planet::operator = (const Planet& _planet) {
    if (this != &_planet) {
        vanish();
        cpy(_planet);
    }
    return *this;
}

Planet::~Planet(){
    vanish();
}

void Planet::setName(const char* _name) {
    delete[] this->name;
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}
void Planet::setPlanetSystem(const char* _planetSystem) {
    delete[] this->planetSystem;
    this->planetSystem = new char[strlen(_planetSystem) + 1];
    strcpy(this->planetSystem, _planetSystem);
}
void Planet::setRepublic(const char* _republic) {
    delete[] this->republic;
    this->republic = new char[strlen(_republic) + 1];
    strcpy(this->republic, _republic);
}
void Planet::setType(const planetType _type) {
    this->type = _type;
}


char* Planet::getName() {return this->name;}
char* Planet::getPlanetSystem() {return this->planetSystem;}
char* Planet::getRepublic(){return this->republic;}
planetType Planet::getType(){return this->type;}


std::ostream& operator<<(std::ostream& os, const Planet& planet) {
    os << planet.name << endl;
    os << planet.planetSystem << endl;
    os << planet.republic << endl;
    switch (planet.type) {
        case (planetType)0: cout << "Chthonian Planet"; break;
        case (planetType)1: cout << "Carbon Planet"; break;
        case (planetType)2: cout << "Coreless Planet"; break;
        case (planetType)3: cout << "Desert Planet"; break;
        case (planetType)4: cout << "Gas Dwarf"; break;
        case (planetType)5: cout << "Gas Giant"; break;
        case (planetType)6: cout << "Helium Planet"; break;
        case (planetType)7: cout << "Ice Giant"; break;
        case (planetType)8: cout << "Ice Planet"; break;
        case (planetType)9: cout << "Iron Planet"; break;
        case (planetType)10: cout << "Lava Planet"; break;
        case (planetType)11: cout << "Ocean Planet"; break;
        case (planetType)12: cout << "Protopanet"; break;
        case (planetType)13: cout << "Puffy Planet"; break;
        case (planetType)14: cout << "Silicate Planet"; break;
        case (planetType)15: cout << "Terrestrial Planet"; break;
    }
}

void Planet::print() const {
    cout << "Planet name: \'" << this->name << "\'. ";
    cout << "It is from the system \'" << this->planetSystem << "\'. ";
    cout << this->name << " is owned by " << this->republic << " republic.";
}