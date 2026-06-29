#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

// The Observer Interface
class Observer {
public:
    virtual ~Observer() = default;

    // Triggered when a tracked property on a car changes
    virtual void StateChanged(const std::string& vin, const std::string& propertyName, int newValue) = 0;
};

class DashboardDisplay : public Observer {
public:
    void StateChanged(const std::string& vin, const std::string& propertyName, int newValue) override;
};

class Logger : public Observer {
public:
    void StateChanged(const std::string& vin, const std::string& propertyName, int newValue) override;
};

#endif // OBSERVER_H