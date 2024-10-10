#include "lab_2_1/lab_2_1.h"
#include "Arduino.h"
#include "dd_led/dd_led.h"
#include "srv_serial_stdio/srv_serial_stdio.h"

volatile unsigned long lastDebounceTime = 0;  // To handle debounce time
const unsigned long debounceDelay = 100;  // Debounce time in milliseconds (50ms)

Led myLed(10);
#define BUTTON_PIN 2

char commandBuffer[20];  // Buffer to store the incoming command
int commandIndex = 0;    // Index to track the position in the buffer


void setupTimer() {
  noInterrupts();  // Disable interrupts during setup

  // Set up Timer1 to trigger interrupt every 50 ms
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  // Set compare match register for 50ms intervals
  OCR1A = 12499;  // For 50ms interval with 16MHz clock and 64 prescaler

  // Enable CTC mode
  TCCR1B |= (1 << WGM12);

  // Set prescaler to 64
  TCCR1B |= (1 << CS11) | (1 << CS10);

  // Enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  interrupts();  // Enable interrupts
}

void handle_button_pressed() {
    unsigned long currentTime = millis(); 
    
    if ((currentTime - lastDebounceTime) > debounceDelay) {
        dd_led_toggle(&myLed); 
        lastDebounceTime = currentTime;
    }
}


void lab_2_1_setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);     

    srv_serial_setup();
    
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handle_button_pressed, FALLING);

    setupTimer();
}

void lab_2_1_loop() {
}


void processCommand() {
    for (int i = 0; i < commandIndex; i++) {
    if (commandBuffer[i] == '\r' || commandBuffer[i] == '\n') {
      commandBuffer[i] = '\0';  // Replace it with a null terminator
      break;
    }
  }

  if (strcmp(commandBuffer, "ledon") == 0) {
    dd_led_turn_on(&myLed);
    printf("LED turned on\n");
  } else if (strcmp(commandBuffer, "ledoff") == 0) {
    
    dd_led_turn_off(&myLed);
    printf("LED turned off\n");
  } else {
    printf("Unknown command: %s\n", commandBuffer);  // Handle invalid command
  }
}
// Timer interrupt service routine (ISR) to handle serial input
ISR(TIMER1_COMPA_vect) {
  int c = srv_serial_get_char(stdin);  // Get the next character from serial (non-blocking)
  
  if (c != -1) {  // If a character was received
    if (c == '\n') {  // If the Enter key (newline) is pressed, process the command
      commandBuffer[commandIndex] = '\0';  // Null-terminate the string
      processCommand();  // Process the command stored in the buffer
      commandIndex = 0;  // Reset buffer index for the next command
    } else if (commandIndex < sizeof(commandBuffer) - 1) {
      commandBuffer[commandIndex++] = c;  // Add character to the buffer
    }
  }
}

// Function to process the command in the buffer
