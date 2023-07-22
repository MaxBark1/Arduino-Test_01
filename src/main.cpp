//2018.6.28
#include <Arduino.h>
#include "avr8-stub.h"
#include <dht_nonblocking.h>
#include <string.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11
//#define DHT_SENSOR_TYPE DHT_TYPE_21
//#define DHT_SENSOR_TYPE DHT_TYPE_22

static const int DHT_SENSOR_PIN = 13;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

void setup( )
{
  debug_init();
}

void mymessage (String mymessage) {
  char message[1];
  //message=mymessage.c_str();
  breakpoint();
  strcpy(message, mymessage.c_str());
  debug_message(message);
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
    breakpoint();
    //debug_message(myMessage.c_str());
    mymessage(myMessage);
  }
}

