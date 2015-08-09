#include "Briko.h"


byte motor_flag_usb=1;  //bandera para detectar el usb

int16_t var_blink=0; //variable para hacer el blink en el pause
bool state_blink=0;

//////funcion de pausa/////////
void pause(void){
///reset///////////////
//detachInterrupt(4);
wdt_enable(WDTO_250MS);  // reset after one second, if no "pat the dog" received
while(1){};
}

//////funcion de pausa/////////
void blink_pause(void){
var_blink=var_blink+1;
if(var_blink>=200){
bk7led(state_blink^=1);
var_blink=0;
}
delay(1);
}

void setup(){

///desabilita el watchdog
wdt_disable ();  // reset after one second, if no "pat the dog" received
///para detectra si esta conectado a pila o usb
  UEINTX &= ~0b11111111; // Hace cero registro de banderas
  delay(900);  // Wait at least 900ms or else the UEINTX always reads TRUE

  if ((UEINTX & 0b00000001) ){ // checa TXINI - Transmitter Ready Interrupt Flag
        // USB CONNECTED
        motor_flag_usb = 1;
    }
  else {
      // Battery CONNECTED
      motor_flag_usb = 0;
    }

///activa interrupcion y funcion para parar todo(pause mode)
pinMode(7,INPUT_PULLUP);

///*****Agregar aqui modulos extra para que se apaguen con el pause***///
////multiplexor habilita//////////////
Wire.begin();  // join i2c bus
Wire.beginTransmission(0x70);
Wire.write(0b11111111); //habilita todas las salidas
Wire.endTransmission();
///apaga motor//////////////////
writeBK(0x5E,0X02,0);
///apaga buzzer//////////////////
writeBK(0x5F,0x01,0);
///apaga LEDS//////////////////
writeBK(0b1110110,0x00,0x89);
writeBK(0b1110110,0x02,0xAA);
writeBK(0b1110110,0x03,0xAA);
writeBK(0b1110110,0x04,0xAA);
writeBK(0b1110110,0x05,0xAA);
writeBK(0b1110110,0x43,0x14);
writeBK(0b1110110,0X0C,0);
writeBK(0b1110110,0X0B,0);
writeBK(0b1110110,0X0A,0);
writeBK(0b1110110,0X0F,0);
writeBK(0b1110110,0X0E,0);
writeBK(0b1110110,0X0D,0);
writeBK(0b1110110,0X12,0);
writeBK(0b1110110,0X11,0);
writeBK(0b1110110,0X10,0);
writeBK(0b1110110,0X15,0);
writeBK(0b1110110,0X14,0);
writeBK(0b1110110,0X13,0);
writeBK(0b1110110,0X18,0);
writeBK(0b1110110,0X17,0);
writeBK(0b1110110,0X16,0);
///apaga Display//////////////////
Wire.beginTransmission(0x3D); //Begin transmission to desired address
Wire.write(1);  //select register
Wire.write(0);     //address to a register where the information will be written
Wire.write(0);     //address to a register where the information will be written
Wire.write(0);     //address to a register where the information will be written
Wire.write(0);     //address to a register where the information will be written
Wire.write(0);     //address to a register where the information will be written
Wire.endTransmission();     // stop transmitting
Wire.beginTransmission(SLAVE_ADDRESS_DISPLAY); //Begin transmission to desired address
Wire.write(REGISTER_DISPLAY_1_bytes);  //select register
Wire.write(5);     //address to a register where the information will be written
Wire.write(0b00000000);     //address to a register where the information will be written
Wire.endTransmission();     // stop transmitting
///apaga relay//////////////////
writeBK(0x6E,0X01,0);
///multiplexor apagar//////////////
Wire.beginTransmission(0x70);
Wire.write(0b00000000); //habilita todas las salidas
Wire.endTransmission();

while(digitalRead(7)==0){blink_pause();}  //se espera a que libere el switch
attachInterrupt(4, pause, FALLING); //activa interrupcion

bk7led(0); ///apaga led

}   //para quitar el setup de el ide, lo corres aqui para no modificar por ahora el main el ide.





