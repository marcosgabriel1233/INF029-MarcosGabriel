#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "aluno.h"

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
    int teste = 1, tesmat = 1, i;

    while(tesmat > 0){
      printf("Digite a Matrícula do Aluno: ");
      scanf("%d", &listAlunos[numAlunos].matriculaAluno);
      getchar();
      
      tesmat = 0;
      for(i=0;i<numAlunos;i++){
        if(listAlunos[numAlunos].matriculaAluno == listAlunos[i].matriculaAluno){
          tesmat++;
          }
      }
        }

    printf("Digite o nome do aluno: ");
    fgets(listAlunos[numAlunos].nome, 40, stdin);
    size_t ln = strlen(listAlunos[numAlunos].nome) - 1;
    if (listAlunos[numAlunos].nome[ln] == '\n')
        listAlunos[numAlunos].nome[ln] = '\0';

    while(teste != 0){
      printf("Digite o sexo do aluno (M/F): ");
      fgets(listAlunos[numAlunos].sexoAluno, 2, stdin);
      ln = strlen(listAlunos[numAlunos].sexoAluno) -1;
      if (listAlunos[numAlunos].sexoAluno[ln] == '\n')
          listAlunos[numAlunos].sexoAluno[ln] = '\0';
      
      teste = strcmp(listAlunos[numAlunos].sexoAluno,"M");
        if(teste != 0){
          teste = strcmp(listAlunos[numAlunos].sexoAluno,"F");
      }
      if(teste != 0){
        printf("Sexo Inválido.\n");
      }
      }

    printf("Digite a data de nascimento:\n");
    printf("Ano: ");
    scanf("%d", &listAlunos[numAlunos].dataAluno.ano);
  
    while(listAlunos[numAlunos].dataAluno.ano < 1910){
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
  int i, ndm, teste = 1, num = 0, conf = 0;
  
  while(conf == 0){
  printf("\nInforme a matrícula do aluno a ser atualizado: ");
  scanf("%d",&ndm);
  getchar();

  conf = 0;
  for(i=0;i<numAlunos;i++){
    num++;
    if(listAlunos[i].matriculaAluno == ndm){
      conf++;
      i = numAlunos;
    }
  }
    }
  
    printf("\nDigite a nova matrícula do aluno: ");
    scanf("%d", &listAlunos[num].matriculaAluno);
    getchar();

    printf("Digite o nome do aluno: ");
    fgets(listAlunos[num].nome, 40, stdin);
    size_t ln = strlen(listAlunos[num].nome) - 1;
    if (listAlunos[num].nome[ln] == '\n')
        listAlunos[num].nome[ln] = '\0';

    while(teste != 0){
      printf("Digite o sexo do aluno (M/F): ");
      fgets(listAlunos[num].sexoAluno, 2, stdin);
      ln = strlen(listAlunos[num].sexoAluno) -1;
      if (listAlunos[num].sexoAluno[ln] == '\n')
          listAlunos[num].sexoAluno[ln] = '\0';
      
      teste = strcmp(listAlunos[num].sexoAluno,"M");
        if(teste != 0){
          teste = strcmp(listAlunos[num].sexoAluno,"F");
      }
      if(teste != 0){
        printf("Sexo Inválido.\n");
      }
      }

    printf("Digite a data de nascimento: (DD.MM.AAAA):\nDia: ");
    scanf("%d", &listAlunos[num].dataAluno.dia);
    printf("Mês: ");
    scanf("%d",&listAlunos[num].dataAluno.mes);
    printf("Ano: ");
    scanf("%d",&listAlunos[num].dataAluno.ano);
    getchar();

    printf("Digite o CPF: ");
    fgets(listAlunos[num].cpfAluno, 15, stdin);
    ln = strlen(listAlunos[num].cpfAluno) -1;
    if (listAlunos[num].cpfAluno[ln] == '\n')
        listAlunos[num].cpfAluno[ln] = '\0';

    __fpurge(stdin);
    
    printf("\nDados atualizados com sucesso.");
    return completado;
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

void alfabeticaAlunos (cadAlunos listAlunos[], int numAlunos)
{
  cadAlunos alfabetica[n];
  int i, j, k;
  char aux[50];

  for(i=0;i<numAlunos;i++){
    strcpy(alfabetica[i].nome, listAlunos[i].nome);
  }
  
  printf("\nAlunos Cadastrados em Ordem Alfabética:\n\n");
  for(i=0;i<numAlunos;i++){
    for(j = i+1; j < numAlunos; j++){
      k = strcmp(alfabetica[i].nome, alfabetica[j].nome);
      if(k > 0){
        strcpy(aux, alfabetica[i].nome);
        strcpy(alfabetica[i].nome, alfabetica[j].nome);
        strcpy(alfabetica[j].nome, aux);
      }
    }
  }
  for(i = 0; i < numAlunos; i++){
    printf("- %s\n", alfabetica[i].nome);
  }
}

void sexoalunos (cadAlunos listAlunos[], int numAlunos)
{
  int i, teste;
  printf("\nAlunas Cadastradas no Sistema:\n");
  for(i=0;i<numAlunos;i++){
    teste = strcmp(listAlunos[i].sexoAluno, "F");
    if(teste == 0){
      printf("\n- %s",listAlunos[i].nome);
    }
  }
  printf("\n--------------------\nAlunos Cadastrados no Sistema:\n");
  for(i=0;i<numAlunos;i++){
    teste = strcmp(listAlunos[i].sexoAluno, "M");
    if(teste == 0){
      printf("\n- %s",listAlunos[i].nome);
    }
  }
}