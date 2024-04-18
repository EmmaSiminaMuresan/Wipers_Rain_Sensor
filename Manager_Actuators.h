
#include "Wipers.h"
#include "Rain_Sensor.h"
#include "Manager_Wipers.h"

class Manager_Actuators
{

public:
	Manager_Actuators(Manager_Wipers*speedResult) : speed_result(speedResult) {}


	void ReadManagerWipers(Manager_Wipers* speedResult)
	{
		speed_result = speedResult;
	}

	void SetRainSensor() {
		rain_volume.SetVolume(std::get<1>(speed_result->CalculateWipersSpeed()));
	}
	

	Rain_Sensor GetVolume() const {
		return rain_volume;
	}

	
	Manager_Actuators(Manager_Wipers* speedResult) : speed_result(speedResult) {}

private:
	Rain_Sensor rain_volume;
	Manager_Wipers* speed_result;
};