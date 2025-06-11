#include <Bounce2.h>
Bounce2::Button button = Bounce2::Button();

#define SD_ChipSelectPin 4

#include <TMRpcm.h>

TMRpcm player;
int ringButton = 2;
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

void sdAlert() {
  for (int i;i<3;i++) {
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
  }
}

void setup() {
  button.attach(ringButton,INPUT_PULLUP);
  button.interval(5);
  button.setPressedState(LOW);
  pinMode(led, OUTPUT);
  player.speakerPin = 9;
  Serial.begin(9600);
  while (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    sdAlert();
  }
  player.setVolume(volume);
}

void loop() {
  button.update();
  updateLed();
  if (button.pressed()) {
    player.setVolume(volume);
    player.play("dingdong.wav");
  }
  if (!player.isPlaying()) {
    player.setVolume(0);
  }
}
