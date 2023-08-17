#include <IRremote.h>

const int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int RED = 11,GREEN = 9, BLUE = 10;
int pz = 13;
int pir = 7;
int red = 255,grn = 255,blu = 255;
char c=' ';


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(RED, OUTPUT); 
  pinMode(GREEN, OUTPUT); 
  pinMode(BLUE, OUTPUT);
  pinMode(pz, OUTPUT);
  pinMode(pir, INPUT);
}

void loop()
{
   
   int PIR = digitalRead(pir);
  
   if (PIR == HIGH){
      digitalWrite(RED,HIGH);
      digitalWrite(pz,HIGH);
    }
   if (PIR == LOW){    
      digitalWrite(pz, LOW);
      digitalWrite(GREEN,HIGH);
    }

  
if (irrecv.decode(&results))
  {
   switch(results.value)
   {
     case 16582903: 
         setColor(255,0,0); 
         c = 'r';
         Serial.print("Button 1 ");
         Serial.println(c);
         delay(100);
         red = red/0.25;
         analogWrite(RED,red);
         break;

     case 16615543: 
         setColor(0,255,0); 
         c = 'g';
         Serial.print("Button 2 ");
         Serial.println(c);
         delay(100);
         grn = grn/0.25;
         analogWrite(GREEN,grn);
         break;

     case 16599223:
         setColor(0,0,255); 
         c = 'b';
         Serial.print("Button 3 ");
         Serial.println(c);
         delay(100);
         blu = blu/0.25;
         analogWrite(BLUE,blu);
         break;


     case 16591063: 
         setColor(255,0,0); 
         c = 'r';
         Serial.print("Button 4 ");
         Serial.println(c);
         delay(100);
     red = red*0.25;
        analogWrite(RED,red);
         break;



     case 16623703: 
         setColor(0,255,0); 
         c = 'g';
         Serial.print("Button 5 ");
         Serial.println(c);
         delay(100);
         grn = grn*0.25;
         analogWrite(GREEN,grn);
         break;

     case 16607383:
         setColor(0,0,255); 
         c = 'b';
         Serial.print("Button 6 ");
         Serial.println(c);
         delay(100);
         blu = blu*0.25;
         analogWrite(BLUE,blu);
         break;


       case 16593103:
       setColor(0,0,0);
       break;



       case 16603303:
       setColor(255,255,255);
       break;
   }
       irrecv.resume();
  }
}


void setColor (int red, int green, int blue) {
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
}



