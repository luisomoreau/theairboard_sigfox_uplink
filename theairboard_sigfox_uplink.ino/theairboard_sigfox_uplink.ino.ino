// ---------------------------------------------------------------------
// This file is a example for use the library armapi with
// The AirBoard using the SigBee shield module
//
// This software send periodically the analog value of the pin A4 to Sigfox network.
//
// Created date: 03.05.2016
// Author: Louis Moreau
// Adapted from: https://github.com/atim-radiocommunications/armapi
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Include
// ---------------------------------------------------------------------
#include <arm.h>

// ---------------------------------------------------------------------
// Define
// ---------------------------------------------------------------------
#define GREEN   5               // GREEN LED
#define BLUE   6               // BLUE LED
#define RED      9             // RED LED
#define VALUE  A4             //Analog Pin 
#define TIMEINTERVALL 900000 // 900 sec -> 15 min sleep time

// ---------------------------------------------------------------------
// Global variables
// ---------------------------------------------------------------------
//Instance of  the class Arm
Arm myArm;
//The message to send at sigfox
uint8_t msg[] = "Hello";
unsigned long timer;          // timer for sleeping


// ---------------------------------------------------------------------
// Implemented functions
// ---------------------------------------------------------------------

void setup()
{
  //Pin modes
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(VALUE, INPUT);

  
	digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(RED, LOW);
	
	//Init Arm and set LED to on if error
	if (myArm.Init(&Serial) != ARM_ERR_NONE)
		digitalWrite(RED, HIGH);
	
	//Set Sigfox mode in uplink.
	myArm.SetMode(ARM_MODE_SFX);
	myArm.SfxEnableDownlink(false);
	myArm.UpdateConfig();
}

void loop()
{
	
}

void sendMessage(){
  //Send the message to sigfox
  myArm.Send(msg, sizeof(msg));
}

