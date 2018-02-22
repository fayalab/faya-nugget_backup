// Faya-Nugget Sample Code 
// Date: 2015/4/28
// Module Name: Geared Motor
// Module Number: #ngt-mt-grdmtr-1A
// Description: 用Arduino輸出3組不同的訊號,控制減速馬達的轉速以及方向. 

// Wiring: Module Pin ==> Arduino Pin
//                SIG ==> D11
//                DIR ==> D12

// define pins
int MtSig=11;
int MtDir=12;

void setup()
{
  // initialize the digital pin as an output.
  pinMode(MtSig,OUTPUT);
  pinMode(MtDir,OUTPUT);
}



void loop()
{
    //順時針慢速
    analogWrite(MtSig,140);
    digitalWrite(MtDir,HIGH);
    delay(3000);
    
    //順時針高速
    analogWrite(MtSig,200);
    digitalWrite(MtDir,HIGH);
    delay(3000);
    
    //逆時針慢速
    analogWrite(MtSig,140);
    digitalWrite(MtDir,LOW);
    delay(3000);
}
