//
// Created by Ilia on 3/26/2021.
//
#pragma once

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

template<class Pilot>
class BattleShip{
private:
    float speed;
    size_t cannonsCount;
    bool hyperJump;
    float shipSize;
    Pilot pilot;

    void cpy(const BattleShip& other) {
        this->speed = other.speed;
        this->cannonsCount = other.cannonsCount;
        this->hyperJump = other.hyperJump;
        this->shipSize = other.shipSize;
        this->pilot = other.pilot;
    }

    void vanish() {
        this->speed = 0;
        this->cannonsCount = 0;
        this->hyperJump = false;
        this->shipSize = 0;
    }
public:
    BattleShip() {
        vanish();
    }
    BattleShip(const float _speed, const size_t _cannonCount, const bool _hyperJump, const float _shipSize, const Pilot _pilot) {
        this->speed = _speed;
        this->cannonsCount = _cannonCount;
        this->hyperJump = _hyperJump;
        this->shipSize = _shipSize;
        try {
            if (typeid(pilot) == typeid(Jedi) || typeid(pilot) == typeid(Stormtrooper)) {
                this->pilot = _pilot;
            }
        }
        catch() {
            cout << "Invalid Pilot" << endl;
        }
    }
    BattleShip(const BattleShip& other) {
        cpy(other);
    }
    BattleShip& operator=(const BattleShip& other) {
        cpy(other);
    }
    ~BattleShip() {
        vanish();
    };

    void setSpeed(const float _speed) {this->speed = _speed};
    void setCannonCount(const size_t _cannonCount) {this->cannonsCount = _cannonCount};
    void setHyperJump(const bool _hyperJump) {this->hyperJump = _hyperJump};
    void setShipSize(const float _shipSize) {this->shipSize = _shipSize};
    void setPilot(const Pilot _pilot) {
        try {
            if (typeid(pilot) == typeid(Jedi) || typeid(pilot) == typeid(Stormtrooper)) {
                this->pilot = _pilot;
            }
        }
        catch() {
            cout << "Invalid Pilot" << endl;
        }
    }

    float getSpeed() const {return this->speed}
    size_t getCannonCount() const {return this->cannonsCount}
    bool getHyperJump() const {return this->hyperJump}
    float getShipSize() const {return this->shipSize}
    Pilot getPilot() const {return this->pilot}

    friend std::ostream& operator<<(std::ostream os, const BattleShip& battleShip) {
        os << "Max speed: " << this->speed << endl;
        os << "Cannon count: " << this->cannonsCount << endl;
        os << "Hyperjump: " << this->hyperJump ? "Yes" : "No" << endl;
        os << "Size of the ship (in meters): " << this->shipSize << endl;
        os << "Pilot: " << endl << this->pilot << endl;
        return os;
    }
    friend std::istream& operator>>(std::istream is, BattleShip& battleShip) {
        is >> this->speed >> this->cannonsCount >> this->hyperJump >> this->shipSize >> this->pilot;
        return is;
    }

};