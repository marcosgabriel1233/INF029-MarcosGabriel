#include <stdio.h>
int main()
{
    int id;
    printf("Digite a sua idade: ");
    scanf("%d", &id);
    if (id >= 18){
        printf("Voce  maior de idade.");
    }
    else
        printf("Voce ainda nao e maior de idade.");
}