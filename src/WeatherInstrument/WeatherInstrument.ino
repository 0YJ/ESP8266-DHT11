#include <ESP8266WiFi.h>
#include "BMP085.h"
#include "BH1750.h"

/******************** Begin Settings ********************/

/***************************
 * WIFI Settings
 **************************/
const char* WiFi_Name = "**********";
const char* WiFi_Password = "**********";
WiFiClient client;

/***************************
 * Thingspeak Settings
 * Sign up here to get an new account:  https://thingspeak.com 
 * in thingspeak.com create a new Channel and receive "temperature", "humidity", "light" and "atmosphere" data from ESP8266
 **************************/
const char *thingspeak_Host = "api.thingspeak.com";                  //IP address of the thingspeak server
const char *thingspeak_API_key ="****************";                  //Your own thingspeak api_key
const int httpPort = 80;

/***************************
 * Begin DHT11 Settings
 **************************/
#define DHT11_Data_Pin D7     //ESP8266 D7 read Temperature and Humidity data
int currentTemperature = 0; //current temperature
int currentHumidity = 0; //current humidity
void readTemperatureHumidity();
void uploadDatatoThinkspeak();
long readTime = 0; 
long uploadTime = 0; 

/***************************
 * Begin BMP180 Atmosphere Sensor Settings
 **************************/
#define SDA_BH1750_BMP180_Pin D2     //ESP8266 D2 connect BMP180 and BH1750FVI SDA Port
#define SCL_BH1750_BMP180_Pin D1     //ESP8266 D1 connect BMP180 and BH1750FVI SCL Port
Adafruit_BMP085 bmpSensor;
int currentAtoms = 0;
void readAtmosphere();

/***************************
 * Begin BH1750FVI Light Sensor Settings
 **************************/
BH1750 lightSensor;
//const int Light_ADDR = 0b0100011;   // address:0x23
//const int Atom_ADDR = 0b1110111;  // address:0x77
int currentLight = 0;
void readLight();

/******************** End Settings ********************/

void setup() {
  Serial.begin(115200);
  //initialize BMP180 and BH1750FVI sensor
  Wire.begin(SDA_BH1750_BMP180_Pin,SCL_BH1750_BMP180_Pin);
  lightSensor.begin();
  if(!bmpSensor.begin()){
    Serial.println("Could not find a valid BMP180 sensor, check wiring!");
    while (1) {}
  }else{
    Serial.println("Find BMP180 Sensor");
  }

  WiFi.begin(WiFi_Name, WiFi_Password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  client.setTimeout(300000);
}

void loop() {
  //Read Temperature Humidity every 10 seconds
  if(millis() - readTime > 10000){
    readTemperatureHumidity();
    readLight();
    readAtmosphere();
    readTime = millis();
  }
  //Upload Temperature Humidity every 120 seconds
  if(millis() - uploadTime > 120000){
    Serial.println("---Upload Temperature Humidity every 120 seconds---");
    uploadDatatoThinkspeak();
    uploadTime = millis();
  }
}

//read temperature humidity data
void readTemperatureHumidity(){
  int j;
  unsigned int loopCnt;
  int chr[40] = {0};
  unsigned long time1;
bgn:
  delay(2000);
  //Set interface mode 2 to: output
  //Output low level 20ms (>18ms)
  //Output high level 40μs
  pinMode(DHT11_Data_Pin, OUTPUT);
  digitalWrite(DHT11_Data_Pin, LOW);
  delay(20);
  digitalWrite(DHT11_Data_Pin, HIGH);
  delayMicroseconds(40);
  digitalWrite(DHT11_Data_Pin, LOW);
  //Set interface mode 2: input
  pinMode(DHT11_Data_Pin, INPUT);
  //High level response signal
  loopCnt = 10000;
  while (digitalRead(DHT11_Data_Pin) != HIGH){
    if (loopCnt-- == 0){
      //If don't return to high level for a long time, output a prompt and start over
      Serial.println("HIGH");
      goto bgn;
    }
  }
  //Low level response signal
  loopCnt = 30000;
  while (digitalRead(DHT11_Data_Pin) != LOW){
    if (loopCnt-- == 0){
      //If don't return low for a long time, output a prompt and start over
      Serial.println("LOW");
      goto bgn;
    }
  }
  //Start reading the value of bit1-40
  for (int i = 0; i < 40; i++){
    while (digitalRead(DHT11_Data_Pin) == LOW){}
    //When the high level occurs, write down the time "time"
    time1 = micros();
    while (digitalRead(DHT11_Data_Pin) == HIGH){}
    //When there is a low level, write down the time and subtract the time just saved
    //If the value obtained is greater than 50μs, it is ‘1’, otherwise it is ‘0’
    //And save it in an array
    if (micros() - time1  > 50){
      chr[i] = 1;
    } else {
      chr[i] = 0;
    }
  }

  //Humidity, 8-bit bit, converted to a value
  currentHumidity = chr[0] * 128 + chr[1] * 64 + chr[2] * 32 + chr[3] * 16 + chr[4] * 8 + chr[5] * 4 + chr[6] * 2 + chr[7];
  //Temperature, 8-bit bit, converted to a value
  currentTemperature = chr[16] * 128 + chr[17] * 64 + chr[18] * 32 + chr[19] * 16 + chr[20] * 8 + chr[21] * 4 + chr[22] * 2 + chr[23];

  Serial.print("Temperature:");
  Serial.print(currentTemperature);
  Serial.print("    Humidity:");
  Serial.println(currentHumidity);
}

void readLight(){
  uint16_t lux = lightSensor.readLightLevel();
  currentLight = lux;
  Serial.print("Light: ");
  Serial.print(currentLight);
  Serial.println(" lx");
}

void readAtmosphere(){
  currentAtoms = bmpSensor.readPressure();
  Serial.print("Atoms = ");
  Serial.print(currentAtoms);
  Serial.println(" Pascal");
}

//upload temperature humidity data to thinkspeak.com
void uploadDatatoThinkspeak(){
  if(!client.connect(thingspeak_Host, httpPort)){
    Serial.println("connection Thingspeak failed");
    return;
  }
  // Three values(field1 field2 field3 field4) have been set in thingspeak.com 
  client.print(String("GET ") + "/update?api_key="+thingspeak_API_key+"&field1="+currentTemperature+"&field2="+currentHumidity + "&field3="+currentLight+"&field4="+currentAtoms+" HTTP/1.1\r\n" +"Host: " + thingspeak_Host + "\r\n" + "Connection: close\r\n\r\n");
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
}
