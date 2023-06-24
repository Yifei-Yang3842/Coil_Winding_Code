#ifndef CONSTANTS_H
#define CONSTANTS_H

// Misc
const int WIRE_D = 0.8; // Wire diameter in mm
const int CORE_W = 20.5; // Core width (height) in mm, (linear guide left-right travel distance)
const int N_TURNS = 300; // Number of coil turns on the core

// Motor info
const int SPINDLE_MICROSTEPS = 1;
const int GUIDE_MICROSTEPS = 32;

const int REVS_TO_DIST = 40; // distance per full revolution of the guide motor (mm)

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