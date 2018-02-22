/* Test Code */
// Faya-Nugget Sample Code 
// Date: 2015/4/29
// Module Name: Proximity Sensor
// Module Number: #ngt-ss-prxty-1A
// Description: . 

// Wiring: Module Pin ==> Arduino Pin
//               Vout ==> A0

int prxtyPin=5;
int LEDPin=13;

void setup()
{
  Serial.begin(9600);
  pinMode(prxtyPin,INPUT);
  pinMode(LEDPin,OUTPUT);
}

void loop()
{
  
  if(digitalRead(prxtyPin)==HIGH)
    digitalWrite(LEDPin,HIGH);
  else if(digitalRead(prxtyPin)==LOW)
    digitalWrite(LEDPin,LOW);
  Serial.println(digitalRead(prxtyPin));
  //delay(500);
}
