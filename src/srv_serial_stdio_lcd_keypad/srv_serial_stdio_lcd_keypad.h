#ifndef SRV_SERIAL_STDIO_LCD_KEYPAD_H
#define SRV_SERIAL_STDIO_LCD_KEYPAD_H

#include <stdio.h>
#include <LiquidCrystal_I2C.h>

// Include any necessary libraries here


extern LiquidCrystal_I2C lcd;

// Declare any global variables or constants here

// Declare function prototypes here
void srv_serial_lcd_keypad_setup();
int srv_serial_keypad_get_char(FILE* stream);
int srv_serial_lcd_put_char(char c,FILE* stream);

#endif // SRV_SERIAL_STDIO_LCD_KEYPAD_H