#include "ModuloAluno.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opcaoAlunos;
extern int qtdAlunos;
extern int qtdDisciplina;

int ModuloAluno(Aluno listaAluno[], Disciplina listaDisciplina[]);
int AtualizarAluno(Aluno listaAluno[]);
int RemoverAluno(Aluno listaAluno[]);
int CadastroAluno(Aluno listaAluno[]);

extern int opcao;
int lnAluno;
char validaCPF[15];
int corretoCPF;

int ListarAluno(Aluno listaAluno[], Disciplina listaDisciplina[]) {

  while (opcao != 0) {
    printf("Buscar Alunos:\n");
    printf("Digite o numero da opção desejada:\n");
    printf("1 - Buscar Alunos Ordenados por Nome\n");
    printf("2 - Buscar Alunos Ordenados por Data de Nascimento\n");
    printf("3 - Listar Alunos matriculados em 3 ou mais Disciplinas\n");
    printf("4 - Listar Alunos por Sexo\n");
    printf("5 - Listar todos os Alunos\n");
    printf("6 - Listar Aniversariantes do mês\n");
    printf("9 - Retornar Menu Anterior\n");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
    case 1:

      break;
    case 2:

      break;
    case 3:
      printf("###### Alunos Cadastrados em 3 ou mais Disciplinas: ######\n");
      if (qtdAlunos > 0) {
        int qtdMatricula = 0;
        for (int i = 0; i < qtdAlunos; i++) {
          for (int j = 0; j < qtdDisciplina; j++) {
            for (int l = 0; l < TAM; l++) {
              if (listaDisciplina[j].matriculaAluno[l] ==
                  listaAluno[i].matricula) {
                qtdMatricula++;
              }
            }
          }
          if (qtdMatricula >= 3) {
            printf("Aluno: %s. Disciplinas Matriculadas: %d",
                   listaAluno[i].nome, qtdMatricula);
          }
          qtdMatricula = 0;
        }
      } else
        printf("Nenhum Aluno Cadastrado\n");
      printf("####################\n");
      break;
    case 4:
      printf("###### Alunos Cadastrados por Sexo: ######\n");
      if (qtdAlunos > 0) {
        printf("Alunos Cadastrados do sexo Masculino:\n");
        for (int i = 0; i < qtdAlunos; i++) {
          if (listaAluno[i].sexo == 'm' || listaAluno[i].sexo == 'M') {
            printf("Nome: %s\n", listaAluno[i].nome);
            printf("Matricula: %d\n", listaAluno[i].matricula);
          }
        }
          printf("Alunos Cadastrados do sexo Feminino:\n");
          for (int i = 0; i < qtdAlunos; i++) {
            if (listaAluno[i].sexo == 'f' || listaAluno[i].sexo == 'F') {
              printf("Nome: %s\n", listaAluno[i].nome);
              printf("Matricula: %d\n", listaAluno[i].matricula);
            }
          }
        }
       else
        printf("Nenhum Aluno Cadastrado\n");
      printf("####################\n");
      break;
    case 5:
      printf("###### Alunos Cadastrados ######\n");
      if (qtdAlunos > 0) {
        printf("%d Alunos Cadastrados:\n", qtdAlunos);
        for (int i = 0; i < qtdAlunos; i++) {
          printf("Nome: %s\n", listaAluno[i].nome);
          printf("Matricula: %d\n", listaAluno[i].matricula);
        }
      } else
        printf("Nenhum Aluno Cadastrado\n");
      printf("####################\n");
      break;
    case 6:
        printf("Informe o mês que deseja obter os aniversariantes:\n");
        int niverMes = 0;
        scanf("%d", &niverMes);

        if(niverMes<=0 || niverMes>12)
          printf("Valor digitado invalido.\n");
        else{
          int qtdNiver=0;
          for(int i=0; i<qtdAlunos;i++){                    
            if(listaAluno[i].dataNas.mes == niverMes){
              printf("Aniversariante do mes %d:\n", niverMes);
              printf("Aluno: %s\n", listaAluno[i].nome);
              qtdNiver++;
            }
          }
          if(qtdNiver==0)
            printf("Sem aniversariantes no mes de %d.\n", niverMes);
        }
        
      
      
    case 9:
      return 9;
      break;
    default:
      printf("Opcao invalida, digite novamente o valor desejado:\n");
      opcao--;
    }
  }
  return 0;
}

