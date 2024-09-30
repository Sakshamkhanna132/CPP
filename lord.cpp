// main.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Human.h"
#include "SuperHuman.h"

using namespace std;

// Function prototypes
void displayMenu();
void createHuman(vector<Human>& humans);
void createSuperHuman(vector<SuperHuman>& superHumans);
void listHumans(const vector<Human>& humans);
void listSuperHumans(const vector<SuperHuman>& superHumans);
void modifyHuman(vector<Human>& humans);
void modifySuperHuman(vector<SuperHuman>& superHumans);
void haveFun();

int main() {
    vector<Human> humans;
    vector<SuperHuman> superHumans;
    int choice;

    cout << "Welcome to the World of Humans and SuperHumans!" << endl;
    cout << "Prepare yourself for an adventure filled with ordinary people and extraordinary beings!" << endl;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the input buffer to prevent issues with getline()
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                createHuman(humans);
                break;
            case 2:
                createSuperHuman(superHumans);
                break;
            case 3:
                listHumans(humans);
                break;
            case 4:
                listSuperHumans(superHumans);
                break;
            case 5:
                modifyHuman(humans);
                break;
            case 6:
                modifySuperHuman(superHumans);
                break;
            case 7:
                haveFun();
                break;
            case 0:
                cout << "Thank you for visiting our world. Come back soon!" << endl;
                break;
            default:
                cout << "Hmm, that's not a valid option. Maybe try again?" << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}

// Function to display the main menu
void displayMenu() {
    cout << "\n========== Main Menu ==========" << endl;
    cout << "1. Create a Human" << endl;
    cout << "2. Create a SuperHuman" << endl;
    cout << "3. List all Humans" << endl;
    cout << "4. List all SuperHumans" << endl;
    cout << "5. Modify a Human" << endl;
    cout << "6. Modify a SuperHuman" << endl;
    cout << "7. Have some fun!" << endl;
    cout << "0. Exit" << endl;
}

// Function to create a new Human
void createHuman(vector<Human>& humans) {
    string name;
    int age;
    double height;

    cout << "\nCreating a new Human!" << endl;
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter age: ";
    cin >> age;
    cout << "Enter height (in meters): ";
    cin >> height;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    humans.emplace_back(name, age, height);

    cout << "Human " << name << " has been created. Welcome to the mundane world!" << endl;
}

// Function to create a new SuperHuman
void createSuperHuman(vector<SuperHuman>& superHumans) {
    string name;
    int age;
    double height;
    string planet;
    string environment;
    int superPowerLevel;
    string specialAbility;

    cout << "\nCreating a new SuperHuman!" << endl;
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter age: ";
    cin >> age;
    cout << "Enter height (in meters): ";
    cin >> height;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter planet of origin: ";
    getline(cin, planet);
    cout << "Enter preferred environment: ";
    getline(cin, environment);
    cout << "Enter super power level (0-100): ";
    cin >> superPowerLevel;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter special ability: ";
    getline(cin, specialAbility);

    superHumans.emplace_back(name, age, height, planet, environment, superPowerLevel, specialAbility);

    cout << "SuperHuman " << name << " has joined the ranks of the extraordinary!" << endl;
}

// Function to list all Humans
void listHumans(const vector<Human>& humans) {
    if (humans.empty()) {
        cout << "\nNo Humans to display. Maybe create some first?" << endl;
        return;
    }

    cout << "\nListing all Humans:" << endl;
    for (const auto& human : humans) {
        human.displayInfo();
    }
}

// Function to list all SuperHumans
void listSuperHumans(const vector<SuperHuman>& superHumans) {
    if (superHumans.empty()) {
        cout << "\nNo SuperHumans to display. Perhaps summon some heroes?" << endl;
        return;
    }

    cout << "\nListing all SuperHumans:" << endl;
    for (const auto& superHuman : superHumans) {
        superHuman.displayInfo();
    }
}

// Function to modify a Human
void modifyHuman(vector<Human>& humans) {
    if (humans.empty()) {
        cout << "\nNo Humans to modify. Create some first!" << endl;
        return;
    }

    cout << "\nEnter the name of the Human you wish to modify: ";
    string name;
    getline(cin, name);

    auto it = find_if(humans.begin(), humans.end(), [name](const Human& h) {
        return h.getName() == name;
    });

    if (it != humans.end()) {
        int choice;
        cout << "\nWhat would you like to modify for " << name << "?" << endl;
        cout << "1. Age" << endl;
        cout << "2. Height" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                int newAge;
                cout << "Enter new age: ";
                cin >> newAge;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                it->setAge(newAge);
                cout << name << "'s age has been updated to " << newAge << "." << endl;
                break;
            }
            case 2: {
                double newHeight;
                cout << "Enter new height (in meters): ";
                cin >> newHeight;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                it->setHeight(newHeight);
                cout << name << "'s height has been updated to " << newHeight << " meters." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Returning to main menu." << endl;
                break;
        }
    } else {
        cout << "Human named " << name << " not found. Maybe they were abducted by aliens?" << endl;
    }
}

// Function to modify a SuperHuman
void modifySuperHuman(vector<SuperHuman>& superHumans) {
    if (superHumans.empty()) {
        cout << "\nNo SuperHumans to modify. Create some first!" << endl;
        return;
    }

    cout << "\nEnter the name of the SuperHuman you wish to modify: ";
    string name;
    getline(cin, name);

    auto it = find_if(superHumans.begin(), superHumans.end(), [name](const SuperHuman& sh) {
        return sh.getName() == name;
    });

    if (it != superHumans.end()) {
        int choice;
        cout << "\nWhat would you like to modify for " << name << "?" << endl;
        cout << "1. Super Power Level" << endl;
        cout << "2. Special Ability" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                int newLevel;
                cout << "Enter new Super Power Level (0-100): ";
                cin >> newLevel;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                it->setSuperPowerLevel(newLevel);
                cout << name << "'s Super Power Level has been updated to " << newLevel << "." << endl;
                break;
            }
            case 2: {
                string newAbility;
                cout << "Enter new Special Ability: ";
                getline(cin, newAbility);
                it->setSpecialAbility(newAbility);
                cout << name << " can now " << newAbility << "! Impressive!" << endl;
                break;
            }
            default:
                cout << "Invalid choice. Returning to main menu." << endl;
                break;
        }
    } else {
        cout << "SuperHuman named " << name << " not found. Perhaps they turned invisible?" << endl;
    }
}

// Function for some fun interactions
void haveFun() {
    cout << "\nTime for some fun! Choose an option:" << endl;
    cout << "1. Joke" << endl;
    cout << "2. Random Fact" << endl;
    cout << "3. Surprise me!" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
        case 1:
            cout << "\nWhy did the SuperHuman go to art school? Because they wanted to draw their own conclusions!" << endl;
            break;
        case 2:
            cout << "\nDid you know? The average human walks the equivalent of three times around the world in a lifetime!" << endl;
            break;
        case 3:
            cout << "\nSurprise! You've just unlocked a hidden superpower: Procrastination!" << endl;
            break;
        default:
            cout << "Well, that's mysterious. Even I don't know what that choice does!" << endl;
            break;
    }
}
