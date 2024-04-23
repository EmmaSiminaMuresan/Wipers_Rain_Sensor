#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../firstapp/Manager_Wipers_Mock.h"
#include "../firstapp/Manager_Actuators.h"
#include "../firstapp/Button.h" 

using ::testing::AtLeast;

TEST(SomeGmockTest, DoingSomething) {
    Manager_Wipers_Mock mw_mock;

    EXPECT_CALL(mw_mock, SetButton(ButtonState::Automatic)).Times(1);
    EXPECT_CALL(mw_mock, GetButton()).Times(AtLeast(1)).WillRepeatedly(testing::Return(ButtonState::Low));
    EXPECT_CALL(mw_mock, CalculateWipersSpeed()).Times(AtLeast(1)).WillRepeatedly(testing::Return(std::make_tuple(WipersSpeed::Off)));

    mw_mock.SetButton(ButtonState::Automatic);

    EXPECT_EQ(mw_mock.GetButton(), ButtonState::Low);

    mw_mock.CalculateWipersSpeed();

    Manager_Actuators m_a(&mw_mock);

    m_a.SetWiper();

    EXPECT_EQ(m_a.GetWiperSpeed(), WipersSpeed::Off);
}

TEST(SomeGmockTest, DoingSomethingElse) {
    ::testing::NiceMock<Manager_Wipers_Mock> mw_mock;

    EXPECT_CALL(mw_mock, GetButton()).WillRepeatedly(testing::Return(ButtonState::Low));
    EXPECT_CALL(mw_mock, CalculateWipersSpeed()).WillRepeatedly(testing::Return(std::make_tuple(WipersSpeed::Low)));

    Manager_Actuators m_a(&mw_mock);

    m_a.SetWiper();

    EXPECT_EQ(m_a.GetWiperSpeed(), WipersSpeed::Off);
}
