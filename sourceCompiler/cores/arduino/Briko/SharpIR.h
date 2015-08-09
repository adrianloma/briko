 /*
*
* SharpIR.h
*
* Copyright 2014 IPSUM <contacto@ipsumss.com>
*
* This library is free software; you can redistribute it and/or
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* 11/08/14 Mexico.
*
*/

#ifndef SharpIR_H  //if not define
	#define SharpIR_H  //defines header's name

    #include "Arduino.h"

    #define CM 0
    #define IN 1

    class distancebk   //opens class (set of functions)
        {
        public:  //to be used outside the class
                    distancebk(uint8_t pin);  //constructor
                    float read(uint8_t unit);  //reading sensor function
                    float read (void);
        private:  //to be used only inside the class
                    uint8_t _pin;  //declares a variable
                    float val[10];
        };    //closes class

#endif  //end define
