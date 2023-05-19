#include <Arduino.h>
#include "LedWinker.hpp"

LedWinker::LedWinker(uint8_t pin, bool activeHigh) : pin(pin), activeHigh(activeHigh)
{
    // Set to default LOW (off) the LED
    pinMode(pin, OUTPUT);
    off();
}

void LedWinker::off()
{
    this->winkSpeed = winkType::LED_OFF;
    digitalWrite(pin, !(activeHigh ^ LOW));
    lastState = false;
}

void LedWinker::on()
{
    this->winkSpeed = winkType::LED_ON;
    digitalWrite(pin, !(activeHigh ^ HIGH));
    lastState = true;
}

void LedWinker::Loop()
{
    if (winkSpeed == winkType::LED_ON || winkSpeed == winkType::LED_OFF)
    {
        return;
    }
    const auto currentMillis = millis();
    if (currentMillis - lastBlinkedTime >= winkSpeed)
    {
        lastBlinkedTime = currentMillis;
        digitalWrite(pin, !(activeHigh ^ !lastState));
        lastState = !lastState;
    }
}