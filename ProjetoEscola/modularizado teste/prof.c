#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
include "prof.h"

int cadastroprof(cadProf listProf[], int numProf)
{
    int teste = 1, tesmat = 1, i;

    while(tesmat > 0){
      printf("Digite a Matrícula do professor: ");
      scanf("%d", &listProf[numProf].matriculaProf);
      getchar();
      
      tesmat = 0;
      for(i=0;i<numProf;i++){
        if(listProf[numProf].matriculaProf == listProf[i].matriculaProf){
          tesmat++;
          }
      }
        }

    printf("Digite o nome do professor: ");
    fgets(listProf[numProf].nomeProf, 40, stdin);
    size_t ln = strlen(listProf[numProf].nomeProf) - 1;
    if (listProf[numProf].nomeProf[ln] == '\n')
        listProf[numProf].nomeProf[ln] = '\0';

    while(teste != 0){
      printf("Digite o sexo do professor (M/F): ");
      fgets(listProf[numProf].sexoProf, 2, stdin);
      ln = strlen(listProf[numProf].sexoProf) -1;
      if (listProf[numProf].sexoProf[ln] == '\n')
          listProf[numProf].sexoProf[ln] = '\0';
      
      teste = strcmp(listProf[numProf].sexoProf,"M");
        if(teste != 0){
          teste = strcmp(listProf[numProf].sexoProf,"F");
      }
      if(teste != 0){
        printf("Sexo Inválido.\n");
      }
      }

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
  int i, ndm, teste = 1, num = 0, conf = 0;
  
  while(conf == 0){
  printf("\nInforme a matrícula do professor a ser atualizado: ");
  scanf("%d",&ndm);
  getchar();

  conf = 0;
  for(i=0;i<numProf;i++){
    num++;
    if(listProf[i].matriculaProf == ndm){
      conf++;
      i = numProf;
    }
  }
    }
    printf("\nDigite a nova matrícula do professor: ");
    scanf("%d", &listProf[num].matriculaProf);
    getchar();

    printf("Digite o nome do professor: ");
    fgets(listProf[num].nomeProf, 40, stdin);
    size_t ln = strlen(listProf[num].nomeProf) - 1;
    if (listProf[num].nomeProf[ln] == '\n')
        listProf[num].nomeProf[ln] = '\0';

    while(teste != 0){
      printf("Digite o sexo do professor (M/F): ");
      fgets(listProf[num].sexoProf, 2, stdin);
      ln = strlen(listProf[num].sexoProf) -1;
      if (listProf[num].sexoProf[ln] == '\n')
          listProf[num].sexoProf[ln] = '\0';
      
      teste = strcmp(listProf[num].sexoProf,"M");
        if(teste != 0){
          teste = strcmp(listProf[num].sexoProf,"F");
      }
      if(teste != 0){
        printf("Sexo Inválido.\n");
      }
      }
  
    printf("Digite a data de nascimento: (DD.MM.AAAA):\nDia: ");
    scanf("%d", &listProf[num].dataProf.dia);
    printf("Mês: ");
    scanf("%d",&listProf[num].dataProf.mes);
    printf("Ano: ");
    scanf("%d",&listProf[num].dataProf.ano);
    getchar();

    printf("Digite o CPF: ");
    fgets(listProf[num].cpfProf, 15, stdin);
    ln = strlen(listProf[num].cpfProf) -1;
    if (listProf[num].cpfProf[ln] == '\n')
        listProf[num].cpfProf[ln] = '\0';

    __fpurge(stdin);
    
    printf("\nDados atualizados com sucesso.");
    return completado;
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

void sexoprof (cadProf listProf[], int numProf)
{
  int i, teste;
  printf("\nProfessoras Cadastradas no Sistema:\n");
  for(i=0;i<numProf;i++){
    teste = strcmp(listProf[i].sexoProf, "F");
    if(teste == 0){
      printf("\n- %s",listProf[i].nomeProf);
    }
  }
  printf("\n--------------------\nProfessores Cadastrados no Sistema:\n");
  for(i=0;i<numProf;i++){
    teste = strcmp(listProf[i].sexoProf, "M");
    if(teste == 0){
      printf("\n- %s",listProf[i].nomeProf);
    }
  }
}


void alfabeticaProf (cadProf listProf[], int numProf)
{
  cadProf alfabeticaP[n];
  int i, j, k;
  char aux[50];

  for(i=0;i<numProf;i++){
    strcpy(alfabeticaP[i].nomeProf, listProf[i].nomeProf);
  }
  
  printf("\nProfessores Cadastrados em Ordem Alfabética:\n\n");
  for(i=0;i<numProf;i++){
    for(j = i+1; j < numProf; j++){
      k = strcmp(alfabeticaP[i].nomeProf, alfabeticaP[j].nomeProf);
      if(k > 0){
        strcpy(aux, alfabeticaP[i].nomeProf);
        strcpy(alfabeticaP[i].nomeProf, alfabeticaP[j].nomeProf);
        strcpy(alfabeticaP[j].nomeProf, aux);
      }
    }
  }
  for(i = 0; i < numProf; i++){
    printf("- %s\n", alfabeticaP[i].nomeProf);
  }
}        