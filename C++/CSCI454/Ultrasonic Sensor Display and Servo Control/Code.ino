#include <Servo.h>

Servo servo;
byte seven_seg_digits[11][7] = {

{ 1, 1, 1, 1, 1, 1, 0 },

{ 0, 1, 1, 0, 0, 0, 0 },

{ 1, 1, 0, 1, 1, 0, 1 },

{ 1, 1, 1, 1, 0, 0, 1 },

{ 0, 1, 1, 0, 0, 1, 1 },

{ 1, 0, 1, 1, 0, 1, 1 },

{ 1, 0, 1, 1, 1, 1, 1 },

{ 1, 1, 1, 0, 0, 0, 0 },

{ 1, 1, 1, 1, 1, 1, 1 },

{ 1, 1, 1, 0, 0, 1, 1 }

};

int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int G = 8;
int DP = 9;

long cm;
int trig = 11;
int echo = 10;

void setup() {
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo.attach(12);
  Serial.begin(9600);
}

void loop() {
  cm = 0.01723 * readUltrasonicDistance(trig, echo);
  if (cm < 50) {
    int p = analogRead(A0);
    int p1 = map(p, 0, 1023, 0, 9);
    byte p2 = p1;
    sevenSegWrite(p2);

    int p3 = map(p, 0, 1023, 0, 180);
    servo.write(p3);
    Serial.print("Distance ");
    Serial.print(cm);
    Serial.print(" Angle ");
    Serial.print(p3);
    Serial.print(" Number ");
    Serial.println(p1);
    delay(500);
  } else {
    Serial.print("Distance ");
    Serial.println(cm);
    delay(500);
  }
}

void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
}

long readUltrasonicDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}