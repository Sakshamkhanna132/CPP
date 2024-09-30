#include "SuperHuman.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor (needed for std::vector)
SuperHuman::SuperHuman()
    : Human(), planet("Unknown"), environment("Unknown"), superPowerLevel(0), specialAbility("None") {}

SuperHuman::SuperHuman(string name, int age, double height, string planet, string environment, int superPowerLevel, string specialAbility) : Human(name, age, height) {
    this->planet = planet;
    this->environment = environment;
    this->superPowerLevel = superPowerLevel;
    this->specialAbility = specialAbility;
}

string SuperHuman::getPlanet() const {
    return planet;
}

string SuperHuman::getEnvironment() const {
    return environment;
}

int SuperHuman::getSuperPowerLevel() const {
    return superPowerLevel;
}

string SuperHuman::getSpecialAbility() const {
    return specialAbility;
}

void SuperHuman::setPlanet(string planet) {
    this->planet = planet;
}   

void SuperHuman::setEnvironment(string environment) {
    this->environment = environment;
}

void SuperHuman::setSuperPowerLevel(int level) {
    if (level >= 0) {
        superPowerLevel = level;
    } else {
        cout << "Error: Super power level cannot be negative." << endl;
    }
}
void SuperHuman::setSpecialAbility(string specialAbility) {
    this->specialAbility = specialAbility;
}

void SuperHuman::displayInfo() const {
    Human::displayInfo();
    cout << "Planet: " << planet << endl;
    cout << "Environment: " << environment << endl;
    cout << "Super Power Level: " << superPowerLevel << endl;
    cout << "Special Ability: " << specialAbility << endl;
}