#include <IRremote.h>

int piezo = 12;
const int rcvpin = 11;
IRrecv irrecv(rcvpin);
decode_results result;
const int RED = 9, GREEN = 8, BLUE = 10;
int red = 255, grn = 255, blu = 255;

int in1 = 5, in2 = 6, enA = 7;
int in3 = 3, in4 = 4, enB = 2;

int speed;

void runMotor(int pin1, int pin2, int pinSpeed, int speed, bool clockwise = true) {
    if (clockwise) { 
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
    } else { 
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
    }
    analogWrite(pinSpeed, speed);
}

void stopMotor(int pin1, int pin2) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
} 

const int bluePin = 10;
const int greenPin = 12;

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();
    irrecv.blink13(true);
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(in1, OUTPUT); 
    pinMode(in2, OUTPUT);
    pinMode(enA, OUTPUT); 
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT); 
    pinMode(enB, OUTPUT);
    pinMode(piezo, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
}

void loop() {
    if (irrecv.decode(&result)) {
        switch(result.value) {
            case 16615543:
                digitalWrite(in1, HIGH);
                digitalWrite(in2, LOW);
                digitalWrite(in3, HIGH);
                digitalWrite(in4, LOW);
                break;

            case 16607383: 
                digitalWrite(in1, HIGH);
                digitalWrite(in2, LOW);
                break;

            case 16619623:
                digitalWrite(in1, LOW);
                digitalWrite(in2, HIGH);
                digitalWrite(in3, LOW);
                digitalWrite(in4, HIGH);
                break;

            case 16591063:
                digitalWrite(in3, HIGH);
                digitalWrite(in4, LOW);
                break;

            case 16623703:
                analogWrite(BLUE, 255);
                delay(20);
                analogWrite(BLUE, 0);
                break;

            case 16593103:
                tone(piezo, 262, 3000);
                break;
        }
        irrecv.resume();
    }

    for (speed = 1; speed <= 255; speed += 2) {
        runMotor(in1, in2, enA, speed, true);
        runMotor(in3, in4, enB, speed, true);
        delay(20);
    }
    stopMotor(in1, in2);
    stopMotor(in3, in4);
    delay(2000);

    for (speed = 255; speed >= 0; speed -= 2) {
        runMotor(in1, in2, enA, speed, false);
        runMotor(in3, in4, enB, speed, false);
        delay(20);
    }
    delay(2000);
}

void setColor(int red, int green, int blue) {
    analogWrite(RED, red); 
    analogWrite(GREEN, green);
    analogWrite(BLUE, blue);
}

