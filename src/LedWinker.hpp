#ifndef LEDWINKER_H
#define LEDWINKER_H

#include <stdint.h>

enum winkType : uint16_t
{
  LED_SLOW = 900,
  LED_FAST = 180,
  LED_ON = UINT16_MAX,
  LED_OFF = 0,
};

class LedWinker
{
    private:
        uint8_t pin;
        uint16_t winkSpeed = winkType::LED_OFF;
        bool lastState = false;
        unsigned long lastBlinkedTime = 0;

    public:
        LedWinker(uint8_t pin);
        void Loop();

        inline bool GetState() const
        {
          return lastState;
        }

        inline void Wink(uint16_t winkSpeed)
        {
          this->winkSpeed = winkSpeed;
        }

        void off();
        void on();
  
        inline uint16_t getWinkSpeed() const {
          return winkSpeed;
        }
};

#endif
