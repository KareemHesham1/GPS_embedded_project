#include "tm4c123gh6pm.h"
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
void delay(long d);
void LCD_CMD(uint8_t cmd);
void LCD_Init(void);
void LCD_SendChar(uint8_t data);
void LCD_SendString(uint8_t *str ,uint8_t len);
