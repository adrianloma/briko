/*
*
* Display.h
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

#ifndef Display_H
#define Display_H

#include "WireBK.h"

#define SLAVE_ADDRESS_DISPLAY 0x3D  //define slave address for display module
#define REGISTER_DISPLAY_5_bytes 1  //define slave address for display module
#define REGISTER_DISPLAY_1_bytes 2  //define slave address for display module
#define DISPLAY_TWO_DOTS 5,0b00000011  //para prender los dos puntos
#define DISPLAY_UP_DOT 5,0b00000100    //para prender el punto de grados de arriba

class displaybk{  //open class
public:                 //public functions
    displaybk(byte port_number);   //declares constructor
    void erase();   // this function erase all de digits in the the display
    void erase(uint8_t n);  //this function erase a specific digit
    void printcustom(byte n, byte segments);    //this function turns on specific segments (indicated in the segments variable) of the n digit (1-4)
    void printindividual(uint8_t n, uint8_t num);   //this function prints a number (0-9) to a specific digit (1-4)
    void print(int16_t num);        //this function prints a integer number in the 4 digits of 7 segments display
    void print(float num);  //this function prints a float number in the display
    void print(double num);  //this function prints a float number in the display
private:                //private unctions and variables
    uint8_t _port;
    uint8_t Number2byte(uint8_t Number_s); //funcion que transforma numeros a secuencias de leds
};

#endif
