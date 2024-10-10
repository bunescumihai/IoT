#include "lab_1_2.h"
#include "Arduino.h"
#include "srv_serial_stdio_lcd_keypad/srv_serial_stdio_lcd_keypad.h"
#include <LiquidCrystal_I2C.h>

void lab_1_2_setup()
{    
  srv_serial_lcd_keypad_setup();
  
  Serial.begin(9600);
}

int sum(int a, int b){
  return a + b;
}

int prod(int a, int b){
  return a * b;
}

void lab_1_2_loop()
{
  Serial.println("Wait to press a button:");
  int first_number, second_number;
  char c;

  scanf("%d%c%d",&first_number, &c, &second_number);

  lcd.clear();
  
  if( c == '+')
    printf("%d", sum(first_number, second_number));
  
  if( c == '*')
    printf("%d", prod(first_number, second_number));

  

  Serial.println(first_number);
  Serial.println(c);
  Serial.println(second_number);
}