#include <SD.h>
#define SD_ChipSelectPin 4

#include <SPI.h>

#include <TMRpcm.h>
#include <pcmConfig.h>
#include <pcmRF.h>

TMRpcm player;
int button = 2;
int volume = 5; //set the volume outside the code
int buttonState;
int led = 5;

void updateLed() {
  bool playing = player.isPlaying();
  if (playing == true) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  player.speakerPin = 9;
  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }
  player.setVolume(volume);
}

void loop() {
  updateLed();
  buttonState = digitalRead(button);
  if (buttonState == 0) {
    player.play("dingdong.wav");
  }
}
