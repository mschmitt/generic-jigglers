// Mouse Jiggler for Atmega32U4-based BadUSB Beetles
// Compile for "Arduino Leonardo"
#include "Mouse.h"

// Lower and upper limit in milliseconds for time between random mouse movements
#define MINMS 30000
#define MAXMS 60000

// Movement distance - Set to e.g. 10 to make visible for debugging
#define DISTANCE 1

// Movement pattern
int motions[4][4] = {
  {  0, -1}, // 1 up
  {  1,  0}, // 1 right
  {  0,  1}, // 1 down
  { -1,  0}  // 1 left
};

void setup() {
  Mouse.begin();
  // Startup sequence to show there's a sketch running
  delay(500); Mouse.move(  0, -10);
  delay(500); Mouse.move( 10,   0);
  delay(500); Mouse.move(  0,  10);
  delay(500); Mouse.move(-10,   0);
}

void loop() {
  for (int i = 0; i < 4; i++) {
    // Move mouse
    Mouse.move(motions[i][0]*DISTANCE, motions[i][1]*DISTANCE, 0);
    // Wait random amount of time
    delay(random(MINMS, MAXMS));
  }
}
