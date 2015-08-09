 /*
*
* Motor.h
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

#ifndef Motor_H //if not define
        #define Motor_H  //defines header name

        #include "WireBK.h"     //includes i2c library

        //Slave Address
        #define SLAVE_ADDRESS_MOTOR 0x5E  //0b1011110

        //declaration of register's address
        #define ADDR_VELOCITY_M 0X01
        #define ADDR_DIRECTION_M 0X02
        #define ADDR_ENCODER_M 0X03

        //Motor direction constants
        #define STOP 0
        #define RIGHT 1 //0b01
        #define LEFT 2 //0b10

        class motorbk   //opens LED_Driver Class
            {
                public:  //to be used outside the class
                         motorbk(uint8_t port_number);  //constructor where it is declared the enable pin
                         void set(uint8_t direction, uint8_t speed); //sends a set of colors to a specific LED
                         void set(uint8_t direction);
                         uint8_t error;

                private:  //variables and functions used only inside this class
                          uint8_t _port;  //declares a variable for the enable pin
                          uint8_t Velocity_saved;   //para guardar la velocidad ya establecida

            };    //closes class

#endif  //end define

