#include <stdio.h>
int main()
{
    int num[10];
    int primos[10];

    for (int i = 0; i < 10; i++){
    primos[i] = 1;
    }

    for (int i = 0; i < 10; i++){
        printf("Digite um numero: ");
        scanf("%d", &num[i]);
    }
    
    for(int i = 0; i < 10; i++){
        for(int j = 2; j < num[i]; j++)
            if (num[i] % j == 0){
                primos[i] = 0;
                break;
            }
    }
    int soma = 0;
    printf("os numeros primos sao: ");
    for(int i = 0; i < 10; i++){
        if(primos[i] == 1){
            soma = soma + num[i];
            printf("%d, ", num[i]);
        }
    }
    printf("\nA soma eh: %d", soma);
}