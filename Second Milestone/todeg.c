#include "tm4c123gh6pm.h"
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "todeg.h"

float todeg(float angle){
  float degree=(float)angle/100;
  float minutes =angle-(float)degree*100;
  return(degree+(minutes/60));
}
