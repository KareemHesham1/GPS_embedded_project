#include "tm4c123gh6pm.h"
#include "sw1_input.h"

unsigned char sw1_input(void)
{
	return GPIO_PORTF_DATA_R&0x10;
}
