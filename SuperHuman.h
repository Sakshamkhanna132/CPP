#ifndef SUPERHUMAN_H
#define SUPERHUMAN_H

#include "Human.h"
#include <iostream>
using namespace std;

class SuperHuman : Human {

private:

    string planet;
    string environment;
    int superPowerLevel;
    string specialAbility;

public:

    SuperHuman(string name, int age, double height, string planet, string environment, int superPowerLevel, string specialAbility);

    string getPlanet() const;
    string getEnvironment() const;
    int getSuperPowerLevel() const;
    string getSpecialAbility() const;

    void setPlanet(string planet);
    void setEnvironment(string environment);
    void setSuperPowerLevel(int superPowerLevel);
    void setSpecialAbility(string specialAbility);

    void displayInfo() const;



};

#endif