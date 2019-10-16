import processing.serial.*;
Serial myPort;
int xPos = 0, yPos = 0, inByte = 0;
void setup() {
size(400,300);
// printArray(Serial.list());
String portName = Serial.list()[0];
myPort = new Serial(this, portName, 9600);
stroke(255,0,0);
}
void draw() {
xPos++;
if (xPos > width) {
xPos = 0;
background(200);
}
yPos = height - inByte;
line(xPos, height, xPos, yPos);
}
void serialEvent (Serial myPort) {
inByte = myPort.read();
// println(analogRead);
}