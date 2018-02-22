// Faya-Nugget Sample Code 
// Date: 2015/04/28
// Module Name: Limit Switch
// Module Number: #ngt-di-lmt-1A
// Description: 讀取微動開關的狀態,延長計時器倒數的時間,並透過Serial Monitor顯示. 

// Wiring: Module Pin ==> Arduino Pin
//               N.C. ==> D11
//               N.O. ==> D12

// define pins
int NC=11;
int NO=12;

void setup()
{
  //setup uart baud rate.
  Serial.begin(9600);
  // initialize the digital pin as an input.
  pinMode(NC,INPUT);
  pinMode(NO,INPUT);
}

int temp=201;  //預設的起始時間

void loop()
{
  
  if(digitalRead(NC)==HIGH && temp>0)  //微動開關未按下時,持續倒數
  {
    temp--;
    delay(1000);
    Serial.print("Value= ");
    Serial.println(temp);
  }
  else if(digitalRead(NO)==HIGH)      //按下微動開關,增加倒數的數值
  {
    temp++;
    delay(100);
    Serial.print("Value= ");
    Serial.println(temp);
  }
  
     
  
  
}
