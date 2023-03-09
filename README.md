# OpticSensor
Простенькая библиотека для управления оптическим датчиком. Датчик может определять освещенность помещения. Может реагировать на свет. 

## Установка
- Скачать библиотеку архивом для ручной установки:
- Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
- Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
- Распаковать и положить в *Документы/Arduino/libraries/*
- (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив
## Инициализация
```cpp
OpticSensor sensor(pin); // Инициализация пина датчика
```
## Использование
```cpp
void let(); // Если на оптический датчик попадает свет, то выведет true
void letDelay(); //Если вам нужна задержка после срабатывания (т.е. оптический датчик зафиксировал отсутсвие света
// и после посявления света, датчик еще 10мс будет выдавать TRUE)
```
## Примеры 
```cpp
#include <OpticSensor.h> //Подключение 
OpticSensor opticSens(7); //Инициализация
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (opticSens.let() ){ //Если свет падает на датчик
    digitalWrite(13, HIGH);
  }
  else digitalWrite(13, LOW); //Если свет не падает на датчик
}
```
