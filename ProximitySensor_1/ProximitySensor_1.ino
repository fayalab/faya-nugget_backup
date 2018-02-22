// 2017/11/28
// Faya-Nugget 範例程式 (ProximitySensor_1.ino)
// 單元: 模組介紹:faya近接開關模組(金屬感測模組)
// 網址:
// 目標: (1) Arduino接收近接開關模組的訊號
//       (2) 當模組感測到金屬物質時，則Arduino內建的LED則會ON，否則為OFF

// 接線: Arduino ==> faya模組
//             8 ==> Out (近接開關模組)

//近接開關模組腳位設定
int ProxSensor = 8;     //Arduino D8 連到近接開關模組 Out
int LED = 13;

void setup() {
  
  pinMode(ProxSensor,INPUT);   // 設定  8 腳為輸入腳，接收模組的訊號 
  pinMode(LED,OUTPUT);         // 設定 13 腳為輸出腳，控制內建LED

}

void loop() {
  
  if(digitalRead(ProxSensor) == HIGH)  //當模組偵測到金屬物質的時，執行以下程式
     digitalWrite(LED,HIGH);  //使Arduino內建的LED為ON
  else
     digitalWrite(LED,LOW);   //使Arduino內建的LED為OFF
}


