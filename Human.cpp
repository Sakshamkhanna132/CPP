#include "Human.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Human::Human() : name("Unknown"), age(0), height(0.0) {}

Human::Human(string name, int age, double height) {
        this->name = name;     
        this->age = age;       
        this->height = height; 
    }

string Human::getName() const {
    return name;
}

// Get the person's age, though they may not want you to
int Human::getAge() const {
    return age;
}

// Set the person's age, with some basic validation to prevent weirdness
void Human::setAge(int age) {
    if (age >= 0) {
        this->age = age;
    } else {
        cout << "Error: Age cannot be negative. Nice try, time traveler." << endl;
    }
}

// Get the person's height, because apparently it's important to know
double Human::getHeight() const {
    return height;
}

// Set the person's height, but only if it's realistic
void Human::setHeight(double height) {
    if (height >= 0) {
        this->height = height;
    } else {
        cout << "Error: Height cannot be negative. This isn't Wonderland." << endl;
    }
}

// Display all the juicy details about the person
void Human::displayInfo() const {
    cout << "Name: " << name << ", Age: " << age 
         << " (Don't ask further), Height: " << height << " meters." << endl;
}



// class Human {
// private:
//     // Private members: the stuff no one else should mess with directly
//     string name;     // Because every person needs a name, right?
//     int age;         // Your age, the number you start hiding after 30
//     double height;   // Height, because apparently people care about that

// public:
//     // Constructor: Because we need a way to actually create humans, obviously
//     Human(string name, int age, double height) {
//         this->name = name;     // Setting the name (because we can't just call everyone "Human")
//         this->age = age;       // Setting the age, though they'll lie about it eventually
//         this->height = height; // Setting height, because "short" or "tall" isn't specific enough
//     }

//     // Public methods to access the private details (because privacy is a thing)

//     // Get the person's name (since people tend to forget it)
//     string getName() const {
//         return name;
//     }

//     // Get the person's age, though they may not want you to
//     int getAge() const {
//         return age;
//     }

//     // Set the person's age, with some basic validation to prevent weirdness
//     void setAge(int age) {
//         if (age >= 0) {
//             this->age = age;
//         } else {
//             cout << "Error: Age cannot be negative. Nice try, time traveler." << endl;
//         }
//     }

//     // Get the person's height, because apparently it's important to know
//     double getHeight() const {
//         return height;
//     }

//     // Set the person's height, but only if it's realistic
//     void setHeight(double height) {
//         if (height >= 0) {
//             this->height = height;
//         } else {
//             cout << "Error: Height cannot be negative. This isn't Wonderland." << endl;
//         }
//     }

//     // Display all the juicy details about the person
//     void displayInfo() const {
//         cout << "Name: " << name << ", Age: " << age 
//              << " (Don't ask further), Height: " << height << " meters." << endl;
//     }
// };
