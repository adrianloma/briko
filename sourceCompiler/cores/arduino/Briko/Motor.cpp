 /*
*
* Motor.cpp
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

#include "Motor.h"    //includes header
extern byte motor_flag_usb;

motorbk::motorbk(uint8_t port_number)        //declare constructor
{
  _port = port_number;			//pin is stored in private variable _pin
  error=0;
  Velocity_saved=0;    //inicializa la velocidad
  Wire.begin();			// join i2c bus
}

void motorbk::set(uint8_t direction, uint8_t speed) //function to set the motor in a certain speed and direction
{
    portEnable(_port);
    if(motor_flag_usb == 0){ //battery connected
    Velocity_saved = speed;
    writeBK(SLAVE_ADDRESS_MOTOR,ADDR_VELOCITY_M,Velocity_saved);
    error=writeBK(SLAVE_ADDRESS_MOTOR,ADDR_DIRECTION_M,direction);
    }
    if(motor_flag_usb == 1){  //usb connected
    Velocity_saved = 0;
    writeBK(SLAVE_ADDRESS_MOTOR,ADDR_VELOCITY_M,Velocity_saved);
    error=writeBK(SLAVE_ADDRESS_MOTOR,ADDR_DIRECTION_M,STOP);
    }
    portEnable(0);
}

void motorbk::set(uint8_t direction) //function to stop the motor
{
    portEnable(_port);
    if (direction==0){
        writeBK(SLAVE_ADDRESS_MOTOR,ADDR_VELOCITY_M,0);
        error=writeBK(SLAVE_ADDRESS_MOTOR,ADDR_DIRECTION_M,STOP);
    }
    else{
        writeBK(SLAVE_ADDRESS_MOTOR,ADDR_VELOCITY_M,Velocity_saved);
        error=writeBK(SLAVE_ADDRESS_MOTOR,ADDR_DIRECTION_M,direction);
    }
    portEnable(0);
}