int ModuloAluno(Aluno listaAluno[], Disciplina listaDisciplina[]) {

  while (opcao != 0) {
    printf("Bem vindo ao Modulo Aluno\n");
    printf("Digite o numero da opção desejada:\n");
    printf("1 - Cadastrar Alunos\n");
    printf("2 - Listar Alunos\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Remover Aluno\n");
    printf("9 - Retornar Menu Anterior\n");

    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
    case 1:
      opcao = CadastroAluno(listaAluno);
      break;
    case 2:
      opcao = ListarAluno(listaAluno, listaDisciplina);
      break;
    case 3:
      opcao = AtualizarAluno(listaAluno);
      break;
    case 4:
      opcao = RemoverAluno(listaAluno);
      break;
    case 9:
      return opcao;
      break;
    default:
      printf("Opcao invalida, digite novamente o valor desejado:\n");
      opcao--;
    }
  }
  return opcao;
}

int CadastroAluno(Aluno listaAluno[]) {
  
  while (opcao == 1) {
    corretoCPF = 0;
    // definir qtd alunos como parametro de if

    printf("##### Tela de Cadastro do Aluno #####\n");
    printf("Alunos cadastrados: %d\n", qtdAlunos);
    if (qtdAlunos >= TAM) {
      printf("Lista de alunos totalmente preenchida\n");
      return 9;
    }

    printf("Informe o nome do aluno\n");

    fgets(listaAluno[qtdAlunos].nome, 50, stdin);
    size_t ln = strlen(listaAluno[qtdAlunos].nome) -
                1; // size_t = unsigned integer type
    if (listaAluno[qtdAlunos].nome[ln] == '\n')
      listaAluno[qtdAlunos].nome[ln] = '\0';
    do {
      printf("Digite o Sexo. M para masculino e F para feminino:\n");
      scanf("%c", &listaAluno[qtdAlunos].sexo);
      getchar();
      if (listaAluno[qtdAlunos].sexo != 'm' &&
          listaAluno[qtdAlunos].sexo != 'M' &&
          listaAluno[qtdAlunos].sexo != 'f' &&
          listaAluno[qtdAlunos].sexo != 'F')
        printf("Digite um valor de sexo valido\n");
    } while (listaAluno[qtdAlunos].sexo != 'm' &&
             listaAluno[qtdAlunos].sexo != 'M' &&
             listaAluno[qtdAlunos].sexo != 'f' &&
             listaAluno[qtdAlunos].sexo != 'F');

    do {
      printf("Digite a Data de Nascimento do Aluno:\n");
      scanf("%d %d %d", &listaAluno[qtdAlunos].dataNas.dia,
            &listaAluno[qtdAlunos].dataNas.mes,
            &listaAluno[qtdAlunos].dataNas.ano);
      getchar();
      printf("\n");
    } while (listaAluno[qtdAlunos].dataNas.dia < 1 ||
             listaAluno[qtdAlunos].dataNas.dia > 31 ||
             listaAluno[qtdAlunos].dataNas.mes < 1 ||
             listaAluno[qtdAlunos].dataNas.mes > 12 ||
             listaAluno[qtdAlunos].dataNas.ano > 2023);
    do {
      printf("Digite a matricula de %s\n", listaAluno[qtdAlunos].nome);
      scanf("%d", &listaAluno[qtdAlunos].matricula);
      getchar();
      if (listaAluno[qtdAlunos].matricula <= 0)
        printf("Valor invalido.\n");
    } while (listaAluno[qtdAlunos].matricula <= 0);

    do {

      printf("Digite  CPF do Aluno com '.' e'-':");

      fgets(validaCPF, 15, stdin);

      lnAluno =
          strlen(validaCPF) - 1; // na função fgets o ultimo termo é o '\n' por
                                 // isso fica com mais uma identação
      if (validaCPF[lnAluno] == '\n') {
        validaCPF[lnAluno] = '\0';
      }

      if (validaCPF[3] == '.' && validaCPF[7] == '.' && validaCPF[11] == '-') {
        strcpy(listaAluno[qtdAlunos].cpf,
               validaCPF); // essa função copia a strcpy(destino,	copiada)
        corretoCPF = 1;
      } else
        printf("Formato incorreto:\n");
    } while (corretoCPF==0);
    
    qtdAlunos++;

    printf("\n");
    printf("### Deseja cadastrar outro aluno? ###\n");
    printf("##Opcao 1- Sim");
    printf("##Opcao 9 - Nao");
    scanf("%d", &opcao);
    getchar();
    if (opcao != 1 && opcao != 9) {
      printf("Opcao nao encontrada, escolha entre as disponiveis \n");
      while (opcao != 1 && opcao != 9) {
        printf("##Opcao 1- Sim");
        printf("##Opcao 9 - Nao");
        scanf("%d", &opcao);
        getchar();
      }
    }
  }
  return 9;
}

