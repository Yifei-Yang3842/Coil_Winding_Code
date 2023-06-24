#ifndef CONSTANTS_H
#define CONSTANTS_H

// Misc
const float WIRE_D = 0.4; // Wire diameter in mm
const float CORE_W = 20.5; // Core width (height) in mm, (linear guide left-right travel distance)
const float N_TURNS = 300; // Number of coil turns on the core
const int SHORTEST_SPINDLE_DELAY = 800;
const int LONGEST_SPINDLE_DELAY = 6000;

// Motor info
const int SPINDLE_MICROSTEPS = 1;
const int GUIDE_MICROSTEPS = 32;

const float REVS_TO_DIST = 40; // distance per full revolution of the guide motor (mm)
const int SPINDLE_REDUCTION = 8; // Reduction ration for the spindle

// Board inputs
const int POT_PIN = 34;
const int MAIN_BUTTON_PIN = 23;
const int GUIDE_RESET_PIN = 25;

// Motor pins
const int DIR_1_PIN = 33;
const int STP_1_PIN = 32;
const int DIR_2_PIN = 26;
const int STP_2_PIN = 27;

#endif