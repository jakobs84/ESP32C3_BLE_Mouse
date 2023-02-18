#include "LuatOS_C3.h"
#include <Credentials.h>
#include <Arduino.h>
#include <BleMouse.h>

BleMouse bleMouse("MX Master C3", "LOGGII", 88);
//long check1s = 0;
long check2s = 0;
int x3 = 0;

void setup() {
//  Serial.begin(115200);
//  Serial.println("Hello ESP32C3!!");
  initLEDs();
  //initKeys();
  blinkk(5, 100, PIN_LED1);
  //autoConfigWifi();
  bleMouse.begin();
}

void loop() {
  auto ms = millis();
  /*
  if (ms - check1s > 1000) {
    check1s = ms;
    ArduinoOTA.handle();
  }
  */
  if(bleMouse.isConnected()) {
    if(ms - check2s > (200000 + x3)) {
        check2s = ms;
        int x1 = random(-60, 60);
        int x2 = random(-60, 60);
        x3 = random(1000, 2000);
        x3 = x3 * (-1, 1 );  
        blinkk(8, 120, PIN_LED1);
        digitalWrite(PIN_LED1, HIGH);
        delay(500);
        bleMouse.move(x1, x2);
        delay(30);
        bleMouse.move(-x1, -x2);
        delay(30);
        digitalWrite(PIN_LED1, LOW);    
    }
  }
}