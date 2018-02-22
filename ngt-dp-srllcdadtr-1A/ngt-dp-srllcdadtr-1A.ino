/* Test Code */

// Faya-Nugget Sample Code 
// Date: 2015/4/28
// Module Name: Serial 4-digiht 7-segment Display
// Module Number: #ngt-dp-4d7segsrl-1A
// Description: 傳送串列式訊號至LCD顯示器，顯示資訊.  

// Wiring: Module Pin ==> Arduino Pin
//                SDA ==> D20 (2560),A4 (UNO)
//                SCL ==> D21 (2560),A5 (UNO)


//We always have to include the library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.print("Hello, world!");
}

void loop()
{
  
}
