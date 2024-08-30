#pragma once
#include <Arduino.h>
#include <time.h>


class Astronomy {
  private:

  public:
    typedef struct MoonData {
      uint8_t phase;
      double illumination;
    } MoonData;

    Astronomy();

    uint8_t calculateMoonPhase(time_t timestamp);
    uint8_t calculateMoonPhase(uint16_t year, uint8_t month, uint8_t day);
    MoonData calculateMoonData(time_t timestamp);
    MoonData calculateMoonData(uint16_t year, uint8_t month, uint8_t day);

};
