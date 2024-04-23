#ifndef INTEGRATION_TEST_FIXTURE_H
#define INTEGRATION_TEST_FIXTURE_H

#include <gtest/gtest.h>
#include "../firstapp/Manager_Wipers.h" 

// Define the integration test fixture
class IntegrationTestFixture : public ::testing::Test {
protected:
    // Test setup
    void SetUp() override;
    // Test teardown
    void TearDown() override;

    // Test objects
    Manager_Wipers m_w;
    Button button;
};

#endif // INTEGRATION_TEST_FIXTURE_H
