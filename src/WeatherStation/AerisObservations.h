#pragma once
//#define NIGHTICONS
#include <Arduino.h>
#include "JsonListener.h"
#include "JsonStreamingParser.h"

typedef struct AerisObservationsData {
    uint64_t timestamp;
    String dateTimeISO;
    int16_t tempC;
    int16_t tempF;
    int16_t dewpointC;
    int16_t dewpointF;
    uint8_t humidity;
    uint16_t pressureMB;
    float pressureIN;
    uint16_t spressureMB;
    float spressureIN;
    uint16_t altimeterMB;
    float altimeterIN;
    uint16_t windSpeedKTS;
    uint16_t windSpeedKPH;
    uint16_t windSpeedMPH;
    uint16_t windDirDEG;
    String windDir;
    uint16_t windGustKTS;
    uint16_t windGustKPH;
    uint16_t windGustMPH;
    String flightRule;
    float visibilityKM;
    float visibilityMI;
    String weather;
    String weatherShort;
    String weatherCoded;
    String weatherPrimary;
    String weatherPrimaryCoded;
    String cloudsCoded;
    String icon;
    String iconMeteoCon;
    int16_t heatindexC;
    int16_t heatindexF;
    int16_t windchillC;
    int16_t windchillF;
    int16_t feelslikeC;
    int16_t feelslikeF;
    boolean isDay;
    uint64_t sunrise;
    String sunriseISO;
    uint64_t sunset;
    String sunsetISO;
    uint16_t snowDepthCM;
    uint16_t snowDepthIN;
    uint16_t precipMM;
    uint16_t precipIN;
    uint16_t solradWM2;
    String solradMethod;
    uint16_t light;
    uint16_t sky;
} AerisObservationsData;

class AerisObservations: public JsonListener {
  private:
    const String host = "api.aerisapi.com";
    const uint8_t port = 80;
    boolean isMetric = true;
    String currentKey;
    String currentParent;
    AerisObservationsData *observations;


  void doUpdate(AerisObservationsData *conditions, String url);

  public:
    AerisObservations();
    void updateObservations(AerisObservationsData *observations, String clientId, String clientKey, String location);

    String getMeteoconIcon(String icon);
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
