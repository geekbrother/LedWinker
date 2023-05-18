#include <Arduino.h>
#include "LedWinker.hpp"

LedWinker::LedWinker(uint8_t pin): pin(pin)
{
    // Set to default LOW (off) the LED
    pinMode(pin, OUTPUT);
    off();
}

void LedWinker::off()
{
    this->winkSpeed = winkType::LED_OFF;
    digitalWrite(pin, LOW);
    lastState = false;
}

void LedWinker::on()
{
    this->winkSpeed = winkType::LED_ON;
    digitalWrite(pin, HIGH);
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
        digitalWrite(pin, !lastState);
        lastState = !lastState;
    }
}