#include<stdio.h>
int main(void)
{
    float vmain[3];
    float ler3numeros (float vetor[]);

    ler3numeros (vmain);

    printf("\n%.1f", vmain[0]);
    printf("\n%.1f", vmain[1]);
    printf("\n%.1f", vmain[2]);

    return 0;
}

    float ler3numeros (float vetor[])
    {
            printf("Digite um numero: ");
            scanf("%f", &vetor[0]);
            printf("Digite um numero: ");
            scanf("%f", &vetor[1]);
            printf("Digite um numero: ");
            scanf("%f", &vetor[2]);
    }
