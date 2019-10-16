const int PINPHOTORESISTOR = A0;
const int ledpin = 13;
int value;
int incomingByte;

void setup(){
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}
void loop(){
 if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      digitalWrite(ledpin, HIGH);
    }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      digitalWrite(ledpin, LOW);
    }
 }
}
