#pragma once

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

class Planet {
private:
    char* name;
    char* planetSystem;
    char* republic;

    void cpy(const Planet& _planet);

    void vanish();

public:

    Planet();

    Planet(const char* _name, const char* _planetSystem, const char* _republic);

    Planet(const Planet& _planet);

    Planet& operator = (const Planet& _planet);

    ~Planet();

    void setName(const char* _name);
    void setPlanetSystem(const char* _planetSystem);
    void setRepublic(const char* _republic);

    char* getName();
    char* getPlanetSystem();
    char* getRepublic();

    void print() const;
};