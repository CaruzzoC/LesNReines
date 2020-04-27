#include "fonctions.h"

void isSafeTest(char *filename, bool isSafe(int*, int, int, int)){
  int k = 0;
  FILE *fp;
  int t, r, s, x, y;
  char b[1];
  fp=fopen(filename,"r");
  fscanf(fp, "%i", &t);
  r = t;
  while(t--){
    fscanf(fp, "%i %i", &x, &y);
    fscanf(fp, "%i", &s);
    int arr[s];
    for (int i = 0; i < s; i++){
      fscanf(fp, "%i", &arr[i]);
    }
    fscanf(fp, "%s", &b[0]);

    if (( b[0] == 'T' && isSafe(arr, x, y, s) ) || ( b[0] == 'F' && !isSafe(arr, x, y, s) )){
      k++;
      printf("%i | Test accepté\n", t+1);
    }
    else{
      printf("%i | Test refusé\n", t+1);
    }
  }
  printf("\nNombre de tests effectués : %i\nNombre de tests acceptés : %i\n", r, k);
  if (k == r){
      printf("\nLa fonction est correct");
    }
  else{
    printf("\nLa fonction est incorrect");
  }
  fclose(fp);
}