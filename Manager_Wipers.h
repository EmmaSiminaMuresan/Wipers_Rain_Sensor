#include "Button.h"
#include "Sensor_Rain.h"
#include "Wipers.h"
#include <tuple>

class Manager_Wipers
{
	Button button;
	Sensor_Rain rain;

public:

	void SetButton(const ButtonState buttonState) {
		button.SetState(buttonState);
	}

	void SetSensor_Rain(const float value) {
		rain.SetValue(value);
	}


	virtual ButtonState GetButton() {
		return button.GetState();
	}

	std::tuple<WipersSpeed> CalculateWipersSpeed() {

		auto wipers_speed = std::make_tuple(WipersSpeed::Off);

		switch (button.GetState())
		{
		case ButtonState::Low:
		{
			wipers_speed = std::make_tuple(WipersSpeed::Low);
			break;
		}
		case ButtonState::High:
		{
			wipers_speed = std::make_tuple(WipersSpeed::High);
			break;
		}
		case ButtonState::Automatic:
		{
			if (rain.GetValue() >= NoRain_Low && rain.GetValue() <= NoRain_High) {
				wipers_speed = std::make_tuple(WipersSpeed::Off);
			}
			// no rain
			else {
				if (rain.GetValue() >= LowRain_Low && rain.GetValue() <= LowRain_High) {
					wipers_speed = std::make_tuple(WipersSpeed::Low);
				}
				// low rain
				else {
					if (rain.GetValue() >= HighRain_Low && rain.GetValue() <= HighRain_High) {
						wipers_speed = std::make_tuple(WipersSpeed::High);
					}
					// high rain
				}
			}
			break;
		}
		case ButtonState::Off:
		default:
		{
			wipers_speed = std::make_tuple(WipersSpeed::Off);
			break;
		}
		}
		return wipers_speed;
	}

};