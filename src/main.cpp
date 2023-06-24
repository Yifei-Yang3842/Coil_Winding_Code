#include <Arduino.h>
#include "Constants.h"
#include "Stepper.h"

// Functions declaration
void waitButtonPress();
bool checkButtonPress();
int readPot(int min, int max);

// Global variables (:p)
int guideCounter = 0;
bool guideDir = 0;

// Create stepper motor objects
Stepper guide(DIR_1_PIN, STP_1_PIN, 1);
Stepper spindle(DIR_2_PIN, STP_2_PIN, 8);

void setup() {

  Serial.begin(9600);
  // Init controller board components
  pinMode(MAIN_BUTTON_PIN, INPUT);

  // Init motors
  guide.initialize();
  guide.setMicrosteps(GUIDE_MICROSTEPS);
  spindle.initialize();
  spindle.setMicrosteps(SPINDLE_MICROSTEPS);

  // 1. Wait for init button press
  waitButtonPress();
  // 2. Test the spindle and reset
  spindle.moveTest();
  spindle.resetSteps();
  // 3. Home the linear guide
  guide.setHome(GUIDE_RESET_PIN, 0);
  // 4. Move the guide to zero pos (of coil)
  guide.setTimePerStep(300);
  guide.moveDist(CORE_W+1, HIGH);
  guide.setTimePerStep(100);
  // 5. Wait for button press
  waitButtonPress();
  delay(1000);

}

void loop() { // Loops for every spindle turn

  // 6. Check for "pause" command (or stop)
  if(checkButtonPress()) {
    while(digitalRead(MAIN_BUTTON_PIN) == HIGH) {
      delay(2000);}
    // 6.a. Wait for "resume" command
    waitButtonPress(); 
  }
  // 7. Turn the spindle once
  spindle.setTimePerStep(readPot(LONGEST_SPINDLE_DELAY, SHORTEST_SPINDLE_DELAY));
  spindle.spinRevs(1, HIGH);
  // 8. Move linear guide
  if (guideCounter > CORE_W/WIRE_D) {
    guideCounter = 0;
    guideDir = !guideDir;
  }
  guide.moveDist(WIRE_D, guideDir);
  // 9. increment counter
  guideCounter++;
  // 10. Output counter
  Serial.print("revs: ");
  Serial.print(spindle.readRevs());
  Serial.print("  guideCount: ");
  Serial.println(guideCounter);
  
}


// Useful functions
void waitButtonPress() {
  while(digitalRead(MAIN_BUTTON_PIN) == LOW) {
    delay(10);}
  while(digitalRead(MAIN_BUTTON_PIN) == HIGH) {
    delay(10);}
}

bool checkButtonPress() {
  return (digitalRead(MAIN_BUTTON_PIN) == HIGH);
}

int readPot(int min, int max) {
  return map(analogRead(POT_PIN), 0, 4095, min, max);
}