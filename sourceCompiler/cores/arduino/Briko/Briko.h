/*
*
* Briko.h
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

#ifndef Briko_H
#define Briko_H

//include header files for different modules
#include "Arduino.h"
#include "WireBK.h"
#include "LED.h"
#include "SharpIR.h"
#include "Potenciometer.h"
#include "Buttons.h"
#include "Motor.h"
#include "Temperature.h"
#include "Light.h"
#include "Buzzer.h"
#include "Display.h"
#include "ServoBK.h"
#include "relayBK.h"
#include "BK8keyboard.h"
#include "BK8functions.h"
#include "AppBK.h"


#include <avr/wdt.h>  //para el watchdog


#define code() void loop()
void pause(void);
void blink_pause(void);
#endif

