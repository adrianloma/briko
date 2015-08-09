/*
*
* WireBK.cpp
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

//include header files

#include "WireBK.h"


void portEnable(uint8_t port_number)  //send information for enabling i2c channel of a specific PORT
{
    byte Port_Enable_Bits=0;
    if(port_number==PORT1)Port_Enable_Bits=0b1000;
    else if(port_number==PORT2)Port_Enable_Bits=0b100;
    else if(port_number==PORT3)Port_Enable_Bits=0b10;
    else if(port_number==PORT4)Port_Enable_Bits=0b1;
    else if(port_number==PORT5)Port_Enable_Bits=0b10000000;
    else if(port_number==PORT6)Port_Enable_Bits=0b1000000;
    else if(port_number==PORT7)Port_Enable_Bits=0b100000;
    else if(port_number==PORT8)Port_Enable_Bits=0b10000;
    else Port_Enable_Bits=0;

    Wire.beginTransmission(MULTIPLEXOR_ADDRESS);
    Wire.write(Port_Enable_Bits);
    Wire.endTransmission();
}

uint8_t writeBK(uint8_t i2c_address, uint8_t register_address)       //function to write array of bytes
{
    uint8_t error=0;   //variable to store error of the comunication
    Wire.beginTransmission(i2c_address); //Begin transmission to desired address
    Wire.write(register_address);    //address to a register where the information will be written
    error=Wire.endTransmission();     // stop transmitting
    return(error);  //return
}

uint8_t writeBK(uint8_t i2c_address, uint8_t register_address, uint8_t data)       //function to write array of bytes
{
    uint8_t error=0;   //variable to store error of the comunication
    Wire.beginTransmission(i2c_address); //Begin transmission to desired address
    Wire.write(register_address);     //address to a register where the information will be written
    Wire.write(data);     //write information
    error=Wire.endTransmission();     // stop transmitting
    return(error);
}

uint8_t write2BK(uint8_t i2c_address, uint8_t register_address, unsigned int data)       //function to write array of bytes
{
    uint8_t error=0;
    uint8_t high_byte=data>>8;
    uint8_t low_byte=data&0xFF;
    Wire.beginTransmission(i2c_address); //Begin transmission to 0x76 address (LED Driver)
    Wire.write(register_address);     //
    Wire.write(high_byte);
    Wire.write(low_byte);     //
    error=Wire.endTransmission();     // stop transmitting
    return(error);
}

uint8_t readBK(uint8_t i2c_address)
{
    uint8_t data=0;
    Wire.requestFrom((int)i2c_address, (int)1);    // request 6 bytes from slave device #2
    while(Wire.available())    // slave may send less than requested
    {
     data = Wire.read(); // receive a byte as character
    }
    return(data);
}
