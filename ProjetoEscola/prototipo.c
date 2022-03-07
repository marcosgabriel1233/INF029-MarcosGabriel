#include <stdio.h>
#include <string.h>
#include <locale.h>

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

    struct Aluno cadastro;
    struct data cadData;
    int opcao;
    int sair = 0;

    while (!sair)
    {

        printf("Escolha a operação:\n");
        printf("0 - Sair\n");
        printf("1 - Inserir Aluno\n");
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
            scanf("%d", &cadastro.matricula);
            getchar();

            printf("Digite o nome do aluno: ");
            fgets(cadastro.nome, 50, stdin);
            size_t ln = strlen(cadastro.nome) - 1;
            if (cadastro.nome[ln] == '\n')
                cadastro.nome[ln] = '\0';

            printf("Digite o sexo: ");
            scanf("%c", &cadastro.sexo);

            printf("Digite a data de nascimento (dd/mm/aa): ");
            scanf("%d/%d/%d", &cadData.dia, &cadData.mes, &cadData.ano);
            getchar();

            printf("Digite o CPF: ");
            scanf("%d", &cadastro.cpf);
            printf("\n");

            break;
        }
        }
    }
    return 1;
}