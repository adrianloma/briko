/*
*
* AppBK.h
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

#ifndef AppBK_h
#define AppBK_h

#include "BK8functions.h"

#define L_BUTTON_PRESSED 1
#define R_BUTTON_PRESSED 2
#define START_BUTTON_PRESSED 3
#define SELECT_BUTTON_PRESSED 4
#define A_BUTTON_PRESSED 5
#define B_BUTTON_PRESSED 6
#define UP_ARROW_PRESSED 7
#define LEFT_ARROW_PRESSED 8
#define RIGHT_ARROW_PRESSED 9
#define DOWN_ARROW_PRESSED 10

#define L_BUTTON_UNPRESSED 11
#define R_BUTTON_UNPRESSED 12
#define START_BUTTON_UNPRESSED 13
#define SELECT_BUTTON_UNPRESSED 14
#define A_BUTTON_UNPRESSED 15
#define B_BUTTON_UNPRESSED 16
#define UP_ARROW_UNPRESSED 17
#define LEFT_ARROW_UNPRESSED 18
#define RIGHT_ARROW_UNPRESSED 19
#define DOWN_ARROW_UNPRESSED 20

#define BARBK1 1
#define BARBK2 2
#define LEDBK1 3
#define LEDBK2 4
#define LEDBK3 5

#define SLIDERBK1 1
#define SLIDERBK2 2
#define SLIDERBK3 3
#define PITCHBK 4
#define ROLLBK 5
#define YAWBK 6
#define BUTTONBK1 7

///Este archivo es para usar la aplicacion de Briko

uint8_t bkcontrolread(void);  //funcion para leer lo que manda el control de la App(control)
uint16_t bkslidersread(uint8_t slider_num); //lee los controles de la app(sliders)
void bksliderswrite(uint8_t object, uint8_t value); //escribe en los indicadores de la app(sliders)
void Send_6_bytes(char *String_3_bytes, uint8_t number_p); //funcion interna
long bksocial_facebook_likes(char *Name);  //solicita likes de una pagina
void bksocial_facebook_user(char *Saver,char *Name); //funcion para leer la informacion del usuario en face
void bksocial_twitter_get(char *Saver,char *Name,char selector); //get a last tweet in your timeline
void bksocial_twitter_send(char *Name); ///send a tweet
#endif
