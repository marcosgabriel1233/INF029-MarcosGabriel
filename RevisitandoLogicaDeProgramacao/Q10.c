#include<stdio.h>
int main()
{
    struct dados
    {
        //char nome;
        int idade;
        //char sexo;
        int cpf;
    };
    
    struct dados teste[5];
    //teste[0].nome;
    teste[0].idade;
    //teste[0].sexo;
    teste[0].cpf;

    for(int i = 0; i < 5; i++)
    {
        //printf("Digite seu Nome: ");
        //scanf("%c", &teste[i].nome);
        
        printf("Digite sua idade: ");
        scanf("%d", &teste[i].idade);
        
        //printf("Digite seu sexo: ");
        //scanf("%c", &teste[i].sexo);
        
        printf("Digite seu CPF: ");
        scanf("%d", &teste[i].cpf);
    }
    for(int i = 0; i < 5; i++)
    {
        printf("Idade: %d. CPF: %d.\n", teste[i].idade, teste[i].cpf);
    }
}