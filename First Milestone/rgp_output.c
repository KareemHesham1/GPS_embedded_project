// mahmoud hesham mahmoud 
#include"tm4c123gh6pm.h"
#include"rgp_output.h"
void rgp_output(unsigned char data)
{
	GPIO_PORTF_DATA_R&=~0x0E;
	GPIO_PORTF_DATA_R|=data;
}
