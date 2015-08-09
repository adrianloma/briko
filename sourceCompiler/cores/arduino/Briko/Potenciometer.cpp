 /*
*
* Pot.h
*
* Copyright 2014 IPSUM <contacto@ipsumss.com>
*
* This library is free software; you can redistribute it and/or
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* 14/08/14 Mexico.
*
*/
#include "Potenciometer.h"    //includes the header in the library

knobbk::knobbk(uint8_t pin)        //declares the constructor
{
  _pin = pin;     //stores the analog input pin to the private variable _pin
}

uint8_t knobbk::read()			//reading and mapping analog input function
{
	int raw_value=0;				//declares variable for the value from 0 to 1023
	int mapped_value = 0;               //declares variable for the value from 0 to 100
	raw_value=analogRead(_pin);			//stores analog read value
	mapped_value=map(raw_value,0,1023,0,255);//maps the analog read value from 0 to 100
	return((uint8_t)mapped_value);					//returns mapped value
}

