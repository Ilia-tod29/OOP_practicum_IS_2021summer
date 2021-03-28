#include "Stormtrooper.h"

void Stormtrooper::cpy(const Stormtrooper& _stormtrooper) {
    this->id = new char[strlen(_stormtrooper.id) + 1];
    strcpy(this->id, _stormtrooper.id);
    this->rank = _stormtrooper.rank;
    this->type = new char[strlen(_stormtrooper.type) + 1];
    strcpy(this->type, _stormtrooper.type);
    this->planet = _stormtrooper.planet;
}

void Stormtrooper::vanish(){
    delete[] this->id;
    delete[] this->type;
}

Stormtrooper::Stormtrooper() {
    this->id = nullptr;
    this->rank = (stormtrooperRank)0;
    this->type = nullptr;
    this->planet = {};
}

Stormtrooper::Stormtrooper(const char* _id, const stormtrooperRank _rank, const char* _type, const Planet _planet){
    this->id = new char[strlen(_id) + 1];
    strcpy(this->id, _id);
    this->rank = _rank;
    this->type = new char[strlen(_type) + 1];
    strcpy(this->type, _type);
    this->planet = _planet;
}

Stormtrooper::Stormtrooper(const Stormtrooper& _stormtrooper) {
    cpy(_stormtrooper);
}

Stormtrooper& Stormtrooper::operator = (const Stormtrooper& stormtrooper) {
    if(this != &stormtrooper) {
        vanish();
        cpy(stormtrooper);
    }
    return *this;
}

Stormtrooper::~Stormtrooper(){
    vanish();
}

void Stormtrooper::setId(const char* _id) {
    delete[] this->id;
    this->id = new char[strlen(_id) + 1];
    strcpy(this->id, _id);
}
void Stormtrooper::setRank(const stormtrooperRank _rank) {
    this->rank = _rank;
}
void Stormtrooper::setType(const char* _type) {
    delete[] this->type;
    this->type = new char[strlen(_type) + 1];
    strcpy(this->type, _type);
}
void Stormtrooper::setPlanet(const Planet _planet) {
    this->planet = _planet;
}

char* Stormtrooper::getId() const {return this->id;}
stormtrooperRank Stormtrooper::getRank() const {return this->rank;}
char* Stormtrooper::getType() const {return this->type;}
Planet Stormtrooper::getPlanet() const {return this->planet;}


std::ostream& operator<<(std::ostream& os, const Stormtrooper& stormtrooper) {
    os << stormtrooper.id << endl;
    switch (stormtrooper.rank) {
        case (stormtrooperRank)0: os << "Cadet"<< endl; break;
        case (stormtrooperRank)1: os << "Private"<< endl; break;
        case (stormtrooperRank)2: os << "Lance Corporal"<< endl; break;
        case (stormtrooperRank)3: os << "Corporal"<< endl; break;
        case (stormtrooperRank)4: os << "Sergeant"<< endl; break;
        case (stormtrooperRank)5: os << "Staff Sergeant"<< endl; break;
        case (stormtrooperRank)6: os << "Master Sergeant"<< endl; break;
        default: os << "Invalid rank" << endl; break;
    }
    os << stormtrooper.type << endl;
    os << stormtrooper.planet.getName() << endl;
    return os;
}

std::istream& operator>>(std::istream& is, Stormtrooper& stormtrooper) {
    delete[] stormtrooper.id;
    delete[] stormtrooper.type;

    char* container = new char[100];
    int temp;

    cout << "Enter id:";
    is.getline(container, 100);
    stormtrooper.id = new char[strlen(container) + 1];
    strcpy(stormtrooper.id, container);

    cout << "Enter rank:";
    is >> temp;
    stormtrooper.rank = (stormtrooperRank)temp;

    is.ignore();

    cout << "Enter type:";
    is.getline(container, 100);
    stormtrooper.type = new char[strlen(container) + 1];
    strcpy(stormtrooper.type, container);
    delete[] container;

    cin >> stormtrooper.planet;
    is.ignore();

    return is;
}

//void Stormtrooper::print() const {
//    cout << "Stormtrooper ID: " << this->id << endl;
//    switch (this->rank) {
//        case Cadet:
//            cout << "Stormtrooper rank: Cadet" << endl;
//            break;
//        case Private:
//            cout << "Stormtrooper rank: Private" << endl;
//            break;
//        case LanceCorporal:
//            cout << "Stormtrooper rank: LanceCorporal" << endl;
//            break;
//        case Corporal:
//            cout << "Stormtrooper rank: Corporal" << endl;
//            break;
//        case Sergeant:
//            cout << "Stormtrooper rank: Sergeant" << endl;
//            break;
//        case StaffSergeant:
//            cout << "Stormtrooper rank: StaffSergeant" << endl;
//            break;
//        case MasterSergeant:
//            cout << "Stormtrooper rank: MasterSergeant"  << endl;
//            break;
//        default:
//            cout << "This Stormtrooper has no rank" << endl;
//            break;
//    }
//    cout << "Stormtrooper type: " << this->type << endl;
//    cout << "Stormtrooper's planet: " << endl;
//    this->planet.print();
//}