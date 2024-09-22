#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Human {
private:
    // Private members: the stuff no one else should mess with directly
    string name;     // Because every person needs a name, right?
    int age;         // Your age, the number you start hiding after 30
    double height;   // Height, because apparently people care about that

public:
    // Constructor: Because we need a way to actually create humans, obviously
    Human(string name, int age, double height) {
        this->name = name;     // Setting the name (because we can't just call everyone "Human")
        this->age = age;       // Setting the age, though they'll lie about it eventually
        this->height = height; // Setting height, because "short" or "tall" isn't specific enough
    }

    // Public methods to access the private details (because privacy is a thing)

    // these are getters --> helps to get the values of private attributes from outside the class

    // Get the person's name (since people tend to forget it)
    string getName() const {
        return name;
    }

    // Get the person's age, though they may not want you to
    int getAge() const {
        return age;
    }

    // Get the person's height, because apparently it's important to know
    double getHeight() const {
        return height;
    }

    // Set the person's age, with some basic validation to prevent weirdness
    void setAge(int age) {
        if (age >= 0) {
            this->age = age;
        } else {
            cout << "Error: Age cannot be negative. Nice try, time traveler." << endl;
        }
    }

    

    // Set the person's height, but only if it's realistic
    void setHeight(double height) {
        if (height >= 0) {
            this->height = height;
        } else {
            cout << "Error: Height cannot be negative. This isn't Wonderland." << endl;
        }
    }

    // Display all the juicy details about the person
    void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age 
             << ", Height: " << height << " meters." << endl;
    }
};

int main() {

    // Create a bunch of people
    vector<Human> humans;
    // humans.push_back(Human("Alice", 5, 1.7));
    // humans.push_back(Human("Bob", 10, 1.8));

    string name;
    int age;
    double height;
    while (true) {
        cout << "Enter name (or 'exit' to quit): ";
        cin >> name;
        if (name == "exit") {
            break;
        }
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter height (in meters): ";
        cin >> height;
        humans.push_back(Human(name, age, height));
    }

    // Display their details
    for (Human x : humans) {
        x.displayInfo();
    }

    

    // Set their ages
    // humans[0].setAge(15);
    // humans[1].setAge(20);

    // // Display their details again  
    // for (Human human : humans) {
    //     human.displayInfo();
    // }

    return 0;
}
