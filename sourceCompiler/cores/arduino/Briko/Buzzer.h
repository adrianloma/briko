/*
*
* Buzzer.h
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
#ifndef Buzzer_h  //if not defined

#define Buzzer_h  //defines header name


//define state constants
#define ON  1
#define OFF 0

#define MODE_BEEP   0x02
#define MODE_PLAY1  0x03
#define MODE_PLAY2  0x04

#define SLAVE_ADDRESS_BUZZER 0x5F

#define ADDR_MODE   0x01
#define ADDR_TON    0x02
#define ADDR_TOFF   0x04
#define ADDR_FREQ   0x06
#define ADDR_DURATION   0x08

//define notes
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262-3
#define NOTE_CS4 277-1
#define NOTE_D4  294-3
#define NOTE_DS4 311-1
#define NOTE_E4  330
#define NOTE_F4  349-3
#define NOTE_FS4 370-3
#define NOTE_G4  392-4
#define NOTE_GS4 415-3
#define NOTE_A4  440-2
#define NOTE_AS4 466-1
#define NOTE_B4  494-5
#define NOTE_C5  523-3
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#include "WireBK.h"   //includes Arduino.h library

class buzzerbk   //opens class which is a set of functions
    {
    public:  //to be used outside the class
             buzzerbk(uint8_t port_number);  //initialize constructor
             void set(uint8_t status);  //
             void beep(unsigned int t_on,unsigned int t_off);
             void playtone(unsigned int frequency);
             void playtone(unsigned int frequency,unsigned int duration);
             uint8_t error;
    private:  //to be used only in this class
             uint8_t _port;  //declares a variable
             unsigned int tonefreq;  //para evitar que vuelva mandar i2c si se repite frecuencia
             bool setstate;  //para evitar que vuelva mandar i2c si se repite frecuencia
};    //close class

#endif  //end define

