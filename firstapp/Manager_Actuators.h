
#include "Wipers.h"
#include "Manager_Wipers.h"

class Manager_Actuators
{

public:
	Manager_Actuators(Manager_Wipers*speedResult) : speed_result(speedResult) {}


	void ReadManagerWipers(Manager_Wipers* speedResult)
	{
		speed_result = speedResult;
	}

	void SetWiper(){
		speed.SetWiperSpeed(std::get<0>(speed_result->CalculateWipersSpeed()));
	}
	

	Wipers GetWiperSpeed() const{
		return speed;
	}

	Manager_Actuators(Manager_Wipers* speedResult) : speed_result(speedResult) {}

private:
	Wipers speed;
	Manager_Wipers* speed_result;
};