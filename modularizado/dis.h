#ifndef DIS_H
#define DIS_H

#include "prof.h"
#include "aluno.h"

typedef struct disciplina
{
    char nomeDis[30];
    char codDis[10];
    int semDis;
    int alunosDis[n];
    char profDis[40];   
} cadDis;

int cadastrodis(cadDis listDis[], int numDis);
void listardis(cadDis listDis[], int numDis);
int atualizardis(cadDis listDis[], int numDis);
int excluirdis(cadDis listDis[], int numDis);

#endif