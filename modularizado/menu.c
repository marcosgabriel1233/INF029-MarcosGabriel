#include "menu.h"

int menuprincipal()
{
    int opcao;
    printf("\n-------------------\nDigite uma Opção:\n\n");
    printf("0 - Sair.\n");
    printf("1 - Gerenciar Alunos.\n");
    printf("2 - Gerenciar Professores.\n");
    printf("3 - Gerenciar Disciplinas.\n");
    printf("4 - Relatórios.\n");
    printf("\n> ");
    scanf("%d", &opcao);

    return opcao;
}

int menuAlunos()
{
    int opcaoAlunos;
    printf("\n-------------------\n.....ALUNOS.....\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Cadastrar Aluno.\n");
    printf("2 - Listar Alunos.\n");
    printf("3 - Atualizar Aluno.\n");
    printf("4 - Excluir Aluno.\n");
    printf("\n> ");
    scanf("%d", &opcaoAlunos);

    return opcaoAlunos;
}

int menuProf()
{
    int opcaoProf;
    printf("\n-------------------\n...PROFESSORES...\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Cadastrar Professor.\n");
    printf("2 - Listar Professores.\n");
    printf("3 - Atualizar Professor.\n");
    printf("4 - Excluir Professor.\n");
    printf("\n> ");
    scanf("%d", &opcaoProf);

    return opcaoProf;
}

int menuDis()
{
    int opcaoDis;
    printf("\n-------------------\n...DISCIPLINAS...\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Cadastrar Disciplina.\n");
    printf("2 - Listar Disciplinas.\n");
    printf("3 - Atualizar Disciplina.\n");
    printf("4 - Excluir Disciplina.\n");
    printf("5 - Incluir Aluno na Disciplina.\n");
    printf("\n> ");
    scanf("%d", &opcaoDis);
    getchar();

    return opcaoDis;
}

int menuRel()
{
  int opcaoRel;
    printf("\n-------------------\n...RELATÓRIOS...\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Listar Alunos por Sexo.\n");
    printf("2 - Listar Professores por Sexo\n");
    printf("3 - Listar Alunos em Ordem Alfabetica.\n");
    printf("4 - Listar Professores em Ordem Alfabetica.\n");
    printf("5 - Aniversáriantes do Mês.\n");
    printf("\n> ");
    scanf("%d", &opcaoRel);
    getchar();

    return opcaoRel;
}