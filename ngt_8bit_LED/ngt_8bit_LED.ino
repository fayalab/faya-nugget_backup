// Faya-Nugget Sample Code
// Date: 2015/1/26
// Module Name: 8-bit Red LED
// Module Number: #ngt-dp-led8r-1A
// Description: Make a shift-left running LED.

// Wiring: Module Pin ==> Arduino Pin
//                 D0 ==> D6
//                 D1 ==> D7
//                 D2 ==> D8
//                 D3 ==> D9
//                 D4 ==> D10
//                 D5 ==> D11
//                 D6 ==> D12
//                 D7 ==> D13


// define pins
#define Led0_Pin 6

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
 for(int i=Led0_Pin; i<=Led0_Pin+7; i+=1)
      pinMode(i, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  for(int i=Led0_Pin; i<=Led0_Pin+7; i+=1)
  {
        digitalWrite(i, HIGH);
        delay(500);
        digitalWrite(i, LOW);
        delay(100);
  }
}

