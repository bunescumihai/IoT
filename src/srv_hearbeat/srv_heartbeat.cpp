#include "srv_hearbeat/srv_heartbeat.h"
#include "Arduino.h"

#define HEARTBEAT_PIN LED_BUILTIN

void srv_heartbeat_setup()
{
    pinMode(HEARTBEAT_PIN, OUTPUT);
}

void srv_heartbeat_toggle()
{
    digitalWrite(HEARTBEAT_PIN, !digitalRead(HEARTBEAT_PIN));
}