#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"

int main(void) {
  printf("Hello World\n");


  int ArrayQ[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
  int ArrayB[14] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  int ArrayK[32] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};


  //printSolution(ArrayQ, 8, 'Q');

  //SaveSolution("LesNReines", ArrayQ, 8, 'Q');

  //printf("%d",queenIsSafe(ArrayQ, 0, 0, 8));

  
  //search(ArrayQ, 8, 0, 'Q', "LesNReines");
  searchO(ArrayB, 14, 8, 0, 0, 0, 'B', "LesNBishop",bishopIsSafe);

  
  //printf("%d",bishopIsSafe(ArrayB, 1, 7, 14));

  //printf("%d",kingIsSafe(ArrayK, 4, 4, 32));

  


}