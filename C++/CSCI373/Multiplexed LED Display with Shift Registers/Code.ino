const byte lth = 12;
const byte clk = 13;
const byte dat = 11;

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

void setup()
{
  pinMode(lth, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(dat, OUTPUT);
}

void loop()
{
  for(int i = 0; i < 9; i++) {
    digitalWrite(lth, LOW);
    shiftOut(dat, clk, LSBFIRST, bit[i]);
    digitalWrite(lth, HIGH);
    delay(750);
  }
}
