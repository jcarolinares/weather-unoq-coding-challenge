#include <Arduino.h>
#line 1 "/home/arduino/ArduinoApps/weather-unoq-coding-challenge/sketch/sketch.ino"
// SPDX-FileCopyrightText: Copyright (C) ARDUINO SRL (http://www.arduino.cc)
//
// SPDX-License-Identifier: MPL-2.0

#include <Arduino_LED_Matrix.h>
#include <Arduino_RouterBridge.h>

#include "weather_frames.h"


Arduino_LED_Matrix matrix;

String city = "Ivrea";

#line 15 "/home/arduino/ArduinoApps/weather-unoq-coding-challenge/sketch/sketch.ino"
void setup();
#line 22 "/home/arduino/ArduinoApps/weather-unoq-coding-challenge/sketch/sketch.ino"
void loop();
#line 45 "/home/arduino/ArduinoApps/weather-unoq-coding-challenge/sketch/sketch.ino"
void playRepeat(int repeat_count);
#line 15 "/home/arduino/ArduinoApps/weather-unoq-coding-challenge/sketch/sketch.ino"
void setup() {
  matrix.begin();
  matrix.clear();

  Bridge.begin();
}

void loop() {
  String weather_forecast;
  bool ok = Bridge.call("get_weather_forecast", city).result(weather_forecast);
  if (ok) {
    if (weather_forecast == "sunny") {
      matrix.loadSequence(sunny);
      playRepeat(10);
    } else if (weather_forecast == "cloudy") {
      matrix.loadSequence(cloudy);
      playRepeat(10);
    } else if (weather_forecast == "rainy") {
      matrix.loadSequence(rainy);
      playRepeat(20);
    } else if (weather_forecast == "snowy") {
      matrix.loadSequence(snowy);
      playRepeat(10);
    } else if (weather_forecast == "foggy") {
      matrix.loadSequence(foggy);
      playRepeat(5);
    }
  }
}

void playRepeat(int repeat_count) {
  for (int i = 0; i < repeat_count; i++) {
    matrix.playSequence();
  }
}

