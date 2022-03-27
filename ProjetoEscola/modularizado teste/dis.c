#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "dis.h"

int cadastrodis(cadDis listDis[], int numDis)
{

  int i, teste;
  
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
  ln = strlen(listDis[numDis].codDis) -1;
  if (listDis[numDis].codDis[ln] == '\n')
      listDis[numDis].codDis[ln] = '\0';

  printf("Insira o nome do professor: ");
  fgets(listDis[numDis].profDis, 40, stdin);
  ln = strlen(listDis[numDis].profDis) -1;
  if (listDis[numDis].profDis[ln] == '\n')
      listDis[numDis].profDis[ln] = '\0';

  for(i=0;i<numProf;i++){
    teste = strcmp(listDis[numDis].profDis,listProf[i].nomeProf);
    if(teste == 0){
      i=numProf;
    }
    }
  if(teste!=0){
    printf("\nERRO: Professor não encontrado.");
    }
  else{
    __fpurge(stdin);
    return completado;
  }
}

void listardis(cadDis listDis[], int numDis)
{
      printf("\n*******************\n");
      for (int i = 0; i < numDis; i++)
    {
        printf("----------\n");
        printf("Nome: %s (%d)\n", listDis[i].nomeDis,i);
        printf("Código: %s\n", listDis[i].codDis);
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
    ln = strlen(listDis[ndd].codDis) -1;
    if (listDis[ndd].codDis[ln] == '\n')
        listDis[ndd].codDis[ln] = '\0';

    printf("Digite o nome do professor da disciplina: ");
    fgets(listDis[ndd].profDis, 40, stdin);
    ln = strlen(listDis[ndd].profDis) -1;
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