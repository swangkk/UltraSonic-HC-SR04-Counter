//초음파센서부분
#define TrigPin  D7
#define EchoPin  D8

  //변수선언
  float duration;
  float distance;
  float a,b,c,d[5],e[5];
  int dtot, dave, eave;

void setup() {
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  delay(1000);
}

void loop() {
  int etot;
  
  // 센서 읽기
  for (int i=0;i<5;i++){
    delay(100);
    digitalWrite(TrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin, LOW);
    duration = pulseIn(EchoPin, HIGH, 11764);
    distance = duration * 0.034 / 2;
      if(distance == 0){
        distance = 200.0;
      } else{}
    a = b;
    b = c;
    c = b*0.8 + distance*0.2;
    e[i]=c;
    etot=etot+e[i];
  }
  dave=dtot/5;
  eave=etot/5;
  dtot=etot; 
  Serial.print(dave);
  Serial.print("      ");
  Serial.print(eave);
  Serial.print("\n");
}
