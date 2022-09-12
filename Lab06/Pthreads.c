#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define row 4 
#define columns 4 
#define Dcolumns 3 
#define Dcolumns2 3

typedef struct {
	int indice;
	float valor;
}node;

node ME[4][4] = {{{2, 1.0}, {4, 4.0}}, {{3, 2.0}, {4, 3.0}}, {{1, 3.0}, {2, 2.0}, {3, 5.0}}, {{1, 4.0}, {2, 1.0}}};

node ME2[4][3] = {{{3, 1.0}}, {{2, 2.0}, {3, 3.0}}, {{1, 3.0}, {3, 2.0}}, {{1, 4.0}, {2, 1.0}}};

float VETOR[4] = {1.0, 2.0, 3.0, 4.0};

float MD[4][3] = {{0, 1, 2}, {3, 2, 1}, {2, 4, 2}, {3, 6, 2}};
