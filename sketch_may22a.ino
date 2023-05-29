#include<Servo.h> //Servo 라이브러리를 추가

Servo myservo;      //Servo 클래스로 servo객체 생성
int value = 0;    // 각도를 조절할 변수 value
char serial_data;

void setup() {
 Serial.begin(9600);
 myservo.attach(7);
 myservo.write(90);
 delay(500);  
 myservo.write(30);
 delay(500);
 myservo.write(160);
 delay(500);
 myservo.write(90);
}

void loop() {
  while(Serial.available()>0)
  {
    serial_data = Serial.read();
    if (serial_data == 'R')
    {
      myservo.write(30);
    }
    else if (serial_data == 'G')
    {
      myservo.write(150);
    }
    else if (serial_data == 'N')
    {
      myservo.write(90);  
    }
  }
}