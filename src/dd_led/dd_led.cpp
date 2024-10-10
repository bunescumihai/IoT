#include "dd_led.h"
#include "Arduino.h"

void dd_led_turn_on(Led *led)
{
    digitalWrite(led->led_pin, HIGH);
}

void dd_led_turn_off(Led *led)
{
    digitalWrite(led->led_pin, LOW);
}

int dd_led_is_on(Led *led){
 return (digitalRead(led->led_pin)==HIGH);
}

void dd_led_toggle(Led *led)
{
    if(dd_led_is_on(led)){
        dd_led_turn_off(led);
    }else{
        dd_led_turn_on(led);
    }
}

Led::Led(char pin) : led_pin(pin){
    pinMode(led_pin, OUTPUT);  // Set the pin as OUTPUT
}