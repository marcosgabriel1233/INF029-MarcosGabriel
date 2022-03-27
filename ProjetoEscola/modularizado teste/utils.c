#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
include "utils.h"

{
  int mes, i;
  printf("Informe o mês: \n");
  scanf("%d",&mes);

  printf("Anivérsariantes do Mês %d:\n\n",mes);
  for(i=0;i<numAlunos;i++){
    if(listAlunos[i].dataAluno.mes == mes){
      printf("- %s (Aluno)\n",listAlunos[i].nome);
    }
  }
  for(i=0;i<numProf;i++){
    if(listProf[i].dataProf.mes == mes){
      printf("- %s (Prof.)\n",listProf[i].nomeProf); 
    }
  }
}