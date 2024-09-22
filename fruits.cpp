#include <iostream>
#include <string>
using namespace std;

class Fruit {
private:
    string name;     // Private member: can only be accessed within the class
    int quantity;    // Private member: can only be accessed within the class
    double price;    // New private member

public:
    // Constructor
    Fruit(string name, int quantity, double price) {
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }

    // Public methods to access and modify private members
    string getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantity) {
        if (quantity >= 0) {
            this->quantity = quantity;
        } else {
            cout << "Error: Quantity cannot be negative." << endl;
        }
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        if (price >= 0) {
            this->price = price;
        } else {
            cout << "Error: Price cannot be negative." << endl;
        }
    }

    // Public method to calculate total value
    double getTotalValue() const {
        return quantity * price;
    }

    // Public method to display fruit information
    void displayInfo() const {
        cout << "Fruit: " << name << ", Quantity: " << quantity 
             << ", Price: $" << price << ", Total Value: $" << getTotalValue() << endl;
    }
};

int main() {
    // Creating a Fruit object
    Fruit apple("Apple", 5, 0.5);

    // Using public methods to interact with the object
    apple.displayInfo();

    apple.setQuantity(10);
    apple.setPrice(0.75);

    apple.displayInfo();

    // This would cause a compilation error:
    // cout << apple.name; // Error: 'name' is private

    return 0;
}