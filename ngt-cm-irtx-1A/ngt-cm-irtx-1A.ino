// Faya-Nugget Sample Code 
// Date: 2015/4/28
// Module Name: IR Transmitter
// Module Number: #ngt-cm-irtx-1A
// Description: 需搭配IR Receiver測試.

// Wiring: Module Pin ==> Arduino Pin
//               Dout ==> D1 (Tx)


void setup()
{
  //setup uart baud rate.
  Serial.begin(2400);
}

void loop()
{
  Serial.println("TestOK!");  //傳送字串 TestOK!
  delay(1000);
}
