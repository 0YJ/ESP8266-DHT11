#pragma once

#include "JsonListener.h"
#include "JsonStreamingParser.h"

class MetOfficeClient: public JsonListener {
  private:
    String currentKey;
    String currentParent = "";
    String currentDate = "";
    String currentForecast = "";
    String secondForecast = "";
    String thirdForecast = "";
    String fourthForecast = "";
    String locationName = "";
    String temperature = "";
    String feelsLikeTemp = "";
    String windDirection = "";
    String windSpeed = "";
    String windGust = "";
    String maxUvIndex = "";
    String weatherType = "";
    String precipProb = "";
    String forecastArray[36] = { }; // String array to hold the segmented forecast data for the required 4 periods
    int count = 0; // Count used to populate the above array with required forecast values on parsing

    void doUpdate(String url);

  public:
    MetOfficeClient();
    virtual void whitespace(char c);
    virtual void startDocument();
    virtual void key(String key);
    virtual void value(String value);
    virtual void endArray();
    virtual void endObject();
    virtual void endDocument();
    virtual void startArray();
    virtual void startObject();

    void updateConditions(String ThirdForecastPeriod, int location, String apiKey);

    String getLocationName();
    String getCurrentDate();
    String getCurrentForecastTime();
    String getCurrentWindDirection();
    String getCurrentFeelsLikeTemp();
    String getCurrentWindGust();
    String getCurrentPrecipProb();
    String getCurrentWindSpeed();
    String getCurrentTemperature();
    String getCurrentWeatherType();
    String getCurrentMaxUvIndex();
    String getSecondForecastTime();
    String getSecondWindDirection();
    String getSecondFeelsLikeTemp();
    String getSecondWindGust();
    String getSecondPrecipProb();
    String getSecondWindSpeed();
    String getSecondTemperature();
    String getSecondWeatherType();
    String getSecondMaxUvIndex();
    String getThirdForecastTime();
    String getThirdWindDirection();
    String getThirdFeelsLikeTemp();
    String getThirdWindGust();
    String getThirdPrecipProb();
    String getThirdWindSpeed();
    String getThirdTemperature();
    String getThirdWeatherType();
    String getThirdMaxUvIndex();
    String getFourthForecastTime();
    String getFourthWindDirection();
    String getFourthFeelsLikeTemp();
    String getFourthWindGust();
    String getFourthPrecipProb();
    String getFourthWindSpeed();
    String getFourthTemperature();
    String getFourthWeatherType();
    String getFourthMaxUvIndex();
    String getWeatherIconName(String weatherType);

};
