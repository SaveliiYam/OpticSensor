#include "OpticSensor.h"

OpticSensor::OpticSensor(byte pin){
	_pin = pin;
	pinMode(_pin, INPUT_PULLUP);
	_state = false;
	_currentTime = millis();
}

bool OpticSensor::letDelay(){
	bool stateNow = digitalRead(_pin);
	if(stateNow && !_state ){
		_currentTime = millis();
		_state = true;
		return true;
	}
	if(stateNow && _state){
		_currentTime = millis();
		return true;
	}
	if(!stateNow && _state && millis() - _currentTime >= 10){
		_currentTime = millis();
		_state = false;
		return false;
	}	
	return true;
}	

bool OpticSensor::let(){
	bool stateNow = digitalRead(_pin);
	if(stateNow && !_state && millis() - _currentTime >= 20){//мундштук есть
		_state = true;
		_currentTime = millis();
		return true;
	}
	if(stateNow && _state && millis() - _currentTime >= 10){
		_currentTime = millis();
		return true;
	}
	if(!stateNow && _state){
		_state = false;
		
	}
	return false;
}