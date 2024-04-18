#include "Data_Type.h"

class Rain_Sensor
{

public:
	Rain_Sensor() {}
	void SetVolume(RainSensor level) { rain_volume = level; }
	RainSensor GetVolume() const { return rain_volume; } // debug

protected:
	RainSensor rain_volume;

};
