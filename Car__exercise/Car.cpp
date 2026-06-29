#include "Car.h"
#include <algorithm>

Car::Car(string f,
    string b,
    string d,
    int p,
    string t,
    const char* vin)
{
    fuel = f;
    bodyType = b;
    drivetrain = d;
    power = p;
    trimLevel = t;
    cout << "Car constructor\n";
    vinNumber = new char[strlen(vin) + 1];
    strcpy(vinNumber, vin);
}

Car::~Car() {
    cout << "Car destructor\n";
    delete[] vinNumber;
}
void Car::attach(Observer* observer) {
    if (observer) {
        observers.push_back(observer);
    }
}
void Car::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}
void Car::notify(const std::string& propertyName, int newValue) {
    std::string vinStr = vinNumber ? vinNumber : "N/A";
    for (auto observer : observers) {
        observer->StateChanged(vinStr, propertyName, newValue);
    }
}