// Tests I2C/CAN sensor for ARM firmware
#include <cassert>
#include <iostream>
#include <chrono>

// Mock drivers (replace with I2C/CAN APIs)
class MockSensor {
public:
    static bool init() { return true; }
    static bool read_data(double& data) { data = 42.0; return true; }
    static double get_response_time() { return 45.0; } // ms
};

void test_sensor() {
    auto start = std::chrono::high_resolution_clock::now();
    double data;
    assert(MockSensor::init() && "Sensor init failed");
    assert(MockSensor::read_data(data) && "Sensor read failed");
    assert(data == 42.0 && "Data incorrect");
    double response_time = MockSensor::get_response_time();
    assert(response_time < 50 && "Response exceeds 50ms");
    auto end = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration<double, std::milli>(end - start).count();
    std::cout << "Sensor data: " << data << ", Response: " << response_time << "ms\n";
}

int main() {
    test_sensor();
    return 0;
}
