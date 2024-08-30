#pragma once

#include "JsonListener.h"
#include "JsonStreamingParser.h"
#include "ESPWiFi.h"
#include <WiFiClient.h>


class WorldClockClient: public JsonListener {
  private:
    unsigned long millisOfDayAtUpdate = 0;
    unsigned long localMillisAtUpdate;
    boolean isHeader = true;
    String currentKey = "";
    String myLanguage;
    String myCountry;
    String* myTimeZoneIds;
    int myNumberOfTimeZoneIds;
    String myDateFormat;

    int currentTimeZoneIndex;
    long* timeZoneOffsetToUtcMillis;

  public:
    WorldClockClient(String language, String country, String dateFormat, int numberOfTimeZones, String* timeZoneIds);

    void updateTime();

    String getFormattedTime(int timeZoneIndex);

    String getHours(int timeZoneIndex);

    String getMinutes(int timeZoneIndex);

    String getSeconds(int timeZoneIndex);

    long getSecondsOfDay(int timeZoneIndex);

    virtual void whitespace(char c);

    virtual void startDocument();

    virtual void key(String key);

    virtual void value(String value);

    virtual void endArray();

    virtual void endObject();

    virtual void endDocument();

    virtual void startArray();

    virtual void startObject();
};
