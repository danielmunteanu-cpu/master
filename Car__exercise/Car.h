#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <cstring>
#include <vector>
#include "Observer.h" // Include the Observer interface
using namespace std;

class Car {
protected:
    string fuel;
    string bodyType;
    string drivetrain;
    int power;
    string trimLevel;
    char* vinNumber;
    // List of observers
    std::vector<Observer*> observers;
public:
    Car(string f,
        string b,
        string d,
        int p,
        string t,
        const char* vin);

    virtual ~Car();
    virtual void showInfo() = 0;
    // Observer management methods
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify(const std::string& propertyName, int newValue);
};

#endif