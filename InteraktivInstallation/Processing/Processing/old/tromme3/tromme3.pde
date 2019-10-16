import processing.serial.*;
import processing.sound.*;

Serial myPort;
int inByte = 0;
SoundFile horn;
boolean playing = false;

void setup() {
  size(400, 300);
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  horn = new SoundFile(this, "horn.wav");
}
void draw() {
  if (inByte == 1 && !playing) {
    playing = true;

      horn.play();
      
    
  } else if (inByte == 0) {
    horn.stop();
    playing = false;
  }
}
void serialEvent (Serial myPort) {
  inByte = myPort.read();
}