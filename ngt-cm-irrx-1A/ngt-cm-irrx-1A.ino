// Faya-Nugget Sample Code 
// Date: 2015/4/28
// Module Name: IR Receiver
// Module Number: #ngt-cm-irrx-1A
// Description: 需搭配IR Transmitter測試.

// Wiring: Module Pin ==> Arduino Pin
//                Din ==> D0 (Rx)


void setup()
{
  //setup uart baud rate.
  Serial.begin(2400);
}

char ReadData = 0; //資料暫存宣告

void loop()
{
  // send data only when you receive data:
  if (Serial.available() > 0) //判斷Rx是否有資料來
  {
     ReadData = Serial.read();//讀取Rx資料
     Serial.print(ReadData);  //由Serial Monitor顯示讀取到的資料
  }
}
