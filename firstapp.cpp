// firstapp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Manager_Actuators.h"

int main()
{

	Manager_Wipers m_w{};

	m_w.SetButton(ButtonState::Off);
	std::cout << "Wipers speed: " << std::get<1>(m_w.CalculateWipersSpeed()) << std::endl;

	m_w.SetButton(ButtonState::Low);
	std::cout << "Wipers speed: " << std::get<1>(m_w.CalculateWipersSpeed()) << std::endl;

	m_w.SetButton(ButtonState::High);
	std::cout << "Wipers speed: " << std::get<1>(m_w.CalculateWipersSpeed()) << std::endl;

	m_w.SetButton(ButtonState::Automatic);
	m_w.SetSensor_Rain(0.4); // no rain
	std::cout << "Wipers speed: " << std::get<1>(m_w.CalculateWipersSpeed()) << std::endl;

	m_w.SetButton(ButtonState::Automatic);
	m_w.SetSensor_Rain(2.4); // low rain
	std::cout << "Wipers speed: " << std::get<1>(m_w.CalculateWipersSpeed()) << std::endl;

	m_w.SetButton(ButtonState::Automatic);
	m_w.SetSensor_Rain(9.4); // high rain
	std::cout << "Wipers speed: " << std::get<1>(m_w.CalculateWipersSpeed()) << std::endl;


	Manager_Actuators m_a(&m_w);
	m_a.SetRainSensor();

	std::cout << "Rain: " << m_a.GetVolume().GetVolume() << std::endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
