#ifndef HUMAN_H
#define HUMAN_H


#include <iostream>
using namespace std;

class Human {
private:
    string name;     
    int age;         
    double height;   

public:
    // Constructor: Because we need a way to actually create humans, obviously
    Human(string name, int age, double height);


    string getName() const;
    int getAge() const;
    void setAge(int age);
    double getHeight() const;
    void setHeight(double height);
    void displayInfo() const;

};



#endif
