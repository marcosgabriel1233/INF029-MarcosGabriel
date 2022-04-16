// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Marcos Gabriel Carvalho de Oliveira
//  email: mgoliveira2021@gmail.com
//  Matrícula: 20212160050
//  Semestre: 2022.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "MarcosGabriel20212160050T1.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>


DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i;

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if((i == 1 || i == 2) && (data[i] != 'a' || data[i] != 'b' || data[i] != 'c' || data[i] != 'd' || data[i] != 'e' || data[i] != 'f' || data[i] != 'g' || data[i] != 'h' ||      data[i] != 'i' || data[i] != 'j' || data[i] != 'k' || data[i] != 'l' || data[i] != 'm' || data[i] != 'n' || data[i] != 'o' || data[i] != 'p' || data[i] != 'q' ||           data[i] != 'r' || data[i] != 's' || data[i] != 't' || data[i] != 'u' || data[i] != 'v' || data[i] != 'x' || data[i] != 'w' || data[i] != 'y' || data[i] != 'z')){ 
		sDia[i] = '\0';  // coloca o barra zero no final
	}else 
		dq.valido = 0;
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2 && (data[j] != 'a' || data[j] != 'b' || data[j] != 'c' || data[j] != 'd' || data[j] != 'e' || data[j] != 'f' || data[j] != 'g' || data[j] != 'h' ||      data[j] != 'i' || data[j] != 'j' || data[j] != 'k' || data[j] != 'l' || data[j] != 'm' || data[j] != 'n' || data[j] != 'o' || data[j] != 'p' || data[j] != 'q' ||           data[j] != 'r' || data[j] != 's' || data[j] != 't' || data[j] != 'u' || data[j] != 'v' || data[j] != 'x' || data[j] != 'w' || data[j] != 'y' || data[j] != 'z')){
		sMes[i] = '\0';  // coloca o barra zero no final
	}else
		dq.valido = 0;
	
	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4 && (data[j] != 'a' || data[j] != 'b' || data[j] != 'c' || data[j] != 'd' || data[j] != 'e' || data[j] != 'f' || data[j] != 'g' || data[j] != 'h' ||      data[j] != 'i' || data[j] != 'j' || data[j] != 'k' || data[j] != 'l' || data[j] != 'm' || data[j] != 'n' || data[j] != 'o' || data[j] != 'p' || data[j] != 'q' ||           data[j] != 'r' || data[j] != 's' || data[j] != 't' || data[j] != 'u' || data[j] != 'v' || data[j] != 'x' || data[j] != 'w' || data[j] != 'y' || data[j] != 'z')){
		sAno[i] = '\0';  // coloca o barra zero no final
	}else
		dq.valido = 0;

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno); 

	dq.valido = 1;
  
  return dq;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;

  if (iMes > 12 || iMes < 1 || iDia < 1 || iDia > 31){
		datavalida = 0;
	}
    
	else if ((iDia < 1 && iDia > 31) && (iMes == 1||iMes == 3||iMes == 5||iMes == 7||mes == 8||iMes == 10||iMes == 12)) {
		datavalida = 0;
	}
    
	else if ((iDia < 1 && iDia > 30) && (iMes == 4|| iMes == 6 || iMes == 9 || iMes == 11)){
    datavalida = 0;
  }
    
	else if (iAno % 400 == 0 || (iAno % 4 == 0 && iAno % 100 != 0)) {
		if (iMes == 2 && iDia > 29) {
			datavalida = 0;
		}
	}
    
	else if (iMes == 2 && iDia > 28) {
		datavalida = 0;
	}
  
}

    if (datavalida == 1)
        return 1;
    else
        return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 2;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      
      //calcule a distancia entre as datas


      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}
