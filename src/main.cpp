#include <Arduino.h>

#include "lab_0/lab_0.h"
#include "lab_1_1/lab_1_1.h"
#include "lab_1_2/lab_1_2.h"
#include "lab_2_1/lab_2_1.h"


#define LAB_0 0
#define LAB_1_1 11
#define LAB_1_2 12
#define LAB_2_1 21
#define LAB_2_2 22


// define current app
#define APP_NAME LAB_2_1


// put your setup code here, to run once:
void setup()
{

  #if APP_NAME == LAB_0
    lab_0_setup();
  #endif

  #if APP_NAME == LAB_1_1
    lab_1_1_setup();
  #endif

  #if APP_NAME == LAB_1_2
    lab_1_2_setup();
  #endif
  
  #if APP_NAME == LAB_2_1
    lab_2_1_setup();
  #endif
}


// put your main code here, to run repeatedly
void loop()
{

  #if APP_NAME == LAB_0
    lab_0_loop();
  #endif

  #if APP_NAME == LAB_1_1
    lab_1_1_loop();
  #endif

  
  #if APP_NAME == LAB_1_2
    lab_1_2_loop();
  #endif
  
  #if APP_NAME == LAB_2_1
    lab_2_1_loop();
  #endif
}
