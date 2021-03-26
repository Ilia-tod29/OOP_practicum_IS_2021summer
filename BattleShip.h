//
// Created by Ilia on 3/26/2021.
//
#pragma once

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

class BattleShip{
private:
    float speed;
    size_t cannonsCount;
    bool hyperJump;
    float shipSize
    template<class Pilot>
            Pilot pilot;

    void cpy(const BattleShip& _battleShip);

    void vanish();
public:
    BattleShip();
    BattleShip(const float _speed, const size_t _cannonCount, const bool _hyperJump, const float _shipSize, const Pilot _pilot);
    BattleShip(const BattleShip& other);
    BattleShip& operator=(const BattleShip& other);
    ~BattleShip();

    void setSpeed(const float _speed);
    void setCannonCount(const size_t _cannonCount);
    void setHyperJump(const bool _hyperJump);
    void setShipSize(const float _shipSize);
    void setPilot(const Pilot _pilot);

    float getSpeed() const;
    size_t getCannonCount() const;
    bool getHyperJump() const;
    float getShipSize() const;
    Pilot getPilot() const;

    friend std::ostream& operator<<(std::ostream os, const BattleShip& battleShip);
    friend std::istream& operator>>(std::istream is, BattleShip& battleShip)
};