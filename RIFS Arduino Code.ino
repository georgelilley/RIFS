#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Servo.h>
//adds requires code libraries.

// GUItool: begin automatically generated code
AudioInputI2S i2s1;   //xy=252,316
AudioOutputI2S i2s2;  //xy=541,344
AudioOutputUSB usb2;  //xy=552,236
AudioConnection patchCord1(i2s1, 0, usb2, 0);
AudioConnection patchCord2(i2s1, 0, i2s2, 0);
AudioConnection patchCord3(i2s1, 1, usb2, 1);
AudioConnection patchCord4(i2s1, 1, i2s2, 1);
AudioControlSGTL5000 sgtl5000_1;  //xy=465,72
// GUItool: end automatically generated code
// The code above was generated using the Web based Audio System Design Tool.
//I created a simple system design and exported the code: https://www.pjrc.com/teensy/gui/?info=AudioControlSGTL5000 (Accessed: 29 November 2022).


int value;       //Initialise the variable 'value', specifies it will be used to store integers.
Servo myservo;   //Initialises 'myservo' as a Servo variable.
Servo myservo2;  //Initialises 'myservo2' as a Servo variable.


void setup() { //'setup' function is first function to run upon upload to Teensy and only runs once. 
  AudioMemory(10); //Assigns memory for audio connections.
  sgtl5000_1.enable(); //Enables the Teensy's audio shield.
  sgtl5000_1.volume(1.0); //Sets volume level.
  sgtl5000_1.inputSelect(AUDIO_INPUT_MIC); //Select input.
  sgtl5000_1.micGain(20); //Set Microphone gain.

  Serial.begin(9600);   //This establishes a serial connection. Serial port will be used to received data sent from Max/MSP. This data will be used to move the robotic arm.
  myservo.attach(21);   //Attaches 'myservo' a specific Servo variable to a specific pin. This is digital pin 21. The Servo attached to digital pin 21 can now be controlled via the 'myservo' variable.
  myservo2.attach(19);  //Attaches 'myservo2' to digital pin 19. The Servo attached to digital pin 19 can be controlled by programming the 'myservo2' variable.
}

void loop() {  //Continually loops through this code.

  value = Serial.read(); // Assigns variable 'value' to data banged through the serial port. This will be an integer 1-4 to indicate where the Teensy microphone/robotic arm needs to be positioned. 
  // Below are a series of If statements which action the servos to create movement to 4 distinct positions. 

  if (value == 1) { //If statement is used to ascertain if position received is 1. Only if the condition is true will the code in brackets run and cause Servos to action the movement. 
    myservo2.write(90); //Moves upper servo to a neutral 12 o'clock position. 
    myservo.write(90); //Moves the base(lower) servo to 90° this is the plane in which positions 1 and 3 can be actioned.
    delay(200); //Delay for 200ms gives upper 'myservo2' time to reach neutral position.
    myservo2.write(0); //Top Servo 'myservo2' moved to 0°. 
  } //if statement closed. No movement until new data banged through serial port.

  if (value == 3) { //If statement is used to ascertain if position received is 3. Only if the condition is true will the code in brackets run and cause Servos to action the movement.
    myservo2.write(90); //Moves upper servo to a neutral 12 o'clock position. 
    myservo.write(90); //Moves the base(lower) servo to 90° this is the plane in which positions 1 and 3 can be actioned.
    delay(200); //Delay for 200ms gives upper 'myservo2' time to reach neutral position.
    myservo2.write(180); //Top Servo 'myservo2' moved to 180°. 
  } //if statement closed. No movement until new data banged through serial port.

  if (value == 2) { //If statement is used to ascertain if position received is 2. Only if the condition is true will the code in brackets run and cause Servos to action the movement.
    myservo2.write(90); //Moves upper servo to a neutral 12 o'clock position. 
    myservo.write(0); //Moves the base(lower) servo to 0° this is the plane in which positions 2 and 4 can be actioned.
    delay(200); //Delay for 200ms gives upper 'myservo2' time to reach neutral position.
    myservo2.write(0); //Top Servo 'myservo2' moved to 0°. 
  } //if statement closed. No movement until new data banged through serial port.

  if (value == 4) { //If statement is used to ascertain if position received is 4. Only if the condition is true will the code in brackets run and cause Servos to action the movement.
    myservo2.write(90); //Moves upper servo to a neutral 12 o'clock position. 
    myservo.write(0); //Moves the base(lower) servo to 0° this is the plane in which positions 2 and 4 can be actioned.
    delay(200); //Delay for 200ms gives upper 'myservo2' time to reach neutral position.
    myservo2.write(180); //Top Servo 'myservo2' moved to 180°.
  } //if statement closed. No movement until new data banged through serial port.
} // void loop closed.
