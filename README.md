# LedWinker
This is a tiny Platform.io (Arduino) library to control state of LED(s) in async manner.

Blink your LED (FAST or SLOW), ON/OFF LED and change LED state async (without any delay) inside global loop functions of your Platform.io or Arduino project.

Usage example:
```cpp
// This is sample Arduino / Platform.io program
// to use LedWinker library
#include <Arduino.h>
#include <LedWinker.hpp>


#define LED_GPIO 13
// Initialize winker on LED GPIO number
LedWinker winker(LED_GPIO);

// serial incoming message
String incoming;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Start Winkering ;)");
  Serial.println("Enter one of the state: ON | OFF | SLOW | FAST:");
}

void loop() {
  // put your main code here, to run repeatedly:
  // You need to put winker.Loop() inside your main loop() to observe the changes.
  winker.Loop();

  // Listen to commands from serial
  // You can use ON, OFF, FAST (blinking), SLOW (blinking)
  if (Serial.available() > 0) {
    // read the incoming
    incoming = Serial.readString();
    // say what you got:
    Serial.println(incoming);
    // change led state depend on command
    if (incoming == "ON") winker.Wink(ON); // ON LED
    if (incoming == "OFF") winker.Wink(OFF); // OFF LED
    if (incoming == "FAST") winker.Wink(FAST); // Blink Fast
    if (incoming == "SLOW") winker.Wink(SLOW); // Blink Slow
  } 
}
```
