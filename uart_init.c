#include "tm4c123gh6pm.h"
#include "uart_init.h"

void uart_init(void) {
	SYSCTL_RCGCUART_R|=0x0001;
	SYSCTL_RCGCGPIO_R|=0x0001;
	UART0_CTL_R&=~0x0001;
	UART0_IBRD_R=104;
  	UART0_FBRD_R=11;
	UART0_LCRH_R=0x0070;
	UART0_CTL_R=0x0301;
	GPIO_PORTA_AFSEL_R|=0x03;
	GPIO_PORTA_PCTL_R=(GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011;
	GPIO_PORTA_DEN_R|=0x03;
	GPIO_PORTA_AMSEL_R&=~0x03;
}
