/*
*
* Display.cpp
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

//include headers files
#include "Display.h"

displaybk::displaybk(uint8_t port_number)        //declare constructor
{
  _port = port_number;     //pin is stored in private variable _pin
  Wire.begin();  // join i2c bus
}

void displaybk::erase()       // Function to erase all displays
{
    uint8_t Array_segments[5] = {0,0,0,0,0};  //inicializa en 0

    portEnable(_port);
    Wire.beginTransmission(SLAVE_ADDRESS_DISPLAY); //Begin transmission to desired address
    Wire.write(REGISTER_DISPLAY_5_bytes);  //select register
    Wire.write(Array_segments[0]);     //address to a register where the information will be written
    Wire.write(Array_segments[1]);     //address to a register where the information will be written
    Wire.write(Array_segments[2]);     //address to a register where the information will be written
    Wire.write(Array_segments[3]);     //address to a register where the information will be written
    Wire.write(Array_segments[4]);     //address to a register where the information will be written
    Wire.endTransmission();     // stop transmitting
    portEnable(0);
}

void displaybk::erase(uint8_t n)       // Function to erase one digit
{
    if (n>=1 && n<=5){
        portEnable(_port);
        Wire.beginTransmission(SLAVE_ADDRESS_DISPLAY); //Begin transmission to desired address
        Wire.write(REGISTER_DISPLAY_1_bytes);  //select register
        Wire.write(n);     //address to a register where the information will be written
        Wire.write(0);     //address to a register where the information will be written
        Wire.endTransmission();     // stop transmitting
        portEnable(0);
    }
}

void displaybk::printcustom(uint8_t n, uint8_t segments)    //print the segements indicated in the segments variable of the n digit
{
    if (n>=1 && n<=5){
        portEnable(_port);
        Wire.beginTransmission(SLAVE_ADDRESS_DISPLAY); //Begin transmission to desired address
        Wire.write(REGISTER_DISPLAY_1_bytes);  //select register
        Wire.write(n);     //address to a register where the information will be written
        Wire.write(segments);     //address to a register where the information will be written
        Wire.endTransmission();     // stop transmitting
        portEnable(0);
    }
}

void displaybk::printindividual(uint8_t n, uint8_t num)   //function to display a number in an specific digit
{
    if (num>9){//if the number to be displayed is bigger than 9
        num=9;//sets number value as 9
    }
    if (n>=1 && n<=4){
        portEnable(_port);
        Wire.beginTransmission(SLAVE_ADDRESS_DISPLAY); //Begin transmission to desired address
        Wire.write(REGISTER_DISPLAY_1_bytes);  //select register
        Wire.write(n);     //address to a register where the information will be written
        Wire.write(Number2byte(num));     //address to a register where the information will be written
        Wire.endTransmission();     // stop transmitting
        portEnable(0);
    }
}

void displaybk::print(int16_t num)    //print integer function
{
    bool sign = 0;
    uint8_t cont=0;
    int16_t temp_num=0;
    uint8_t digit_num = 0;
    uint8_t Array[5] = {0,0,0,0,0};  //inicializa en 0
    uint8_t Array_segments[5] = {0,0,0,0,0};  //inicializa en 0

    ///seguridad

    if(num>9999){   //if the number is higher than the maximum possible value
        num=9999;   //the number will be set as the
    }

    if(num<0){  //if number is negative turn zeroflag on
        sign = 1;
        num=abs(num);
        if(num>999){    //if absolute value number is bigger than 999 set it as 999
            num=999;
        }
    }

    ///divide los digitos y guarda cuantos son

    temp_num=num;  //actualiza el valor

    for(cont=4;cont>0;cont--){
       Array[cont] = temp_num%10;
       if(temp_num !=0){
       temp_num= (int16_t)(temp_num/10);
       }
    }

    if(num>999){ digit_num = 4;}
    if(num>99 && num<=999){ digit_num = 3;}
    if(num>9 && num<=99){ digit_num = 2;}
    if(num<=9){ digit_num = 1;}

    ///crea los bytes del display

    for(cont=4;cont>(4-digit_num);cont--){  ///no incluye el byte de los puntos(deja en 0 los que no hay que prender)
    Array_segments[cont] = Number2byte(Array[cont]);
    }

    ///si era negativo agrega el signo
    if(sign == 1){  //negativo
    Array_segments[abs(4-digit_num)] = 0b01000000;  //signo de menos
    }

    ///manda todo
    portEnable(_port);
    Wire.beginTransmission(SLAVE_ADDRESS_DISPLAY); //Begin transmission to desired address
    Wire.write(REGISTER_DISPLAY_5_bytes);  //select register
    Wire.write(Array_segments[1]);     //address to a register where the information will be written
    Wire.write(Array_segments[2]);     //address to a register where the information will be written
    Wire.write(Array_segments[3]);     //address to a register where the information will be written
    Wire.write(Array_segments[4]);     //address to a register where the information will be written
    Wire.write(Array_segments[0]);     //address to a register where the information will be written
    Wire.endTransmission();     // stop transmitting
    portEnable(0);

}

void displaybk::print(float num)
{

     bool sign = 0;
    uint8_t cont=0;
    int16_t temp_num=0;
    int16_t temp_num2=0;
    uint8_t digit_num = 0;
    uint8_t Array[5] = {0,0,0,0,0};  //inicializa en 0
    uint8_t Array_segments[5] = {0,0,0,0,0};  //inicializa en 0

    ///seguridad

    if(num>999.9){   //if the number is higher than the maximum possible value
        num=999.9;   //the number will be set as the
    }

    if(num<0){  //if number is negative turn zeroflag on
        sign = 1;
        num=abs(num);
        if(num>99.9){    //if absolute value number is bigger than 999 set it as 999
            num=99.9;
        }
    }

    ///divide los digitos y guarda cuantos son

    temp_num=num;  //actualiza el valor y quita decimales
    temp_num2=num;  //actualiza el valor y quita decimales

    for(cont=3;cont>0;cont--){
       Array[cont] = temp_num%10;
       if(temp_num !=0){
       temp_num= (int16_t)(temp_num/10);
       }
    }

    if(num>99.999 && num<=999.999){ digit_num = 3;}
    if(num>9.999 && num<=99.999){ digit_num = 2;}
    if(num<=9.999){ digit_num = 1;}

    ///crea los bytes del display

    for(cont=3;cont>(3-digit_num);cont--){  ///no incluye el byte de los puntos(deja en 0 los que no hay que prender)
    Array_segments[cont] = Number2byte(Array[cont]);
    }

    ///si era negativo agrega el signo
    if(sign == 1){  //negativo
    Array_segments[abs(3-digit_num)] = 0b01000000;  //signo de menos
    }

    ///saca decimal y agrega el punto decimal al numero anterior
    Array_segments[4] = Number2byte((uint8_t)((num-temp_num2 )*10.00));  //pone la parte decimal
    Array_segments[3] = Array_segments[3] | 0b10000000;  //pone el punto decimal en el tercer segmento

    ///manda todo
    portEnable(_port);
    Wire.beginTransmission(SLAVE_ADDRESS_DISPLAY); //Begin transmission to desired address
    Wire.write(REGISTER_DISPLAY_5_bytes);  //select register
    Wire.write(Array_segments[1]);     //address to a register where the information will be written
    Wire.write(Array_segments[2]);     //address to a register where the information will be written
    Wire.write(Array_segments[3]);     //address to a register where the information will be written
    Wire.write(Array_segments[4]);     //address to a register where the information will be written
    Wire.write(Array_segments[0]);     //address to a register where the information will be written
    Wire.endTransmission();     // stop transmitting
    portEnable(0);

}

void displaybk::print(double num)
{

     bool sign = 0;
    uint8_t cont=0;
    int16_t temp_num=0;
    int16_t temp_num2=0;
    uint8_t digit_num = 0;
    uint8_t Array[5] = {0,0,0,0,0};  //inicializa en 0
    uint8_t Array_segments[5] = {0,0,0,0,0};  //inicializa en 0

    ///seguridad

    if(num>999.9){   //if the number is higher than the maximum possible value
        num=999.9;   //the number will be set as the
    }

    if(num<0){  //if number is negative turn zeroflag on
        sign = 1;
        num=abs(num);
        if(num>99.9){    //if absolute value number is bigger than 999 set it as 999
            num=99.9;
        }
    }

    ///divide los digitos y guarda cuantos son

    temp_num=num;  //actualiza el valor y quita decimales
    temp_num2=num;  //actualiza el valor y quita decimales

    for(cont=3;cont>0;cont--){
       Array[cont] = temp_num%10;
       if(temp_num !=0){
       temp_num= (int16_t)(temp_num/10);
       }
    }

    if(num>99.999 && num<=999.999){ digit_num = 3;}
    if(num>9.999 && num<=99.999){ digit_num = 2;}
    if(num<=9.999){ digit_num = 1;}

    ///crea los bytes del display

    for(cont=3;cont>(3-digit_num);cont--){  ///no incluye el byte de los puntos(deja en 0 los que no hay que prender)
    Array_segments[cont] = Number2byte(Array[cont]);
    }

    ///si era negativo agrega el signo
    if(sign == 1){  //negativo
    Array_segments[abs(3-digit_num)] = 0b01000000;  //signo de menos
    }

    ///saca decimal y agrega el punto decimal al numero anterior
    Array_segments[4] = Number2byte((uint8_t)((num-temp_num2 )*10.00));  //pone la parte decimal
    Array_segments[3] = Array_segments[3] | 0b10000000;  //pone el punto decimal en el tercer segmento

    ///manda todo
    portEnable(_port);
    Wire.beginTransmission(SLAVE_ADDRESS_DISPLAY); //Begin transmission to desired address
    Wire.write(REGISTER_DISPLAY_5_bytes);  //select register
    Wire.write(Array_segments[1]);     //address to a register where the information will be written
    Wire.write(Array_segments[2]);     //address to a register where the information will be written
    Wire.write(Array_segments[3]);     //address to a register where the information will be written
    Wire.write(Array_segments[4]);     //address to a register where the information will be written
    Wire.write(Array_segments[0]);     //address to a register where the information will be written
    Wire.endTransmission();     // stop transmitting
    portEnable(0);

}

//////////////////locales////////////////
uint8_t displaybk::Number2byte(uint8_t Number_s){  //convierte decimal a su equivalente byte de leds para el display
    uint8_t Return_var = 0;

    switch(Number_s){
        case 0:
        Return_var = 0b00111111;
        break;

        case 1:
        Return_var = 0b00000110;
        break;

        case 2:
        Return_var = 0b01011011;
        break;

        case 3:
        Return_var = 0b01001111;
        break;

        case 4:
        Return_var = 0b01100110;
        break;

        case 5:
        Return_var = 0b01101101;
        break;

        case 6:
        Return_var = 0b01111101 ;
        break;

        case 7:
        Return_var = 0b00000111;
        break;

        case 8:
        Return_var = 0b01111111;
        break;

        case 9:
        Return_var = 0b01100111;
        break;

        default:  //nada
        break;
        }

        return(Return_var);

    }
