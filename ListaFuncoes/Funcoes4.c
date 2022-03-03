#include<stdio.h>
int main(void)
{
    float vmain[3];
    vmain[0] = 0;
    vmain[1] = 1;
    vmain[2] = 2;
    float ler3numeros (float vetor[]);

    ler3numeros (vmain);

    printf("\n%.1f", vmain[0]);
    printf("\n%.1f", vmain[1]);
    printf("\n%.1f", vmain[2]);

    return 0;
}

    float ler3numeros (float vetor[])
    {
        vetor[0] = 3;
        vetor[1] = 4;
        vetor[2] = 5;
            printf("Digite um numero: ");
            scanf("%f", &vetor[0]);
            printf("Digite um numero: ");
            scanf("%f", &vetor[1]);
            printf("Digite um numero: ");
            scanf("%f", &vetor[2]);
    }
