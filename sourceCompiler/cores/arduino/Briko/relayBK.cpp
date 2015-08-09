/*
*
* relay.h
*
* Copyright 2014 IPSUM <contacto@ipsumss.com>
*
* This library is free software; you can redistribute it and/or
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* 2014 Mexico.
*
*/
#include "relayBK.h"    //includes the header in the library

relaybk::relaybk(uint8_t port_number)        //declares the constructor
{
  _port = port_number;			//pin is stored in private variable _pin
  Wire.begin();			// join i2c bus
}

void relaybk::set(uint8_t state)			//reading and mapping analog input function
{
if(state>1){ state =1;}
if(state<0){ state =0;}
portEnable(_port);
writeBK(SLAVE_ADDRESS_RELAY,REGISTER_RELAY_SET,state);
portEnable(0);
}

