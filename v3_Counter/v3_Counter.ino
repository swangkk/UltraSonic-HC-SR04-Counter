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
  int count=0;

void setup() {
  //시리얼포트 활성화
  Serial.begin(9600);
  
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
    duration = pulseIn(EchoPin, HIGH, 11764); //11764us (약200cm)초과하면 0으로
    distance = duration * 0.034 / 2;

   //0일땐 값 200cm
      if(distance == 0){
        distance = 200;
      } else{}


  //필터
    distance0 = distance1;
    distance1 = distance0*0.80 + distance*0.20;

  //시리얼 모니터에 표시
  Serial.print(distance0);
  Serial.print("      ");
  Serial.println(distance1);
  
  //트리거
  if(distance0>70 and distance1<=70){
    count=count+1;
  }else{}

  //OLED에 표시
  Serial.println(count);
  display.clearDisplay();
  display.setTextSize(4);
  display.setCursor(50, 0);
  display.print(count);
  display.display();
    
}
