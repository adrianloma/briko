 /*
*
* SharpIR.cpp
*
* Copyright 2014 IPSUM <contacto@ipsumss.com>
*
* This library is free software; you can redistribute it and/or
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* 11/08/14 Mexico.
*
*/

#include "SharpIR.h"    //includes library header

distancebk::distancebk(uint8_t pin)        //declares constructor
{
    _pin = pin;     //stores the analog input pin
}

float distancebk::read(void)       //reading sensor and return distance in cm function
{
    float distance=0;
    float impulses=0;
    float volts;               //mapped value in volts
    uint8_t i, n;
    uint8_t j, app;
    // read n=10 values from IR sharp sensor
    n=9;
    // read n=10 values from IR sharp sensor
    for (i=0; i<n; i++){
        val[i]=analogRead(_pin);
    }

    // sort 10 values read from IR sharp sensor
    for (i = 1; i <= n; i++)
    {
        app = val[i];
        for (j = i - 1; (j >= 0) && (val[j] > app); j--)
            val[j+1] = val[j];
        val[j + 1] = app;
    }
    impulses=0;
    // consider only 6 values (discard left and right tails)
    for(i=2; i<=n-2; i++)
    {
        impulses  =  impulses+val[i];
    }
    distance=impulses/((float)n+1-4); // calculate 6 values average
    volts=((float)distance/1023)*5;   //conversion from mean analog read to volts
    distance = 24.723*pow(volts,-1.191);    //conversion from volts to distance (cm) according to characteristic curve of the GP2YA21K

    if( distance > 80){        //if the measured distance is above 81 cm  return -1 to indicate the reflective object is out of range
        return(80);
    }

    return (distance);
}

float distancebk::read(uint8_t unit)       //reading sensor and return distance in cm function
{
		//declaration of variables
        float dist;
        dist = read();           //distance in centimeters

        if(unit==0){
			return(dist);       //returns distance value in cm
		}
		else if(unit==1){
			return(dist/2.54); //returns distance value in inches
		}
		else{
			return(-1);			//return -1 to indicate error in units field
		}

		//delay(10);           //waits 10 milisecs
}

