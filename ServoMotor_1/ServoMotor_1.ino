// 2017/11/28
// Faya-Nugget 範例程式 (ServoMotor_1.ino)
// 單元: 模組介紹:faya伺服馬達模組
// 網址:
// 目標: (1) Arduino輸出控制訊號到伺服馬達，使兩個馬達的角度位置移動到中間位置
//       (2) 接著Arduino輪流控制馬達從最小角度移動到最大角度
// 接線: Arduino ==> faya模組
//             6 ==> YM1 (伺服馬達模組)
//             5 ==> XM2 (伺服馬達模組)

#include <Servo.h>          //使用伺服馬達專用的函示庫

//伺服馬達模組腳位設定
#define SEV1  6     //Arduino D6 連到伺服馬達模組 YM1
#define SEV2  5     //Arduino D5 連到伺服馬達模組 XM2
Servo ServoM1; 
Servo ServoM2;

void setup() {
  
  pinMode(SEV1,OUTPUT);       
  pinMode(SEV2,OUTPUT);      
  
  ServoM1.attach(SEV1,500,2400);  //設定給予伺服馬達的頻寬限制
  ServoM2.attach(SEV2,500,2400);
  
  ServoM1.write(90); //讓垂直軸的馬達(YM1)移動至中間位置
  ServoM2.write(90); //讓水平軸的馬達(XM2)移動至中間位置
  
   delay(1000);   //延遲1秒
   YM1Test();     //給予垂直軸的馬達從0~180的控制訊號  0=min, 180=max
   delay(1000);   //延遲1秒
   XM2Test();     //給予水平軸的馬達從0~180的控制訊號  0=min, 180=max
}

void loop() {
}

void YM1Test()
{
  for(int i=0;i<=180;i++)
  {  ServoM1.write(i); 
     delay(50);
  }
}

void XM2Test()
{
  for(int i=0;i<=180;i++)
  {  ServoM2.write(i); 
     delay(50);
  }
}
