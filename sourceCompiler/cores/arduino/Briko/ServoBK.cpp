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
#include "ServoBK.h"    //includes the header in the library

///Clases de servo para cada pin
Servo servobriko1;
Servo servobriko2;
Servo servobriko3;
Servo servobriko4;
Servo servobriko5;
Servo servobriko6;
Servo servobriko7;
////////////////////////////////////

extern byte motor_flag_usb; //variable externa declarada en el briko.h en el setup

servobk::servobk(uint8_t pin)        //declares the constructor
{
  _pin = pin;     //stores the analog input pin to the private variable _pin
  flag_init=0;
}

void servobk::set(uint16_t Degrees)			//reading and mapping analog input function
{

if(motor_flag_usb == 0){ //battery connected
Attach_pin(_pin);
if(Degrees>180){Degrees=180;}
if(Degrees<0){Degrees=0;}
Write_pin(_pin,Degrees);  //Mueve el servo ciertos grados
}

if(motor_flag_usb == 1){  //usb connected
Attach_pin(_pin);
}

}

uint16_t servobk::read(void)			//reading and mapping analog input function
{
uint16_t Degrees = 0;
Attach_pin(_pin);
Degrees = Read_pin(_pin);  //Mueve el servo ciertos grados
return(Degrees);
}


void servobk::Attach_pin(uint8_t pin_used){
if(pin_used == PORT1){
    if(flag_init == 0){
    servobriko1.attach(pin_used);
    flag_init = 1;
    }
}
if(pin_used == PORT2){
    if(flag_init == 0){
    servobriko2.attach(pin_used);
    flag_init = 1;
    }
}
if(pin_used == PORT3){
    if(flag_init == 0){
    servobriko3.attach(pin_used);
    flag_init = 1;
    }
}
if(pin_used == PORT4){
    if(flag_init == 0){
    servobriko4.attach(pin_used);
    flag_init = 1;
    }
}
if(pin_used == PORT5){
    if(flag_init == 0){
    servobriko5.attach(pin_used);
    flag_init = 1;
    }
}
if(pin_used == PORT6){
    if(flag_init == 0){
    servobriko6.attach(pin_used);
    flag_init = 1;
    }
}
if(pin_used == PORT7){
    if(flag_init == 0){
    servobriko7.attach(pin_used);
    flag_init = 1;
    }
}
}

void servobk::Write_pin(uint8_t pin_used,uint16_t value){
if(pin_used == PORT1){
    servobriko1.write(value);
}
if(pin_used == PORT2){
    servobriko2.write(value);
}
if(pin_used == PORT3){
    servobriko3.write(value);
}
if(pin_used == PORT4){
    servobriko4.write(value);
}
if(pin_used == PORT5){
    servobriko5.write(value);
}
if(pin_used == PORT6){
    servobriko6.write(value);
}
if(pin_used == PORT7){
    servobriko7.write(value);
}
}

uint16_t servobk::Read_pin(uint8_t pin_used){
    uint16_t value=0;
if(pin_used == PORT1){
    value=servobriko1.read();
}
if(pin_used == PORT2){
    value=servobriko2.read();
}
if(pin_used == PORT3){
    value=servobriko3.read();
}
if(pin_used == PORT4){
    value=servobriko4.read();
}
if(pin_used == PORT5){
    value=servobriko5.read();
}
if(pin_used == PORT6){
    value=servobriko6.read();
}
if(pin_used == PORT7){
    value=servobriko7.read();
}
return(value);
}

