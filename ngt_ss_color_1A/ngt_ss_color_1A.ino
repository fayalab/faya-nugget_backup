/*********************************************************************
** FayaLab RGB Sensor                                       **
********************************************************************/

#include <TimerOne.h>

#define S0     3
#define S1     4
#define S2     5
#define S3     6
#define LED    7
#define OUT    2

int   RGB_count = 0;   // 計數頻率
int   RGB_array[3];    // 儲存RGB值
int   RGB_flag = 0;    // 分離RGB三原色
float RGB_SF[3];       // 儲存RGB的比例係數
 
// 始初化TCS3200並設定頻率
void TSC3200_Init()
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(OUT, INPUT);
  
  digitalWrite(LED, HIGH);  // LED亮起
  digitalWrite(S0, LOW);    // S0=0、S1=1代表設定Output Frequency Scaling為2%
  digitalWrite(S1, HIGH); 
}
 
// 選擇FilterColor 
void TSC3200_FilterColor(int Level01, int Level02)
{
  if(Level01 != 0)
    Level01 = HIGH;
 
  if(Level02 != 0)
    Level02 = HIGH;
 
  digitalWrite(S2, Level01); 
  digitalWrite(S3, Level02); 
}
 
void TSC3200_Count()
{
  RGB_count ++ ;
}
 
void TSC3200_Callback()
{
  switch(RGB_flag)
  {
    case 0: 
         Serial.println("->White Balance Start");
         TSC3200_WB(LOW, LOW);              // S2=0、S3=0代表設定Photodiode Type為Red
         break;
    case 1:
         Serial.print("->Frequency R=");
         Serial.println(RGB_count);
         RGB_array[0] = RGB_count;
         TSC3200_WB(HIGH, HIGH);            // S2=1、S3=1代表設定Photodiode Type為Green
         break;
    case 2:
         Serial.print("->Frequency G=");
         Serial.println(RGB_count);
         RGB_array[1] = RGB_count;
         TSC3200_WB(LOW, HIGH);             // S2=0、S3=1代表設定Photodiode Type為Blue
         break;
 
    case 3:
         Serial.print("->Frequency B=");
         Serial.println(RGB_count);
         Serial.println("->White Balance End");
           RGB_array[2] = RGB_count;
         TSC3200_WB(HIGH, LOW);             // S2=1、S3=0代表設定Photodiode Type為Clear(no filter)   
         break;
   default:
         RGB_count = 0;
         break;
  }
}
 
void TSC3200_WB(int Level0, int Level1)      // 執行白平衡
{
  RGB_count = 0;
  RGB_flag ++;
  TSC3200_FilterColor(Level0, Level1);
  Timer1.setPeriod(1000000);               // 設定週期為1s
}
 
void setup()
{
  TSC3200_Init();
  Serial.begin(115200);
  Timer1.initialize();                 // 計時器預設為1s
  Timer1.attachInterrupt(TSC3200_Callback);  
  attachInterrupt(0, TSC3200_Count, RISING);  
 
  delay(4000);
 
  for(int i=0; i<3; i++)
    Serial.println(RGB_array[i]);
 
  RGB_SF[0] = 255.0/ RGB_array[0];     // R的比例係數
  RGB_SF[1] = 255.0/ RGB_array[1] ;    // G的比例係數
  RGB_SF[2] = 255.0/ RGB_array[2] ;    // B的比例係數
 
  Serial.println(RGB_SF[0]);
  Serial.println(RGB_SF[1]);
  Serial.println(RGB_SF[2]);
 
}
 
void loop()
{
   RGB_flag = 0;
   for(int i=0; i<3; i++)
    Serial.println(int(RGB_array[i] * RGB_SF[i]));
   delay(4000);
 
}



