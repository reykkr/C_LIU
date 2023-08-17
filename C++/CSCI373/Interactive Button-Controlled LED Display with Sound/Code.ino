#define b1 6
#define b2 2
#define b3 3
#define b4 4

#define blue 13
#define green 12
#define white 11
#define yellow 10

#define buzzer 5

void setup() {
  Serial.begin(9600);
  
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(yellow, OUTPUT);
  
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
  
  pinMode(buzzer, OUTPUT); 
}

void loop() {
  if (digitalRead(b1) == HIGH) {
    digitalWrite(yellow, HIGH);
    analogWrite(buzzer, 64);
    delay(1000);
    digitalWrite(yellow, LOW);
    analogWrite(buzzer, LOW);
  }
  
  if (digitalRead(b2) == HIGH) {
    digitalWrite(white, HIGH);
    analogWrite(buzzer, 128);
    delay(1000);
    digitalWrite(white, LOW);
    analogWrite(buzzer, LOW);
  }
  
  if (digitalRead(b3) == HIGH) {
    digitalWrite(green, HIGH);
    analogWrite(buzzer, 32);
    delay(1000);
    digitalWrite(green, LOW);
    analogWrite(buzzer, LOW);
  }
  
  if (digitalRead(b4) == HIGH) {
    digitalWrite(blue, HIGH);
    analogWrite(buzzer, 16);
    delay(1000);
    digitalWrite(blue, LOW);
    analogWrite(buzzer, LOW);
  }
}