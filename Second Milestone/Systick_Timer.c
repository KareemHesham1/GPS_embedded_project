#include "tm4c123gh6pm.h"
#include "string.h"
#include "stdint.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdio.h"


// systick timer

void systick_init(void)
{
    NVIC_ST_CTRL_R = 0X00;
    NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;

    NVIC_ST_CURRENT_R = 0X00;
    NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE | NVIC_ST_CTRL_CLK_SRC ;
}

void systick_wait_1s(void)
{
    NVIC_ST_RELOAD_R = (16000000) - 1;
    NVIC_ST_CURRENT_R = 0X00;
    while ((NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT) == 0x00){}
}

void systick_wait_1ms(void)
{
    NVIC_ST_RELOAD_R = (16000) - 1;
    NVIC_ST_CURRENT_R = 0X00;
    while ((NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT) == 0x00) {}
}

void delay_IN_ms(int total)
{
    int i;
    for (i = 0; i < total; i++)
    {
        systick_wait_1ms();
    }
}
