import processing.serial.*;
Serial myPort;
int inByte = 0;
void setup() {
  size(400, 300);
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}
void draw() {
  if(inByte == 1){
    
  }
}
void serialEvent (Serial myPort) {
  inByte = myPort.read();
   println(inByte);
}