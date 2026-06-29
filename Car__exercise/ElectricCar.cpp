#include "ElectricCar.h"

ElectricCar* ElectricCar::instance = nullptr;

ElectricCar::ElectricCar(string b,
    string d,
    int p,
    string t,
    const char* vin,
    int battery)
    : Car("Electric", b, d, p, t, vin)
{
    batteryCapacity = battery;
    cout << "ElectricCar constructor\n";
}
ElectricCar::~ElectricCar() {
    cout << "ElectricCar destructor\n";
}
ElectricCar* ElectricCar::getInstance(string b,
    string d,
    int p,
    string t,
    const char* vin,
    int battery)
{
    if (instance == nullptr) {
        instance = new ElectricCar(b, d, p, t, vin, battery);
    }
    else {
        cout << "ElectricCar already exists!\n";
    }

    return instance;
}

void ElectricCar::showInfo() {
    cout << "Fuel: " << fuel << endl;
    cout << "Body Type: " << bodyType << endl;
    cout << "Drivetrain: " << drivetrain << endl;
    cout << "Power: " << power << " HP" << endl;
    cout << "Trim: " << trimLevel << endl;
    cout << "VIN: " << vinNumber << endl;
    cout << "Battery: " << batteryCapacity << " kWh" << endl;
}
