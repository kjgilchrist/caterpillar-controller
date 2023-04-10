#include <Bounce2.h>
#include <Wire.h>


/*

FSR Code:
Connect one end of FSR to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
For more information see www.ladyada.net/learn/sensors/fsr.html
*/

/*
 * Teensy-LC Analog Pins
 * A0 - 14 - Yellow - Button - Left Arrow
 * A1 - 15 - Green - Button - Right Arrow
 * A2 - 16 - White - FSR - "x" button
 */
 
const int but1AnalogPin = A0;
const int but2AnalogPin = A1;
const int fsrAnalogPin = A2;
int prevButton1State = 0;
int prevButton2State = 0;
int prevFsrReading = 0;

void setup() {
  // Debugging via Serial Monitor
  Serial.begin(9600);
  Serial.println("Serial Begin");
}


void loop() {
  // Read Analog Inputs from all sensors.
  int button1State = analogRead(but1AnalogPin);
  int button2State = analogRead(but2AnalogPin);
  int fsrReading = analogRead(fsrAnalogPin);
  
  // Print current state of each sensor.
  if (fsrReading > prevFsrReading && fsrReading > 190) { //&& fsrReading != prevFsrReading) {
    // Serial.print("FSR Analog: ");
    // Serial.println(fsrReading);
    // Keyboard.print("x");
    // Keyboard.press(KEY_UP_ARROW);
    // delay(50);
    // Keyboard.release(KEY_UP_ARROW);
    Keyboard.press(KEY_SPACE);
    delay(50);
    Keyboard.release(KEY_SPACE);
  }
  
  if (button1State > 1020) { //&& button1State != prevButton1State) {
    // Serial.println("Button 1 Pressed");
    Keyboard.press(KEY_LEFT_ARROW);
    delay(50);
    Keyboard.release(KEY_LEFT_ARROW);
  }
  if (button2State > 1020) { //&& button2State != prevButton2State) {
    // Serial.println("Button 2 Pressed");
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(50);
    Keyboard.release(KEY_RIGHT_ARROW);
  }
  // Set current to previous for next loop.
  prevButton1State = button1State;
  prevButton2State = button2State;
  prevFsrReading = fsrReading;
  delay(200);
}

/*
 * Tests
 * 
 */
