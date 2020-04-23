#include "fonctions.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>



void printSolution(int *Array, int size, char piece){
  for (int i = 0; i < size; ++i){
    for (int j = 0; j < size; ++j){
      if(j == Array[i]){
        printf(" %c ", piece);
      }
      else{
        printf(" x ");
      }
    }
    printf("\n");
  }
}

void SaveSolution(char *filename, int *Array, int size, char piece){
  FILE *fp;
  int i = 0;

  fp=fopen(filename,"a");

  for (int i = 0; i < size; ++i){
      for (int j = 0; j < size; ++j){
        if(j == Array[i]){
          fprintf(fp," %c ", piece);
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

bool queenIsSafe(int *Array, int x, int y, int size){
  int i = 0;
  while (i < size){
    if(Array[i] > -1){
      if (x == i || y == Array[i] || ( abs(x - i) == abs(y - Array[i]) ) ){
        return false;
      }
    }
    i++;
  }
  return true;
}

bool bishopIsSafe(int *Array, int x, int y, int size){
  int i = 0;
  while (i < size){
    if(Array[i] > -1){
      if (( abs(x - Array[i]/10) == abs(y - Array[i]%10) ) ){
        return false;
      }
    }
    i++;
  }
  return true;
}

bool kingIsSafe(int *Array, int x, int y, int size){
  int i = 0;
  while (i < size){
    if(Array[i] > -1){
      if ( pow( (Array[i]/10) - x, 2) + pow( (Array[i]%10) - y, 2) <= 2 ){
        return false;
      }
    }
    i++;
  }
  return true;
}

bool knightIsSafe(int *Array, int x, int y, int size){
  int i = 0;
  while (i < size){
    if(Array[i] > -1){
      if ( pow( (Array[i]/10) - x, 2) + pow( (Array[i]%10) - y, 2) == 5 && (Array[i]/10 == x && Array[i]%10 == y)){
        return false;
      }
    }
    i++;
  }
  return true;
}

void search(int *Array, int size, int y, char piece, char *filename){
  if (y >= size){
    SaveSolution(filename, Array, size, piece);
  }
  else{
    for (int i = 0; i < size; ++i){
      if(queenIsSafe(Array, y, i, size)){
        Array[y] = i;
        search(Array, size, y+1, piece, filename);
        Array[y] = -1;
      }
    }
  }
}



void searchO(int *Array, int size, int chessSize, int nbSol, int x, int y, char piece, char *filename, bool isSafe(int*, int, int, int)){
  if (nbSol == size){
    //printf("nbsol:%d size:%d",nbSol,size);
    for (int i = 0; i < size; i++){
      printf("%i ", Array[i]);
    }
    //getchar();
    SaveSolutionO(filename, Array, chessSize, piece);
  }
  else{
    if( y >= chessSize) {
      y = 0;
      x++;
    }
    //printf("x : %i, y : %i\n", x, y);
    //getchar();
    if( x < chessSize ) {
      if( isSafe(Array, x, y, nbSol)){
        
        Array[nbSol] = (x*10)+y;
        //printf("Solution:(%d,%d) - nbSol:%d \n", x,y, nbSol+1);

        searchO(Array, size, chessSize, nbSol+1, x, y+1, piece, filename, isSafe);
        Array[nbSol] = -1;
      }
      searchO(Array, size, chessSize, nbSol, x, y+1, piece, filename, isSafe);
    }
  }
}

void SaveSolutionO(char *filename, int *Array, int size, char piece){
  FILE *fp;
  int i = 0;

  fp=fopen(filename,"a");

  for (int i = 0; i < size; ++i){
      for (int j = 0; j < size; ++j){
        if(j == Array[j]%10 && i == Array[i]/10){
          fprintf(fp," %c ", piece);
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

