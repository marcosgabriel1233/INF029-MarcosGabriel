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
    int Amatricula;
    char Anome[50];
    char Asexo;
    int Acpf;
};

struct Professor
{
    int Pmatricula;
    char Pnome[50];
    char Psexo;
    int Pcpf;
};


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    struct Aluno Acadastro[n];
    struct Professor Pcadastro[n];
    struct data cadData;
    int opcao;
    int Acadastrados, Pcadastrados;
    int sair = 0;

    while (!sair)
    {

        printf("Escolha a operação:\n");
        printf("0 - Sair\n");
        printf("1 - Inserir Aluno\n");
        printf("2 - Cadastrar Professor\n");
        printf("3 - Listar alunos cadastrados\n");
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
            scanf("%d", &Acadastro[Acadastrados].Amatricula);
            getchar();

            printf("Digite o nome: ");
            fgets(Acadastro[Acadastrados].Anome, 50, stdin);
            size_t ln = strlen(Acadastro[Acadastrados].Anome) - 1;
            if (Acadastro[Acadastrados].Anome[ln] == '\n')
                Acadastro[Acadastrados].Anome[ln] = '\0';

            printf("Digite o sexo: ");
            scanf("%c", &Acadastro[Acadastrados].Asexo);

            printf("Digite a data de nascimento (dd/mm/aa): ");
            scanf("%d/%d/%d", &cadData.dia, &cadData.mes, &cadData.ano);
            getchar();

            printf("Digite o CPF: ");
            scanf("%d", &Acadastro[Acadastrados].Acpf);
            printf("\n");

            Acadastrados++;

            break;
        }
            case 2:
        {
            printf("Digite a matrícula: ");
            scanf("%d", &Pcadastro[Pcadastrados].Pmatricula);
            getchar();

            printf("Digite o nome: ");
            fgets(Pcadastro[Pcadastrados].Pnome, 50, stdin);
            size_t ln = strlen(Pcadastro[Pcadastrados].Pnome) - 1;
            if (Pcadastro[Pcadastrados].Pnome[ln] == '\n')
                Pcadastro[Pcadastrados].Pnome[ln] = '\0';

            printf("Digite o sexo: ");
            scanf("%c", &Pcadastro[Pcadastrados].Psexo);

            printf("Digite a data de nascimento (dd/mm/aa): ");
            scanf("%d/%d/%d", &cadData.dia, &cadData.mes, &cadData.ano);
            getchar();

            printf("Digite o CPF: ");
            scanf("%d", &Pcadastro[Pcadastrados].Pcpf);
            printf("\n");

            Pcadastrados++;

            break;
        }

        case 3: 
        {
            for(int i = 0; i < Acadastrados; i++)
            {
                printf("Nome: %s\n", Acadastro[i].Anome);
                printf("CPF: %d\n", Acadastro[i].Acpf);
                printf("Matrícula: %d\n", Acadastro[i].Amatricula);
            }
        }
        case 4: 
        {
            for(int i = 0; i < Pcadastrados; i++)
            {
                printf("Nome: %s\n", Pcadastro[i].Pnome);
                printf("CPF: %d\n", Pcadastro[i].Pcpf);
                printf("Matrícula: %d\n", Pcadastro[i].Pmatricula);
            }
        }
        }
    }
    return 1;
}