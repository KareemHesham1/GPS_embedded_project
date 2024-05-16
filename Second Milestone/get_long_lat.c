#include "tm4c123gh6pm.h"
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_long_lat.h"

void lat_1 ()
{
     if(strcmp(splited[4],"N")==0)
        {
             current_lat=atof(splited[3]);
        }
        else
        {
              current_lat=-1*(atof(splited[3]));
        }


}
void lat_2 ()
{
     if(strcmp(splited[4],"N")==0)
        {
             next_lat=atof(splited[3]);
        }
        else
        {
              next_lat=-1*(atof(splited[3]));
        }


}
void long_1()
{
      if(strcmp(splited[6],"E")==0)
            {
             current_long=(atof(splited[5]));
        }
        else
        {
             current_long=-1*(atof(splited[5]));
        }
}
void long_2()
{
      if(strcmp(splited[6],"E")==0)
            {
             next_long=(atof(splited[5]));
        }
        else
        {
             next_long=-1*(atof(splited[5]));
        }
}
