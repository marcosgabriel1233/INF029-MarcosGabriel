#include<stdio.h>
int main(void)
{
    int a, final;
    int fatorial(int a);

    printf("Digite o numero para o fatorial: ");
    scanf("%i", &a);

    final = fatorial(a);

    printf("O fatorial de %i eh: %i", a, final);

    return 0;
}

    int fatorial(int a)
    {
        int fat = 1;

        if(a > 0)
        {
            for(int i = 1; i <= a; i++)
            {
                fat = i * (fat);
            }
        }else{
            fat = 1;
        }

        return fat;
    }