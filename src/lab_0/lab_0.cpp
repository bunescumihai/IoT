#include "lab_0.h"
#include "dd_led/dd_led.h"
#include "led_control/led_control.h"
#include "dd_button/dd_button.h"

#include "Arduino.h"

Led led1(11);

void lab_0_setup(){
    dd_button_setup();
    Serial.begin(9600);
}

void lab_0_loop(){

    Serial.println("Asteptare apasare buton");
    
    while(!dd_button_is_pressed());
    Serial.println("Buton apasat");
    
    dd_led_toggle(&led1);

    while(dd_button_is_pressed());

    delay(100);
}