int AtualizarAluno(Aluno listaAluno[]) {
  corretoCPF = 0;
  while (opcao == 3) {
    printf("##### Atualização de alunos #####\n");

    if (qtdAlunos == 0) {
      printf("No momento não existem alunos cadastrados\n");
      return 3;
    } else {
      printf("Alunos cadastrados: %d\n", qtdAlunos);
      for (int count = 0; count < qtdAlunos; count++) {
        printf("Posição %d\n", count);
        printf("%s\n", listaAluno[count].nome);
        printf("%s\n", listaAluno[count].cpf);
        printf("%c\n", listaAluno[count].sexo);
        printf("%d\n", listaAluno[count].matricula);
        printf("%d/%d/%d\n", listaAluno[count].dataNas.dia,
               listaAluno[count].dataNas.mes, listaAluno[count].dataNas.ano);
        printf("\n");
      }
      opcaoAlunos = TAM + 1;
      while (opcaoAlunos < 0 || opcaoAlunos >= qtdAlunos) {
        printf("Informe a posicao do aluno que deseja atualizar:\n");
        scanf("%d", &opcaoAlunos);
        getchar();
        if (opcaoAlunos < 0 || opcaoAlunos >= qtdAlunos) {
          printf("Posicao incorreta, informe uma posição presente na lista "
                 "anterior\n");
        } else {

          printf("Insira o novo nome para %s:\n", listaAluno[opcaoAlunos].nome);
          fgets(listaAluno[opcaoAlunos].nome, 50, stdin);
          size_t ln = strlen(listaAluno[opcaoAlunos].nome) -
                      1; // size_t = unsigned integer type
          if (listaAluno[opcaoAlunos].nome[ln] == '\n')
            listaAluno[opcaoAlunos].nome[ln] = '\0';

          do {

            printf("Insira um novo CPF do Aluno com '.' e'-':");

            fgets(validaCPF, 15, stdin);

            lnAluno = strlen(validaCPF) -
                      1; // na função fgets o ultimo termo é o '\n' por
                         // isso fica com mais uma identação
            if (validaCPF[lnAluno] == '\n') {
              validaCPF[lnAluno] = '\0';
            }

            if (validaCPF[3] == '.' && validaCPF[7] == '.' &&
                validaCPF[11] == '-') {
              strcpy(listaAluno[opcaoAlunos].cpf,
                     validaCPF); // essa função copia a strcpy(destino,	copiada)
              corretoCPF = 1;
            } else
              printf("Formato incorreto:\n");
          } while (!corretoCPF);
          do {
            getchar();
            printf("Digite o Sexo. M para masculino e F para feminino:\n");
            scanf("%c", &listaAluno[opcaoAlunos].sexo);
            getchar();
            if (listaAluno[opcaoAlunos].sexo != 'm' &&
                listaAluno[opcaoAlunos].sexo != 'M' &&
                listaAluno[opcaoAlunos].sexo != 'f' &&
                listaAluno[opcaoAlunos].sexo != 'F')
              printf("Digite um valor de sexo valido\n");
          } while (listaAluno[opcaoAlunos].sexo != 'm' &&
                   listaAluno[opcaoAlunos].sexo != 'M' &&
                   listaAluno[opcaoAlunos].sexo != 'f' &&
                   listaAluno[opcaoAlunos].sexo != 'F');
          do {
            printf("Digite a matricula de %s\n", listaAluno[opcaoAlunos].nome);
            scanf("%d", &listaAluno[opcaoAlunos].matricula);
            getchar();
            if (listaAluno[opcaoAlunos].matricula <= 0)
              printf("Valor invalido.\n");
          } while (listaAluno[opcaoAlunos].matricula <= 0);
          do {
            printf("Digite a Data de Nascimento do Aluno:\n");
            scanf("%d %d %d", &listaAluno[opcaoAlunos].dataNas.dia,
                  &listaAluno[opcaoAlunos].dataNas.mes,
                  &listaAluno[opcaoAlunos].dataNas.ano);
            printf("\n");
          } while (listaAluno[opcaoAlunos].dataNas.dia < 1 ||
                   listaAluno[opcaoAlunos].dataNas.dia > 31 ||
                   listaAluno[opcaoAlunos].dataNas.mes < 1 ||
                   listaAluno[opcaoAlunos].dataNas.mes > 12 ||
                   listaAluno[opcaoAlunos].dataNas.ano > 2023);
          opcaoAlunos = 3;
          while (opcaoAlunos == 3) {
            printf("#### Aluno atualizado com sucesso:\n Deseja atualizar "
                   "outro aluno?\n Digite 3 para sim ou 9 para não:\n");
            scanf("%d", &opcaoAlunos);
            getchar();
            if (opcaoAlunos == 3) {
              opcao = 3;
              opcaoAlunos = 0;
            } else if (opcaoAlunos == 9) {
              opcao = 9;
              opcaoAlunos = 9;
            } else {
              printf("Opção inválida, digite novamente.\n");
              opcaoAlunos = 3;
              opcao = 3;
            }
          }
        }
      }
    }
  }
  return 9;
}

