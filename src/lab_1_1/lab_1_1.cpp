#include "lab_1_1.h"
#include "dd_led/dd_led.h"
#include "led_control/led_control.h"
#include "srv_serial_stdio/srv_serial_stdio.h"
#include <Arduino.h>
#include <string.h>

Led led2(12);

void lab_1_1_setup()
{
  srv_serial_setup();

  printf("Led is off\n");
}

void lab_1_1_loop()
{
    char c[100];

    printf("Enter a command: ");

    scanf("%s", c);

    if(strcmp(c, "ledon") == 0){
      printf("Led turned on!\n");
      dd_led_turn_on(&led2);
    }
    else if(strcmp(c, "ledoff") == 0){
      printf("Led turned off!\n");
      dd_led_turn_off(&led2);
    }
    else{
      printf("\"%s\" is an invalid command\n", c);
    }

    delay(500);
}