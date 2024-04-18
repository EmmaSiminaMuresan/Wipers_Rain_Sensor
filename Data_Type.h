
typedef enum ButtonState
{
	Off = 0, // wiperspeed = 0
	Low,	// 1 // wiperspeed = 1
	High,	// 2 // wiperspeed = 2
	Automatic	// 3
};

typedef enum WipersSpeed
{
	Off = 0, 
	Low,	// 1
	High,	// 2
};

typedef enum RainSensor
{
	None = 0, // wiperspeed = 0
	Low,	// 1 // wiperspeed = 1
	High,	// 2 // wiperspeed = 2
};

constexpr float NoRain_Low{ 0 }; // no rain 
constexpr float NoRain_High{ 1.99 }; // no rain 
constexpr float LowRain_Low{ 2 }; // low rain 
constexpr float LowRain_High{ 4.99 }; // low rain 
constexpr float HighRain_Low{ 5 }; // high rain 
constexpr float HighRain_High{ 12 }; // high rain 

