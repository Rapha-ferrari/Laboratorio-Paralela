#include <stdio.h>
#include <math.h>
double f(double x);
int main()
{
  // Declaração de variáveis.
  int i;
  int n = 0;      // Número de partições.
  double a, b;    // Limites do intervalo de integração.
  double sum = 0; // Valor do integral.
  double h;// Altura.
  // Entrada de dados.
  printf("Este programa calcula o integral no intervalo [a,b]\n");
  printf("Introduza limite inferior a = PI\n ");
  //Atribuindo o Valor PI para Variável "a"
  a = M_PI;
  printf("Introduza limite superior b (b>a) = ");
  scanf("%lf", &b);
  //Manipullação da Variável "b" Conforme Exercicio Proposto
  b = (5 * M_PI)/2 - b;
  printf("Introduza número de partições do intervalo (n>1) n = ");
  scanf("%d", &n);
  // Calcular dimensão de cada partição.
  h = (b - a) / n ;
  printf("Valor de h: %f\n",h);
  // Ciclo de cálculo.
  for (i = 0; i < n; i++)
  {
    sum = sum + (f(a) + f((a + h)))*h/2;
    a = a + h;
  }
 printf("\n");
  // Escrita do resultado.
  printf("O resultado da soma e': %lf\n", sum);
} // end main()

// Função a integrar.
double f(double x)
{
  return  sqrt(1+ sin(x)*sin(x));


}
