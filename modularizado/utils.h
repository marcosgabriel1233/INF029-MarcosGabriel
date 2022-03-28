#ifndef UTILS_H
#define UTILS_H

typedef struct data
{
    int dia;
    int mes;
    int ano;
} datanasc;

void aniversarios (cadProf listProf[], cadAlunos listAlunos[], int numAlunos, int numProf);

#endif