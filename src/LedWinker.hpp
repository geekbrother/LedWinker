#ifndef LEDWINKER_H
#define LEDWINKER_H

#include "Arduino.h"

enum winkType {
  LED_SLOW,
  LED_FAST,
  LED_ON,
  LED_OFF
};

class LedWinker
{
    public:
        LedWinker(int GPIO);
        void Wink(winkType TYPE);
        void Loop();
        winkType GetState();
    private:
        int _GPIO{0};
        winkType _winkType{LED_OFF};
        uint8_t _lastState{LOW};
        unsigned long _lastBlinkedTime{0};

        void checkBlinkTime(int);
};

#endif
