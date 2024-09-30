// // main.cpp
// #include <iostream>
// #include "SuperHuman.h"

// using namespace std;

// int main() {
//     // Create SuperHuman objects
//     SuperHuman superJohn("John", 30, 1.75, "Earth", "Urban", 100, "Flight");
//     SuperHuman superAlice("Alice", 29, 1.68, "Mars", "Desert", 85, "Invisibility");

//     // Display initial information
//     cout << "Initial information:" << endl;
//     superJohn.displayInfo();
//     superAlice.displayInfo();

//     // Modify attributes
//     cout << "Modifying attributes:" << endl;
//     superJohn.setSuperPowerLevel(110);
//     superAlice.setSpecialAbility("Telepathy");

//     // Display updated information
//     cout << "Updated information:" << endl;
//     superJohn.displayInfo();
//     superAlice.displayInfo();

//     return 0;
// }



// main.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include "Human.h"
#include "SuperHuman.h"

using namespace std;

int main() {
    // Create vectors to store Humans and SuperHumans
    vector<Human> humans;
    vector<SuperHuman> superHumans;

    // Add Human objects
    humans.emplace_back("Bob", 25, 1.80);
    humans.emplace_back("Carol", 32, 1.65);
    humans.emplace_back("Dave", 40, 1.75);

    // Add SuperHuman objects
    superHumans.emplace_back("John", 30, 1.75, "Earth", "Urban", 100, "Flight");
    superHumans.emplace_back("Alice", 29, 1.68, "Mars", "Desert", 85, "Invisibility");
    superHumans.emplace_back("Eve", 35, 1.70, "Venus", "Forest", 90, "Telekinesis");

    // Display Humans
    cout << "List of Humans:" << endl;
    for (const auto& human : humans) {
        human.displayInfo();
    }

    // Display SuperHumans
    cout << "\nList of SuperHumans:" << endl;
    for (const auto& superHuman : superHumans) {
        superHuman.displayInfo();
    }

    // Sort Humans by age (ascending order)
    sort(humans.begin(), humans.end(), [](const Human& a, const Human& b) {
        return a.getAge() < b.getAge();
    });

    // Sort SuperHumans by super power level (descending order)
    sort(superHumans.begin(), superHumans.end(), [](const SuperHuman& a, const SuperHuman& b) {
        return a.getSuperPowerLevel() > b.getSuperPowerLevel();
    });

    // Display sorted lists
    cout << "\nHumans sorted by age:" << endl;
    for (const auto& human : humans) {
        human.displayInfo();
    }

    cout << "\nSuperHumans sorted by Super Power Level:" << endl;
    for (const auto& superHuman : superHumans) {
        superHuman.displayInfo();
    }

    // Find a Human by name
    string searchName = "Carol";
    auto it = find_if(humans.begin(), humans.end(), [searchName](const Human& h) {
        return h.getName() == searchName;
    });

    if (it != humans.end()) {
        cout << "\nFound Human:" << endl;
        it->displayInfo();
    } else {
        cout << "\nHuman named " << searchName << " not found." << endl;
    }

    return 0;
}
