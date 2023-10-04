// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do
//  trabalho

//  ----- Dados do Aluno -----
//  Nome: Julian Freitas Reina
//  email: julianreina@gmail.com
//  Matrícula: 20212160005
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include "JulianFreitas-20212160005.h" // Substitua pelo seu arquivo de header renomeado
#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <string.h>
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y) {
  int soma;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x) { // função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a) {
  int val;
  if (a == 2)
    val = 3;
  else
    val = 4;

  return val;
}

DataQuebrada quebraData(char data[]) {
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;

  for (i = 0; data[i] != '/'; i++) {
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sDia[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  int j = i + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++) {
    sMes[i] = data[j];
    i++;
  }

  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sMes[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  j = j + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '\0'; j++) {
    sAno[i] = data[j];
    i++;
  }

  if (i == 2 || i == 4) { // testa se tem 2 ou 4 digitos
    sAno[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

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
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia,
mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa
podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]) {
  int datavalida = 1;

  // quebrar a string data em strings sDia, sMes, sAno

  DataQuebrada dataQuebrada = quebraData(data);

  datavalida = dataQuebrada.valido;

  if (datavalida == 1) {
    if (dataQuebrada.iMes > 0 && dataQuebrada.iMes <= 12) {
      if (dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 28)
        return 1;

      else if (dataQuebrada.iDia >= 29 && dataQuebrada.iDia <= 31) {

        if (dataQuebrada.iMes == 2) {
          if (dataQuebrada.iDia != 29)
            return 0;
          else {
            if (dataQuebrada.iAno % 4 == 0) {
              if (dataQuebrada.iAno % 100 == 0) {
                if (dataQuebrada.iAno % 400 == 0)
                  return 1;
                else
                  return 0;
              } else
                return 1;
            } else
              return 0;

            // validacao bissexto
          }
        } else if (dataQuebrada.iDia == 31) {
          if (dataQuebrada.iMes % 2 != 0 || dataQuebrada.iMes == 8)
            return 1;
          else
            return 0;
        } else
          return 1;
      } else
        return 0;
    } else
      return 0;
  }

  else
    return 0;
  // if (dataQuebrada.valido == 0) return 0;

  // printf("%s\n", data);
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis
 valores abaixo 1 -> cálculo de diferença realizado com sucesso 2 -> datainicial
 inválida 3 -> datafinal inválida 4 -> datainicial > datafinal Caso o cálculo
 esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos
 com os valores correspondentes.
 */int QdtDiasMes(int mes, int ano) {
  switch (mes) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
  case 4:
  case 6:
  case 9:
  case 11:
    return 30;
  case 2: {
    if (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)) {
      return 29;
    } else {
      return 28;
    }
  }
  }
}

int QtdDiasAno(int mes, int ano) {
  int dias = 0;
  int MESES = 1;
  while (mes > MESES) {
    dias = dias + QdtDiasMes(MESES, ano);
    MESES++;
  }
  return dias;
}
DiasMesesAnos q2(char datainicial[], char datafinal[]) {
  DiasMesesAnos dma;

  if (q1(datainicial) == 0) {
    dma.retorno = 2; 
    return dma;
  } else if (q1(datafinal) == 0) {
    dma.retorno = 3; 
    return dma;
  } else {
    
    DataQuebrada dmai = quebraData(datainicial);
    DataQuebrada dmaf = quebraData(datafinal);

    if ((dmai.iAno > dmaf.iAno) ||
        (dmai.iAno == dmaf.iAno && dmai.iMes > dmaf.iMes) ||
        (dmai.iAno == dmaf.iAno && dmai.iMes == dmaf.iMes &&
         dmai.iDia > dmaf.iDia)) {
      dma.retorno = 4;
      return dma;
    } else {
      int mes = QdtDiasMes(dmai.iMes, dmai.iAno);
      dma.retorno = 1; 
      int datai = QtdDiasAno(dmai.iMes, dmai.iAno) + dmai.iDia;
      datai = datai + dmai.iAno * 365;
      int dataf = QtdDiasAno(dmaf.iMes, dmaf.iAno) + dmaf.iDia;
      dataf = dataf + dmaf.iAno * 365;
      int difdata = dataf - datai;
      dma.qtdAnos = difdata / 365;
      difdata +=
          QtdDiasAno(dmai.iMes, dmai.iAno) == QtdDiasAno(dmaf.iMes, dmaf.iAno);
      difdata = difdata - dma.qtdAnos * 365;
      dma.qtdMeses = difdata / mes;
      dma.qtdDias = difdata % mes;

      return dma;
    }
  }
  dma.retorno = 1;
  return dma;
}



/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa
 Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar
 diferenças entre maiúsculos e minúsculos. Se isCaseSensitive != 1, a pesquisa
 não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) {
  int qtdOcorrencias = 0;

  if (isCaseSensitive == 1) {
    for (int i = 0; texto[i] != '\0'; i++) {
      if (texto[i] == c)
        qtdOcorrencias++;
    }
    return qtdOcorrencias;
  } else {
    for (int i = 0; texto[i] != '\0'; i++) {
      if (texto[i] == c || texto[i] + 32 == c || texto[i] == c + 32)
        qtdOcorrencias++;
    }
    return qtdOcorrencias;
  }
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros
 (posicoes) que irá guardar as posições de início e fim de cada ocorrência da
 palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída
 correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do
 vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve
 ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a
 segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente.
 Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como
 há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da
 seguinte forma: posicoes[0] = 13; posicoes[1] = 16; Observe que o índice da
 posição no texto deve começar ser contado a partir de 1. O retorno da função,
 n, nesse caso seria 1;

 */

int q4(char *strTexto, char *strBusca, int posicoes[30]) {

  int tam, aux, i, j, ver, k, qtd, neg;
  char text[250], busca[30];
  strcpy(text, strTexto);
  strcpy(busca, strBusca);
  int qtdOcorrencias = 0;
  for (tam = 0; busca[tam] != '\0'; tam++) {
  }
  // printf("%d ", tam);
  qtd = 0;
  neg = 0;
  for (i = 0; text[i] != '\0'; i++) {
    if (text[i] == -61) {
      neg++;
    }
    if (text[i] == busca[0]) {
      k = 0;
      aux = i + 1 - neg;
      j = i;
      ver = 0;
      while (text[j] == busca[k]) {
        ver++;
        j++;
        k++;
        i++;
      }
      if (ver == tam) {
        posicoes[qtd] = aux;
        posicoes[qtd + 1] = aux + tam - 1;
        qtdOcorrencias++;
        i--;
        qtd += 2;
      }
    }
  }

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

int q5(int num) {

  int invertido = 0;
  while (num > 0) {
    invertido = invertido * 10 + num % 10;
    num /= 10;
  }
  return invertido;
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
int numerodeDigitos(int num) {
  int contador = 1;
  while (num > 9) {
    num /= 10;
    contador++;
  }
  return contador;
}

int q6(int numerobase, int numerobusca) {
  if (numerobase < numerobusca) {
    return 0;
  }
  int qtdocorrencias = 0;
  int digitosnumerobase = numerodeDigitos(numerobase);
  int digitosnumerobusca = numerodeDigitos(numerobusca);
  // printf("qtd dig busca:%d\n",digitosnumerobusca);
  int auxbase = numerobase;
  int auxbusca = numerobusca;
  int digit = 0;

  while (auxbase != 0) {
    int digitosauxbase = numerodeDigitos(auxbase);
    int rbase, rbusca;
    rbase = auxbase % 10;
    // printf("restobase:%d\n",rbase);
    auxbase /= 10;
    // printf("auxbase:%d\n",auxbase);
    if (auxbusca / 10 != 0) {
      rbusca = auxbusca % 10;
      auxbusca /= 10;
    } else {
      rbusca = auxbusca % 10;
      auxbusca = numerobusca;
    }

    // printf("rbusca:%d rbase:%d\n",rbusca ,rbase);
    // printf("auxbusca:%d auxbase:%d\n",auxbusca ,auxbase);
    if (rbusca == rbase) {
      digit++;
      // printf("digit:%d\n",digit);
    } else {
      auxbusca = numerobusca;
      digit = 0;
    }

    if (digit == digitosnumerobusca) {
      qtdocorrencias++;
      digit = 0;
      // printf("qtdocorrencias:%d\n",qtdocorrencias);
    }
    if (digitosnumerobusca == 1) {
      digit = 0;
    }
  }
  // printf("*** OCORRENCIAS:%d ***",qtdocorrencias);
  return qtdocorrencias;
}

