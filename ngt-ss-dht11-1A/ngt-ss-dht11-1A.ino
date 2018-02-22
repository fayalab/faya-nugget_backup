// Faya-Nugget Sample Code 
// Date: 2015/04/28
// Module Name: Humidity & Temperature Sensor
// Module Number: #ngt-ss-dht11-1A
// Description: 讀取溫濕度感測器的溫度與濕度訊號,並將訊號轉換後顯示在Serial Monitor中. 
// Reference:http://playground.arduino.cc/Main/DHTLib

// Wiring: Module Pin ==> Arduino Pin
//               Data ==> D5

//We always have to include the library
#include <dht.h>
dht DHT;

// define pins
#define DHT11_PIN 5

void setup()
{
  Serial.begin(115200);
  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT_LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
}

void loop()
{
  // READ DATA
  Serial.print("DHT11, \t");
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
		Serial.print("OK,\t"); 
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		Serial.print("Checksum error,\t"); 
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		Serial.print("Time out error,\t"); 
		break;
    default: 
		Serial.print("Unknown error,\t"); 
		break;
  }
  // DISPLAY DATA
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);

  delay(2000);
}

