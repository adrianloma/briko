/*
*
* Buzzer.cpp
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
#include "Buzzer.h"    //includes the header in the library


buzzerbk::buzzerbk(uint8_t port_number)        //declares the constructor
{
  _port = port_number;          //pin is stored in private variable _pin
  error=0;
  tonefreq=0;
  setstate=0;
  Wire.begin();         // join i2c bus
}

void buzzerbk::set(uint8_t status)         //reading and mapping analog input function
{
    portEnable(_port);
    if(status>1){status=1;}
    if(status<0){status=0;}
    if(setstate!=status){ //solo si no se repite
    write2BK(SLAVE_ADDRESS_BUZZER, ADDR_FREQ, 800);
    error=writeBK(SLAVE_ADDRESS_BUZZER, ADDR_MODE, (uint8_t)status);
    setstate=status; //actualiza el valor
    if(status==0){tonefreq =0;}  //resetea la frecuencia
    }
    portEnable(0);
}

void buzzerbk::beep(unsigned int t_on,unsigned int t_off)
{
    if (t_on>65000)
        t_on=65000;
    if (t_off>65000)
        t_off=65000;

    portEnable(_port);
    writeBK(SLAVE_ADDRESS_BUZZER,ADDR_MODE,(byte)MODE_BEEP);
    write2BK(SLAVE_ADDRESS_BUZZER,ADDR_TON,t_on);
    error = write2BK(SLAVE_ADDRESS_BUZZER,ADDR_TOFF,t_off);
    setstate=1; //actualiza el valor
    portEnable(0);
}

void buzzerbk::playtone(unsigned int frequency, unsigned int duration)
{
    portEnable(_port);
    if (duration>65000)
        duration=65000;
    if(frequency<60||frequency>20000)
        frequency = 0;
    else{
        if(tonefreq != frequency){
            write2BK(SLAVE_ADDRESS_BUZZER, ADDR_FREQ, frequency);
            error=write2BK(SLAVE_ADDRESS_BUZZER,ADDR_DURATION, duration);
            writeBK(SLAVE_ADDRESS_BUZZER, ADDR_MODE, (byte)MODE_PLAY1);
            tonefreq = frequency;
            setstate=1; //actualiza el valor
        }
    }
    portEnable(0);
}

void buzzerbk::playtone(unsigned int frequency)
{

    portEnable(_port);
    if(frequency<60||frequency>20000)
        frequency = 0;
    else{
        if(tonefreq != frequency){
            write2BK(SLAVE_ADDRESS_BUZZER, ADDR_FREQ, frequency);
            writeBK(SLAVE_ADDRESS_BUZZER, ADDR_MODE,1);
            tonefreq = frequency;
            setstate=1; //actualiza el valor
        }
    }
    portEnable(0);
}
