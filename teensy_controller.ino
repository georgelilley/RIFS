/*
 * RIFS – Teensy Servo Controller
 *
 * Receives directional commands over serial from the host system (Max/MSP)
 * and positions two servos to orient the microphone toward one of four
 * predefined zones.
 *
 * Input: integer command (1–4)
 * Output: coordinated servo movement
 */

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Servo.h>

// Audio system (generated via PJRC design tool)
AudioInputI2S i2s1;
AudioOutputI2S i2s2;
AudioOutputUSB usb2;
AudioConnection patchCord1(i2s1, 0, usb2, 0);
AudioConnection patchCord2(i2s1, 0, i2s2, 0);
AudioConnection patchCord3(i2s1, 1, usb2, 1);
AudioConnection patchCord4(i2s1, 1, i2s2, 1);
AudioControlSGTL5000 sgtl5000_1;

Servo baseServo;
Servo topServo;

int command = -1;

void setup() {
  AudioMemory(10);
  sgtl5000_1.enable();
  sgtl5000_1.volume(1.0);
  sgtl5000_1.inputSelect(AUDIO_INPUT_MIC);
  sgtl5000_1.micGain(20);

  Serial.begin(9600);

  baseServo.attach(21);
  topServo.attach(19);
}

void moveToPosition(int pos) {
  // Move top servo to neutral before rotating base
  topServo.write(90);
  delay(200);

  switch (pos) {
    case 1:
      baseServo.write(90);
      topServo.write(0);
      break;

    case 2:
      baseServo.write(0);
      topServo.write(0);
      break;

    case 3:
      baseServo.write(90);
      topServo.write(180);
      break;

    case 4:
      baseServo.write(0);
      topServo.write(180);
      break;
  }
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    if (command >= 1 && command <= 4) {
      moveToPosition(command);
    }
  }
}
