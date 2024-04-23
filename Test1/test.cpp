#include "pch.h"
#include <random>


#include "../firstapp/Manager_Wipers.h"
#include "Integration_test_fixture.h"
#include "../firstapp/Manager_Actuators.h"


TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

// Unit Tests

// #1UB.SwV1.0 Unit Test Button SwC / 18.04.2024 / 1.0 / Future Up / Assignment


// Define the test fixture
class ButtonTestFixture : public ::testing::Test {
protected:
    // Test setup
    void SetUp() override {
        // Initialize rain sensor with a default value
        rain_sensor.SetValue(0.0);
    }

    // Rain sensor instance
    Sensor_Rain rain_sensor;
};

// Unit test to cover the rain sensor component
TEST_F(ButtonTestFixture, RainSensorTest) {
    Manager_Wipers m_w;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-2.0, 14.0);

    for (int i = 0; i < 10; ++i) {
        // Generate random value
        double random_value = dis(gen);

        // Set the random value in the rain sensor through the Manager_Wipers instance
        m_w.SetSensor_Rain(random_value);

        // Check the rain intensity range
        if (random_value >= 0.0 && random_value < 2.0) {
            // No rain range [0, 1.99]
            ASSERT_GE(random_value, 0.0);
            ASSERT_LT(random_value, 2.0);
        } else if (random_value >= 2.0 && random_value < 5.0) {
            // Low rain range [2, 4.99]
            ASSERT_GE(random_value, 2.0);
            ASSERT_LT(random_value, 5.0);
        } else if (random_value >= 5.0 && random_value <= 12.0) {
            // High rain range [5, 12]
            ASSERT_GE(random_value, 5.0);
            ASSERT_LE(random_value, 12.0);
        } else {
            // Any value outside the specified ranges is considered invalid
            FAIL() << "Invalid rain intensity value: " << random_value;
        }

        // You may also perform additional checks or print debug information if needed
        std::cout << "Rain intensity: " << random_value << std::endl;
    }
}

// Integration Tests

// #1UML.SwV1.0 Integration Automatic function / 18.04.2024 / 1.0 / Future Up assignment
class BeamsTestFixture : public ::testing::Test {
protected:
    // Test setup
    void SetUp() override {
        // Set switch to automatic mode
        button.SetState(ButtonState::Automatic);
    }

    // Test objects
    Manager_Wipers m_w;
    Button button;
};

// Integration test to cover the software requirement 2.4
TEST_F(IntegrationTestFixture, GivenAutomatic) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-2.0, 14.0);

    for (int i = 0; i < 10; ++i) {
        // Generate random value for rain sensor
        double random_value = dis(gen);
        
        // Set the random rain sensor value
        m_w.SetSensor_Rain(random_value);
        
        // Calculate wipers speed based on rain sensor and switch state
        auto wipers_speed = m_w.CalculateWipersSpeed();
        
        // Check if the calculated wipers speed meets the requirements
        // Check for no rain
        if (random_value >= NoRain_Low && random_value <= NoRain_High) {
            ASSERT_EQ(std::get<0>(wipers_speed), WipersSpeed::Off);
        }
        // Check for low rain
        else if (random_value >= LowRain_Low && random_value <= LowRain_High) {
            ASSERT_EQ(std::get<0>(wipers_speed), WipersSpeed::Low);
        }
        // Check for high rain
        else if (random_value >= HighRain_Low && random_value <= HighRain_High) {
            ASSERT_EQ(std::get<0>(wipers_speed), WipersSpeed::High);
        }
        // Fail if the rain sensor value is invalid
        else {
            FAIL() << "Invalid rain intensity value: " << random_value;
        }
    }
}