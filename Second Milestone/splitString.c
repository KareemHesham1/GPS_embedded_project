#include "tm4c123gh6pm.h"
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void splitString(char *inputString, char delimiter, char result[15][15]) {
  int i;
  int row = 0, col = 0;

  for (i = 0; inputString[i] != '\0'; i++) {
    if (inputString[i] != delimiter) {
      result[row][col++] = inputString[i];
    } else {
      result[row][col] = '\0'; // Null-terminate the string
      row++;
      col = 0;
    }
  }
  result[row][col] = '\0'; // Null-terminate the last string
}
