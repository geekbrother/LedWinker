#ifndef LEDWINKER_H
#define LEDWINKER_H

#include <stdint.h>

enum winkType {
  LED_SLOW,
  LED_FAST,
  LED_ON,
  LED_OFF
};

class LedWinker
{
    public:
        LedWinker(uint8_t pin);
        void Wink(winkType TYPE);
        void Loop();
        winkType GetState();
    private:
        uint8_t pin;
        winkType _winkType{LED_OFF};
        uint8_t _lastState{LOW};
        unsigned long _lastBlinkedTime{0};

        void checkBlinkTime(int);
};

#endif
