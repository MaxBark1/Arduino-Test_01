#include <Arduino.h>
#include "avr8-stub.h"
#include "app_api.h" // only needed with flash breakpoints
int i=0;
void setup()
{
pinMode(LED_BUILTIN, OUTPUT);
// initialize the avr-debugger
debug_init();
}
void loop()
{
digitalWrite(LED_BUILTIN, HIGH);
i++;
delay(300);
digitalWrite(LED_BUILTIN, LOW);
delay(100);
}