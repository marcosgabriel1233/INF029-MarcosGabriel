#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "aluno.h"
#include "menu.h"
#include "prof.h"
#include "dis.h"
#include "utils.h"

cadAlunos listAlunos[n];
cadProf listProf[n];
cadDis listDis[n];
char *pt1, *pt2;
int numAlunos = 0;
int numProf = 0;
int numDis = 0;
int opcao, opcaoAlunos, opcaoProf, opcaoDis, opcaoRel, retorno;
int sair = 0;

int main(void)
{  
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
                retorno = excluiraluno(listAlunos, numAlunos);
                if(retorno == completado){
                  numAlunos--;
                }
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
                retorno = excluirprof(listProf, numProf);
                if(retorno == completado){
                  numProf--;
                }
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
                retorno = excluirdis(listDis, numDis);
                if(retorno == completado){
                  numDis--;
                }
                break;
                }
              }
              /*default:{
                printf("\nOpção Inválida. Tente novamente.\n");
                break;
              }*/
            break;
            }//Disciplina.
          case 4:{
            opcaoRel = menuRel();
            switch(opcaoRel){
              case 0:{
                  break;
                }
              case 1:{
                sexoalunos(listAlunos, numAlunos);
                break;
              }
              case 2:{
                sexoprof (listProf, numProf);
                break;
              }
              case 3:{
                alfabeticaAlunos(listAlunos, numAlunos);
                break;
              }
              case 4:{
                alfabeticaProf(listProf, numProf);
                break;
              }
              case 5:{
                aniversarios (listProf, listAlunos, numAlunos, numProf);
                break;
              }
              default:{
                printf("\nOpção Inválida. Tente novamente.\n");
                break;
              }
              break;
            }
          }//Relatórios.
          }
    }
}