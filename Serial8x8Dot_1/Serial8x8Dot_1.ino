// 2017/11/01
// Faya-Nugget 範例程式 (Serial8x8Dot_1.ino)
// 單元: 模組介紹 :faya 串列8x8點矩陣模組
// 網址: https://fayalab.blogspot.com/2017/11/serial8x8dot.html
// 目標 (1) 串列8x8點矩陣模組上顯示一愛心

// 接線: Arduino ==> faya模組
//           D10 ==> LOAD (8*8矩陣顯示器模組)
//           D11 ==> CLK (8*8矩陣顯示器模組)
//           D12 ==> DIN (8*8矩陣顯示器模組)

#include "LedControl.h" 
//定義Arduino與七字節模組的連接腳位與參數
LedControl fayaSerial8x8Dot = LedControl(12,11,10,1);

//定義愛心形狀
int  heart[8][8] = 
{
{0,0,0,0,0,0,0,0},
{0,1,1,0,0,1,1,0},
{1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1},
{0,1,1,1,1,1,1,0},
{0,0,1,1,1,1,0,0},
{0,0,0,1,1,0,0,0}
};

void setup() {
  fayaSerial8x8Dot.shutdown(0,false);  // 初始化
  fayaSerial8x8Dot.setIntensity(0,10);  // 設定亮度 (0~15,15最亮)
  fayaSerial8x8Dot.clearDisplay(0);    // 清除畫面
  show_heart();
}

void loop() {
   }

void show_heart()                   //顯示愛心副程式
{
  for(int i=0; i<=7; i++)
   {
   for (int j=0; j<=7; j++)
      {
      fayaSerial8x8Dot.setLed(0,j,i,heart[i][j]);
      }
   }
}
