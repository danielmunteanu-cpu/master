#include "SportsCar.h"

SportsCar::SportsCar(string f, string b, string d, int p, string t, const char* vin, int speed)
    : Car(f, b, d, p, t, vin)
{
    cout << "SportsCar constructor\n";
    topSpeed = speed;
}
SportsCar::~SportsCar() {
    cout << "SportsCar destructor\n";
}
// 2. Copy Constructor (Rule of 3)
SportsCar::SportsCar(const SportsCar& other) : Car(other) {
    this->topSpeed = other.topSpeed;

    if (other.vinNumber) {
        this->vinNumber = new char[strlen(other.vinNumber) + 1];
        strcpy(this->vinNumber, other.vinNumber);
    }
    else {
        this->vinNumber = nullptr;
    }
}
// 3. Copy Assignment Operator (Rule of 3)
SportsCar& SportsCar::operator=(const SportsCar& other) {
    if (this != &other) {
        fuel = other.fuel;
        bodyType = other.bodyType;
        drivetrain = other.drivetrain;
        power = other.power;
        trimLevel = other.trimLevel;
        topSpeed = other.topSpeed;

        delete[] vinNumber;
        if (other.vinNumber) {
            vinNumber = new char[strlen(other.vinNumber) + 1];
            strcpy(vinNumber, other.vinNumber);
        }
        else {
            vinNumber = nullptr;
        }
    }
    return *this;
}
// 4. Move Constructor (Rule of 5 - C++11)
SportsCar::SportsCar(SportsCar&& other) noexcept : Car(move(other)) {
    this->topSpeed = other.topSpeed;
    other.topSpeed = 0;

    this->vinNumber = other.vinNumber;
    other.vinNumber = nullptr;
}
// 5. Move Assignment Operator (Rule of 5 - C++11)
SportsCar& SportsCar::operator=(SportsCar&& other) noexcept {
    if (this != &other) {
        delete[] vinNumber;

        fuel = move(other.fuel);
        bodyType = move(other.bodyType);
        drivetrain = move(other.drivetrain);
        power = other.power;
        trimLevel = move(other.trimLevel);
        topSpeed = other.topSpeed;

        vinNumber = other.vinNumber;

        other.topSpeed = 0;
        other.vinNumber = nullptr;
    }
    return *this;
}
void SportsCar::showInfo() {
    cout << "Fuel: " << fuel << endl;
    cout << "Body Type: " << bodyType << endl;
    cout << "Drivetrain: " << drivetrain << endl;
    cout << "Power: " << power << " HP" << endl;
    cout << "Trim: " << trimLevel << endl;
    cout << "VIN: " << vinNumber << endl;
    cout << "Top Speed: " << topSpeed << " km/h" << endl;
}
