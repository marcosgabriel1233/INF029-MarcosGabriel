#include<stdio.h>

float soma(float a, float b);
float subtrai(float a, float b);
float multiplica(float resultado1, float resultado2);

int main()
{
  float a, b;
  
  printf("Digite o primeiro numero: ");
  scanf("%f", &a);
  printf("Digite o segundo numero: ");
  scanf("%f", &b);

  float resultado1 = soma(a, b);
  float resultado2 = subtrai(a, b);
  float resultado3 = multiplica(resultado1, resultado2);
    
  printf("A soma eh: %.2f\n", resultado1);
  printf("A subtracao eh: %.2f\n", resultado2);
  printf("A multiplicao do resultado da soma e subtracao eh: %.2f\n", resultado3);

}

float soma(float a, float b)
{
  float resultado1 = a + b;

  return resultado1;
}

float subtrai(float a, float b)
{
  float resultado2 = a - b;

  return resultado2;
}

float multiplica(float resultado1, float resultado2)
{
  float resultado3 = (resultado1 * resultado2);

  return resultado3;
}