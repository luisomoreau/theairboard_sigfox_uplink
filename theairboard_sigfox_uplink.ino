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
#define GREEN   5             // GREEN LED
#define BLUE   6              // BLUE LED
#define RED      9            // RED LED
#define PIEZO  A4             //Analog Pin 
#define TIMEINTERVALL 900000  // 900 sec -> 15 min sleep time

// ---------------------------------------------------------------------
// Global variables
// ---------------------------------------------------------------------
//Instance of  the class Arm
Arm SigFox;
//The message to send at sigfox
uint8_t msg[] = "Hit";
unsigned long timer;          // timer for sleeping
bool blue = false;
bool green = false;
bool red = false;
int success;
int sensorValue;


// ---------------------------------------------------------------------
// Implemented functions
// ---------------------------------------------------------------------

void setup()
{
  //Pin modes
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(PIEZO, INPUT);

  resetLeds();
	//Init Arm and set LED to on if error
	if (SigFox.Init(&Serial) != ARM_ERR_NONE){
		digitalWrite(RED, HIGH);
	}else{
    digitalWrite(GREEN, HIGH);
	}
	
	//Set Sigfox mode in uplink.
	SigFox.SetMode(ARM_MODE_SFX);
	SigFox.SfxEnableDownlink(false);
	SigFox.UpdateConfig();
  delay(1000);
  resetLeds();
}

void loop()
{ 
  sensorValue = analogRead(PIEZO);
  //blinkBlue();
  if(sensorValue==1023){
    digitalWrite(BLUE,HIGH);
    
  }else{
    digitalWrite(BLUE,LOW);
  }
	if (millis()>timer){               // if timer expired
   sendMessage(); 
   timer=millis()+TIMEINTERVALL;    //reset timer
  }  
}

void sendMessage(){
  resetLeds();
  delay(1000);
  for(int i=0;i<60;i++){
    blinkBlue();
    delay(200);
  }
  //Send the message to sigfox
  success = SigFox.Send(msg, sizeof(msg));
  resetLeds();
  if(success==0){
    digitalWrite(RED, HIGH);
  }else{
    digitalWrite(GREEN, HIGH);
  }
  delay(1000);
  resetLeds();
}

void blinkBlue(){
  if(blue){
    digitalWrite(BLUE, LOW);
    blue = false;
  }else{
    digitalWrite(BLUE, HIGH);
    blue = true;
  }
}

void blinkGreen(){
  if(green){
    digitalWrite(GREEN, 0);
    green = false;
  }else{
    analogWrite(GREEN, 1);
    green = true;
  }
}

void blinkRed(){
  if(red){
    digitalWrite(RED, 0);
    red = false;
  }else{
    analogWrite(RED, 1);
    red = true;
  }
}

void resetLeds(){
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(RED, LOW);
}

