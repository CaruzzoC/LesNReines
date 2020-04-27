#include "fonctions.h"

/**
*   PrintSolution(pointeur vers une liste, taille du plateau, symbole de la piece)
*
* int *Array - Il s'agit du pointeur vers une liste dont la taille est égale au maximum
* de pièce posable dans un plateau de n*n
* int size - La taille de plateau (n)
* char piece - symbole de la pièce (Q,B,K,k)
*
* Cette fonction sert à afficher une matrice, en fonction d'une liste passé en paramètre.
* Cette fonction a été disigné pour la structure de donnée de la reine.
**/
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

/**
*   SaveSolution(string nom du fichier, pointeur vers une liste, taille du plateau/liste, symbole de la piece)
*
* char *filename - C'est un pointeur vers le premier charater d'un String. le String
* doit être représentatif des solutions stockée.
* int *Array - Il s'agit du pointeur vers une liste dont la taille est égale au maximum
* de pièce posable dans un plateau de n*n
* int size - La taille de plateau/liste (n)
* char piece - symbole de la pièce (Q,B,K,k)
*
* Cette Fonction sauvegarde dans un fichier la matrice corespondante à la liste passé en paramètre.
* Cette fonction a été disigné pour la structure de donnée de la reine.
**/
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

/**
*   queenIsSafe(pointeur vers une liste, coordonée x, coordonée y, taille du plateau/liste)
*
* int *Array - Il s'agit du pointeur vers une liste dont la taille est égale au maximum
* de pièce posable dans un plateau de n*n
* int x - représente la coordonée des abscisse dans un plan
* int y - représente la coordonnée des ordonnées dans un plan
* int size - La taille de plateau/liste (n)
*
* Cette fonction vérifie si une reine peut être posé aux coordonnées passé en paramètre en fonction
* des reines qui sont déjà dans la liste
**/
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

/**
*   bishopIsSafe(pointeur vers une liste, coordonée x, coordonée y, taille de la liste)
*
* int *Array - Il s'agit du pointeur vers une liste dont la taille est égale au maximum
* de pièce posable dans un plateau de n*n
* int x - représente la coordonée des abscisse dans un plan
* int y - représente la coordonnée des ordonnées dans un plan
* int size - La taille de la liste
*
* Cette fonction vérifie si un fou peut être posé aux coordonnées passé en paramètre en fonction
* des fous qui sont déjà dans la liste
**/
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

/**
*   kingIsSafe(pointeur vers une liste, coordonée x, coordonée y, taille de la liste)
*
* int *Array - Il s'agit du pointeur vers une liste dont la taille est égale au maximum
* de pièce posable dans un plateau de n*n
* int x - représente la coordonée des abscisse dans un plan
* int y - représente la coordonnée des ordonnées dans un plan
* int size - La taille de la liste
*
* Cette fonction vérifie si un roi peut être posé aux coordonnées passé en paramètre en fonction
* des rois qui sont déjà dans la liste
**/
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

/**
*   bishopIsSafe(pointeur vers une liste, coordonée x, coordonée y, taille de la liste)
*
* int *Array - Il s'agit du pointeur vers une liste dont la taille est égale au maximum
* de pièce posable dans un plateau de n*n
* int x - représente la coordonée des abscisse dans un plan
* int y - représente la coordonnée des ordonnées dans un plan
* int size - La taille de la liste
*
* Cette fonction vérifie si un cavalier peut être posé aux coordonnées passé en paramètre en fonction
* des cavaliers qui sont déjà dans la liste
**/
bool knightIsSafe(int *Array, int x, int y, int size){
  int i = 0;
  while (i < size){
    if(Array[i] > -1){
      if ( ( pow( (Array[i]/10) - x, 2) + pow( (Array[i]%10) - y, 2) == 5 ) || (Array[i]/10 == x && Array[i]%10 == y)){
        return false;
      }
    }
    i++;
  }
  return true;
}

