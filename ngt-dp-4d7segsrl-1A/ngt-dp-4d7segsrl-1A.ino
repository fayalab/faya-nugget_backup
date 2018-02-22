/* Test Code  */

// Faya-Nugget Sample Code 
// Date: 2015/4/30
// Module Name: Serial 4-digiht 7-segment Display
// Module Number: #ngt-dp-4d7segsrl-1A
// Description: 傳送串列式訊號控制4位數7段顯示器顯示的數字. 

// Wiring: Module Pin ==> Arduino Pin
//                DIN ==> D12
//                CLK ==> D11
//               LOAD ==> D10

//We always have to include the library
#include "LedControl.h"  

// define pins
LedControl lc=LedControl(12,11,10,1);

unsigned long delaytime=300;

void setup() 
{
  lc.shutdown(0,false); 
  lc.setIntensity(0,8);  /* Set the brightness to a medium values */
  lc.clearDisplay(0);    //Reset Display
}

int i=0;

void loop() 
{ 
  scrollDigits(i);    //Set Display Number
  i += 1111;
  if(i==11110)
    i=0;
 
  
}

void scrollDigits(int temp) 
{
  
    int num1,num2,num3,num4;
    num1=temp/1000;
    num2=(temp%1000)/100;
    num3=(temp%100)/10;
    num4=temp%10;
    
    lc.setDigit(0,3,num1,false);
    lc.setDigit(0,2,num2,false);
    lc.setDigit(0,1,num3,false);
    lc.setDigit(0,0,num4,false);
    delay(delaytime);
    lc.clearDisplay(0);
    
}


