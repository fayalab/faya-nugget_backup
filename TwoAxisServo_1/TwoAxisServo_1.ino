// 2017/9/4
// Faya-Nugget 範例程式 (TwoAxisServo_1.ino)
// 單元: 模組介紹:faya雙軸伺服馬達模組
// 網址: https://fayalab.blogspot.com/2017/08/2axisServo.html
// 目標: (1) 左右移動搖桿時，伺服馬達左右擺動
//       (2) 上下移動搖桿時，伺服馬達上下轉動
// 接線: Arduino ==> faya模組
//             5 ==> YM1 (雙軸伺服馬達模組)
//             6 ==> XM2 (雙軸伺服馬達模組)
//            A5 ==> VRX (搖桿模組)
//            A4 ==> VRY (搖桿模組)

#define  YM1  5    // YM1連到5腳
#define  XM2  6    // XM2連到6腳
#define  VRX  A5   // VRX連到A5腳
#define  VRY  A4   // VRY連到A4腳

#include <Servo.h>    //使用伺服馬達函示庫

Servo fayaServoYM1;		// 建構servo物件 : ServoYM1 (控制上方伺服馬達)
Servo fayaServoXM2;		// 建構servo物件 : ServoXM2 (控制下方伺服馬達)
int val_VRX, val_VRY;		// 搖桿X-Y埠的讀取變數 

void setup()
{  
   fayaServoYM1.attach(YM1); 	 // 伺服馬達YM1連接第5腳
   fayaServoXM2.attach(XM2); 	 // 伺服馬達XM2連接第6腳
   pinMode(VRX, INPUT);   // A5為輸入腳位，偵測VRX值
   pinMode(VRY, INPUT);   // A4為輸入腳位，偵測VRY值
} 

void loop()
{  
   val_VRX = analogRead(VRX);	              // 讀取搖桿VRX電壓 (0~1023)
   val_VRX = map(val_VRX,0,1023, 0,180);	  // 將讀取值對應到 (0~180)
   fayaServoYM1.write(val_VRX); 	          // 利用對應值控制驅動角度
   val_VRY = analogRead(VRY);	              // 讀取搖桿VRY電壓 (0~1023)
   val_VRY = map(val_VRY,0,1023, 0,180);	  // 將讀取值對應到 (0~180)
   fayaServoXM2.write(val_VRY); 	          // 利用對應值控制驅動角度
   delay(100); 			                        
}
