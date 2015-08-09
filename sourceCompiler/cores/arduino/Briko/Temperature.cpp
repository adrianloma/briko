 /*
*
* Temperature.h
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
#include "Temperature.h"    //includes the header in the library


temperaturebk::temperaturebk(uint8_t pin)        //declares the constructor
{
  _pin = pin;     //stores the analog input pin to the private variable _pin
}

int temperaturebk::read()			//reading and mapping analog input function
{
    float temperature = 0;
    for(uint8_t i = 0; i < TEMP_SAMPLES; i++) {
        temperature += analogRead(_pin);
    }
    temperature = temperature / TEMP_SAMPLES;       // raw adc value
    //temperature = (temperature * 5) / 1023;      // temperature in volts
    temperature = ((temperature * 5 / 1023) * 100) - 50;

    return (int)temperature;
}

int temperaturebk::read(uint8_t unit){
    float temperature = 0;
    temperature = read();

    if (unit == 0){
        return (int)temperature;
    }
    else if (unit == 1){
        temperature = (temperature*9/5) + 32 ;
        return (int)temperature;
    }
    else{
            return 0;
    }
}
