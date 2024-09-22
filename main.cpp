// main.cpp
#include <iostream>
#include "SuperHuman.h"

using namespace std;

int main() {
    // Create SuperHuman objects
    SuperHuman superJohn("John", 30, 1.75, "Earth", "Urban", 100, "Flight");
    SuperHuman superAlice("Alice", 29, 1.68, "Mars", "Desert", 85, "Invisibility");

    // Display initial information
    cout << "Initial information:" << endl;
    superJohn.displayInfo();
    superAlice.displayInfo();

    // Modify attributes
    cout << "Modifying attributes:" << endl;
    superJohn.setSuperPowerLevel(110);
    superAlice.setSpecialAbility("Telepathy");

    // Display updated information
    cout << "Updated information:" << endl;
    superJohn.displayInfo();
    superAlice.displayInfo();

    return 0;
}
