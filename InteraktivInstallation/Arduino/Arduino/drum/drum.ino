const int PIEZO = A0;

void setup() {
  pinMode(PIEZO, INPUT);

  Serial.begin(9600);
}

void loop() {
  float value = analogRead(PIEZO);
  if(value > 1){

  Serial.write("D");

    
  }
  else Serial.write("N");
  
  delay(50);

}
