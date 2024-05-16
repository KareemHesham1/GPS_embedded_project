#include "tm4c123gh6pm.h"
#include<string.h>
#include<stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_long_lat.h"


char test2[15]={0};
 char test[100]="";
    char splited[15][15]={0};
        float current_lat =0;
        float current_long=0;
        float next_lat=0;
        float next_long=0;

float distance =0;

int main(){
    portBInit();
    RGBInit ();
    systick_init();
    UART0Init();
    UART7Init();
    LCD_Init();
    EEPROMINIT();
    int counter_eeprom_write=0;
    int counter_eeprom_read=0;
    int lat=0;
    int loong=0;
    UART7_readstr(test);
    splitString(test,',',splited);
    lat =(float)atof(splited[3])*100000;
    EEPROM_Write(counter_eeprom_write,lat);
    counter_eeprom_write+=4;
    loong =(float)atof(splited[5])*100000;
    EEPROM_Write(counter_eeprom_write,loong);
    counter_eeprom_write+=4;
    LCD_CMD(0x80);
               LCD_SendString("DIS:",4);
               LCD_CMD(0xC0);
               LCD_SendString("0",1);
    lat_1();
      long_1();

    while(1){
    UART7_readstr(test);

    splitString(test,',',splited);

    lat_2();
        long_2();
        //sprintf(test2, "%.*f", 5, distance);
        //UART0_printf(test2);
        //UART0_printf("\n");
        if(get_distance(next_long,next_lat,current_long,current_lat)>3&&get_distance(next_long,next_lat,current_long,current_lat)<150){
            lat =(float)atof(splited[3])*100000;
                  EEPROM_Write(counter_eeprom_write,lat);
                  counter_eeprom_write+=4;
                  loong =(float)atof(splited[5])*100000;
                  EEPROM_Write(counter_eeprom_write,loong);
                  counter_eeprom_write+=4;
        distance=distance+get_distance(next_long,next_lat,current_long,current_lat);

            delay_IN_ms(500);
            sprintf(test2, "%.*f", 5, distance);
            LCD_CMD(0x80);
            LCD_SendString("DIS:",4);
            LCD_CMD(0xC0);
            LCD_SendString(test2,strlen(test2));
            lat_1();
            long_1();
            if(distance>100){
                LCD_CMD(0x80);
                           LCD_SendString("DIS:",4);
                           LCD_CMD(0xC0);
                           LCD_SendString("Arrived  ",9);
                GPIO_PORTF_DATA_R=0x04;
                       for( counter_eeprom_read=0;counter_eeprom_read <counter_eeprom_write ; counter_eeprom_read+=8){
                       get_deg(EEPROM_Read(counter_eeprom_read),EEPROM_Read(counter_eeprom_read+4));


                   }
                       GPIO_PORTF_DATA_R=0x08;
            while(1){

                UART0_printf(lattt);
                    UART0_printf(",");
                    UART0_printf(longgg);
                    UART0_printf("\n");

            }}
    }
    }}

