#include "LuatOS_C3.h"
#include <Credentials.h>
#include <Arduino.h>
#include <BleMouse.h>
#include <stdint.h>

#define DUMP 1
int BLINK = 3; // 0 no blink, 1 - LED1 (MOVE), 2 - LED2 (Connection), 3 = 1+2;

BleMouse bleMouse("MX Master S3", "LOGGII", 33);

unsigned long previousTime = 0; // Czas początkowy
unsigned long interval = 0;     // Interwał czasowy -  losowy
int x, y, r; // Zmienne x i y, r random opuźnienie
int z = 10;  // opuźnienie stałe * 1000ms = s;  r = random(1, 9);  interval = (r + z) * 1000;


void setup()
{
#ifdef DUMP
  Serial.begin(115200);
  Serial.println("Hello ESP32C3!!");
#endif
  initLEDs();
  randomSeed(analogRead(0)); // Inicjalizacja generatora liczb losowych
  // initKeys();
  blinkk(5, 100, PIN_LED1);
  // autoConfigWifi();
  bleMouse.begin();
}

void loop()
{
  // auto ms = millis();
  unsigned long currentTime = millis(); // Aktualny czas w milisekundach

  if (bleMouse.isConnected())
  {
    if (BLINK == 2 || BLINK == 3)
    {
      digitalWrite(PIN_LED2, HIGH);
    }

    // Sprawdzamy, czy upłynął określony czas
    if (currentTime - previousTime >= interval)
    {
      x = random(-60, 61);
      y = random(-60, 61);
      if (BLINK == 1 || BLINK == 3)
      {
        blinkk(8, 120, PIN_LED1);
        digitalWrite(PIN_LED1, HIGH);
        delay(500);
        bleMouse.move(x, y);
        delay(30);
        bleMouse.move(-x, -y);
        delay(30);
        digitalWrite(PIN_LED1, LOW);
      }
      else
      {
        bleMouse.move(x, y);
        delay(30);
        bleMouse.move(-x, -y);
        delay(30);
      }

      // Losujemy nowy interwał (czas oczekiwania)
      r = random(1, 9);
      interval = (r + z) * 1000;

    #ifdef DUMP
      Serial.print("x: ");
      Serial.print(x);
      Serial.print("\t y: ");
      Serial.print(y);
      Serial.print("\t Delay: ");
      Serial.print(r);
      Serial.print(" + ");
      Serial.print(z);
      Serial.println(" s");
    #endif

      // Aktualizujemy czas początkowy
      previousTime = currentTime;
    }
  }
  else
  {
    if (BLINK == 2 || BLINK == 3)
      digitalWrite(PIN_LED2, LOW);
  }
}