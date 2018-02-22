/* Test Code */
// Faya-Nugget Sample Code 
// Date: 2015/04/29
// Module Name: Motion Sensor
// Module Number: #ngt-ss-pir-1A
// Description: . 

// Wiring: Module Pin ==> Arduino Pin
//               Vout ==> A0


int Pir=0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Pir = analogRead(A0);
  Serial.println(Pir);
  if(Pir<659)
  {
    Serial.println("No motion");
  }
  if(Pir>660)
  {
    Serial.println("Motion!");
  }
  delay(500);
}