int RemoverAluno(Aluno listaAluno[]) {
  Aluno copiaAluno;
  if (qtdAlunos == 0) {
    printf("Não há alunos cadastrados!!!\n");
    return 4;
  }

  while (opcao == 4) {
    printf("###### Alunos Cadastrados ######\n");
    printf("%d Alunos Cadastrados:\n", qtdAlunos);
    for (int i = 0; i <= qtdAlunos; i++) {
      printf("Posição %d: \n %s\n", i, listaAluno[i].nome);
    }
    printf("Digite a posição do aluno que deseja remover:\n");
    scanf("%d", &opcaoAlunos);
    getchar();
    if (opcaoAlunos < 0 || opcaoAlunos >= qtdAlunos) {
      printf("Posicao invalida\n");
    } else {

      listaAluno[opcaoAlunos].cpf[0] = '\0';
      listaAluno[opcaoAlunos].dataNas.ano = 0;
      listaAluno[opcaoAlunos].dataNas.mes = 0;
      listaAluno[opcaoAlunos].dataNas.dia = 0;
      listaAluno[opcaoAlunos].nome[0] = '\0';
      listaAluno[opcaoAlunos].sexo = '\0';
      listaAluno[opcaoAlunos].matricula = 0;
      for (int j = opcaoAlunos; j < qtdAlunos - 1;
           j++) { // reordenação do vetor!
        copiaAluno = listaAluno[j];
        listaAluno[j] = listaAluno[j + 1];
        listaAluno[j + 1] = copiaAluno;
      }
      printf("Aluno excluido com sucesso");
      opcao = 5;
      qtdAlunos--;
    }
  }
  return 4;
}

// Listar Alunos por sexo (Masculino/Feminino)
//◦ Listar Alunos ordenados por Nome
//◦ Listar Alunos ordenados por data de nascimento
// Lista de alunos matriculados em menos de 3 disciplinas
// atualizar e remover alunos}