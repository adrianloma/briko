/*
*
* BK8functions.cpp
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

//include header files

#include "BK8functions.h"

int Serial_flaginit = 0;   ///Para inicializar el serial una sola vez
int Serial1_flaginit = 0;   ///Para inicializar el serial una sola vez


void bk7led(int State){  /// Prende o apaga el led del bk7
 pinMode(13,1);
 digitalWrite(13,State);
}

/////funciones para el serial de USB
void bk7print(int SerialMessage){
if(Serial_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial.begin(9600);
    Serial_flaginit = 1;
}
 Serial.println(SerialMessage);
}

/////funciones para el serial de USB
void bk7print(long SerialMessage){
if(Serial_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial.begin(9600);
    Serial_flaginit = 1;
}
 Serial.println(SerialMessage);
}

void bk7print(char SerialMessage){
if(Serial_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial.begin(9600);
    Serial_flaginit = 1;
}
 Serial.println(SerialMessage);
}

void bk7print(float SerialMessage){
if(Serial_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial.begin(9600);
    Serial_flaginit = 1;
}
 Serial.println(SerialMessage);
}

void bk7print(double SerialMessage){
if(Serial_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial.begin(9600);
    Serial_flaginit = 1;
}
 Serial.println(SerialMessage);
}

void bk7print(char *SerialMessage){
if(Serial_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial.begin(9600);
    Serial_flaginit = 1;
}
 Serial.println(SerialMessage);
}

void bk7write(int SerialMessage){
if(Serial_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial.begin(9600);
    Serial_flaginit = 1;
}
 Serial.print(SerialMessage);
}

void bk7write(char SerialMessage){
if(Serial_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial.begin(9600);
    Serial_flaginit = 1;
}
 Serial.print(SerialMessage);
}

void bk7write(float SerialMessage){
if(Serial_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial.begin(9600);
    Serial_flaginit = 1;
}
 Serial.print(SerialMessage);
}

void bk7write(double SerialMessage){
if(Serial_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial.begin(9600);
    Serial_flaginit = 1;
}
 Serial.print(SerialMessage);
}

void bk7write(char *SerialMessage){
if(Serial_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial.begin(9600);
    Serial_flaginit = 1;
}
 Serial.print(SerialMessage);
}

char bk7read(void){

char inByte = 0;

if(Serial_flaginit==0){  //si no esta inicializado el serial lo inicializa
    Serial.begin(9600);
    Serial_flaginit = 1;
}

if (Serial.available() > 0) {  //si hay data disponible en el buffer de serial
    // get incoming byte:
    inByte = Serial.read();  //lee el primer byte
}
return(inByte);
}

///Funcion para leer un mensaje largo esta es llamada por la funcion de abajo y el resultado lo guarda en el arreglo de la estructura
void bk7read(int Read_size,char *CharArray,int Array_size){  //CharArray es un buffer para que el apuntador  apunte a este arreglo y acabe guardando ahi

char temporal_char;
int counter = 0;

for(counter=0;counter<Array_size;counter++){
  CharArray[counter]=0;
}

if(Serial_flaginit==0){  //si no esta inicializado el serial lo inicializa
    Serial.begin(9600);
    Serial_flaginit = 1;
}

counter=0;
if (Serial.available() > (Read_size-1)) {  //si hay data disponible en el buffer de serial
    // get incoming byte:
    while(Serial.available()>0){
        temporal_char = Serial.read();
        if(temporal_char != '/n'){
            CharArray[counter]=temporal_char;
            counter = counter+1;
        }
        if(temporal_char == '/n'){
            break;
        }
        if(counter >= Read_size){
            break;
        }
    }
}

}

///funcion que llama a la de arriba para que el usuario final solo introdusca el objeto estructura
/// esta funcion borra el buffer!!!
void bk7read(stringbk *Controlvar, int size_array){  //para llamar la funcion de arriba y solo tener que poner el objeto de la estructura
bk7read(size_array,Controlvar->stringbuffer,30);  //llama la funcion de leer un mensaje largo
bk7clean();  //limpia el serial
}

///funcion para guardar el mensaje en el arreglo
void bk7message(stringbk *Controlvar,char *Message , uint8_t Message_size){  //para llamar la funcion de arriba y solo tener que poner el objeto de la estructura
uint8_t counter = 0;
for(counter = 0; counter< Message_size; counter++){
Controlvar->stringbuffer[counter] = Message[counter] ;  //llama la funcion de arriba, usa apuntador en la estructura por eso es -> en lugar del punto
}
}

void bk7clean(void){  //funcion para limpiar el buffer
char Serialcleaner;
if(Serial_flaginit==0){  //si no esta inicializado el serial lo inicializa
    Serial.begin(9600);
    Serial_flaginit = 1;
}
while(Serial.available()>0){Serialcleaner=Serial.read(); }  ///borra todo lo que haya en el serial
}

/////funciones para el serial de los pines de tx y rx (no mandan el comando de nueva linea)
void bk7btwrite(int SerialMessage){
if(Serial1_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial1.begin(9600);
    Serial1_flaginit = 1;
}
 Serial1.print(SerialMessage);
}

void bk7btwrite(char SerialMessage){
if(Serial1_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial1.begin(9600);
    Serial1_flaginit = 1;
}
 Serial1.print(SerialMessage);
}

void bk7btwrite(float SerialMessage){
if(Serial1_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial1.begin(9600);
    Serial1_flaginit = 1;
}
 Serial1.print(SerialMessage);
}

void bk7btwrite(double SerialMessage){
if(Serial1_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial1.begin(9600);
    Serial1_flaginit = 1;
}
 Serial1.print(SerialMessage);
}

void bk7btwrite(char *SerialMessage){
if(Serial1_flaginit==0){ //si no esta inicializado el serial lo inicializa
    Serial1.begin(9600);
    Serial1_flaginit = 1;
}
 Serial1.print(SerialMessage);
}

char bk7btread(void){

char inByte = 0;
char Serial1cleaner = 0;

if(Serial1_flaginit==0){  //si no esta inicializado el serial lo inicializa
    Serial1.begin(9600);
    Serial1_flaginit = 1;
}
if (Serial1.available() > 0) {  //si hay data disponible en el buffer de serial
    // get incoming byte:
    inByte = Serial1.read();  //lee el primer byte
    }

return(inByte);
}

///Funcion para leer un mensaje largo esta es llamada por la funcion de abajo y el resultado lo guarda en el arreglo de la estructura
void bk7btread(int Read_size,char *CharArray,int Array_size){  //CharArray es un buffer para que el apuntador  apunte a este arreglo y acabe guardando ahi

char temporal_char;
int counter = 0;

for(counter=0;counter<Array_size;counter++){
  CharArray[counter]=0;
}

if(Serial1_flaginit==0){  //si no esta inicializado el serial lo inicializa
    Serial1.begin(9600);
    Serial1_flaginit = 1;
}

counter=0;
if (Serial1.available() > (Read_size-1)) {  //si hay data disponible en el buffer de serial
    // get incoming byte:
    while(Serial1.available()>0){
        temporal_char = Serial1.read();
        if(temporal_char != '/n'){
            CharArray[counter]=temporal_char;
            counter = counter+1;
        }
        if(temporal_char == '/n'){
            break;
        }
        if(counter >= Read_size){
            break;
        }
    }
}

}

///funcion que llama a la de arriba para que el usuario final solo introdusca el objeto estructura
/// esta funcion no borra el buffer!!!
void bk7btread(stringbk *Controlvar, int size_array){  //para llamar la funcion de arriba y solo tener que poner el objeto de la estructura
bk7btread(size_array,Controlvar->stringbuffer,30);  //llama la funcion de leer un mensaje largo
}

void bk7btclean(void){
char Serialcleaner;
if(Serial1_flaginit==0){  //si no esta inicializado el serial lo inicializa
    Serial1.begin(9600);
    Serial1_flaginit = 1;
}
while(Serial1.available()>0){Serialcleaner=Serial1.read(); }  ///borra todo lo que haya en el serial
}
