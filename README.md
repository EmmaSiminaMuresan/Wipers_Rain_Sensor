# C++ Wiper Control System with Google Test 🚗

This project is a **C++ implementation of a wiper control system**, designed to simulate and test wiper speed adjustments based on rain sensor input and button states. The system was developed using **C++17** and follows a structured software development approach, incorporating **unit testing with Google Test (gTest)**.

## 🛠 Key Features:
- **Wiper Speed Calculation**: Adjusts based on rain intensity and user input.
- **Sensor Integration**: Simulates rain sensor data and button controls.
- **Mocking with Google Test**: Ensures robust unit testing of components.
- **Object-Oriented Design**: Uses classes for actuators, sensors, and controllers.

## 📂 Project Structure:
- **`firstapp.cpp`** - Main file handling execution and testing scenarios.
- **`Manager_Wipers.h`** - Core logic for controlling wiper speed.
- **`Manager_Actuators.h`** - Manages interactions with actuators.
- **`Sensor_Rain.h` & `Sensor.h`** - Handles rain detection.
- **`Button.h`** - Simulates button inputs.
- **`Wipers.h`** - Defines wiper behavior.
- **`Data_Type.h`** - Enumerations for button states and wiper speeds.
- **`Manager_Wipers_Mock.h`** - Mock version for unit testing with Google Test.

## 🎓 Workshop Experience:
This project was developed as part of the "Exploring C++ and Google Test: Mastering the Software Development Cycle" workshop at ARRK Engineering Academy. The workshop provided hands-on experience with C++17, unit testing methodologies, and the Google Test framework, focusing on mocking, structured validation, and automation for reliable software development.

## 📌 Notes:
- Requires a C++17-compatible compiler.
- Google Test is used for unit testing (mocking supported).
- This implementation can be expanded for real-world automotive applications.
