#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#ifndef FONCTIONS_H
#define FONCTIONS_H


void printSolution(int *Array, int size, char piece);

void SaveSolution(char *filename, int *Array, int size, char piece);
void SaveSolutionOther(char *filename, int *Array, int size, int chessSize, char piece);
void SaveSolutionKnight(char *filename, int *Array, int size, int chessSize, char piece);

bool queenIsSafe(int *Array, int x, int y, int size);
bool bishopIsSafe(int *Array, int x, int y, int size);
bool kingIsSafe(int *Array, int x, int y, int size);
bool knightIsSafe(int *Array, int x, int y, int size);

void searchQueen(int *Array, int size, int y, char piece, char *filename);
void searchOther(int *Array, int size, int chessSize, int nbSol, int x, int y, char piece, char *filename, bool isSafe(int*, int, int, int));
void isSafeTest(char *filename, bool isSafe(int*, int, int, int));


#endif