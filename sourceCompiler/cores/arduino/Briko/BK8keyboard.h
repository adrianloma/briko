/*
*
* BK8keyboard.h
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

#ifndef BK8keyboard_h
#define BK8keyboard_h

#include <Arduino.h>

///Este archivos usar el bk7 como keyboard o mouse.

/* comandos
Key	Hexadecimal value	Decimal value
KEY_LEFT_CTRL	0x80	128
KEY_LEFT_SHIFT	0x81	129
KEY_LEFT_ALT	0x82	130
KEY_LEFT_GUI	0x83	131
KEY_RIGHT_CTRL	0x84	132
KEY_RIGHT_SHIFT	0x85	133
KEY_RIGHT_ALT	0x86	134
KEY_RIGHT_GUI	0x87	135
KEY_UP_ARROW	0xDA	218
KEY_DOWN_ARROW	0xD9	217
KEY_LEFT_ARROW	0xD8	216
KEY_RIGHT_ARROW	0xD7	215
KEY_BACKSPACE	0xB2	178
KEY_TAB	0xB3	179
KEY_RETURN	0xB0	176
KEY_ESC	0xB1	177
KEY_INSERT	0xD1	209
KEY_DELETE	0xD4	212
KEY_PAGE_UP	0xD3	211
KEY_PAGE_DOWN	0xD6	214
KEY_HOME	0xD2	210
KEY_END	0xD5	213
KEY_CAPS_LOCK	0xC1	193
KEY_F1	0xC2	194
KEY_F2	0xC3	195
KEY_F3	0xC4	196
KEY_F4	0xC5	197
KEY_F5	0xC6	198
KEY_F6	0xC7	199
KEY_F7	0xC8	200
KEY_F8	0xC9	201
KEY_F9	0xCA	202
KEY_F10	0xCB	203
KEY_F11	0xCC	204
KEY_F12	0xCD	205


button: which mouse button to press - char

MOUSE_LEFT (default)
MOUSE_RIGHT
MOUSE_MIDDLE

*/

/////Funcion para escribir parrafos
void bk7keywrite(uint16_t KeyMessage);  //para mandar mensajes por serial
void bk7keywrite(char KeyMessage);  //para mandar mensajes por serial
void bk7keywrite(char *KeyMessage);  //para mandar mensajes por serial


/////Funcion para escribir parrafos con nueva linea
void bk7keyprint(uint16_t KeyMessage);  //para mandar mensajes por serial
void bk7keyprint(char KeyMessage);  //para mandar mensajes por serial
void bk7keyprint(char *KeyMessage);  //para mandar mensajes por serial

////funcion para presionar tecla
void bk7keypress(uint16_t key);
void bk7keypress(uint16_t key,uint16_t time);

////funcion para liberar la tecla o todas
void bk7keyrelease(uint16_t key);
void bk7keyreleaseall(void);

////funcion para liberar los recursos
void bk7keyend(void);

//funcion para usar los botones briko
void bk7keybuttons(uint16_t bits, uint16_t key1,uint16_t key2,uint16_t key3,uint16_t key4,uint16_t key5);
void bk7keybuttons(uint16_t bits, char *key1,char *key2,char *key3,char *key4,char *key5);

////funcion para dar click
void bk7mouseclick(uint16_t key);

////funcion para mover el cursor
void bk7mousemove(uint16_t x, uint16_t y);

////funcion para arrastrar
void bk7mousepress(uint16_t key);
void bk7mouserelease(uint16_t key);

////funcion para liberar los recursos
void bk7mouseend(void);

#endif

