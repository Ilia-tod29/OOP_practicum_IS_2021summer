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
        case (planetType)0: os << "Chthonian Planet" << endl; break;
        case (planetType)1: os << "Carbon Planet" << endl; break;
        case (planetType)2: os << "Coreless Planet" << endl; break;
        case (planetType)3: os << "Desert Planet" << endl; break;
        case (planetType)4: os << "Gas Dwarf" << endl; break;
        case (planetType)5: os << "Gas Giant" << endl; break;
        case (planetType)6: os << "Helium Planet" << endl; break;
        case (planetType)7: os << "Ice Giant" << endl; break;
        case (planetType)8: os << "Ice Planet" << endl; break;
        case (planetType)9: os << "Iron Planet" << endl; break;
        case (planetType)10: os << "Lava Planet" << endl; break;
        case (planetType)11: os << "Ocean Planet" << endl; break;
        case (planetType)12: os << "Protopanet" << endl; break;
        case (planetType)13: os << "Puffy Planet" << endl; break;
        case (planetType)14: os << "Silicate Planet" << endl; break;
        case (planetType)15: os << "Terrestrial Planet" << endl; break;
        default: os << "Invalid type" << endl; break;
    }
    return os;
}

std::istream& operator >> (std::istream& is, Planet& planet) {
    delete[] planet.name;
    delete[] planet.planetSystem;
    delete[] planet.republic;

    char* container = new char[100];
    int temp;

    cout << "Enter planet name:";
    is.getline(container, 100);
    planet.name = new char[strlen(container) + 1];
    strcpy(planet.name, container);

    cout << "Enter planet system:";
    is.getline(container, 100);
    planet.planetSystem = new char[strlen(container) + 1];
    strcpy(planet.planetSystem, container);

    cout << "Enter republic:";
    is.getline(container, 1000);
    planet.republic = new char[strlen(container) + 1];
    strcpy(planet.republic, container);
    delete[] container;

    cout << "Enter planet type:";
    is >> temp;
    planet.type = (planetType)temp;
    is.ignore();

    return is;
}

//template<class T>
//void Planet::print(T toPrint) {
//    cout << toPrint << endl;
//}

//void Planet::print() const {
//    cout << "Planet name: \'" << this->name << "\'. ";
//    cout << "It is from the system \'" << this->planetSystem << "\'. ";
//    cout << this->name << " is owned by " << this->republic << " republic.";
//}