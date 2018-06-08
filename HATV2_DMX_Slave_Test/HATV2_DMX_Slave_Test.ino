/*
  DMX_Slave.ino - Example code for using the Conceptinetics DMX library
  Copyright (c) 2013 W.A. van der Meeren <danny@illogic.nl>.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


#include <Conceptinetics.h>

//
// CTC-DRA-13-1 ISOLATED DMX-RDM SHIELD JUMPER INSTRUCTIONS
//
// If you are using the above mentioned shield you should 
// place the RXEN jumper towards G (Ground), This will turn
// the shield into read mode without using up an IO pin
//
// The !EN Jumper should be either placed in the G (GROUND) 
// position to enable the shield circuitry 
//   OR
// if one of the pins is selected the selected pin should be
// set to OUTPUT mode and set to LOGIC LOW in order for the 
// shield to work
//

//
// The slave device will use a block of 10 channels counting from
// its start address.
//
// If the start address is for example 56, then the channels kept
// by the dmx_slave object is channel 56-66
//
#define DMX_SLAVE_CHANNELS   3 

//
// Pin number to change read or write mode on the shield
// Uncomment the following line if you choose to control 
// read and write via a pin
//
// On the CTC-DRA-13-1 shield this will always be pin 2,
// if you are using other shields you should look it up 
// yourself
//
///// #define RXEN_PIN                2


// Configure a DMX slave controller
DMX_Slave dmx_slave ( DMX_SLAVE_CHANNELS );

// If you are using an IO pin to control the shields RXEN
// the use the following line instead
///// DMX_Slave dmx_slave ( DMX_SLAVE_CHANNELS , RXEN_PIN );

const int ledPinRed = 3;
const int ledPinGreen = 5;
const int ledPinBlue = 6;
int redVal = 0;
int greenVal = 0;
int blueVal = 0;

int dmx_add = 0;  // 0 - 511
int dmx_mode = 0; // 0-7
int jp3 = 0;      // JP3 0=Open 1=Closed
int val = 0;      // Temp variable used to read input

// the setup routine runs once when you press reset:
void setup() {    
   
  // Setup pins to read DMX address and DMX_Mode.  Becuse of the internal pullup resistor 
  // when the swith id off the input will be HIGH and when the switch is on the input will
  // be LOW
  // read in DMX address (9bits)
  
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  pinMode(A6, INPUT); // Note A6 & A7 Analog only and need external pullup resistor
  pinMode(A7, INPUT);

  // read in DMX address (9bits)
  dmx_add = 0;
  val = digitalRead(2); 
  if (val==LOW) {
      dmx_add |= 1;
    };
  val = digitalRead(4); 
  if (val==LOW) {
      dmx_add |= 1<<1;
    };
  val = digitalRead(7); 
  if (val==LOW) {
      dmx_add |= 1<<2;
    };
  val = digitalRead(8); 
  if (val==LOW) {
      dmx_add |= 1<<3;
    };
  val = digitalRead(9); 
  if (val==LOW) {
      dmx_add |= 1<<4;
    };
  val = digitalRead(A0); 
  if (val==LOW) {
      dmx_add |= 1<<5;
    };
  val = digitalRead(A1); 
  if (val==LOW) {
      dmx_add |= 1<<6;
    };
  val = digitalRead(A2); 
  if (val==LOW) {
      dmx_add |= 1<<7;
    };
  val = digitalRead(A3); 
  if (val==LOW) {
      dmx_add |= 1<<8;
    };
  
  // Enable DMX slave interface and start recording
  // DMX data
  dmx_slave.enable ();  
  
  // Set start address to 1, this is also the default setting
  // You can change this address at any time during the program
  dmx_slave.setStartAddress (1);
  
  // Set led pin as output pin
  pinMode ( ledPinRed, OUTPUT );
  pinMode ( ledPinGreen, OUTPUT );
  pinMode ( ledPinBlue, OUTPUT );
}

// the loop routine runs over and over again forever:
void loop() 
{
  //
  // EXAMPLE DESCRIPTION
  //
  // Uses PWM on 3 pins to do RGB in a very crude way.
  
  // NOTE:
  // getChannelValue is relative to the configured startaddress
  
  redVal= dmx_slave.getChannelValue(1);
  analogWrite(ledPinRed,redVal);
  greenVal= dmx_slave.getChannelValue(2);
  analogWrite(ledPinGreen,greenVal);
  blueVal= dmx_slave.getChannelValue(3);
  analogWrite(ledPinBlue,blueVal);
  
}
