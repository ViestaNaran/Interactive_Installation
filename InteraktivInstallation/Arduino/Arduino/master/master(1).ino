#include <DmxSimple.h>

const int DRUM = A4;
const int ANVIL = A3;
const int DECAP = A5;
const int HORN = 10;

void setup() {
  pinMode(DRUM, INPUT);
  pinMode(ANVIL, INPUT);
  pinMode(HORN, INPUT);

  Serial.begin(9600);
}

void loop() {
  float drumValue = analogRead(DRUM);
  float anvilValue = analogRead(ANVIL);
  float decapValue = analogRead(DECAP);
  int hornValue = digitalRead(HORN);

// Konstant lys  
  DmxSimple.write(1, 0);
  DmxSimple.write(2, 0);
  DmxSimple.write(3, 255);

  //DmxSimple.write(10, 0);
  //DmxSimple.write(11, 0);

  Serial.println(decapValue);

  //Sensor på trumme
  if(drumValue > 400){
    Serial.write("D");
  }
  else if(drumValue <= 400){
    Serial.write("d");   
  }

  //knap på horn
  if(hornValue == 1){
    Serial.write("H");
    //DmxSimple.write(1,0);
    DmxSimple.write(2,100);
    //DmxSimple.write(3,0);
    delay(100);
  }
  else {
    Serial.write("h");
  }
  
      

  if(anvilValue > 400){
    Serial.write("A");
    delay(500);
    DmxSimple.write(7, 255);
    DmxSimple.write(11, 255);
    delay(1500);
    DmxSimple.write(7, 0);
    DmxSimple.write(11, 0);
    
    
  }
  else if(anvilValue <= 400){
    Serial.write("a");
  }

  if(decapValue > 400){
    Serial.write("K");
    DmxSimple.write(1,255);
    DmxSimple.write(2,0);
    DmxSimple.write(3,0);
    delay(4000);
    
  }
  else if(decapValue <= 400){
    Serial.write("k");
  }

  
  
  //delay(100);

}
