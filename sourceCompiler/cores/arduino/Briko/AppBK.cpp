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
#include "AppBK.h"

stringbk Data;  //estructura que guarda un arreglo

uint8_t bkcontrolread(void){

    bk7btread(&Data,3);

    if (Data.stringbuffer[2] >0){   // Si hay algo en el buffer
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='1' && Data.stringbuffer[2]=='a')    return(L_BUTTON_PRESSED);       // Se presiona L
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='2' && Data.stringbuffer[2]=='a')    return(R_BUTTON_PRESSED);       // Se presiona R
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='3' && Data.stringbuffer[2]=='a')    return(START_BUTTON_PRESSED);   // Se presiona START
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='4' && Data.stringbuffer[2]=='a')    return(SELECT_BUTTON_PRESSED);  // Se presiona SELECT
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='5' && Data.stringbuffer[2]=='a')    return(A_BUTTON_PRESSED);       // Se presiona A
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='6' && Data.stringbuffer[2]=='a')    return(B_BUTTON_PRESSED);       // Se presiona B
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='7' && Data.stringbuffer[2]=='a')    return(UP_ARROW_PRESSED);       // Se presiona UP
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='8' && Data.stringbuffer[2]=='a')    return(LEFT_ARROW_PRESSED);     // Se presiona LEFT
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='9' && Data.stringbuffer[2]=='a')    return(RIGHT_ARROW_PRESSED);    // Se presiona RIGHT
        if (Data.stringbuffer[0]=='1' && Data.stringbuffer[1]=='0' && Data.stringbuffer[2]=='a')    return(DOWN_ARROW_PRESSED);     // Se presiona DOWN

        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='1' && Data.stringbuffer[2]=='u')    return(L_BUTTON_UNPRESSED);       // Se presiona L
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='2' && Data.stringbuffer[2]=='u')    return(R_BUTTON_UNPRESSED);       // Se presiona R
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='3' && Data.stringbuffer[2]=='u')    return(START_BUTTON_UNPRESSED);   // Se presiona START
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='4' && Data.stringbuffer[2]=='u')    return(SELECT_BUTTON_UNPRESSED);  // Se presiona SELECT
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='5' && Data.stringbuffer[2]=='u')    return(A_BUTTON_UNPRESSED);       // Se presiona A
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='6' && Data.stringbuffer[2]=='u')    return(B_BUTTON_UNPRESSED);       // Se presiona B
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='7' && Data.stringbuffer[2]=='u')    return(UP_ARROW_UNPRESSED);       // Se presiona UP
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='8' && Data.stringbuffer[2]=='u')    return(LEFT_ARROW_UNPRESSED);     // Se presiona LEFT
        if (Data.stringbuffer[0]=='0' && Data.stringbuffer[1]=='9' && Data.stringbuffer[2]=='u')    return(RIGHT_ARROW_UNPRESSED);    // Se presiona RIGHT
        if (Data.stringbuffer[0]=='1' && Data.stringbuffer[1]=='0' && Data.stringbuffer[2]=='u')    return(DOWN_ARROW_UNPRESSED);     // Se presiona DOWN
    } else{
    return 0; }
}

//lee los controles de la app
uint16_t bkslidersread(uint8_t slider_num){
    uint16_t var_ret = -1;  //regresara -1 si hubo error
    uint8_t deci =0;
    uint8_t counter_tim =0;
    uint8_t counter_tim2 =0;
    bool flag_rest = 1;
    int8_t fori=0;
    uint8_t mult = 1;


    //seguridad
    if(slider_num > 7 || slider_num<1){
        slider_num=0;
    }

    //solicita data
    if(slider_num == 1){ //slider 1
        bk7btwrite("11a"); }
    if(slider_num == 2){ //slider 2
        bk7btwrite("12a"); }
    if(slider_num == 3){  //slider 3
        bk7btwrite("13a"); }
    if(slider_num == 4){ //PITCH
        bk7btwrite("16aP00"); }
        if(slider_num == 5){ //ROLL
        bk7btwrite("16aR00"); }
        if(slider_num == 6){ //YAW
        bk7btwrite("16aY00"); }
    if(slider_num == 7){  //boton1
        bk7btwrite("17a"); }


    if(slider_num != 0){
        while(flag_rest && counter_tim2<5){  //repite mensaje hasta recivir data(5 vecez max)
            while(Serial1.available()!=3 && counter_tim <100){
            counter_tim++;  //suma al timer
            delay(3);
            }  //espera la data
            if(Serial1.available()>3){bk7btclean();}  //si se pasa borra todo
            if(counter_tim < 100){flag_rest=0;}  //rompe el ciclo
            if(counter_tim >= 100){
           //solicita data
            if(slider_num == 1){ //slider 1
                bk7btwrite("11a"); }
            if(slider_num == 2){ //slider 2
                bk7btwrite("12a"); }
            if(slider_num == 3){  //slider 3
                bk7btwrite("13a"); }
            if(slider_num == 4){ //PITCH
                bk7btwrite("16aP00"); }
                if(slider_num == 5){ //ROLL
                bk7btwrite("16aR00"); }
                if(slider_num == 6){ //YAW
                bk7btwrite("16aY00"); }
            if(slider_num == 7){  //boton1
                bk7btwrite("17a"); }
            counter_tim=0; //resetea timer
            }
            counter_tim2++; //agrega uno al timer 2
        }

        if(counter_tim2<5){ //sino fallo
            bk7btread(&Data,3);  //lee 3 bytes
            //convierte de caracter a decimal
            for(fori=2;fori>=0;fori--){
            deci = ((uint8_t)(Data.stringbuffer[fori]-'0'));
            var_ret = (deci*mult) + var_ret;
            mult=mult*10;
            Data.stringbuffer[fori]=0;  //resetea
            }
        }
    }
delay(50);  //espera a que acabe la app
bk7btclean(); //borra si quedo algo
return(var_ret);

}

