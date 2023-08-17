#define red 13
#define yellow 12
#define green 11
#define startButton 2

int count = 0;

void setup()
{
 pinMode(red, OUTPUT);
 pinMode(yellow, OUTPUT);
 pinMode(green, OUTPUT);
 pinMode(startButton, INPUT_PULLUP);
}

void loop()
{
 digitalWrite(yellow, HIGH);
 delay(500);
 digitalWrite(yellow, LOW);
 delay(500);

 if (digitalRead(startButton) == LOW) // Changed to check for LOW
 {
   count++;

   digitalWrite(green, HIGH);
   delay(5000);
   digitalWrite(green, LOW);

   digitalWrite(yellow, HIGH);
   delay(1000);
   digitalWrite(yellow, LOW);

   digitalWrite(red, HIGH);
   delay(5000);
   digitalWrite(red, LOW);
 }
}
