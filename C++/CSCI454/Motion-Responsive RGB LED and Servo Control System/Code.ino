#include <Servo.h>
#include <IRremote.h>

Servo myServo;
const int RED = 6, GREEN = 5, BLUE = 4, pz = 10, infra = 9, pir = 8, btn1 = 12, btn2 = 13;
int PIRvalue = 0;
int state = LOW;
IRrecv irrecv(infra);
decode_results results;

void setup() {
  irrecv.enableIRIn();
  myServo.attach(3);
  pinMode(pz, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  PIRvalue = digitalRead(pir);
  if (PIRvalue == HIGH) {
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    digitalWrite(pz, HIGH);

    if (state == LOW) {
      Serial.println("Motion detected!");
      state = HIGH;
    }
  } else {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(pz, LOW);

    if (state == HIGH) {
      Serial.println("Motion stopped!");
      state = LOW;
    }
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
}


