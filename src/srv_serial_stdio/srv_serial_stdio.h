#ifndef SRV_SERIAL_STDIO_H
#define SRV_SERIAL_STDIO_H

#include <stdio.h>

// Include any necessary libraries here

// Declare any global variables or constants here

// Declare function prototypes here
void srv_serial_setup();
int srv_serial_get_char(FILE* stream);
int srv_serial_put_char(char c,FILE* stream);

#endif // SRV_SERIAL_STDIO_H