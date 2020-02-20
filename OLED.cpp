/* 
This sketch draws to the 64x48 pixel MicroOLED
  
  Hardware Connections:
    We'll be using the Qwiic I2C interface on the MicroOLED
==============================================================================*/

#include <Wire.h>
#include <SFE_MicroOLED.h>
#include "image.h"

//////////////////////////
// MicroOLED Definition //
//////////////////////////
// The library assumes a reset pin is necessary
// The Qwiic OLED has RST hard-wired, so pick an arbitrary IO pin that is not being used
#define PIN_RESET 9  
// The DC_JUMPER is the I2C Address Select jumper
// Set to 1 if the jumper is open (Default), or set to 0 if it's closed
#define DC_JUMPER 1 

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
// I2C declaration
// I2C will result in a very slow update rate
MicroOLED oled(PIN_RESET, DC_JUMPER);

// works well as a delay for anything displayed
#define IMAGE_DELAY 750

void setupscreeen(void) {
    delay(100);
  
 
    Wire.begin();

  
    oled.begin();


    oled.clear(ALL);

    // Display title text
    oled.setFontType(2);
    oled.clear(PAGE);
    oled.setCursor(0, 0);
    oled.print("Yes");
    oled.print("ICan");
    oled.display();

    // Pause for the title screen
    delay(IMAGE_DELAY);

}
//---------------------------------------------------------------
void displayText(const char* text){
    // Display text
    oled.setFontType(1);
    oled.clear(PAGE);
    oled.setCursor(0, 1);
    oled.print(text);
    oled.display();
    // short delay for debugging
    delay(400);
}
//---------------------------------------------------------------
void drawYIC()
{
    oled.clear(PAGE);
    oled.drawBitmap(YICImage);
    oled.display();
}
//---------------------------------------------------------------
void drawUp()
{
   oled.setFontType(1);
    oled.clear(PAGE);
    oled.setCursor(0, 1);
    oled.print("UP");
    oled.display();
    // short delay for debugging
    delay(400);
}
//---------------------------------------------------------------
void drawRight()
{
   oled.setFontType(1);
    oled.clear(PAGE);
    oled.setCursor(0, 1);
    oled.print("Right");
    oled.display();
    // short delay for debugging
    delay(400);
}
//---------------------------------------------------------------
void drawDown()
{
  oled.setFontType(1);
    oled.clear(PAGE);
    oled.setCursor(0, 1);
    oled.print("Down");
    oled.display();
    // short delay for debugging
    delay(400);
}
//---------------------------------------------------------------
void drawLeft()
{
    oled.setFontType(1);
    oled.clear(PAGE);
    oled.setCursor(0, 1);
    oled.print("Left");
    oled.display();
    // short delay for debugging
    delay(400);
}
void clearDisplay() {
    oled.clear(PAGE);
    oled.display();
}
//---------------------------------------------------------------
