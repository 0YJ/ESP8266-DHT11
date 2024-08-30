#pragma once

#include "ESPWiFi.h"

#define NTP_PACKET_SIZE 48

class TimeClient {

  private:
    float myUtcOffset = 0;
    long localEpoc = 0;
    unsigned long localMillisAtUpdate;

    const char* ntpServerName = "time.nist.gov";
    unsigned int localPort = 2390;

    byte packetBuffer[ NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets


  public:
    TimeClient(float utcOffset);
    void updateTime();
    void setUtcOffset(float utcOffset);
    String getHours();
    String getMinutes();
    String getSeconds();
    String getFormattedTime();
    long getCurrentEpoch();
    long getCurrentEpochWithUtcOffset();

};
