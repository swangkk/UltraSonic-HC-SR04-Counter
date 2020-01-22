//초음파센서부분선언
#define TrigPin  D7
#define EchoPin  D8

//디스플레이부분선언
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET LED_BUILTIN  //4
Adafruit_SSD1306 display(OLED_RESET);
#if (SSD1306_LCDHEIGHT != 64)
//#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


  //변수선언
  float duration, distance, distance0, distance1=199;
  //float dist_a, dist_b, dist_c, ave_abc;
  int count=0, countdis=0;

void setup() {
  //시리얼포트 활성화
  Serial.begin(115200);
  
  //초음파센서 활성화
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  //디스플레이 활성화
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  //display.display();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("START!");
  display.display();
  
  delay(1000);
}

void loop() {
  
  // 센서 읽기
    delay(10);
    digitalWrite(TrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin, LOW);
    duration = pulseIn(EchoPin, HIGH, 11764); //11764us (약200cm)
    distance = duration * 0.034 / 2;
 if(distance == 0){distance = 200;}else{}

//  dist_a = dist_b;
//  dist_b = dist_c;
 // dist_c = distance;
 // ave_abc = (dist_a + dist_b + dist_c)/3;

 //if((abs(ave_abc - dist_b) < 20) or (dist_a >= dist_b >= dist_c) or (dist_a <= dist_b <= dist_c)){
 
 
   //lowpass highpass
   //if(dist_b > 5 and dist_b < 201){
   if(distance > 5 and distance < 201){

  //필터
    distance0 = distance1;
    //distance1 = distance0*0.90 + dist_b*0.10;
    distance1 = distance0*0.95 + distance*0.05;

  //시리얼 모니터에 표시
  Serial.print(distance1);
  Serial.print("      ");
  Serial.print(distance);
  Serial.print("      ");
  Serial.println(count);
  
  //트리거
  if(distance0>40 and distance1<=40){
    count=count+1;
  }else{}

  //OLED에 표시
  if(count > countdis){
    display.clearDisplay();
    display.setTextSize(6);
    display.setCursor(20, 10);
    display.print(count);
    display.display();
    countdis=count;
    delay(500);
//  } else{}
  } else{}
 } else{}
}
