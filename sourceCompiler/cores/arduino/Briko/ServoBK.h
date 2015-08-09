/*
*
* Servo.h
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
#ifndef ServoBK_H  //if not defined
    #define ServoBK_H  //defines header name

        #include "Arduino.h"
        #include "Wire.h"
        #include "Servo.h"  //libreria de arduino

        class servobk   //opens class which is a set of functions
            {
            public:  //to be used outside the class
                     servobk (uint8_t pin);  //initialize constructor
                     void set(uint16_t Degrees);  //mueve el servo ciertos grados
                     uint16_t read(void);  //read degree in wich servo is
            private:  //to be used only in this class
                     uint8_t _pin;  //declares a variable
                     bool flag_init;
                     void Attach_pin(uint8_t pin_used);  //para seleccionar el puerto
                     uint16_t Read_pin(uint8_t pin_used);
                     void Write_pin(uint8_t pin_used,uint16_t value);
            };    //close class

#endif  //end define
