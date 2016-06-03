# The Airboard SIGFOX uplink

##Description

First steps to send a Sigfox message using the airboard with sigfox shield SigBee (Atim module). 
This software send periodically the analog value of the pin A4 to Sigfox network.

##Get hardware
[The AirBoard](http://sales.theairboard.cc/)

[Atim SigBee shield](http://www.atim.com/fr/produits/catalogue/modules-shields/sigbeelorabee/)

Note: The AirBoard has been designed to be wirelessly reprogrammable. The microUSB connector is used for battery charging only. To upload a new program, you will need additional wireless shields such as XBee or BLE and their associated USB dongle, or an external serial connection over FTDI.

##Installation

Install Arduino IDE

Get the Arduino library from [API for ARM modules](http://atim-radiocommunications.github.io/armapi/)

Copy/Past the armapi folder under Arduino/libraries

##Run the code

- plug the light sensor between the A4 and GND pins
- repeatedly read the light sensor from analog pin A4
- send the value to the SIGFOX network every 10 minutes
  (maximum 140 messages per day)
   
1. upload this program to The AirBoard via the BLE-LINK/XBee shield
2. replace the BLE-LINK/XBee shield by the SIGFOX shield
3. connect to the SIGFOX backend: http://backend.sigfox.com
