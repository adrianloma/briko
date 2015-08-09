/*
*
* BK8keyboard.cpp
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

#include "BK8keyboard.h"

bool Keyboard_flaginit = 0;   ///Para inicializar el serial una sola vez
bool Init_press_flag = 0;
bool Press_flag[5];  //para la funcion de mandar texto

bool Mouse_flaginit = 0;      ///Para inicializar el serial una sola vez


void bk7keywrite(uint16_t KeyMessage){
if(Keyboard_flaginit==0){ //si no esta inicializado lo inicializa
    Keyboard.begin();
    Keyboard_flaginit = 1;
}
 Keyboard.print(KeyMessage);
}

void bk7keywrite(char KeyMessage){
if(Keyboard_flaginit==0){ //si no esta inicializado lo inicializa
    Keyboard.begin();
    Keyboard_flaginit = 1;
}
 Keyboard.print(KeyMessage);
}

void bk7keywrite(char *KeyMessage){
if(Keyboard_flaginit==0){ //si no esta inicializado lo inicializa
    Keyboard.begin();
    Keyboard_flaginit = 1;
}
 Keyboard.print(KeyMessage);
}

void bk7keyprint(uint16_t KeyMessage){
if(Keyboard_flaginit==0){ //si no esta inicializado lo inicializa
    Keyboard.begin();
    Keyboard_flaginit = 1;
}
 Keyboard.println(KeyMessage);
}

void bk7keyprint(char KeyMessage){
if(Keyboard_flaginit==0){ //si no esta inicializado lo inicializa
    Keyboard.begin();
    Keyboard_flaginit = 1;
}
 Keyboard.println(KeyMessage);
}

void bk7keyprint(char *KeyMessage){
if(Keyboard_flaginit==0){ //si no esta inicializado lo inicializa
    Keyboard.begin();
    Keyboard_flaginit = 1;
}
 Keyboard.println(KeyMessage);
}

void bk7keypress(uint16_t key){
if(Keyboard_flaginit==0){ //si no esta inicializado lo inicializa
    Keyboard.begin();
    Keyboard_flaginit = 1;
}
Keyboard.press(key);
}

void bk7keypress(uint16_t key,uint16_t time){
if(Keyboard_flaginit==0){ //si no esta inicializado lo inicializa
    Keyboard.begin();
    Keyboard_flaginit = 1;
}
Keyboard.press(key);
delay(time);
Keyboard.release(key);
}

void bk7keyrelease(uint16_t key){
if(Keyboard_flaginit==0){ //si no esta inicializado lo inicializa
    Keyboard.begin();
    Keyboard_flaginit = 1;
}
Keyboard.release(key);
}

void bk7keyreleaseall(void){
if(Keyboard_flaginit==0){ //si no esta inicializado lo inicializa
    Keyboard.begin();
    Keyboard_flaginit = 1;
}
Keyboard.releaseAll();
}

void bk7keyend(void){
Keyboard.end();
}

void bk7keybuttons(uint16_t bits, uint16_t key1,uint16_t key2,uint16_t key3,uint16_t key4,uint16_t key5){
if(Keyboard_flaginit==0){ //si no esta inicializado lo inicializa
    Keyboard.begin();
    Keyboard_flaginit = 1;
}

if(((bits & 0X01) >> 0)==1){  //button 1
  Keyboard.press(key1);
  }else{(Keyboard.release(key1));}

if(((bits & 0X02) >> 1)==1){  //button 2
  Keyboard.press(key2);
  }else{(Keyboard.release(key2));}

if(((bits & 0X04) >> 2)==1){  //button 3
  Keyboard.press(key3);
  }else{(Keyboard.release(key3));}

if(((bits & 0X08) >> 3)==1){  //button 4
  Keyboard.press(key4);
  }else{(Keyboard.release(key4));}

if(((bits & 0X10) >> 4)==1){  //button 5
  Keyboard.press(key5);
  }else{(Keyboard.release(key5));}


}


void bk7keybuttons(uint16_t bits, char *key1,char *key2,char *key3,char *key4,char *key5){
if(Keyboard_flaginit==0){ //si no esta inicializado lo inicializa
    Keyboard.begin();
    Keyboard_flaginit = 1;
}

if(Init_press_flag==0){
    uint16_t c_i;
    for(c_i=0;c_i<5;c_i++){  //inicializa en 0
    Press_flag[c_i]=0;
    }
    Init_press_flag=1;
}

if(((bits & 0X01) >> 0)==1 && Press_flag[0]==0){  //button 1
  Keyboard.print(key1);
  Press_flag[0]=1;
  }
if(((bits & 0X01) >> 0)==0){Press_flag[0]=0;}

if(((bits & 0X02) >> 1)==1 && Press_flag[1]==0){  //button 1
  Keyboard.print(key2);
  Press_flag[1]=1;
  }
if(((bits & 0X02) >> 1)==0){Press_flag[1]=0;}

if(((bits & 0X04) >> 2)==1 && Press_flag[2]==0){  //button 1
  Keyboard.print(key3);
  Press_flag[2]=1;
  }
if(((bits & 0X04) >> 2)==0){Press_flag[2]=0;}

if(((bits & 0X08) >> 3)==1 && Press_flag[3]==0){  //button 1
  Keyboard.print(key4);
  Press_flag[3]=1;
  }
if(((bits & 0X08) >> 3)==0){Press_flag[3]=0;}

if(((bits & 0X10) >> 4)==1 && Press_flag[4]==0){  //button 1
  Keyboard.print(key5);
  Press_flag[4]=1;
  }
if(((bits & 0X10) >> 4)==0){Press_flag[4]=0;}

}

void bk7mouseclick(uint16_t key){
if(Mouse_flaginit==0){ //si no esta inicializado lo inicializa
    Mouse.begin();
    Mouse_flaginit = 1;
}
 Mouse.click(key);
}

void bk7mousemove(uint16_t x_val, uint16_t y_val){
if(Mouse_flaginit==0){ //si no esta inicializado lo inicializa
    Mouse.begin();
    Mouse_flaginit = 1;
}
bool sign_x = 0;
bool sign_y = 0;
uint16_t range_mouse=6;

if(x_val>255){ x_val=255;}
if(y_val>255){ y_val=255;}
if(x_val<0){ x_val=0;}
if(y_val<0){ y_val=0;}

if(x_val<=127){
 sign_x=1;
 x_val=map(x_val,0,128,range_mouse,0);
}
if(x_val>127){
 x_val=x_val-127;
 x_val=map(x_val,0,128,0,range_mouse);
}
if(y_val<=127){
 sign_y=1;
 y_val=map(y_val,0,128,range_mouse,0);
}
if(y_val>127){
 y_val=y_val-127;
 y_val=map(y_val,0,128,0,range_mouse);
}

if(sign_x==1){x_val=x_val*-1;}
if(sign_y==1){y_val=y_val*-1;}

Serial.println(y_val);

Mouse.move(x_val,y_val,0); //mouse wheel in 0

}

void bk7mousepress(uint16_t key){
if(Mouse_flaginit==0){ //si no esta inicializado lo inicializa
    Mouse.begin();
    Mouse_flaginit = 1;
}
 Mouse.press(key);
}

void bk7mouserelease(uint16_t key){
if(Mouse_flaginit==0){ //si no esta inicializado lo inicializa
    Mouse.begin();
    Mouse_flaginit = 1;
}
 Mouse.release(key);
}

void bk7mouseend(void){
Mouse.end();
}




