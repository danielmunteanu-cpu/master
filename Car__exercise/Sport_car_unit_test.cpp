/*
#define BOOST_TEST_MODULE SportsCarTest
#include <boost/test/included/unit_test.hpp>
#include "SportsCar.h"
#include "Observer.h"
#include <string>

// A mock observer to verify that SportsCar notifies updates correctly
class MockObserver : public Observer {
public:
    std::string lastVin;
    std::string lastProperty;
    int lastValue = -1;
    int notificationCount = 0;

    void StateChanged(const std::string& vin, const std::string& propertyName, int newValue) override {
        lastVin = vin;
        lastProperty = propertyName;
        lastValue = newValue;
        notificationCount++;
    }
};

BOOST_AUTO_TEST_SUITE(SportsCarTests)

BOOST_AUTO_TEST_CASE(TestSportsCarObserverNotification) {
    // 1. Arrange: Create a SportsCar and a mock observer
    SportsCar car("Petrol", "Coupe", "RWD", 700, "Sport", "FERRARI999", 340);
    MockObserver mock;

    // Attach the observer to the car
    car.attach(&mock);

    // Initial state: notification count should be 0
    BOOST_CHECK_EQUAL(mock.notificationCount, 0);

    // 2. Act: Call setSpeed, which should notify the observer
    car.setSpeed(120);

    // 3. Assert: Verify the observer was notified with the correct details
    BOOST_CHECK_EQUAL(mock.notificationCount, 1);
    BOOST_CHECK_EQUAL(mock.lastVin, "FERRARI999");
    BOOST_CHECK_EQUAL(mock.lastProperty, "CurrentSpeed");
    BOOST_CHECK_EQUAL(mock.lastValue, 120);

    // 4. Act: Detach the observer and set speed again
    car.detach(&mock);
    car.setSpeed(150);

    // 5. Assert: The observer should NOT have received the new update
    BOOST_CHECK_EQUAL(mock.notificationCount, 1);
}

BOOST_AUTO_TEST_SUITE_END()
*/