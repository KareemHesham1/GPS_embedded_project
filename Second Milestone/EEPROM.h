#include "tm4c123gh6pm.h"
#include "tm4c123gh6pm.h"
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void EEPROMINIT(void);
void EEPROM_Write(uint32_t address, uint32_t data);
uint32_t EEPROM_Read(uint32_t address);
