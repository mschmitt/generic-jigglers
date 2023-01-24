# Generic Jigglers

Virtual mouse emulators.

Both sketches will briefly move the mouse in a square after plugging in, so you can visually confirm they are working. Afterwards, the mouse will be moved by 1 step every 30-60 seconds.

- **ArduinoJiggler** is for "ATmega32U4 BadUSB Beetles" as found on Ebay. Compile for "Arduino Leonardo".
- **DigisparkJiggler** is for clones of the [ATtiny85 Digispark Board](http://digistump.com/products/1). Compile for "Digispark Default 16.5 MHz".
  - [Instructions for setting up the Arduino IDE for Digispark](http://digistump.com/wiki/digispark/tutorials/connecting) - Mirror included in the *DigisparkJiggler* Directory.
  - The Digispark has been found to be unreliable on some unpowered USB hubs.
  - *DigisparkJiggler* outputs a diagnostic-ish blink pattern; see the sketch about that.
