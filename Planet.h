#pragma once

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

enum planetType {
        ChthonianPlanet = 0, CarbonPlanet, CorelessPlanet, DesertPlanet, GasDwarf,
        GasGiant, HeliumPlanet, IceGiant, IcePlanet, IronPlanet, LavaPlanet,
        OceanPlanet, Protopanet, PuffyPlanet, SilicatePlanet, TerrestrialPlanet
};
class Planet {
private:
    char* name;
    char* planetSystem;
    char* republic;
    planetType type;

    void cpy(const Planet& _planet);

    void vanish();

public:

    Planet();

    Planet(const char* _name, const char* _planetSystem, const char* _republic, const planetType _type);

    Planet(const Planet& _planet);

    Planet& operator = (const Planet& _planet);

    ~Planet();

    void setName(const char* _name);
    void setPlanetSystem(const char* _planetSystem);
    void setRepublic(const char* _republic);
    void setType(const planetType _type);

    char* getName();
    char* getPlanetSystem();
    char* getRepublic();
    planetType getType();

    friend std::ostream& operator<<(std::ostream& os, const Planet& planet);
    void print() const;
};