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
  if (inByte == 'D' && !playing) {
    playing = true;

      horn.play();
      delay((int)(horn.duration()*1000));
      println((int)horn.duration());
      
    
  } else if (inByte == 'N') {
    //horn.stop();
    playing = false;
  }
}
void serialEvent (Serial myPort) {
  inByte = myPort.read();
}