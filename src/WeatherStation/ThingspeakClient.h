#pragma once

#include "JsonListener.h"
#include "JsonStreamingParser.h"
#include "ESPWiFi.h"
#include <WiFiClient.h>

#define MAX_FORECAST_PERIODS 7

class ThingspeakClient: public JsonListener {
  private:
    // Thingspeak has a maximum of 8 fields
    String lastFields[8];
    String fieldLabels[8];
    String createdAt;
    boolean isHeader = true;
    String currentKey = "";
    
  public:
    ThingspeakClient();
    
    void getLastChannelItem(String channelId, String readApiKey);

    String getFieldLabel(int index);

    String getFieldValue(int index);

    String getCreatedAt();
    
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
