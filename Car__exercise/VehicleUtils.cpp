#include "VehicleUtils.h"

void VehicleUtils::printCustomAlert(const string& message) {
    cout << "[System alert] >>> " << message << " <<<" << endl;
}

double VehicleUtils::calculateAverage(const vector<int>& values) {
    if (values.empty()) return 0.0;

    int sum = 0;
    for (int val : values) {
        sum += val;
    }
    return static_cast<double>(sum) / values.size();
}

double VehicleUtils::convertHpToKw(int hp) {
    return hp * 0.745699; // 1 CP = ~0.746 kW
}