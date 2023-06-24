#include <Arduino.h>
#include "Constants.h"
#include "Stepper.h"


// Create stepper motor objects
Stepper guide(DIR_1_PIN, STP_1_PIN);
Stepper spindle(DIR_2_PIN, STP_2_PIN);

void setup() {
  
  // Init motors
  guide.initialize();
  guide.setMicrosteps(GUIDE_MICROSTEPS);
  spindle.initialize();
  spindle.setMicrosteps(SPINDLE_MICROSTEPS);

  // Test the spindle
  spindle.moveTest();
  // Home the linear guide
  guide.setHome(GUIDE_RESET_PIN, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
}