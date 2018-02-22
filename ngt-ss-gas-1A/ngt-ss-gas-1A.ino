// Faya-Nugget Sample Code 
// Date: 2015/04/29
// Module Name: Gas Sensor
// Module Number: #ngt-ss-gas-1A
// Description: 讀取微動開關的狀態,延長計時器倒數的時間,並透過Serial Monitor顯示. 

// Wiring: Module Pin ==> Arduino Pin
//               N.C. ==> D11
//               N.O. ==> D12

int LedPin=11;

void setup()
{
  Serial.begin(9600);
  pinMode(LedPin,OUTPUT);
}

int GasValue=0;
int temp=0;
int i=0;
int j=0;

void loop()
{
  GasValue=analogRead(A0);
  temp=map(GasValue,0,1023,100,1);
  
  analogWrite(LedPin,i);
  if(i<255 && j==0)
  {
    i++;
    if(i==255)
      j=1;
  }
  else if(i>0 && j==1)
  {
    i--;
    if(i==0)
      j=0;
  }
  delay(temp);
  
  
  Serial.println(GasValue);
  
}

