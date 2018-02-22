// 2017/10/18
// Faya-Nugget 範例程式 (Color_Sticker_1.ino)
// 單元: 模組介紹:faya串列全彩LED模組
// 網址: https://fayalab.blogspot.com/2017/09/colorsticker.html
// 目標: (1) 跑馬燈依序顯示紅橙黃綠青藍靛紫8種顏色

// 接線: Arduino ==> faya模組
//            D2 ==> 串列全彩LED_Din

#include <Adafruit_NeoPixel.h>

#define Neo_Pin       2   //串列全彩LED_Din腳位
#define NUMPIXELS     8   //串列全彩LED數量 
Adafruit_NeoPixel faya_colorSticker = Adafruit_NeoPixel(NUMPIXELS, Neo_Pin, NEO_GRB + NEO_KHZ800);

void setup() 
{
  faya_colorSticker.begin();            // 初始化NeoPixel函示庫
  faya_colorSticker.setBrightness(10);  // 亮度設定 (0~255) 
}

void loop()
{
  faya_colorSticker.setPixelColor(0,255,0,0);     //紅
  delay(200);
  faya_colorSticker.show();
  faya_colorSticker.setPixelColor(1,255,127,0);   //橙 
  delay(200);
  faya_colorSticker.show();
  faya_colorSticker.setPixelColor(2,255,255,0);   //黃 
  delay(200);
  faya_colorSticker.show();
  faya_colorSticker.setPixelColor(3,0,255,0);     //綠
  delay(200);
  faya_colorSticker.show();
  faya_colorSticker.setPixelColor(4,0,255,255);   //青
  delay(200);
  faya_colorSticker.show();                       
  faya_colorSticker.setPixelColor(5,0,0,255);     //藍   
  delay(200);
  faya_colorSticker.show();
  faya_colorSticker.setPixelColor(6,43,0,255);    //靛  
  delay(200);
  faya_colorSticker.show();
  faya_colorSticker.setPixelColor(7,87,0,255);    //紫
  delay(200);
  faya_colorSticker.show();
  delay(200);
  faya_colorSticker.clear();
}
