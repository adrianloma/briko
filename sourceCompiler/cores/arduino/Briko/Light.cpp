/*
*
* Light.h
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
#include "Light.h"    //includes the header in the library

lightbk::lightbk(uint8_t pin)        //declares the constructor
{
  _pin = pin;     //stores the analog input pin to the private variable _pin
}

uint8_t lightbk::read()			//reading and mapping analog input function
{
	uint16_t percent=0;
	percent= analogRead(_pin);             //maps the read value
	percent = map(percent,0,1023,255,0);        //lo cambia de 0 a 1023 a 255 a 0  (lo invierte)
	return((uint8_t)percent);					//returns mapped value
}


