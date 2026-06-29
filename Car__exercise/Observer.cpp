#include "Observer.h"
#include <iostream>

void DashboardDisplay::StateChanged(const std::string& vin, const std::string& propertyName, int newValue) {
    std::cout << "\n>>> [Dashboard UI (" << vin << ")] Property \""
        << propertyName << "\" updated to: " << newValue << " <<<\n";
}

void Logger::StateChanged(const std::string& vin, const std::string& propertyName, int newValue) {
    std::cout << "[LOG (" << vin << ")] State update: "
        << propertyName << " -> " << newValue << "\n";
}