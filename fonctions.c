#include "fonctions.h"
#include <stdlib.h>
#include <stdbool.h>

void printSolution(int *Array, int size){
  for (int i = 0; i < size; ++i){
    for (int j = 0; j < size; ++j){
      if(j == Array[i]){
        printf(" o ");
      }
      else{
        printf(" x ");
      }
    }
    printf("\n");
  }
}

void SaveSolution(char *filename, int *Array, int size){
  FILE *fp;
  int i = 0;

  fp=fopen(filename,"a");

  for (int i = 0; i < size; ++i){
      for (int j = 0; j < size; ++j){
        if(j == Array[i]){
          fprintf(fp," o ");
        }
        else{
          fprintf(fp," x ");
        }
      }
      fprintf(fp,"\n");
    }
  fprintf(fp,"\n");
  fclose(fp);

  printf("\n%s file created",filename);
}

bool queenIsSafe(int *Array, int y){
    
  return true;
}