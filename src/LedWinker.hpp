#include "Arduino.h"

enum winkType {
  SLOW,
  FAST,
  ON,
  OFF
};

class LedWinker
{
    public:
        LedWinker(int GPIO);
        void Wink(winkType TYPE);
        void Loop();
    private:
        int _GPIO{0};
        winkType _winkType{OFF};
        uint8_t _lastState{LOW};
        unsigned long _lastBlinkedTime{0};

        void checkBlinkTime(int);
};
