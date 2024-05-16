#include "tm4c123gh6pm.h"
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <lcd.h>
void delay(long d)
{
   while(d--);
}

void Printdata(uint8_t data)
{
    // data = 8 bit hexadecimal data
  if ((data&0x01) ==0x01)
    GPIO_PORTA_DATA_R |= 0x80;
  else
    GPIO_PORTA_DATA_R &= ~0x80;

  if ((data &0x02) ==0x02)
    GPIO_PORTA_DATA_R |= 0x40;
  else
    GPIO_PORTA_DATA_R &= ~0x40;

  if ((data &0x04)==0x04)
    GPIO_PORTA_DATA_R |= 0x20;
  else
    GPIO_PORTA_DATA_R &= ~0x20;

  if ((data &0x08) ==0x08)
    GPIO_PORTB_DATA_R |= 0x10;
  else
    GPIO_PORTB_DATA_R &= ~0x10;

  if ((data &0x10) ==0x10)
    GPIO_PORTE_DATA_R |= 0x20;
  else
    GPIO_PORTE_DATA_R &= ~0x20;

  if ((data &0x20) ==0x20)
    GPIO_PORTE_DATA_R |= 0x10;
  else
    GPIO_PORTE_DATA_R &= ~0x10;

  if ((data &0x40) ==0x40)
    GPIO_PORTB_DATA_R |= 0x02;
  else
    GPIO_PORTB_DATA_R &= ~0x02;

  if ((data &0x80) ==0x80)
    GPIO_PORTB_DATA_R |= 0x01;
  else
    GPIO_PORTB_DATA_R &= ~0x01;
}

void LCD_CMD(uint8_t cmd)
{

    Printdata(cmd);                  //pass the 8bit data in the datalines of lcd
    GPIO_PORTD_DATA_R &= ~ 0x02 ;    //turn off the R/W pin for write operation in lcd
    GPIO_PORTD_DATA_R &= ~ 0x01;     //turn off the RS for writing to the instruction register of lcd
    GPIO_PORTD_DATA_R |= 0x04;       //turn on the En of lcd for enabling the clock of lcd
    delay(10000);                    //wait for sometime
    GPIO_PORTD_DATA_R &=~ 0x04;      //Turn off the En of lcd
}

void LCD_Init(void)
{

    SYSCTL_RCGCGPIO_R |= 0x1B;
    while((SYSCTL_PRGPIO_R & 0x0001)==0);

    GPIO_PORTA_DEN_R  |= 0xE0;
    GPIO_PORTB_DEN_R  |= 0x13;
    GPIO_PORTD_DEN_R  |= 0x07;
    GPIO_PORTE_DEN_R  |= 0x30;

    GPIO_PORTA_DIR_R  |= 0xE0;
    GPIO_PORTB_DIR_R  |= 0x13;
    GPIO_PORTD_DIR_R  |= 0x07;
    GPIO_PORTE_DIR_R  |= 0x30;
    LCD_CMD(0x38); //8bit mode utilising 16 columns and 2 rows
    LCD_CMD(0x06); // autoincrementing the cursor when prints the data in current
    LCD_CMD(0x0C); //cursor off and display on
    LCD_CMD(0x01); //clearscreen
}


void LCD_SendChar(uint8_t data)
{
    Printdata(data);                  //pass the data in the datalines of lcd
    GPIO_PORTD_DATA_R &= ~ 0x02 ;    //turn off the R/W pin for write operation in lcd
    GPIO_PORTD_DATA_R |= 0x01;      //turn on the RS for writing to the data register of lcd
    GPIO_PORTD_DATA_R |= 0x04;     //turn on the En of lcd for enabling the clock of lcd
    delay(10000);                            //wait for sometime
    GPIO_PORTD_DATA_R &=~ 0x04;             //Turn off the En of lcd
}

void LCD_SendString(uint8_t *str ,uint8_t len)
{
    uint8_t i;
   for (i=0;i<len;i++){
    LCD_SendChar(str[i]);
     }
}
