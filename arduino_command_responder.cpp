/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "command_responder.h"

#include <Arduino.h>

#include <Servo.h>
#include  "OLED.h"
Servo myServo;

int pos = 0;

// This implementation will light up the LEDs on the board in response to
// different commands.
void RespondToCommand(tflite::ErrorReporter* error_reporter,
                      int32_t current_time, const char* found_command,
                      uint8_t score, bool is_new_command) {
  static bool is_initialized = false;
  if (!is_initialized) {
    Serial.begin(9600);
    // Setup Servos as outputs
     myServo.attach(8);
    is_initialized = true;
    drawYIC();
  }
  static int count = 0;

  // Toggle the blue LED every time an inference is performed.
  ++count;
  if (count & 1) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

 

  if (is_new_command) {
    error_reporter->Report("Heard %s (%d) @%dms", found_command, score,
                           current_time);
    if (found_command[1] == 'n') {
      //error_reporter->Report("\nUNKNOWN");
    }
    else if (found_command[0] == 'y') {
      //error_reporter->Report("\nYES");
      for (pos = 0; pos <=180 ; pos++) { // goes from 0 degrees to 180 degrees
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
    }                       // waits 15ms for the servo to reach the position
    for (pos = 180; pos >=0 ; pos--) { // goes from 0 degrees to 180 degrees
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
     }

      
    }
    else if (found_command[0] == 'n') {

    }
    else if (found_command[0] == 'u') {
       for (pos = 0; pos <=90 ; pos++) { // goes from 0 degrees to 180 degrees
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
     }
     Serial.write("up");
     drawUp();
    }
    else if (found_command[0] == 'd') {
    for (pos = 0; pos <=270 ; pos++) { // goes from 0 degrees to 180 degrees
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
     }
     Serial.write("down");
     drawDown();
    }
    else if (found_command[0] == 'l') {
      //error_reporter->Report("\nLEFT");
     for (pos = 180; pos >=0 ; pos--) { // goes from 0 degrees to 180 degrees
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
     }
     Serial.write("left");
     drawLeft();
    }
    else if (found_command[0] == 'r') {
      for (pos = 0; pos <=180 ; pos++) { // goes from 0 degrees to 180 degrees
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
    }  
    Serial.write("right");
    drawRight();
    }

    }
  }
