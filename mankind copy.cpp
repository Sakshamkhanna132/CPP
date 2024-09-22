#include <iostream>
#include <string>
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
             << " (Don't ask further), Height: " << height << " meters." << endl;
    }
};

int main() {
    // Creating a Human object: Meet John, another average guy
    Human john("John", 30, 1.75);  // John is the unfortunate subject here

    // Using public methods to show John's current status in life
    john.displayInfo();  // Oh look, John is 30 and 1.75m tall, how exciting

    // John's having a birthday and grew a little (hey, it could happen)
    john.setAge(32);     // John's now 32, probably still telling people he's 29
    john.setHeight(1.80); // He swears he grew 5 cm. Sure, John. Sure.

    john.displayInfo();  // Let's see if anyone buys that new height claim

    // Trying to access the private stuff directly would cause an error:
    // cout << john.name; // Oops, can't just shout out his name. What is this, an invasion of privacy?

    return 0;
}
