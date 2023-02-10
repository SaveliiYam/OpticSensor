/* Данный класс настроен выдавать true
   только, если оъект в зоне действия датчика
*/
#pragma once
#include <Arduino.h>

class OpticSensor{
	private:
		int _pin;
		uint64_t _tmr;
		bool _flag;
	public:
		OpticSensor(int pin){
			_pin = pin;
			pinMode(_pin, INPUT_PULLUP);
		}
		bool let(){ // если объект находится в зоне действия оптического датчика - true
			bool opticState = digitalRead(_pin);
			if(!opticState && !_flag && millis() - _tmr >= 50){
				_tmr = millis();
				_flag = true;
				return true;
			}
			if(!opticState && _flag && millis() - _tmr >= 80){
				_tmr = millis();
				return true;
			}
			if(opticState && _flag){
				_tmr = millis();
				_flag = false;
			}
			return false;
		}
};
