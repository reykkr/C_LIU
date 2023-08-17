#include <Servo.h>

#define GREEN_LED_PIN 3
#define RED_LED_PIN 2
#define PIEZO_PIN 5

Servo servo;
int distance_cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  servo.attach(9);
  pinMode(6, INPUT);
  pinMode(7, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(PIEZO_PIN, OUTPUT);
}

void loop() {
  distance_cm = 0.01723 * readUltrasonicDistance(7, 6);
  if (distance_cm > 5 && distance_cm < 150) {
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    analogWrite(PIEZO_PIN, HIGH);
    servo.write(90);
  }
  if (distance_cm > 150) {
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
    analogWrite(PIEZO_PIN, LOW);
    servo.write(0);
  }
}
