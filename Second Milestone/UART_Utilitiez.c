#include "tm4c123gh6pm.h"
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include <UART_Utilitiez.h>




void UART7_readstr(char* str){
    int i=0;
    char c;

while(1){
    int cuntrighr=0;
        c=UART7_read();

        if(c == '$'){
            cuntrighr++;
                    c=UART7_read();

                    if(c== 'G'){
                        cuntrighr++;
                        c=UART7_read();

                        if(c == 'P'){
                            cuntrighr++;
                            c=UART7_read();

                            if(c == 'R'){
                                cuntrighr++;
                                c=UART7_read();

                                if(c == 'M'){
                                    cuntrighr++;
                                    c=UART7_read();

                                    if(c == 'C'){
                                        cuntrighr++;
                                        while(1){

                                              c=UART7_read();

                                              if(c == 'A'){
                                                  cuntrighr++;
                                              }



        str[i]=c;
        i++;
        if (c== '\n' || c == '\r'||c=='*')
                   {break;}
                                    }
                                }
                            }
                        }
                    }
        }
    }
        if(cuntrighr==8)break;
}

}
void UART0_printf(char* str){

    while(*str){
        UART0_write(*str);
        str++;
    }
}
