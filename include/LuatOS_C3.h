#ifndef __LUAT_OS_C3_H__
#define __LUAT_OS_C3_H__

#include <Arduino.h>
#include <Credentials.h>
#include <ArduinoOTA.h>
//#include <TFT_eSPI.h>

#define TZ 2            // Polsk 2 Chiny 8
#define DST_MN 0        // 默认为0
#define TZ_MN ((TZ)*60) //时间换算
#define TZ_SEC ((TZ)*3600)
#define DST_SEC ((DST_MN)*60)

#ifdef BOARDSuperMini
#define PIN_LED1 8 //LED_BUILTIN 8
#else 
#define PIN_LED1 12
#define PIN_LED2 13
#endif


/*
// 4,5,8,9,13
#define KEY_LEFT 5
#define KEY_RIGHT 9
#define KEY_UP 8
#define KEY_DOWN 13
#define KEY_CENTER 4

uint8_t PIN_KEYS[] = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, KEY_CENTER};
//extern TFT_eSPI tft;
extern char buf[];

void inline initKeys() {
  for (int i = 0; i < sizeof(PIN_KEYS); i++) {
    pinMode(PIN_KEYS[i], INPUT_PULLUP);
  }
}
*/
//void inline setLCDBrightness(int bri) { ledcWrite(0, bri); }
/*
void inline setupOTAConfig() {
  ArduinoOTA.onStart([] {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_PINK, TFT_BLACK);
    tft.drawCentreString("OTA Update", 80, 10, 2);
    tft.drawRoundRect(30, 40, 100, 10, 2, TFT_ORANGE);
  });
  ArduinoOTA.onProgress([](u32_t pro, u32_t total) {
    tft.setTextColor(TFT_SKYBLUE, TFT_BLACK);
    sprintf(buf, "%d / %d", pro, total);
    tft.drawCentreString(buf, 80, 60, 2);
    int pros = pro * 100 / total;
    tft.fillRoundRect(30, 40, pros, 10, 2, TFT_ORANGE);
  });
  ArduinoOTA.onEnd([] {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.drawCentreString("Update Succeed!!", 80, 20, 2);
    tft.setTextColor(TFT_SKYBLUE, TFT_BLACK);
    tft.drawCentreString("Restarting...", 80, 40, 2);
  });
  ArduinoOTA.onError([](ota_error_t err) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_RED, TFT_BLACK);
    sprintf(buf, "OTA Error [%d]!!", err);
    tft.drawCentreString(buf, 80, 30, 2);
  });
  ArduinoOTA.begin();
}
*/
//#ifndef BOARDSuperMini // NEGACJA BOARDSuperMini

/*
void inline autoConfigWifi() {
  WiFi.mode(WIFI_MODE_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println(mySSID);
  WiFi.begin(mySSID, myPASSWORD);
  //WiFi.begin();
  for (int i = 0; WiFi.status() != WL_CONNECTED && i < 100; i++) {
    delay(100);
  }
  Serial.print("IP: ");
  Serial.println(WiFi.localIP().toString().c_str());
  //sprintf(buf, "IP: %s", WiFi.localIP().toString().c_str());
  //tft.println(buf);
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.mode(WIFI_MODE_APSTA);
    WiFi.beginSmartConfig();
    while (WiFi.status() != WL_CONNECTED) {
      delay(100);
       Serial.print(".");
    }
    WiFi.stopSmartConfig();
    WiFi.mode(WIFI_MODE_STA);
  }
}
//#endif
*/


/*
void inline initTFT() {
  tft.begin();
  tft.setRotation(3);
  tft.setTextFont(2);
  tft.fillScreen(TFT_BLACK);
  pinMode(TFT_BL, OUTPUT);
  ledcSetup(0, 1000, 10);
  ledcAttachPin(TFT_BL, 0);
  setLCDBrightness(100);
}
*/
void inline initLEDs() {
 #ifdef BOARDSuperMini
  pinMode(PIN_LED1, OUTPUT);
  digitalWrite(PIN_LED1, LOW);
#else 
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, LOW);
#endif

//  pinMode(PIN_LED1, OUTPUT);
//  pinMode(PIN_LED2, OUTPUT);
//  digitalWrite(PIN_LED1, LOW);
//  digitalWrite(PIN_LED2, LOW);
}


void blinkk(short int x, unsigned long del, short int ledd)
//void blinkk(int x; int del)
{
  // short int  -32768 to +32767
  // short char -128 to +128
  //int ledd =13;

  for (int i = 0; i < x; i++) {

    digitalWrite(ledd, HIGH);
    delay(del);
    digitalWrite(ledd, LOW);
    delay(del);
  }
}

#endif
