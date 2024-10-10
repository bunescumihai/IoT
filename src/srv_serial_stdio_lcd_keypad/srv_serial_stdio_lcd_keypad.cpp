
#include "srv_serial_stdio_lcd_keypad.h"

// 1. Include device driver
#include <Arduino.h>

#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define ROWS 4
#define COLS 4

const char row_pins[ROWS] = {2,3,4,5};
const char col_pins[COLS] = {6,7,8,9};
const char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', ' '}
};

Keypad customKeypad = Keypad(makeKeymap(keys), row_pins, col_pins, ROWS, COLS); 


LiquidCrystal_I2C lcd(0x27,16,2);


int srv_serial_keypad_get_char(FILE *stream) {
    char key = NO_KEY;

    while (key == NO_KEY) {
        key = customKeypad.getKey();
    }

    lcd.print(key);


    return key;
}

int srv_serial_lcd_put_char(char c, FILE *stream) {
    lcd.print(c);
    return 0;
}

void srv_serial_lcd_keypad_setup(){
    lcd.init();                 
    lcd.backlight();             
    lcd.clear();                 
    lcd.setCursor(0, 0); 
    
    FILE *my_stream = fdevopen(srv_serial_lcd_put_char, srv_serial_keypad_get_char);

    stdin = stdout = my_stream ;
}