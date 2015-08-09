/*
*
* WireBK.h
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

#ifndef WireBK_h
#define WireBK_h
#include "Arduino.h"
#include "Wire.h"

#include <Math.h>

#define MULTIPLEXOR_ADDRESS 0x70    //multiplexor slave address

#ifdef SHIELD
    #if defined(__AVR_ATmega32U4__)
    //define port pins for shield on arduino leonardo
        #define PORT1 A3
        #define PORT2 A2
        #define PORT3 A1
        #define PORT4 A0
        #define PORT5 A9
        #define PORT6 A8
        #define PORT7 A7
        ///#define PORT8 A6
    #else
    //define port pins for shield on arduino UNO
        #define PORT1 A3
        #define PORT2 A2
        #define PORT3 A1
        #define PORT4 A0
        #define PORT5 D9
        #define PORT6 D8
        #define PORT7 D6
        ///#define PORT8 D4
    #endif
#else
//define port pins for BK8
    #define PORT1 A5
    #define PORT2 A4
    #define PORT3 A3
    #define PORT4 A2
    #define PORT5 A9
    #define PORT6 A8
    #define PORT7 A7
    #define PORT8 A6
#endif

void portEnable(uint8_t port_number);   //Enable desired communication channel

uint8_t writeBK(uint8_t i2c_address, uint8_t register_address);
uint8_t writeBK(uint8_t i2c_address, uint8_t register_address, uint8_t data); //write data to device with i2c_address in the register_address
uint8_t write2BK(uint8_t i2c_address, uint8_t register_address, unsigned int data);  //write integer data to device with i2c_address in the register_address

uint8_t readBK(uint8_t i2c_address);    //read byte from i2c_address

#endif

