# Setup Instructions

## C++ Scripts
- **Requirements**: GCC 9+, CUnit.
- **Install**: `sudo apt-get install g++ libcunit1-dev` (Linux).
- **Run**: `g++ -o test src/cpp/firmware_sensor_test.cpp -lcunit && ./test`
- **Notes**: Replace `MockSensor` with target APIs.

## Python Scripts
- **Requirements**: Python 3.8+, pytest.
- **Install**: `pip install pytest`
- **Run**: `pytest -v src/python/firmware_health_test.py`
- **Notes**: Use device logs or mock data.

## Environment
- Yocto/Buildroot, RTOS (e.g., FreeRTOS).
- JTAG, GDB, Valgrind for debugging.