//manda informacion a los indicadores de la app
void bksliderswrite(uint8_t object, uint8_t value){

//seguridad
if(object > 5 || object<1){
object=0;
}

if(object == 1){  //barra 1
if(value > 255){ value=255;}
if(value <0){ value=0;}
Send_6_bytes("14a",value);
}

if(object == 2){  //barra 2
if(value > 255){ value=255;}
if(value <0){ value=0;}
 Send_6_bytes("15a",value);
}

if(object == 3){  //led1
if(value > 1){ value=1;}
if(value <0){ value=0;}
Send_6_bytes("18a",value);
}

if(object == 4){  //led2
if(value > 1){ value=1;}
if(value <0){ value=0;}
Send_6_bytes("19a",value);
}

if(object == 5){  //led3
if(value > 1){ value=1;}
if(value <0){ value=0;}
Send_6_bytes("20a",value);
}

delay(100);  //espera un poco para que se procese data en celular

}

void Send_6_bytes(char *String_3_bytes, uint8_t number_p){

if (number_p  < 10) { //AGREGA 2 CEROS
bk7btwrite(String_3_bytes);
bk7btwrite('0');
bk7btwrite('0');
bk7btwrite(number_p);
}
if (number_p  < 100 && number_p  >= 10) { //AGREGA 1 CEROS
bk7btwrite(String_3_bytes);
bk7btwrite('0');
bk7btwrite(number_p);
}
if (number_p  >= 100) { //NO AGREGA CEROS
bk7btwrite(String_3_bytes);
bk7btwrite(number_p);
}

}

long bksocial_facebook_likes(char *Name){  //funcion para solicitar likes de la app
bool flag_rest = 1;
uint8_t counter_tim =0;
uint8_t counter_tim2 =0;
long var_ret = 0;
uint8_t deci =0;
int8_t fori=0;
long mult=1;
//solicita la data
bk7btwrite(Name);  //puede ser el id number o el nombre de la pagina(no tan grande)
delay(150);
bk7btwrite("1");
delay(150);
counter_tim =0;
counter_tim2 =0;
//espera a que llegue
while(flag_rest && counter_tim2<5){  //repite mensaje hasta recivir data(5 vecez max)
    while(Serial1.available()!=7 && counter_tim <100){
        counter_tim++;  //suma al timer
        delay(10);
        }  //espera la data
    if(Serial1.available()>7){bk7btclean();}  //si se pasa borra todo
    if(counter_tim < 100){flag_rest=0;}  //rompe el ciclo
    if(counter_tim >= 100){
    //solicita data otra vez
    bk7btwrite(Name);
    delay(150);
    bk7btwrite("1");
    delay(150);
    counter_tim=0; //resetea timer
    }
    counter_tim2++; //agrega uno al timer 2
}
if(counter_tim2  < 5){  //si no hubo error
        bk7btread(&Data,7); //lee la data
        mult=1;  //multiplicador
        var_ret=0; //variable donde sumaremos
        deci=0;  //numero a sumar
         for(fori=6;fori>=0;fori--){
        deci = ((uint8_t)(Data.stringbuffer[fori]-'0'));
        var_ret = (deci*mult) + var_ret;
        mult=mult*10;
        Data.stringbuffer[fori]=0;  //resetea
        }
    } else{ var_ret=-1;}  //hubo error

///lo minimo aqui son 500 milis pero para no saturar lo dejare de 5 segundos igual que twitter
delay(5000);  //wait
bk7btclean(); //limpia el serial antes de continuar
return(var_ret);

}


