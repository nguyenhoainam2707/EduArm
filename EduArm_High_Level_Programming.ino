#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;

int a0, a1, a2, a3, a4, a5;
int tmp;

void setup() {
  Serial.begin(9600);
  myservo1.attach(2);
  myservo2.attach(3);
  myservo3.attach(4);
  myservo4.attach(5);
  myservo5.attach(6);
  myservo6.attach(7);
}

void loop() {
  a0 = analogRead(A0);
  delay(5);
  a1 = analogRead(A1);
  if (a1 < 245) a1 = 245;
  if (a1 > 963) a1 = 963;
  delay(5);
  a2 = analogRead(A2);
  // if (a2 < 218) a2 = 218;
  if (a2 > 530) a2 = 530;
  delay(5);
  a3 = analogRead(A3);
  if (a3 < 187) a3 = 187;
  if (a3 > 904) a3 = 904;
  delay(5);
  a4 = analogRead(A4);
  delay(5);
  a5 = analogRead(A5);
  delay(5);

  tmp = map(a0, 0, 1023, 2520, 460);
  myservo1.writeMicroseconds(tmp);
  Serial.print(String("S1: ") + tmp + String(" \t"));

  tmp = map(a1, 245, 963, 2430, 480);
  myservo2.writeMicroseconds(tmp);
  Serial.print(String("S2: ") + tmp + String(" \t"));

  tmp = map(a2, 0, 530, 730, 2390);
  myservo3.writeMicroseconds(tmp);
  Serial.print(String("S3: ") + tmp + String(" \t"));

  tmp = map(a3, 187, 904, 480, 2480);
  myservo4.writeMicroseconds(tmp);
  Serial.print(String("S4: ") + tmp + String(" \t"));

  tmp = map(a4, 0, 1023, 560, 2410);
  myservo5.writeMicroseconds(tmp);
  Serial.print(String("S5: ") + tmp + String(" \t"));

  tmp = map(a5, 0, 1023, 1040, 1740);
  myservo6.writeMicroseconds(tmp);
  Serial.print(String("S6: ") + tmp + String("\n"));
}
