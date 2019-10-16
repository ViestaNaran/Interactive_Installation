const int PINPOT = 7;
void setup() {
  Serial.begin(9600);
}
void loop(){
  int val = digitalRead(PINPOT);
  Serial.write(val);
  delay(50);
}

