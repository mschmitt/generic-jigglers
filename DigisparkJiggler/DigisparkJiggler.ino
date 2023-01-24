// Mouse Jiggler for Digispark-based USB Beetles
// Compile for "Digispark (Default 16.5 MHz)"
#include <DigiMouse.h>

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
  pinMode(1, OUTPUT);
  DigiMouse.begin();
  // Startup sequence to show there's a sketch running
  // Blink 2 times slow, followed by a quick blink after entering loop()
  digitalWrite(1, HIGH); DigiMouse.delay(500); DigiMouse.moveY(-10);
  digitalWrite(1, LOW);  DigiMouse.delay(500); DigiMouse.moveX(10);
  digitalWrite(1, HIGH); DigiMouse.delay(500); DigiMouse.moveY(10);
  digitalWrite(1, LOW);  DigiMouse.delay(500); DigiMouse.moveX(-10);
  DigiMouse.delay(100);
}

void loop() {
  for (int i = 0; i < 4; i++) {
    // Move mouse
    digitalWrite(1, HIGH);
    DigiMouse.moveY(motions[i][0]*DISTANCE);
    DigiMouse.moveX(motions[i][1]*DISTANCE);
    DigiMouse.delay(50);
    digitalWrite(1, LOW); 
    // Wait random amount of time
    DigiMouse.delay(random(MINMS, MAXMS));
  }
}
