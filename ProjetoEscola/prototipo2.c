#include <stdio.h>
#include <string.h>
#define n 5
#define completado 1

typedef struct data
{
    int dia;
    int mes;
    int ano;
} datanasc;

typedef struct alunos
{
    char nome[40];
    char sexoAluno[2];
    char cpfAluno[15];
    datanasc dataAluno;
    int matriculaAluno;

} cadAlunos;

int menuprincipal();
int cadastroaluno(cadAlunos listAlunos[], int numAlunos);
void listaraluno(cadAlunos listAlunos[], int numAlunos);

int main(void)
{
    cadAlunos listAlunos[n];
    int numAlunos = 0;
    int opcao, retorno;
    int sair = 0;

    printf("- PROJETO ESCOLA -\n-------------------");

    while (!sair)
    {
        opcao = menuprincipal();

        switch (opcao)
        {
        case 0:
        {
            printf("SAINDO...\n");
            sair = 1;
            break;
        }

        case 1:
        {
            retorno = cadastroaluno(listAlunos, numAlunos);
            if (retorno == completado)
            {
                printf("Cadastro realizado com sucesso\n");

                numAlunos++;

                break;
            }
        }
        case 2:
        {
            listaraluno(listAlunos, numAlunos);
            break;
        }
        default:
        {
            printf("Opção Inválida. Tente novamente.");
            break;
        }
        }
    }
}

int menuprincipal()
{
    int opcao;
    printf("\nDigite uma Opção:\n\n");
    printf("0 - Sair.\n");
    printf("1 - Inserir Aluno.\n");
    printf("2 - Listar Alunos.\n");
    scanf("%d", &opcao);

    return opcao;
}

int cadastroaluno(cadAlunos listAlunos[], int numAlunos)
{
    printf("Digite a Matrícula do aluno: ");
    scanf("%d", &listAlunos[numAlunos].matriculaAluno);
    getchar();

    printf("Digite o nome do aluno: ");
    fgets(listAlunos[numAlunos].nome, 40, stdin);
    size_t ln = strlen(listAlunos[numAlunos].nome) - 1;
    if (listAlunos[numAlunos].nome[ln] == '\n')
        listAlunos[numAlunos].nome[ln] = '\0';

    printf("Digite o sexo do aluno: ");
    fgets(listAlunos[numAlunos].sexoAluno, 2, stdin);
    if (listAlunos[numAlunos].sexoAluno[ln] == '\n')
        listAlunos[numAlunos].sexoAluno[ln] = '\0';

    printf("Digite a data de nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &listAlunos[numAlunos].dataAluno.dia, &listAlunos[numAlunos].dataAluno.mes, &listAlunos[numAlunos].dataAluno.ano);
    getchar();

    printf("Digite o CPF: ");
    fgets(listAlunos[numAlunos].cpfAluno, 15, stdin);
    ln = strlen(listAlunos[numAlunos].cpfAluno) - 1;
    if (listAlunos[numAlunos].cpfAluno[ln] == '\n')
        listAlunos[numAlunos].cpfAluno[ln] = '\0';

    return completado;
}

void listaraluno(cadAlunos listAlunos[], int numAlunos)
{
    for (int i = 0; i < numAlunos; i++)
    {
        printf("-----\n");
        printf("Nome: %s\n", listAlunos[i].nome);
        printf("Matricula: %d\n", listAlunos[i].matriculaAluno);
        printf("CPF: %s\n", listAlunos[i].cpfAluno);
        printf("Sexo: %s\n", listAlunos[i].sexoAluno);
    }
}