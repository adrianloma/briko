/*
*
* Light.h
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
#ifndef Light_H  //if not defined
    #define Light_H  //defines header name

        #include "Arduino.h"

        class lightbk   //opens class which is a set of functions
            {
            public:  //to be used outside the class
                     lightbk (uint8_t pin);  //initialize constructor
                     uint8_t read();  //read analog input function
            private:  //to be used only in this class
                     uint8_t _pin;  //declares a variable
            };    //close class

#endif  //end define
