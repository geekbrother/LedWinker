#include <Arduino.h>
#include "LedWinker.hpp"

#define SLOW_BLINK_DELAY 900
#define FAST_BLINK_DELAY 180

LedWinker::LedWinker(uint8_t pin): pin(pin)
{
    // Set to default LOW (off) the LED
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void LedWinker::Wink(winkType TYPE){
    // Just a setter
    _winkType = TYPE;
}

void LedWinker::Loop(){
    // Check for type
    switch (_winkType) {
        case LED_SLOW:
            checkBlinkTime(SLOW_BLINK_DELAY);
            break;
        case LED_FAST:
            checkBlinkTime(FAST_BLINK_DELAY);
            break;
        case LED_ON:
            if(_lastState == LOW){
                _lastState = HIGH;
                digitalWrite(pin, _lastState);
            };
            break;
        case LED_OFF:
            if(_lastState == HIGH){
                _lastState = LOW;
                digitalWrite(pin, _lastState);
            };
            break;
    };
}

// Check is time to ON or OFF led based on delay
void LedWinker::checkBlinkTime(int DELAY){
    const unsigned long currentMillis = millis();
    if (currentMillis - _lastBlinkedTime >= DELAY) {
        // save the last time you blinked the LED
        _lastBlinkedTime = currentMillis;
        // if the LED is off turn it on and vice-versa:
        if (_lastState == LOW) {
            _lastState = HIGH;
        } else {
            _lastState = LOW;
        }
        // set the LED with the ledState of the variable:
        digitalWrite(pin, _lastState);
    }
}

// Getter of the current state
winkType LedWinker::GetState(){
    return _winkType;
}
