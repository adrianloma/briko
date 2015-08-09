/*
*
* LED.cpp
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

#include "LED.h"    //includes header

ledsbk::ledsbk(uint8_t port_number)        //declares constructor
{
    _port = port_number;     //pin is stored in private variable _pin
    error=0;
    constructor_created=0;   //variable para correr el ciclo de inicializacion
    Wire.begin();  // join i2c bus
}

int ledsbk::test()
{

    uint8_t array_temp[2];
    uint8_t check=0;
    uint8_t lowByte=0;
    uint8_t highByte=0;
    int eflag=0xFFFF;

    if(constructor_created==0){   //si no ha inicializado
        constructor_created=1;    //marca como inicializado el modulo
        LedsBegin();              //inicializa el modulo
    }

    portEnable(_port);
    writeBK(SLAVE_ADDRESS_LED, MODE_2,FAULTTEST);
    delay(1);
    writeBK(SLAVE_ADDRESS_LED, MODE_2);
    check = readBK(SLAVE_ADDRESS_LED);
    if (check&0x1000000==0){
        writeBK(SLAVE_ADDRESS_LED,EFLAG0);
        lowByte=readBK(SLAVE_ADDRESS_LED);
        writeBK(SLAVE_ADDRESS_LED,EFLAG1);
        highByte=readBK(SLAVE_ADDRESS_LED);
    }
    eflag = (highByte << 8) + lowByte;               // Put them together
    portEnable(0);
    return(eflag);
}

void ledsbk::color(uint8_t R, uint8_t G, uint8_t B) //function to display RGB colors in nLED
{

    if(constructor_created==0){   //si no ha inicializado
        constructor_created=1;    //marca como inicializado el modulo
        LedsBegin();              //inicializa el modulo
    }

    portEnable(_port);
    writeBK(SLAVE_ADDRESS_LED,ADDR_LED1_R,R);
    writeBK(SLAVE_ADDRESS_LED,ADDR_LED1_G,G);
    writeBK(SLAVE_ADDRESS_LED,ADDR_LED1_B,B);

    writeBK(SLAVE_ADDRESS_LED,ADDR_LED2_R,R);
    writeBK(SLAVE_ADDRESS_LED,ADDR_LED2_G,G);
    writeBK(SLAVE_ADDRESS_LED,ADDR_LED2_B,B);

    writeBK(SLAVE_ADDRESS_LED,ADDR_LED3_R,R);
    writeBK(SLAVE_ADDRESS_LED,ADDR_LED3_G,G);
    writeBK(SLAVE_ADDRESS_LED,ADDR_LED3_B,B);

    writeBK(SLAVE_ADDRESS_LED,ADDR_LED4_R,R);
    writeBK(SLAVE_ADDRESS_LED,ADDR_LED4_G,G);
    writeBK(SLAVE_ADDRESS_LED,ADDR_LED4_B,B);

    writeBK(SLAVE_ADDRESS_LED,ADDR_LED5_R,R);
    writeBK(SLAVE_ADDRESS_LED,ADDR_LED5_G,G);
    error=writeBK(SLAVE_ADDRESS_LED,ADDR_LED5_B,B);
    portEnable(0);
}

void ledsbk::color(uint8_t LED_number, uint8_t R, uint8_t G, uint8_t B) //function to display RGB colors in nLED
{

    if(constructor_created==0){   //si no ha inicializado
        constructor_created=1;    //marca como inicializado el modulo
        LedsBegin();              //inicializa el modulo
    }

    portEnable(_port);
    switch (LED_number){ //selects which LED must be configured, in each case the RGB values are sent to the corresponding PWM registers

	case 1:
        writeBK(SLAVE_ADDRESS_LED,ADDR_LED1_R,R);
        writeBK(SLAVE_ADDRESS_LED,ADDR_LED1_G,G);
        error=writeBK(SLAVE_ADDRESS_LED,ADDR_LED1_B,B);
        break;
	case 2:
        writeBK(SLAVE_ADDRESS_LED,ADDR_LED2_R,R);
        writeBK(SLAVE_ADDRESS_LED,ADDR_LED2_G,G);
        error=writeBK(SLAVE_ADDRESS_LED,ADDR_LED2_B,B);
        break;
	case 3:
        writeBK(SLAVE_ADDRESS_LED,ADDR_LED3_R,R);
        writeBK(SLAVE_ADDRESS_LED,ADDR_LED3_G,G);
        error=writeBK(SLAVE_ADDRESS_LED,ADDR_LED3_B,B);
        break;
	case 4:
        writeBK(SLAVE_ADDRESS_LED,ADDR_LED4_R,R);
        writeBK(SLAVE_ADDRESS_LED,ADDR_LED4_G,G);
        error=writeBK(SLAVE_ADDRESS_LED,ADDR_LED4_B,B);
        break;
	case 5:
        writeBK(SLAVE_ADDRESS_LED,ADDR_LED5_R,R);
        writeBK(SLAVE_ADDRESS_LED,ADDR_LED5_G,G);
        error=writeBK(SLAVE_ADDRESS_LED,ADDR_LED5_B,B);
        break;
    default:
        break;
    }
    portEnable(0);
}

void ledsbk::LedsBegin() //Initialize set up registers
{

    portEnable(_port);
    writeBK(SLAVE_ADDRESS_LED,MODE_1);  //Writes MODE_1 data to its register

    writeBK(SLAVE_ADDRESS_LED,INITIALIZE0); //Writes LEDOUT0 data to its register
    writeBK(SLAVE_ADDRESS_LED,INITIALIZE1); //Writes LEDOUT1 data to its register
    writeBK(SLAVE_ADDRESS_LED,INITIALIZE2); //Writes LEDOUT2 data to its register
    writeBK(SLAVE_ADDRESS_LED,INITIALIZE3); //Writes LEDOUT3 data to its register

    writeBK(SLAVE_ADDRESS_LED,CURRENT_DEFAULT); //Writes IREFALL default value data to its register
    portEnable(0);

    //sets all LEDs off
    color(BLACK);
    //sets brightness at 20%
}

void ledsbk::brightness(uint8_t brightness_intensity)//Update IREFALL value function
{
    if(constructor_created==0){   //si no ha inicializado
        constructor_created=1;    //marca como inicializado el modulo
        LedsBegin();              //inicializa el modulo
    }

	portEnable(_port);
	writeBK(SLAVE_ADDRESS_LED,IREFALL,brightness_intensity);   //Writes new data to led driver
	portEnable(0);
}
