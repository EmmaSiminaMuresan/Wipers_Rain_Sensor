#include "Manager_Wipers.h"
#include "gmock/gmock.h"

class Manager_Wipers_Mock : public Manager_Wipers
{
public:
	MOCK_METHOD((ButtonState), GetButton, (), ());
	// void SetButton (const ButtonState buttonState)
	MOCK_METHOD(void, SetButton, (const ButtonState bt), ());
	MOCK_METHOD(void, SetVolume, (const float), ());
	MOCK_METHOD((std::tuple<WipersSpeed, RainSensor>), CalculateWipersSpeed, (), ());
};		
