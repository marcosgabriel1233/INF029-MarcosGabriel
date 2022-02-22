#include <stdio.h>
int main()
{
    int id1, id2, soma;
    printf("Digite a idade da primeira pessoa: ");
    scanf("%d", &id1);
    printf("Digite a idade da segunda pessoa: ");
    scanf("%d", &id2);
    soma = id1 + id2;
    printf("%d", soma);
}