#include "Planet.h"

void Planet::cpy(const Planet& _planet) {
    this->name = new char[strlen(_planet.name) + 1];
    strcpy(this->name, _planet.name);

    this->planetSystem = new char[strlen(_planet.planetSystem) + 1];
    strcpy(this->planetSystem, _planet.planetSystem);

    this->republic = new char[strlen(_planet.republic) + 1];
    strcpy(this->republic, _planet.republic);
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
}

Planet::Planet(const char* _name, const char* _planetSystem, const char* _republic){
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);

    this->planetSystem = new char[strlen(_planetSystem) + 1];
    strcpy(this->planetSystem, _planetSystem);

    this->republic = new char[strlen(_republic) + 1];
    strcpy(this->republic, _republic);
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

char* Planet::getName() {return this->name;}
char* Planet::getPlanetSystem() {return this->planetSystem;}
char* Planet::getRepublic(){return this->republic;}

void Planet::print() const {
    cout << "Planet name: \'" << this->name << "\'. ";
    cout << "It is from the system \'" << this->planetSystem << "\'. ";
    cout << this->name << " is owned by " << this->republic << " republic.";
}