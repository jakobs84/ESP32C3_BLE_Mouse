//  Debug - OK
//  Board_descryption
//  Add delat - opuźnienie
//
//


#ifdef BOARDSuperMini
#define PIN_LED1 8 //LED_BUILTIN 8
#define BOARD_DESCRIPTION "Super_Mini"
#else 

#define BOARD_DESCRIPTION "LuatOS_C3"
#endif
#include <Credentials.h>
#include <Arduino.h>
#include <BleMouse.h>
#include "LuatOS_C3.h"

//#define DEBUG  // Definiuje DEBUG



BleMouse bleMouse(BOARD_DESCRIPTION, "LOGGII", 88);
long check2s = 0;
int rando = 0;
int delat = 150000;  // opuźnienie 2,5 minuty

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
  //Serial.begin(460800);
  Serial.println("Heloo");
  Serial.println(BOARD_DESCRIPTION);
#endif

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
    if(ms - check2s > (delat + rando)) {
        check2s = ms;
        short int x = random(-60, 60);
        short int y = random(-60, 60);
        rando = random(1000, 2000);
        rando = rando * (-1, 1 );  
        blinkk(8, 120, PIN_LED1);
        digitalWrite(PIN_LED1, LOW);
        delay(500);
        bleMouse.move(x, y);
        delay(30);
        bleMouse.move(-x, -y);
        delay(30);
        digitalWrite(PIN_LED1, HIGH);

      #ifdef DEBUG
      Serial.print(check2s);
      Serial.print("; ");
      Serial.print(x);
      Serial.print("; ");
      Serial.print(y);
      Serial.print("; ");
      Serial.println(rando);
      #endif       
    }
  } 
  #ifdef DEBUG
    if (!bleMouse.isConnected() && (millis() - check2s > delat - 30000)) {
        check2s = millis();  
        Serial.println("Not connected");
    }
  #endif


}