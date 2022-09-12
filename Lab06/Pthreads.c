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

float EM_VECTORS[row];
float EM_MATRIX[row][Dcolumns];
float EM_EM2[row][Dcolumns2];

int menu(){
  system("clear");
  int opt;
  printf("                              MENU\n\n1 - Multiplicação de uma matriz esparsa por um vetor denso\n2 - Multiplicação de uma matriz esparsa por outra matriz esparsa\n3 - Multiplicação de uma matriz esparsa por uma matriz densa \n4 - Sair\n\nopt: ");
  scanf("%d", &opt);
  return opt;

}

void *Vector_X_EM(void *threadid){	
	int i = *(int*)threadid;
	float sum;
	int j;
	for (j = 0, sum = 0; ME[i][j].indice!=0; j++)
		sum += ME[i][j].valor*VETOR[ME[i][j].indice-1];
	EM_VECTORS[i]=sum;
	pthread_exit(NULL);
}

void *EM_X_DM(void *threadid){
	int i = *(int*)threadid;
	int j, k; 
	float sum;

	for ( j = 0; j < Dcolumns; j++){
		for ( k = 0, sum = 0; ME[i][k].indice!=0; k++)
			sum+=ME[i][k].valor*MD[ME[i][k].indice-1][j];
		EM_MATRIX[i][j]=sum;
	}

	pthread_exit(NULL);
}

