#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#endif // _OPENMP

void SerieTaylor(double ln, double* soma);

int main(int argc, char* argv[]) 
{
  double soma = 0;
  double ln = 1000;
  
  // caso queira ter a quantidade em tempo de execução:
  // int thread_count = strtol(argv[1], NULL, 10);
  int thread_count = 4;

  #pragma omp parallel num_threads(thread_count)
  SerieTaylor(ln, &soma);

  printf("ln(%d) = %f\n", (int) ln, soma);
  return 0;
}

// Função que utiliza OpenMP para calcular a soma da
// série de Taylor. O cálculo de início e fim pode ser
// utilizado com sucesso para qualquer divisor 
// do valor de x em ln(x). Exemplo:
// ln(1000) -> pode usar thread_count = 2, 4, 5, ...

void SerieTaylor(double ln, double* soma)
{
  #ifdef _OPENMP
  int my_rank = omp_get_thread_num();
  int thread_count = omp_get_num_threads();
  #else
  int my_rank = 0;
  int thread_count = 1;
  #endif // _OPENMP -> caso o compilador não o reconheça

  double inicio = (ln/thread_count)*my_rank + 1;
  double fim = inicio + (ln/thread_count) - 1;
  double soma_parcial, d;

  for (d = inicio; d <= fim; d++)
  {
    soma_parcial += 1/d;
  }
  
  *soma += soma_parcial;
}