void bksocial_facebook_user(char *Saver,char *Name){  //funcion para leer la informacion del usuario en face
bool flag_rest = 1;
uint8_t counter_tim =0;
uint8_t counter_tim2 =0;
uint8_t Selector_char;
uint8_t i=0;
//solicita la data
bk7btwrite(Name);
delay(150);
bk7btwrite("2");
delay(150);
counter_tim =0;
counter_tim2 =0;
//espera a que llegue
while(flag_rest && counter_tim2<5){  //repite mensaje hasta recivir data(5 vecez max)
    while(Serial1.available()!=7 && counter_tim <100){
        counter_tim++;  //suma al timer
        delay(10);
        }  //espera la data
    if(Serial1.available()>7){bk7btclean();}  //si se pasa borra todo
    if(counter_tim < 100){flag_rest=0;}  //rompe el ciclo
    if(counter_tim >= 100){
    //solicita data otra vez
    bk7btwrite(Name);  //100002191350985   695691513
    delay(150);
    bk7btwrite("2");
    delay(150);
    counter_tim=0; //resetea timer
    }
    counter_tim2++; //agrega uno al timer 2
}

if(counter_tim2  < 5){  //si no hubo error
        bk7btread(&Data,7); //lee la data
        counter_tim=0; //para recorrer la data que se guarda
        for(i=0;i<8;i++){
            if(Data.stringbuffer[i] != '0'){  //ignora la data de relleno
                Saver[counter_tim] = Data.stringbuffer[i]; //guarda la info
                counter_tim++; //incrementa el contador
            }
             Data.stringbuffer[i]=0;  //resetea
        }
    }else{ //hubo error
        for(i=0;i<8;i++){
        Saver[i]='0';}
    }
///lo minimo aqui son 500 milis pero para no saturar lo dejare de 5 segundos igual que twitter
delay(5000);  //wait for app finish
bk7btclean(); //limpia el serial antes de continuar
}

void bksocial_twitter_get(char *Saver,char *Name,char selector){  //funcion para leer un tweet
bool flag_rest = 1;
uint8_t counter_tim =0;
uint8_t counter_tim2 =0;
uint8_t Selector_char;
uint8_t i=0;
if(selector == '3' || selector == '5'){   //3 es para user info y el 5 para informacion de una busqueda

//solicita la data
bk7btwrite(Name);
delay(150);
bk7btwrite(selector);
delay(150);
counter_tim =0;
counter_tim2 =0;
//espera a que llegue
while(flag_rest && counter_tim2<5){  //repite mensaje hasta recivir data(5 vecez max)
    while(Serial1.available()!=7 && counter_tim <100){
        counter_tim++;  //suma al timer
        delay(10);
        }  //espera la data
    if(Serial1.available()>7){bk7btclean();}  //si se pasa borra todo
    if(counter_tim < 100){flag_rest=0;}  //rompe el ciclo
    if(counter_tim >= 100){
    //solicita data otra vez
    bk7btwrite(Name);  //100002191350985   695691513
    delay(150);
    bk7btwrite(selector);
    delay(150);
    counter_tim=0; //resetea timer
    }
    counter_tim2++; //agrega uno al timer 2
}

if(counter_tim2  < 5){  //si no hubo error
        bk7btread(&Data,7); //lee la data
        counter_tim=0; //para recorrer la data que se guarda
        for(i=0;i<8;i++){
            if(Data.stringbuffer[i] != '0'){  //ignora la data de relleno
                Saver[counter_tim] = Data.stringbuffer[i]; //guarda la info
                counter_tim++; //incrementa el contador
            }
            Data.stringbuffer[i]=0;  //resetea
        }
    } else{ //hubo error
        for(i=0;i<8;i++){
        Saver[i]='0';}
    }
}
///*****nota importante solo puedes hacer 180 request en 15 minutos por eso este espera 5 segundos***///
delay(5000);  //wait for app finish
bk7btclean(); //limpia el serial antes de continuar
}

///***solo puedes postear 5 vecez por cada 15 minutos
void bksocial_twitter_send(char *Name){  //funcion para mandar un tweet
bk7btwrite(Name);
delay(150);
bk7btwrite("4");
delay(150);
delay(500);  //wait for app finish
}

