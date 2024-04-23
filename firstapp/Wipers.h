#include "Data_Type.h"

class Wipers
{

public:
	Wipers() {}
	void SetWiperSpeed(WipersSpeed speed) { wiper_speed = speed; }
	WipersSpeed GetWiperSpeed() const { return wiper_speed; } // debug

protected:
	WipersSpeed wiper_speed;
};