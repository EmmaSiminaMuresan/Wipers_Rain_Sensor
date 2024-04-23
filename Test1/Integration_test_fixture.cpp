#include "Integration_test_fixture.h"

void IntegrationTestFixture::SetUp() {
    // Set switch to automatic mode before each test case
    button.SetState(ButtonState::Automatic);
}

void IntegrationTestFixture::TearDown() {
    
}
