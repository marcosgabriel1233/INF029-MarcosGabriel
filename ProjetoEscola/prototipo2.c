#include <stdio.h>
#include <string.h>
#include <locale.h>
#define n 10

struct data
{
    int dia;
    int mes;
    int ano;
};

struct Aluno
{
    int matricula;
    char nome[50];
    char sexo;
    int cpf;
};

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    struct Aluno cadastro[n];
    struct data cadData;
    int opcao;
    int cadastrados;
    int sair = 0;

    while (!sair)
    {

        printf("Escolha a operação:\n");
        printf("0 - Sair\n");
        printf("1 - Inserir Aluno\n");
        printf("2 - Listar alunos cadastrados\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
        {
            printf("Encerrando...\n");
            sair = 1;
            break;
        }
        case 1:
        {
            printf("Digite a matrícula: ");
            scanf("%d", &cadastro[cadastrados].matricula);
            getchar();

            printf("Digite o nome: ");
            fgets(cadastro[cadastrados].nome, 50, stdin);
            size_t ln = strlen(cadastro[cadastrados].nome) - 1;
            if (cadastro[cadastrados].nome[ln] == '\n')
                cadastro[cadastrados].nome[ln] = '\0';

            printf("Digite o sexo: ");
            scanf("%c", &cadastro[cadastrados].sexo);

            printf("Digite a data de nascimento (dd/mm/aa): ");
            scanf("%d/%d/%d", &cadData.dia, &cadData.mes, &cadData.ano);
            getchar();

            printf("Digite o CPF: ");
            scanf("%d", &cadastro[cadastrados].cpf);
            printf("\n");

            cadastrados++;

            break;
        }
        case 2: 
        {
            for(int i = 0; i < cadastrados; i++)
            {
                printf("Nome: %s\n", cadastro[i].nome);
                printf("CPF: %d\n", cadastro[i].cpf);
                printf("Matrícula: %d\n", cadastro[i].matricula);
            }
        }
        }
    }
    return 1;
}