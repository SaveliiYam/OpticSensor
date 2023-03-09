#pragma once
#include <Arduino.h>

class OpticSensor{
	private:
		byte _pin;
		bool _state;
		uint32_t _currentTime;
	public:
		OpticSensor(byte pin);
		bool letDelay();
		bool let();
};	