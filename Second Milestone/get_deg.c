#include "tm4c123gh6pm.h"
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_deg.h"

char lattt[15]={0};
char longgg[15]={0};

void get_deg(uint32_t latt ,uint32_t longg){
  float rad_lat=todeg(((float)(float)latt/100000))+0.0258888+0.000424-0.0012263;
  float rad_long=todeg((float)((float)longg/100000))+0.1109375+0.0002852+0.0010712;
  sprintf(lattt,"%.*f",7,rad_lat);
  sprintf(longgg,"%.*f",7,rad_long);
  UART0_printf(lattt);
  UART0_printf(",");
  UART0_printf(longgg);
  UART0_printf("\n");
}
