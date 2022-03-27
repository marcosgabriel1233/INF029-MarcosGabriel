#ifndef ALUNO_H
#define ALUNO_H

#include "utils.h"

#define n 50
#define completado 1

typedef struct alunos
{
    char nome[40];
    char sexoAluno[2];
    char cpfAluno[15];
    datanasc dataAluno;
    int matriculaAluno;
} cadAlunos;

int cadastroaluno(cadAlunos listAlunos[], int numAlunos);
void listaraluno(cadAlunos listAlunos[], int numAlunos);
int atualizaraluno(cadAlunos listAlunos[], int numAlunos);
int excluiraluno(cadAlunos listAlunos[], int numAlunos);

void sexoalunos(cadAlunos listAlunos[], int numAlunos);
void alfabeticaAlunos (cadAlunos listAlunos[], int numAlunos);

cadAlunos listAlunos[n];

#endif