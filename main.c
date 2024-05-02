#include "tm4c123gh6pm.h"
#include<string.h>
#include<stdint.h>
#include <math.h>
#define CR 0x0D
#include <stdio.h>
#include <stdlib.h>
#include "init_sw1.c"
#include " IO.h"
#include "uart_init.h"
#include "uart_init.c"
#include "sw1_input.h"
#include "rgp_output.c"
#include "init_sw1.h"
#include "init_rgb.h"
int main()
{
 
	init_sw1();
	init_rgb();
	uart_init();
	float distance = 0;

	while(1)
	{
		char input_swtch= sw1_input();
		if( input_swtch == 0 || distance > 100){
		rgp_output(0x08);
			break;
		}
	}
}
