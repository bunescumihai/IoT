
#include "srv_serial_stdio.h"

// 1. Include device driver
#include <Arduino.h>

int srv_serial_get_char(FILE *stream) {
    if (Serial.available() > 0) { 
        char c = Serial.read();   
        Serial.write(c);           
        return c;                  
    } else {
        return -1; 
    }
}

int srv_serial_put_char(char c, FILE *stream) {
    Serial.write(c); 
    return 0;
}

void srv_serial_setup(){
    Serial.begin(9600);
    
    FILE *my_stream = fdevopen(srv_serial_put_char, srv_serial_get_char);

    stdin = stdout = my_stream ;
}
