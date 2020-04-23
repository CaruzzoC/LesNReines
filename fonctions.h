#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef FONCTIONS_H
#define FONCTIONS_H


void printSolution(int *Array, int size, char piece);

void SaveSolution(char *filename, int *Array, int size, char piece);
void SaveSolutionO(char *filename, int *Array, int size, char piece);

bool queenIsSafe(int *Array, int x, int y, int size);
bool bishopIsSafe(int *Array, int x, int y, int size);
bool kingIsSafe(int *Array, int x, int y, int size);

void search(int *Array, int size, int y, char piece, char *filename);
void searchO(int *Array, int size, int chessSize, int nbSol, int x, int y, char piece, char *filename, bool isSafe(int*, int, int, int));




#endif