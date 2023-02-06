#pragma once
#include <Arduino.h>

class Button{
	private:
		byte _pin;
		uint32_t _tmr;
		bool _flag;
	public:
		Button(byte pin){
			_pin = pin;
			pinMode(_pin, INPUT_PULLUP);
		}
		bool click(){
			bool butState = digitalRead(_pin);
			if(!butState && !_flag && millis() - _tmr >= 100){
				_tmr = millis();
				_flag = true;
				return true;
			}
			/*if(!butState && _flag && millis() - _tmr >= 500){
				_tmr = millis();
				return true;
			}*/
			if(butState && _flag){
				_tmr = millis();
				_flag = false;
			}
			return false;
		}
};
