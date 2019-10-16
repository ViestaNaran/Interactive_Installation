const int PIEZO = A0;
const int RED = 13;
bool locked = false;

void setup() {
  pinMode(PIEZO, INPUT);
  pinMode(RED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  float value = analogRead(PIEZO);
  Serial.println(value);
  if(value > 3) {
    locked = !locked;
    Serial.println(locked);
    if(locked==true){
    digitalWrite(RED, HIGH);
  } else digitalWrite(RED, LOW);
    delay(2000);
  }
  else delay(100);

}
