/*
*
* BK8functions.h
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

#ifndef BK8functions_h
#define BK8functions_h

#include "Arduino.h"

///Este archivos es para funciones especiales que corra el maestro

////estructura para poder usar la funcion de leer enunciados en el serial
struct _stringbk {
char stringbuffer[30];  //buffer de char a donde el apuntador se direcciona y donde se guarda lo que regresa la funcion
};
#define stringbk struct _stringbk //crea objeto estructura

void bk7led(int State);  //funcion para controlar el led del maestro
void bk7print(int SerialMessage);  //para mandar mensajes por serial
void bk7print(long SerialMessage);  //para mandar mensajes por serial
void bk7print(char SerialMessage);  //para mandar mensajes por serial
void bk7print(float SerialMessage);  //para mandar mensajes por serial
void bk7print(double SerialMessage);  //para mandar mensajes por serial
void bk7print(char *SerialMessage);  //para mandar mensajes por serial
void bk7write(int SerialMessage);  //para mandar mensajes por serial
void bk7write(char SerialMessage);  //para mandar mensajes por serial
void bk7write(float SerialMessage);  //para mandar mensajes por serial
void bk7write(double SerialMessage);  //para mandar mensajes por serial
void bk7write(char *SerialMessage);  //para mandar mensajes por serial
char bk7read(void);   //para leer mensajes largos  del serial
void bk7read(int Read_size,char *CharArray,int Array_size);  //para leer enunciados del serial
void bk7read(stringbk *Controlvar, int size_array);  //para leer enunciados del serial
void bk7message(stringbk *Controlvar,char *Message , uint8_t Message_size);  //para guardar un mensaje en el arreglo
void bk7clean(void); //funcion para limpiar el buffer de serial
void bk7btwrite(int SerialMessage);  //para mandar mensajes por serial
void bk7btwrite(char SerialMessage);  //para mandar mensajes por serial
void bk7btwrite(float SerialMessage);  //para mandar mensajes por serial
void bk7btwrite(double SerialMessage);  //para mandar mensajes por serial
void bk7btwrite(char *SerialMessage);  //para mandar mensajes por serial
char bk7btread(void);   //para leer mensajes del serial
void bk7btread(int Read_size,char *CharArray,int Array_size);  //para leer enunciados del serial
void bk7btread(stringbk *Controlvar, int size_array);  //para leer enunciados del serial
void bk7btclean(void); //borra lo que haya en el buffer de serial

#endif

