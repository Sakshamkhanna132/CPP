#include <iostream>
#include <string>
using namespace std;

class Fruit {
  private:
    string name;
    int quantity;

  public:
    // constructor
    Fruit(string name, int quantity) {
      this->name = name;
      this->quantity = quantity;
    }

    // getter
    string getName() {
      return name;
    }

    // getter
    int getQuantity() {
      return quantity;
    }

    // setter
    void setQuantity(int quantity) {
      this->quantity = quantity;
    }
};

int main() {
  // create an object of class Fruit
  Fruit apple("apple", 5);

  // access the private member using public getter
  cout << apple.getName() << " : " << apple.getQuantity() << endl;

  // modify the private member using public setter
  apple.setQuantity(10);

  // access the private member using public getter
  cout << apple.getName() << " : " << apple.getQuantity() << endl;

  return 0;
}


