/*
*
* Buttons.cpp
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

#include "Buttons.h"

buttonsbk::buttonsbk(uint8_t port_number) //define constructor and enable pin
{
  _port=port_number;               //store pin in private variable
  Wire.begin();             //begin i2c communication
}

uint8_t buttonsbk::readbits(void)
{
    uint8_t data=0;
    uint8_t temp=0;
    portEnable(_port);
    data=readBK(SLAVE_ADDRESS_BUTTONS); //retrieve information byte
    data = ~data;                       //NOT operation on byte
    temp=data&0b01111100;               //mask bits and store them in temporal variable
    temp=temp>>2;                       //shift 2 bit to the right
    //verify if number is in range
    if (temp>31){
        portEnable(0);
        return (0);
    }
    portEnable(0);
    return(temp);
}

/*
void ButtonsBK::read(uint8_t *bit_array)
{
    uint8_t data=0;
    portEnable(_port);
    data=readBK(SLAVE_ADDRESS_BUTTONS);
    data = ~data;
    //verify if data is in range
    if (data>128)
    {
        data=0;
	}
	for(int i=2;i<=7;i++){
		 bit_array[i-2]=(data>>i)&0x01;//mask the i-th bit and store it in the pointed array
	}
	portEnable(0);
}
*/

uint8_t buttonsbk::read(uint8_t n)
{
    uint8_t data=0;
    //verify button number is in range
    if(n<1||n>5){
        return(0);
    }
    _n=n-1; //determine shift value
    data=readbits();    //get data
    return((data>>_n)&1);   //shift and mask desired bit/button
}

uint8_t buttonsbk::read()
{
    uint8_t data=0;
    uint8_t n=0;
    data=readbits();    //obtain data
    if (data==0)n=0;    //no button pressed
    if (data==1)n=data; //(00001) button 1 pressed
    if (data==2)n=data; //(00010) button 2 pressed
    if (data==4)n=3;    //(00100) button 3 pressed
    if (data==8)n=4;    //(01000) button 4 pressed
    if (data==16)n=5;   //(10000) button 5 pressed
    return(n);
}
