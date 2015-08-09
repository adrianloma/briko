/*
*
* relay.h
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
#ifndef relayBK_H  //if not defined
    #define relayBK_H  //defines header name

        #include "Arduino.h"
        #include "WireBK.h"     //includes i2c library

        //Slave Address
        #define SLAVE_ADDRESS_RELAY 0x6E

        //declaration of register's address
        #define REGISTER_RELAY_SET 0X01

        //Motor direction constants
        #define ON 1
        #define OFF 0

        class relaybk   //opens class which is a set of functions
            {

            public:  //to be used outside the class
                     relaybk (uint8_t port_number);  //initialize constructor
                     void set(uint8_t state);  //prende o apaga el relevador

            private:  //to be used only in this class
                     uint8_t _port;  //declares a variable
            };    //close class

#endif  //end define
