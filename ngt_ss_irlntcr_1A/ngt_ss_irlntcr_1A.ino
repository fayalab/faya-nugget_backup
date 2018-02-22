/*ngt-ss-irlntcr-1A*/

#define SigPin 3      /*  IR訊號發射腳位 */
#define IRPin5 A0     /*  IR Line Read 腳位設定  */
#define IRPin4 A1
#define IRPin3 A2
#define IRPin2 A3
#define IRPin1 A4

void setup()
{
    pinMode(SigPin,OUTPUT);
    Serial.begin(9600);
}

int IRRead1,IRRead2,IRRead3,IRRead4,IRRead5;

void loop()
{
     digitalWrite(SigPin,HIGH);        //IR發射開啟
     IRRead5 = analogRead(IRPin5);     /*-----------*/
     IRRead4 = analogRead(IRPin4);
     IRRead3 = analogRead(IRPin3);     //IR反射讀取
     IRRead2 = analogRead(IRPin2);
     IRRead1 = analogRead(IRPin1);     /*-----------*/
     digitalWrite(SigPin,LOW);         //IR發射關閉
     delay(1000);
     
     /*   類比訊號讀取顯示   */
     Serial.print("IR1= ");             
     Serial.print(IRRead1);    
     Serial.print("  IR2= ");
     Serial.print(IRRead2);
     Serial.print("  IR3= ");
     Serial.print(IRRead3);
     Serial.print("  IR4= ");
     Serial.print(IRRead4);
     Serial.print("  IR5= ");
     Serial.println(IRRead5);
     Serial.println("---------------------------");
}
