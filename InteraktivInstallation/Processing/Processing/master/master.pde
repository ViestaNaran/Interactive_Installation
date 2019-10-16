import processing.serial.*;
import processing.sound.*;

Serial myPort;
int inByte = 0;
SoundFile horn, drum, anvil, decap, thunder, rain;
SoundFile story1, story2;
boolean playingDrum = false;
boolean playingAnvil = false;
boolean playingDecap = false;
boolean playingHorn = false;

float timeDrum, timeAnvil, timeDecap, timeHorn, timeThunder;
float time;

void setup() {
  size(400, 300);
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  horn = new SoundFile(this, "horn.mp3");
  drum = new SoundFile(this, "drum.mp3");
  anvil = new SoundFile(this, "anvil.mp3");
  decap = new SoundFile(this, "decap.mp3");
  thunder = new SoundFile(this, "thunder.mp3");
  rain = new SoundFile(this, "rain.mp3");
}
void draw() {
  //println(inByte);
  //if (inByte == 'H' && !playingHorn) {
  //  playingHorn = true;

  //    horn.play();


  //} else if (inByte == 'h') {
  //  horn.stop();
  //  playingHorn = false;
  //}
  if (inByte == 'D' && !playingDrum) {
    playingDrum = true;
    timeDrum = millis() + drum.duration()*1000;
    drum.play();
  } 
  if (millis() > timeDrum && playingDrum)
  {
    playingDrum = false;
  }

  if (inByte == 'H' && !playingHorn) {
    playingHorn = true;
    timeHorn = millis() + horn.duration()*1000;
    horn.play();
  } 
  if (millis() > timeHorn && playingHorn)
  {
    playingHorn = false;
  }

  if (inByte == 'K' && !playingDecap) {
    playingDecap = true;
    timeDecap = millis()+ 500 + decap.duration()*1000; //500 milliskekunder var for at den ikke spiller lyden 2 gange
    println("test");
    decap.play();
  } 
  if (millis() > timeDecap && playingDecap)
  {
    playingDecap = false;
  }

  if (inByte == 'A' && !playingAnvil) {
    playingAnvil = true;
    timeAnvil = millis() + thunder.duration()*1000;
    //anvil.play();
    thunder.play();
    rain.play();
    rain.stop();
    rain.loop();
    rain.amp(0.1);
  } 
  if (millis() > timeAnvil && playingAnvil)
  {
    playingAnvil = false;
  }

  // else if (inByte == 'd') {
  //drum.stop();
  //playingDrum = false;
  //}
}
void serialEvent (Serial myPort) {
  inByte = myPort.read();
}