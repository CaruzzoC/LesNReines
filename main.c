#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main(void) {
  printf("Hello World\n");

  int Array[8] = {1,1,1,1,1,1,1,1};

  printSolution(Array, 8);

  SaveSolution("LesNReines", Array, 8);




  return 0;
}