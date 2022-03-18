/* 720
! Incluir Alunos nas Disciplinas.
! Relatórios.
! Etc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define n 50
#define completado 1

//-------STRUCTS-------

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

typedef struct professor
{
    char nomeProf[40];
    char sexoProf[2];
    char cpfProf[15];
    datanasc dataProf;
    int matriculaProf;
} cadProf;

typedef struct disciplina
{
    char nomeDis[30];
    char codDis[10];
    int semDis;
    int alunosDis[n];
    char profDis[40];   
} cadDis;

//--------------------

int menuprincipal();
int menuAlunos();
int menuProf();
int menuDis();

int cadastroaluno(cadAlunos listAlunos[], int numAlunos);
int cadastroprof(cadProf listProf[], int numProf);
int cadastrodis(cadDis listDis[], int numDis);

void listaraluno(cadAlunos listAlunos[], int numAlunos);
void listarprof(cadProf listProf[], int numProf);
void listardis(cadDis listDis[], int numDis);

int atualizaraluno(cadAlunos listAlunos[], int numAlunos);
int atualizarprof(cadProf listProf[], int numProf);
int atualizardis(cadDis listDis[], int numDis);

int excluiraluno(cadAlunos listAlunos[], int numAlunos);
int excluirprof(cadProf listProf[], int numProf);
int excluirdis(cadDis listDis[], int numDis);

//------MAIN-------

int main(void)
{  
    cadAlunos listAlunos[n];
    cadProf listProf[n];
    cadDis listDis[n];
    int numAlunos = 0;
    int numProf = 0;
    int numDis = 0;
    int opcao, opcaoAlunos, opcaoProf, opcaoDis, retorno;
    int sair = 0;

    printf("- PROJETO ESCOLA -");

    while (!sair)
    {
        opcao = menuprincipal();

        switch (opcao){
          case 0:{
            printf("\nSAINDO...\n");
            sair = 1;
            break;
          }
          case 1:{
            opcaoAlunos = menuAlunos();
            switch (opcaoAlunos){
              case 0:{
                break;
              }
              case 1:{
                retorno = cadastroaluno(listAlunos,numAlunos);
                if (retorno == completado)
                {
                  printf("\nAluno (%d) cadastrado com sucesso!\n",numAlunos);
                  numAlunos++;
                }
                break;
              }
              case 2:{
                listaraluno(listAlunos, numAlunos);
                break;
              } 
              case 3:{
                atualizaraluno(listAlunos, numAlunos);
                break;
              }
              case 4:{
                excluiraluno(listAlunos, numAlunos);
                numAlunos--;
                break;
              }
              default:{
                printf("Opção Inválida. Tente novamente.");
                break;
              }
            }
            break;
          }//Aluno.
          case 2:{
            opcaoProf = menuProf();
            switch (opcaoProf){
              case 0:{
                break;
              }
              case 1:{
                retorno = cadastroprof(listProf,numProf);
                if (retorno == completado)
                {
                  printf("\nProfessor (%d) cadastrado com sucesso!\n",numProf);
                  numProf++;
                }
                break;
              }
              case 2:{
                listarprof(listProf, numProf);
                break;
              }
              case 3:{
                atualizarprof(listProf, numProf);
                break;
              }
              case 4:{
                excluirprof(listProf, numProf);
                numProf--;
                break;
              }
              default:{
                printf("\nOpção Inválida. Tente novamente.\n");
                break;
              }
            }
            break;
          }//Prof.
          case 3:{
            opcaoDis=menuDis();
            switch(opcaoDis){
              case 0:{
                break;
                }
              case 1:{
                retorno = cadastrodis(listDis,numDis);
                if (retorno == completado)
                {
                  printf("\nDisciplina (%d) cadastrada com sucesso!\n",numDis);
                  numDis++;
                }
                break;
              }
              case 2:{
                listardis(listDis, numDis);
                break;
              }
              case 3:{
                atualizardis(listDis, numDis);
                break;
              }
              case 4:{
                excluirdis(listDis, numDis);
                numDis--;
                break;
              }
              default:{
                printf("\nOpção Inválida. Tente novamente.\n");
                break;
              }
            }
          }//Disciplina.
    }
}
}

//-------FUNÇÕES-------

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

//------- F. ALUNOS------

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

int cadastroaluno(cadAlunos listAlunos[], int numAlunos)
{
    printf("\nDigite a Matrícula do aluno: ");
    scanf("%d", &listAlunos[numAlunos].matriculaAluno);
    getchar();

    printf("Digite o nome do aluno: ");
    fgets(listAlunos[numAlunos].nome, 40, stdin);
    size_t ln = strlen(listAlunos[numAlunos].nome) - 1;
    if (listAlunos[numAlunos].nome[ln] == '\n')
        listAlunos[numAlunos].nome[ln] = '\0';

    printf("Digite o sexo do aluno (M/F): ");
    fgets(listAlunos[numAlunos].sexoAluno, 2, stdin);
    if (listAlunos[numAlunos].sexoAluno[ln] == '\n')
        listAlunos[numAlunos].sexoAluno[ln] = '\0';

    printf("Digite a data de nascimento:\n");
    printf("Ano: ");
    scanf("%d", &listAlunos[numAlunos].dataAluno.ano);
  
    while(listAlunos[numAlunos].dataAluno.ano<1910){
      printf("Inválido.\nAno: ");
      scanf("%d", &listAlunos[numAlunos].dataAluno.ano);
      }

    printf("Mês: ");
    scanf("%d",&listAlunos[numAlunos].dataAluno.mes);
    while(listAlunos[numAlunos].dataAluno.mes>12){
      printf("Inválido.\nMês: ");
      scanf("%d",&listAlunos[numAlunos].dataAluno.mes);
      } 

    printf("Dia: ");
    scanf("%d",&listAlunos[numAlunos].dataAluno.dia);

    if(listAlunos[numAlunos].dataAluno.mes==4||6||9||11)
    {
      while(listAlunos[numAlunos].dataAluno.dia>30){
        printf("Inválido.\nDia: ");
        scanf("%d",&listAlunos[numAlunos].dataAluno.dia);
        } 
    }
    if(listAlunos[numAlunos].dataAluno.mes==1||3||5||7||8||10||12)
    {
      while(listAlunos[numAlunos].dataAluno.dia>31){
        printf("Inválido.\nDia: ");
        scanf("%d",&listAlunos[numAlunos].dataAluno.dia);
      }
    }
    else{
      while(listAlunos[numAlunos].dataAluno.dia>29){
        printf("Inválido.\nDia: ");
        scanf("%d",&listAlunos[numAlunos].dataAluno.dia);
      }
    }
    getchar();

    printf("Digite o CPF: ");
    fgets(listAlunos[numAlunos].cpfAluno, 15, stdin);
    ln = strlen(listAlunos[numAlunos].cpfAluno) - 1;
    if (listAlunos[numAlunos].cpfAluno[ln] == '\n')
        listAlunos[numAlunos].cpfAluno[ln] = '\0';

    __fpurge(stdin);

    return completado;
}

void listaraluno(cadAlunos listAlunos[], int numAlunos)
{
    printf("\n*******************");
    for (int i = 0; i < numAlunos; i++)
    {
        printf("\n----------\n");
        printf("Nome: %s (%d)\n", listAlunos[i].nome, i);
        printf("Matricula: %d\n", listAlunos[i].matriculaAluno);
        printf("CPF: %s\n", listAlunos[i].cpfAluno);
        printf("Sexo: %s\n", listAlunos[i].sexoAluno);
        printf("Data: %d-%d-%d \n", listAlunos[i].dataAluno.dia,listAlunos[i].dataAluno.mes,listAlunos[i].dataAluno.ano);
    }
    printf("\n*******************");

  __fpurge(stdin);
}

int atualizaraluno(cadAlunos listAlunos[], int numAlunos)
{
  int nda;
  int ndam=numAlunos-1;

  printf("\nInforme o número do aluno: ");
  scanf("%d",&nda);
  while(nda>ndam){
    printf("(Digite -1 para sair)\nNúmero inválido! Tente outro: ");
    scanf("%d",&nda);
  }

  if(nda==-1){
    printf("\nNão foi possível concluir a operação.");
  }
  else{
    printf("\nDigite a Matrícula do aluno: ");
    scanf("%d", &listAlunos[nda].matriculaAluno);
    getchar();

    printf("Digite o nome do aluno: ");
    fgets(listAlunos[nda].nome, 40, stdin);
    size_t ln = strlen(listAlunos[nda].nome) - 1;
    if (listAlunos[nda].nome[ln] == '\n')
        listAlunos[nda].nome[ln] = '\0';

    printf("Digite o sexo do aluno (M/F): ");
    fgets(listAlunos[nda].sexoAluno, 2, stdin);
    if (listAlunos[nda].sexoAluno[ln] == '\n')
        listAlunos[nda].sexoAluno[ln] = '\0';

    printf("Digite a data de nascimento: (DD.MM.AAAA):\nDia: ");
    scanf("%d", &listAlunos[nda].dataAluno.dia);
    printf("Mês: ");
    scanf("%d",&listAlunos[nda].dataAluno.mes);
    printf("Ano: ");
    scanf("%d",&listAlunos[nda].dataAluno.ano);
    getchar();

    printf("Digite o CPF: ");
    fgets(listAlunos[nda].cpfAluno, 15, stdin);
    if (listAlunos[nda].cpfAluno[ln] == '\n')
        listAlunos[nda].cpfAluno[ln] = '\0';

    __fpurge(stdin);
    
    printf("\nDados atualizados com sucesso.");
    return completado;
  }
}

int excluiraluno(cadAlunos listAlunos[], int numAlunos)
{
  int eda;
  int ndam=numAlunos-1;
  cadAlunos *ptr1, *ptr2, *ptr3;
  ptr1 = &listAlunos[eda];
  ptr2 = &listAlunos[eda+1];
  ptr3 = &listAlunos[numAlunos-1];
  
  printf("\nInforme o número do aluno: ");
  scanf("%d",&eda);
  while(eda>ndam){
    printf("(Digite -1 para sair)\nNúmero inválido! Tente outro: ");
    scanf("%d",&eda);
  }
  
  if(eda==-1){
    printf("\nNão foi possível concluir a operação.");
  }
  else{
    for(eda;eda<numAlunos;eda++){
      ptr1 = ptr2;
      ptr3 = NULL;
    }

    __fpurge(stdin);
    printf("\nDados excluídos com sucesso. Numeração atualizada.");
    return completado;
  }
}

//-------F. PROFESSORES-------

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

int cadastroprof(cadProf listProf[], int numProf)
{
    printf("\nDigite a Matrícula do professor: ");
    scanf("%d", &listProf[numProf].matriculaProf);
    getchar();

    printf("Digite o nome do professor: ");
    fgets(listProf[numProf].nomeProf, 40, stdin);
    size_t ln = strlen(listProf[numProf].nomeProf) - 1;
    if (listProf[numProf].nomeProf[ln] == '\n')
        listProf[numProf].nomeProf[ln] = '\0';

    printf("Digite o sexo do professor (M/F): ");
    fgets(listProf[numProf].sexoProf, 2, stdin);
    if (listProf[numProf].sexoProf[ln] == '\n')
        listProf[numProf].sexoProf[ln] = '\0';

    printf("Digite a data de nascimento:\n");
    printf("Ano: ");
    scanf("%d", &listProf[numProf].dataProf.ano);
  
    while(listProf[numProf].dataProf.ano<1910){
      printf("Inválido.\nAno: ");
      scanf("%d", &listProf[numProf].dataProf.ano);
      }

    printf("Mês: ");
    scanf("%d",&listProf[numProf].dataProf.mes);
    while(listProf[numProf].dataProf.mes>12){
      printf("Inválido.\nMês: ");
      scanf("%d",&listProf[numProf].dataProf.mes);
      } 

    printf("Dia: ");
    scanf("%d",&listProf[numProf].dataProf.dia);

    if(listProf[numProf].dataProf.mes==4||6||9||11)
    {
      while(listProf[numProf].dataProf.dia>30){
        printf("Inválido.\nDia: ");
        scanf("%d",&listProf[numProf].dataProf.dia);
        } 
    }
    if(listProf[numProf].dataProf.mes==1||3||5||7||8||10||12)
    {
      while(listProf[numProf].dataProf.dia>31){
        printf("Inválido.\nDia: ");
        scanf("%d",&listProf[numProf].dataProf.dia);
      }
    }
    else{
      while(listProf[numProf].dataProf.dia>29){
        printf("Inválido.\nDia: ");
        scanf("%d",&listProf[numProf].dataProf.dia);
      }
    }
    getchar();

    printf("Digite o CPF: ");
    fgets(listProf[numProf].cpfProf, 15, stdin);
    ln = strlen(listProf[numProf].cpfProf) - 1;
    if (listProf[numProf].cpfProf[ln] == '\n')
        listProf[numProf].cpfProf[ln] = '\0';

    __fpurge(stdin);
  
    return completado;
}

void listarprof(cadProf listProf[], int numProf)
{
    printf("\n*******************");
    for (int i = 0; i < numProf; i++)
    {
        printf("\n----------\n");
        printf("Nome: %s (%d)\n", listProf[i].nomeProf, i);
        printf("Matricula: %d\n", listProf[i].matriculaProf);
        printf("CPF: %s\n", listProf[i].cpfProf);
        printf("Sexo: %s\n", listProf[i].sexoProf);
        printf("Data: %d-%d-%d", listProf[i].dataProf.dia,listProf[i].dataProf.mes,listProf[i].dataProf.ano);
    }
    printf("\n*******************");
}

int atualizarprof(cadProf listProf[], int numProf)
{
  int ndp;
  int ndpm=numProf-1;
  printf("\nInforme o número do professor: ");
  scanf("%d",&ndp);
  while(ndp>ndpm){
    printf("(Digite -1 para sair)\nNúmero inválido! Tente outro: ");
    scanf("%d",&ndp);
  }

  if(ndp==-1){
    printf("\nNão foi possível concluir a operação.");
  }
  else{
    printf("\nDigite a matrícula do professor: ");
    scanf("%d", &listProf[ndp].matriculaProf);
    getchar();

    printf("Digite o nome do professor: ");
    fgets(listProf[ndp].nomeProf, 40, stdin);
    size_t ln = strlen(listProf[ndp].nomeProf) - 1;
    if (listProf[ndp].nomeProf[ln] == '\n')
        listProf[ndp].nomeProf[ln] = '\0';

    printf("Digite o sexo do professor (M/F): ");
    fgets(listProf[ndp].sexoProf, 2, stdin);
    if (listProf[ndp].sexoProf[ln] == '\n')
        listProf[ndp].sexoProf[ln] = '\0';

    printf("Digite a data de nascimento: (DD.MM.AAAA):\nDia: ");
    scanf("%d", &listProf[ndp].dataProf.dia);
    printf("Mês: ");
    scanf("%d",&listProf[ndp].dataProf.mes);
    printf("Ano: ");
    scanf("%d",&listProf[ndp].dataProf.ano);
    getchar();

    printf("Digite o CPF: ");
    fgets(listProf[ndp].cpfProf, 15, stdin);
    if (listProf[ndp].cpfProf[ln] == '\n')
        listProf[ndp].cpfProf[ln] = '\0';

    __fpurge(stdin);
    
    printf("\nDados atualizados com sucesso.");
    return completado;
  }
}

int excluirprof(cadProf listProf[], int numProf)
{
  int edp;
  int ndpm=numProf-1;
  cadProf *ptr1, *ptr2, *ptr3;
  ptr1 = &listProf[edp];
  ptr2 = &listProf[edp+1];
  ptr3 = &listProf[edp-1];
  
  printf("\nInforme o número do professor: ");
  scanf("%d",&edp);
  while(edp>ndpm){
    printf("(Digite -1 para sair)\nNúmero inválido! Tente outro: ");
    scanf("%d",&edp);
  }
  
  if(edp==-1){
    printf("\nNão foi possível concluir a operação.");
  }
  else{
    for(edp;edp<numProf;edp++){
      ptr1 = ptr2;
      ptr3 = NULL;
    }

    __fpurge(stdin);
    printf("\nDados excluídos com sucesso. Numeração atualizada.");
    return completado;
  }
}
//-------F. DISCIPLINAS-------

int menuDis()
{
    int opcaoDis;
    printf("\n-------------------\n...DISCIPLINAS...\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Cadastrar Disciplina.\n");
    printf("2 - Listar Disciplinas.\n");
    printf("3 - Atualizar Disciplina.\n");
    printf("4 - Excluir Disciplina.\n");
    printf("\n> ");
    scanf("%d", &opcaoDis);
    getchar();

    return opcaoDis;
}

int cadastrodis(cadDis listDis[], int numDis)
{
  printf("Digite o semestre da disciplina: ");
  scanf("%d", &listDis[numDis].semDis);
  getchar();
  
  printf("Digite o nome do disciplina: ");
  fgets(listDis[numDis].nomeDis, 40, stdin);
  size_t ln = strlen(listDis[numDis].nomeDis) - 1;
  if (listDis[numDis].nomeDis[ln] == '\n')
      listDis[numDis].nomeDis[ln] = '\0';

  printf("Digite o código da disciplina: ");
  fgets(listDis[numDis].codDis, 10, stdin);
  if (listDis[numDis].codDis[ln] == '\n')
      listDis[numDis].codDis[ln] = '\0';

  printf("Digite o nome do professor da disciplina: ");
  fgets(listDis[numDis].profDis, 40, stdin);
  if (listDis[numDis].profDis[ln] == '\n')
      listDis[numDis].profDis[ln] = '\0';
  
  __fpurge(stdin);
  
  return completado;
  }

void listardis(cadDis listDis[], int numDis)
{
      printf("\n*******************\n");
      for (int i = 0; i < numDis; i++)
    {
        printf("----------\n");
        printf("Nome: %s (%d)\n", listDis[i].nomeDis,i);
        printf("Código: %s", listDis[i].codDis);
        printf("Semestre: %d\n", listDis[i].semDis);
        printf("Professor: %s\n", listDis[i].profDis);
    }
      printf("\n*******************");
}

int atualizardis(cadDis listDis[], int numDis)
{
  int ndd;
  int nddm=numDis-1;

  printf("\nInforme o número da disciplina: ");
  scanf("%d",&ndd);
  while(ndd>nddm){
    printf("(Digite -1 para sair)\nNúmero inválido! Tente outro: ");
    scanf("%d",&ndd);
  }

  if(ndd==-1){
    printf("\nNão foi possível concluir a operação.");
  }
  else{
    printf("Digite o semestre da disciplina: ");
    scanf("%d", &listDis[ndd].semDis);
    getchar();
    
    printf("Digite o nome do disciplina: ");
    fgets(listDis[ndd].nomeDis, 40, stdin);
    size_t ln = strlen(listDis[numDis].nomeDis) - 1;
    if (listDis[ndd].nomeDis[ln] == '\n')
        listDis[ndd].nomeDis[ln] = '\0';

    printf("Digite o código da disciplina: ");
    fgets(listDis[ndd].codDis, 10, stdin);
    if (listDis[ndd].codDis[ln] == '\n')
        listDis[ndd].codDis[ln] = '\0';

    printf("Digite o nome do professor da disciplina: ");
    fgets(listDis[ndd].profDis, 40, stdin);
    if (listDis[ndd].profDis[ln] == '\n')
        listDis[ndd].profDis[ln] = '\0';

    __fpurge(stdin);

    printf("\nDados atualizados com sucesso.");
    return completado;
  }
}

int excluirdis(cadDis listDis[], int numDis)
{
  int edd;
  int nddm=numDis-1;
  cadDis *ptr1, *ptr2, *ptr3;
  ptr1 = &listDis[edd];
  ptr2 = &listDis[edd+1];
  ptr3 = &listDis[edd-1];
  
  printf("\nInforme o número da disciplina: ");
  scanf("%d",&edd);
  while(edd>nddm){
    printf("(Digite -1 para sair)\nNúmero inválido! Tente outro: ");
    scanf("%d",&edd);
  }
  
  if(edd==-1){
    printf("\nNão foi possível concluir a operação.");
  }
  else{
    for(edd;edd<numDis;edd++){
      ptr1 = ptr2;
      ptr3 = NULL;
    }

    __fpurge(stdin);
    printf("\nDados excluídos com sucesso. Numeração atualizada.");
    return completado;
  }
}