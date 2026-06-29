#include "Car.h"
#include <vector>
#include <string>

using namespace std;

class VehicleUtils {
private:
    VehicleUtils() = delete; 

public:
    // Custom print
    static void printCustomAlert(const string& message);

    // Calculating the arithmetic mean from a list of numbers (power, consumption, etc.)
    static double calculateAverage(const vector<int>& values);

    // Convert Hp to KW
    static double convertHpToKw(int hp);
};
