 /*
*
* LED.h
*
* Copyright 2014 IPSUM <contacto@ipsumss.com>
*
* This library is free software; you can REDistribute it and/or
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* 14/08/14 Mexico.
*
*/

#ifndef LED_H //if not define

        #define LED_H  //defines header name

        #include "WireBK.h"
        #define SLAVE_ADDRESS_LED 0b1110110

        //pre-define RGB colors for Color function
		#define BLACK 0,0,0
        #define WHITE 255,255,255
        #define RED 255,0,0
        #define GREEN 0,255,0
        #define BLUE 0,0,255
        #define YELLOW 220,110,5
        #define AQUA 0,255,255
        #define MAGENTA 255,0,255
        #define GRAY 128,128,128
        #define OLIVE 128,128,0
        #define LIME 0,128,0
        #define PURPLE 128,0,128
        #define TEAL 0,128,128
        #define NAVY 0,0,128
        #define ORANGE 255,69,0
        #define PINK 255,20,147
        #define BROWN 139,69,19

		#define MODE_1 0x00,0x89			//Defines Mode Register 1 with Bit[3]=1 (so the led driver responds to subaddress1-SUB1)
		#define CURRENT_DEFAULT 0x43,0x14	//Defines IREFALL register a gain output value
		#define INITIALIZE0 0x02,0xAA		//Defines LEDOUT0 register with individual PWM configuration
        #define INITIALIZE1 0x03,0xAA		//Defines LEDOUT1 register with individual PWM configuration
		#define INITIALIZE2 0x04,0xAA		//Defines LEDOUT2 register with individual PWM configuration
		#define INITIALIZE3 0x05,0xAA		//Defines LEDOUT3 register with individual PWM configuration

        #define MODE_2      0x01     //define Mode 2 address register which includes test bits, to start FAULTEST write 1  to MODE2[6]
        #define IREFALL 0x43    //define IREFALL address register for brightness control
        #define EFLAG0   0x44    //define the register of error flag 0
        #define EFLAG1   0x45    //define the register of error flag 1
        #define FAULTTEST   0x45    //define the data to start the faulttest

        #define ADDR_LED1_R 0X0C    //PWM2
        #define ADDR_LED1_G 0X0B    //PWM1
        #define ADDR_LED1_B 0X0A    //PWM0

		#define ADDR_LED2_R 0X0F    //PWM5
        #define ADDR_LED2_G 0X0E    //PWM4
        #define ADDR_LED2_B 0X0D    //PWM3

		#define ADDR_LED3_R 0X12    //PWM8
        #define ADDR_LED3_G 0X11    //PWM7
        #define ADDR_LED3_B 0X10    //PWM6

		#define ADDR_LED4_R 0X15    //PWM11
        #define ADDR_LED4_G 0X14    //PWM10
        #define ADDR_LED4_B 0X13    //PWM9

		#define ADDR_LED5_R 0X18    //PWM14
        #define ADDR_LED5_G 0X17    //PWM13
        #define ADDR_LED5_B 0X16    //PWM12



        class ledsbk   //opens LedsBK Class
            {

            public:  //to be used outside the class
                     ledsbk(uint8_t pin);  //constructor where it is declared the enable pin
					 void color(uint8_t LED_number, uint8_t R, uint8_t G, uint8_t B); //sends a set of colors to a specific LED
					 void color(uint8_t R, uint8_t G, uint8_t B); //set the same color to all LEDs
					 void brightness(uint8_t brightness_intensity); //Modifies general gain output current value
					 uint8_t error;
            private:  //variables and functions used only inside this class
                     void LedsBegin();		//initialize registers MODE_1, IREFALL, and LEDOUTx with default values
                     int test();
                     uint8_t constructor_created;  //para saber si se creo un constructor
                     uint8_t _port;  //declares a variable for the enable pin

            };    //closes class


#endif  //end define

