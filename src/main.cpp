//2018.6.28
#include <Arduino.h>
#include "avr8-stub.h"
#include <dht_nonblocking.h>
#include <string.h>
#include <LiquidCrystal.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
//#define DHT_SENSOR_TYPE DHT_TYPE_21
//#define DHT_SENSOR_TYPE DHT_TYPE_22

static const int DHT_SENSOR_PIN = 13;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setupLCD () {
lcd.begin(16, 2);
lcd.print("hello, world!");
}

void setup()
{
  String testmessage;
  debug_init();
  setupLCD();

}


void displayLCD (String message_to_LCD) {
  lcd.setCursor(0, 1);
  lcd.print(message_to_LCD);
}

void mymessage (String mymessage) {
  debug_message(mymessage.c_str());
}

void loop( )
{
  float temperature;
  float humidity;
  String myMessage;

  if(dht_sensor.measure(&temperature, &humidity)){
    myMessage = "T = " ;
    myMessage += temperature;
    myMessage +=  " deg. C, H = " ;
    myMessage += humidity;
    myMessage += "%\n";
    //breakpoint();
    //debug_message(myMessage.c_str());
    mymessage(myMessage);
    displayLCD(myMessage);
  }
}

