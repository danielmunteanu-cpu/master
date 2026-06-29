#include "Car.h"

class SportsCar : public Car {
private:
    int topSpeed;
    int currentSpeed = 0; // State variable

public:
    SportsCar(string f, string b, string d, int p, string t, const char* vin, int speed);
    // 1. Destructor
    virtual ~SportsCar();
    // 2. Copy Constructor
    SportsCar(const SportsCar& other);
    // 3. Copy Assignment Operator
    SportsCar& operator=(const SportsCar& other);
    // 4. Move Constructor
    SportsCar(SportsCar&& other) noexcept;
    // 5. Move Assignment Operator
    SportsCar& operator=(SportsCar&& other) noexcept;

    void showInfo() override;
    void setSpeed(int speed) {
        currentSpeed = speed;
        notify("CurrentSpeed", currentSpeed);
    }
};
