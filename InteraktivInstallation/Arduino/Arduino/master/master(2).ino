#include <DmxSimple.h>
const int DRUM = A5;
const int ANVIL = A1;
const int DECAP = A2;
const int HORN = 8;

void setup() {
  pinMode(DRUM, INPUT);
  pinMode(ANVIL, INPUT);
  pinMode(HORN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  float drumValue = analogRead(DRUM);
  float anvilValue = analogRead(ANVIL);
  float decapValue = analogRead(DECAP);
  int hornValue = digitalRead(HORN);

  
  DmxSimple.write(1, 0);
  DmxSimple.write(2, 0);
  DmxSimple.write(3, 255);


  Serial.println(drumValue);
  
  if(drumValue > 200){
    Serial.write("D");
    DmxSimple.write(1, 255);
    DmxSimple.write(2, 0);
    DmxSimple.write(3, 0);
      
    DmxSimple.write(10, 255);
    DmxSimple.write(11, 255);
    //digitalWrite(HORN, HIGH);
    delay(1000);
    //digitalWrite(HORN, LOW);
       DmxSimple.write(1, 0);
       DmxSimple.write(2, 0);
       DmxSimple.write(3, 0);
       DmxSimple.write(10, 0);
  DmxSimple.write(11, 0);
    //delay(500);
  }
  else if(drumValue <= 200){
    Serial.write("d");
    //digitalWrite(HORN, LOW);
    
  }

  
      

  /*if(anvilValue > 0){
    Serial.write("A");
  }
  else if(anvilValue <= 1){
    Serial.write("a");
  }

  if(decapValue > 0){
    Serial.write("K");
  }
  else if(decapValue <= 1){
    Serial.write("k");
  }

  if(hornValue == 1){
    Serial.write("H");
  }
  else {
    Serial.write("h");
  }*/
  
  //delay(100);

}
