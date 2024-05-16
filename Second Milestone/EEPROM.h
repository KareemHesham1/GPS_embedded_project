#include "tm4c123gh6pm.h"

void EEPROMINIT(void);
void EEPROM_Write(uint32_t address, uint32_t data);
uint32_t EEPROM_Read(uint32_t address);
