#include <Keypad.h>

const char lth = 12;
const char clk = 13;
const char dat = 11;

const byte numRows = 4;
const byte numCols = 4;

char keymap[numRows][numCols] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {9, 8, 7, 6};
byte colPins[numCols] = {5, 4, 3, 2};

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

int bit[9] = {
    B01100000,
    B11011100,
    B11110100,
    B01100110,
    B10110110,
    B10111110,
    B11100000,
    B11111110,
    B11110110
};

void setup() {
    Serial.begin(9600);
    pinMode(lth, OUTPUT);
    pinMode(clk, OUTPUT);
    pinMode(dat, OUTPUT);
}

void loop() {
    char key = myKeypad.getKey();
    if (key != NO_KEY) {
        Serial.println(key);
        digitalWrite(lth, LOW);
        String stringOne = String(key);
        if (stringOne.toInt() == 0) {
            shiftOut(dat, clk, LSBFIRST, B00000000);
        } else if (stringOne.toInt() <= 9) {
            shiftOut(dat, clk, LSBFIRST, bit[stringOne.toInt() - 1]);
        } else {
        }
        digitalWrite(lth, HIGH);
        delay(750);
    }
}
