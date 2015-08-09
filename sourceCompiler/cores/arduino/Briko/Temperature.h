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
* 14/08/14 Mexico.
*
*/
#ifndef Temperature  //if not defined
    #define Temperature  //defines header name


    #define TEMP_SAMPLES 5 //number of samples to average
    #define C 0
    #define F 1
    #include "Arduino.h"   //includes Arduino.h library

    class temperaturebk
        {
        public:
                temperaturebk(uint8_t pin);  //initialize constructor
                int read();  //read analog input function
                int read(byte unit);
        private:
                uint8_t _pin;  //declares a variable

        };

#endif  //end define
