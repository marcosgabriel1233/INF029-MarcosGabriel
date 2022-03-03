#include<stdio.h>

struct numeros{
    float a;
    float b;
    float c;
    float d;
};

int main(void)
{
    struct numeros teste2;

    void ler4numeros (struct numeros teste);

    printf("\n%.1f", teste2.a);
    printf("\n%.1f", teste2.b);
    printf("\n%.1f", teste2.c);
    printf("\n%.1f", teste2.d);

    return 0;
}

    void ler4numeros (struct numeros teste)
    {
            printf("Digite um numero: ");
            scanf("%f", &teste.a);
            printf("Digite um numero: ");
            scanf("%f", &teste.b);
            printf("Digite um numero: ");
            scanf("%f", &teste.c);
            printf("Digite um numero: ");
            scanf("%f", &teste.d);

            return teste;
    }
