#include "Car.h"

class ElectricCar : public Car {
private:
    int batteryCapacity;

    static ElectricCar* instance;
    ElectricCar(string b,
        string d,
        int p,
        string t,
        const char* vin,
        int battery);
public:
    void updateBatteryCapacity(int newCapacity) {
        batteryCapacity = newCapacity;
        notify("BatteryCapacity", batteryCapacity);
    }
    static ElectricCar* getInstance(string b,
        string d,
        int p,
        string t,
        const char* vin,
        int battery);

    virtual ~ElectricCar();
    void showInfo() override;

    
};
