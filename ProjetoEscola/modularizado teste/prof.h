#ifndef PROF_H
#define PROF_H

#include "utils.h"

typedef struct professor
{
    char nomeProf[40];
    char sexoProf[2];
    char cpfProf[15];
    datanasc dataProf;
    int matriculaProf;
} cadProf;

int cadastroprof(cadProf listProf[], int numProf);
void listarprof(cadProf listProf[], int numProf);
int atualizarprof(cadProf listProf[], int numProf);
int excluirprof(cadProf listProf[], int numProf);

void sexoprof (cadProf listProf[], int numProf);
void alfabeticaProf (cadProf listProf[], int numProf);

cadProf listProf[n];

#endif