#include <IRremote.h>

int PhotoResistor = A0;
int sensorValue = 0;

int RECV_PIN = 4; 
IRrecv irrecv(RECV_PIN); 
decode_results results; 

int piezo = 13;

int count = 0;

void setup()
{
  irrecv.enableIRIn();

  Serial.begin(9600);

  pinMode(piezo, OUTPUT);
}

void loop()
{
  sensorValue = analogRead(PhotoResistor);
  if (irrecv.decode(&results)){
      Serial.println(results.value, HEX);

  if (results.value == 0xFD00FF){
    count++;
    if(count %2 == 1){
      if(sensorValue < 200){
      Serial.println("dark"); 
      delay(500);
    }else if(sensorValue > 200){
      Serial.println("light");
      delay(500);
      }
    }
    else {
     digitalWrite(piezo,HIGH);
      delay(2000);
     digitalWrite(piezo,LOW);

      }


      }
    }
  irrecv.resume();
}