/**
*   searchQueen(pointeur vers une liste, taille du plateau/liste, coordonée y, symbole de la piece, string nom du fichier)
*
* int *Array - Il s'agit du pointeur vers une liste dont la taille est égale au maximum
* de pièce posable dans un plateau de n*n
* int size - La taille du plateau/liste (n)
* int y - représente la coordonnée des ordonnées dans un plan (doit être initialisé à 0 quand lancé)
* char piece - symbole de la pièce (Q,B,K,k)
* char *filename - C'est un pointeur vers le premier charater d'un String. le String
* doit être représentatif des solutions stockée.
*
* Cette fonction cherche de manière récursive toutes les solutions possible pour un plateau de taille size
* et sauvegarde les solutionss dans un fichier. Cette fonction a été disigné selon la structure de donnée 
* de la reine.
**/
void searchQueen(int *Array, int size, int y, char piece, char *filename){
  if (y >= size){
    SaveSolution(filename, Array, size, piece);
  }
  else{
    for (int i = 0; i < size; ++i){
      if(queenIsSafe(Array, y, i, size)){
        Array[y] = i;
        searchQueen(Array, size, y+1, piece, filename);
        Array[y] = -1;
      }
    }
  }
}

/**
*   searchOther(pointeur vers une liste, taille de la liste, taille du plateau, nombre de solution actuel, coordonée x, coordonée y,
*               symbole de la piece, string nom du fichier, fonction isSafe(...))
*
* int *Array - Il s'agit du pointeur vers une liste dont la taille est égale au maximum
* de pièce posable dans un plateau de n*n
* int size - La taille de la liste
* int chessSize - La taille du plateau (n)
* int nbSol - nombre de solution actuellment trouvé
* int x - représente la coordonée des abscisse dans un plan
* int y - représente la coordonnée des ordonnées dans un plan (doit être initialisé à 0 quand lancé)
* char piece - symbole de la pièce (Q,B,K,k)
* char *filename - C'est un pointeur vers le premier charater d'un String. le String
* doit être représentatif des solutions stockée.
* bool isSafe - Pointeur vers la fonction (à choisir en fonction de la pièce)
*
* Cette fonction cherche de manière récursive toutes les solutions possible pour un plateau de taille size
* et sauvegarde les solutionss dans un fichier. Cette fonction a été disigné selon la structure de donnée 
* du reste des pièces (roi,fou,cavalier). Elle ne fonctionne que pour un plateau < 10.
**/
void searchOther(int *Array, int size, int chessSize, int nbSol, int x, int y, char piece, char *filename, bool isSafe(int*, int, int, int)){
  if (nbSol == size){
    SaveSolutionOther(filename, Array, size, chessSize, piece);
  }
  else{
    if( y >= chessSize) {
      y = 0;
      x++;
    }
    if( x < chessSize ) {
      if( isSafe(Array, x, y, nbSol)){
        Array[nbSol] = (x*10)+y;
        searchOther(Array, size, chessSize, nbSol+1, x, y+1, piece, filename, isSafe);
        Array[nbSol] = -1;
      }
      searchOther(Array, size, chessSize, nbSol, x, y+1, piece, filename, isSafe);
    }
  }
}

/**
*   SaveSolutionOther(string nom du fichier, pointeur vers une liste, taille de la liste, taille du plateau symbole de la piece)
*
* char *filename - C'est un pointeur vers le premier charater d'un String. le String
* doit être représentatif des solutions stockée.
* int *Array - Il s'agit du pointeur vers une liste dont la taille est égale au maximum
* de pièce posable dans un plateau de n*n
* int size - La taille de plateau/liste (n)
* char piece - symbole de la pièce (Q,B,K,k)
*
* Cette Fonction sauvegarde dans un fichier la matrice corespondante à la liste passé en paramètre.
* Cette fonction a été designé pour la structure de donnée du reste des pièces (roi,fou,cavalier). Elle ne fonctionne que pour un plateau < 10.
**/
void SaveSolutionOther(char *filename, int *Array, int size, int chessSize, char piece){
  FILE *fp;
  int p = 0;
  fp=fopen(filename,"a");
  for (int i = 0; i < chessSize; ++i){
      for (int j = 0; j < chessSize; ++j){
        if(p < size && Array[p]/10 == i && Array[p]%10 == j){
          fprintf(fp," %c ", piece);
          p++;
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

