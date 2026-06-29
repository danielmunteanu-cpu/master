#include "ElectricCar.h"
#include "SportsCar.h"
#include "VehicleUtils.h"
#include "Car.h"
int main() {
    DashboardDisplay dash;
    Logger logger;
    ElectricCar* c1 = ElectricCar::getInstance(
        "Sedan",
        "AWD",
        500,
        "Performance",
        "TESLA123",
        100
    );
    SportsCar sport_car1(
        "Petrol",
        "Coupe",
        "RWD",
        700,
        "Sport",
        "FERRARI999",
        340
    );

    cout << "=== Electric Car ===\n";
    c1->showInfo();
    c1->attach(&dash);
    c1->updateBatteryCapacity(85);
    VehicleUtils::printCustomAlert("Statistic...");
    int powerSportsCar = 610;
    cout << powerSportsCar << " CP aprox "
        << VehicleUtils::convertHpToKw(powerSportsCar) << " kW." << endl;

    cout << "\n=== Sports Car ===\n";
    sport_car1.showInfo();
    sport_car1.attach(&dash);
    sport_car1.attach(&logger);
    // Trigger updates that will notify observers
    sport_car1.setSpeed(120);
    cout << "--- 2. Test COPY CONSTRUCTOR (sport_car2 = sport_car1) ---" << endl;
    // New object (sport_car2) Deep Copy sport_car1
    SportsCar sport_car2 = sport_car1;

    cout << "Details sport_car2 (copy):" << endl;
    sport_car2.showInfo();

    cout << "--- 3. Test COPY ASSIGNMENT OPERATOR (sport_car3 = sport_car2) ---" << endl;
    SportsCar sport_car3("Gasoline", "Sedan", "AWD", 200, "Standard", "OLD_VIN_99999", 220);

    sport_car3 = sport_car2;

    cout << "Details sport_car3 after copy assignment:" << endl;
    sport_car3.showInfo();

    cout << "--- 4. Test MOVE CONSTRUCTOR (sport_car4 = move(sport_car1)) ---" << endl;
    SportsCar sport_car4 = move(sport_car1);

    cout << "Details sport_car4 (Took the resources by move):" << endl;
    sport_car4.showInfo();

    cout << "Details sport_car1 after move" << endl;
    sport_car1.showInfo();

    cout << "--- 5. Test MOVE ASSIGNMENT OPERATOR (sport_car3 = move(sport_car2)) ---" << endl;
    sport_car3 = move(sport_car2);

    cout << "Details sport_car3 after copy assignment:" << endl;
    sport_car3.showInfo();

    cout << "Details sport_car2 after move:" << endl;
    sport_car2.showInfo(); // Va afișa VIN: N/A


    return 0;
}

  