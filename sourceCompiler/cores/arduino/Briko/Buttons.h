/*
*
* Buttons.h
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

#ifndef Buttons_h
#define Buttons_h

//include header files
#include "WireBK.h"

#define SLAVE_ADDRESS_BUTTONS 0x20 //i2c address 0b0100000

class buttonsbk //open class
{
//public functions
  public:
    buttonsbk(uint8_t port_number);    //declare constructor
    uint8_t readbits(void);
    //void read(uint8_t *bit_array);
    uint8_t read();
    uint8_t read(uint8_t n);

//private variables
  private:
    uint8_t _n;
    uint8_t _port;
};


#endif

