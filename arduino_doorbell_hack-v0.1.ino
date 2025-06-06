#include <SD.h>
#define SD_ChipSelectPin 4

#include <SPI.h>

#include <TMRpcm.h>
#include <pcmConfig.h>
#include <pcmRF.h>

TMRpcm player;
int button = 4;
int volume = 5; //set the volume outside the code

void setup() {
  player.speakerPin = 9;
  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {
  Serial.println("SD fail");
  return;
  }

  player.setVolume(volume);
}
void loop() {
  if (digitalRead(button) == 0) {
    player.play("dingdong.wav");
  }
}
