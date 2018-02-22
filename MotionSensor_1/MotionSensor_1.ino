// 2018/01/18
// Faya-Nugget 範例程式 (MotionSensor_1.ino)
// 單元: 模組介紹-faya人體感應模組
/////// 網址:
// 目標: (1)當感測模組偵測到人體動作變化時
//       (2)LED變為ON，並停2秒
//       (3)可支援Serial Plotter輸出,用於觀察感測數值曲線變化(只支援1.6.6以上的IDE)
//       
// 接線: Arduino  ==> faya模組
//          A0    ==>   Vout  (人體感應模組)
//          
//     
#include <Timer.h>
Timer tcb1;

int PIR_pin=A0;       //人體感應模組的Vout街上Arduino的A0
int LED_pin=13;       //使用Arduino上 pin13 的LED燈
int Motion_value=13;  //人體動作感應的判斷數值, 判斷範圍約:10~40
int sensor_value=0;   //感測器回傳的感測數值
int sensor_temp=0;    //感測數值的暫存器

void setup() {
  
  Serial.begin(9600);            //宣告UART的Board rate為9600
  pinMode(LED_pin,OUTPUT);      //宣告pin13為輸出腳
  
  //使用Timer.h的應用,功能為:每經過800毫秒,呼叫 LED_control 副程式一次
  tcb1.every(800, LED_control); 
  

}

void loop() {
  
  sensor_value=analogRead(PIR_pin); //從A0讀取人體感應模組的感測值
  Serial.println(sensor_value);      //將數值回傳到Serial Monitor (或者Serial Plotter)顯示
  tcb1.update();                    //按照預先設定的時間呼叫 LED_control 副程式
 
}

void LED_control()
{
  //當人體感應模組的感測值與800毫秒之前的感測值做個比較,
  //如果相差超過判斷數值(Motion_value),則使 pin13 的輸出為HIGH,
  //並延遲2秒
  if(abs(sensor_value-sensor_temp)>=Motion_value) 
  {
    digitalWrite(LED_pin,HIGH);
    delay(2000);
  }
  else  //否則使 pin13 的輸出為LOW
    digitalWrite(LED_pin,LOW);

  //將這次人體感應模組的感測值儲存到暫存器中,
  //等待下次的判斷
  sensor_temp=sensor_value;
}
