//2018.6.28
#include <Arduino.h>
#include "avr8-stub.h"
#include <dht_nonblocking.h>

#
#define DHT_SENSOR_TYPE DHT_TYPE_11
//#define DHT_SENSOR_TYPE DHT_TYPE_21
//#define DHT_SENSOR_TYPE DHT_TYPE_22

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

void setup( )
{
  debug_init();
}
void loop( )
{
  float temperature;
  float humidity;

  if(dht_sensor.measure(&temperature, &humidity)){
    debug_message( "T =");
    /*debug_message( temperature, 1 );
    debug_message( " deg. C, H = " );
    debug_message( humidity, 1 );
    debug_message( "%" );*/
  }
}

