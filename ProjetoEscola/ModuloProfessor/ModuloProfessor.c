#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2
#include "ModuloProfessor.h"

extern int qtdProfessores;

int ModuloProfessor(Prof listaProf[]);
int CadastroProfessor(Prof listaProf[]);
int ListarProfessores(Prof listaProf[]);
int AtualizarProfessor(Prof listaProf[]);
int RemoverProfessor(Prof listaProf[]);
int lnProfessor;
char validaCPFProf[15];
int opcaoProfessor;
extern int opcao;

int ModuloProfessor(Prof listaProf[]) {

  while (opcao != 0) {
    printf("Bem vindo ao Modulo Professor\n");
    printf("Digite o numero da opção desejada:\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professores\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Remover Professor\n");
    printf("9 - Retornar Menu Anterior\n");

    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
    case 1:
      opcao = CadastroProfessor(listaProf);
      break;
    case 2:
      opcao = ListarProfessores(listaProf);
      break;
    case 3:
      opcao = AtualizarProfessor(listaProf);
      break;
    case 4:
      opcao = RemoverProfessor(listaProf);
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

int CadastroProfessor(Prof listaProf[]) {

  while (opcao == 1) {
    int corretoCPF = 0;

    // definir qtd alunos como parametro de if

    printf("##### Tela de Cadastro do Professor #####\n");
    printf("Professores cadastrados: %d\n", qtdProfessores);
    if (qtdProfessores >= TAM) {
      printf("Lista de Professores totalmente preenchida\n");
      return 9;
    }

    printf("Informe o nome do professor\n");
    fgets(listaProf[qtdProfessores].nome, 50, stdin);
    size_t ln = strlen(listaProf[qtdProfessores].nome) -
                1; // size_t = unsigned integer type
    if (listaProf[qtdProfessores].nome[ln] == '\n')
      listaProf[qtdProfessores].nome[ln] = '\0';
    do {
      printf("Digite o Sexo. M para masculino e F para feminino:\n");
      scanf("%c", &listaProf[qtdProfessores].sexo);
      getchar();

      if (listaProf[qtdProfessores].sexo != 'm' &&
          listaProf[qtdProfessores].sexo != 'M' &&
          listaProf[qtdProfessores].sexo != 'f' &&
          listaProf[qtdProfessores].sexo != 'F')
        printf("Digite um valor de sexo valido\n");
    } while (listaProf[qtdProfessores].sexo != 'm' &&
             listaProf[qtdProfessores].sexo != 'M' &&
             listaProf[qtdProfessores].sexo != 'f' &&
             listaProf[qtdProfessores].sexo != 'F');

    do {
      printf("Digite a Data de Nascimento do Professor:\n");
      scanf("%d %d %d", &listaProf[qtdProfessores].dataNas.dia,
            &listaProf[qtdProfessores].dataNas.mes,
            &listaProf[qtdProfessores].dataNas.ano);
      getchar();
      printf("\n");
    } while (listaProf[qtdProfessores].dataNas.dia < 1 ||
             listaProf[qtdProfessores].dataNas.dia > 31 ||
             listaProf[qtdProfessores].dataNas.mes < 1 ||
             listaProf[qtdProfessores].dataNas.mes > 12 ||
             listaProf[qtdProfessores].dataNas.ano > 2023);
    do {
      printf("Digite a matricula de %s\n", listaProf[qtdProfessores].nome);
      scanf("%d", &listaProf[qtdProfessores].matricula);
      getchar();
      if (listaProf[qtdProfessores].matricula <= 0)
        printf("Valor invalido.\n");
    } while (listaProf[qtdProfessores].matricula <= 0);

    do {

      printf("Digite o CPF do Professor com '.' e'-':");

      fgets(validaCPFProf, 15, stdin);

      lnProfessor =
          strlen(validaCPFProf) - 1; // na função fgets o ultimo termo é o '\n'
                                     // por isso fica com mais uma identação
      if (validaCPFProf[lnProfessor] == '\n') {
        validaCPFProf[lnProfessor] = '\0';
      }

      if (validaCPFProf[3] == '.' && validaCPFProf[7] == '.' &&
          validaCPFProf[11] == '-') {
        strcpy(listaProf[qtdProfessores].cpf,
               validaCPFProf); // essa função copia a strcpy(destino,	copiada)
        corretoCPF = 1;
      } else
        printf("Formato incorreto:\n");
    } while (!corretoCPF);

    qtdProfessores++;

    printf("\n");
    printf("### Deseja cadastrar outro professor? ###\n");

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

int ListarProfessores(Prof listaProf[]) {

  while (opcao != 0) {
    printf("Buscar Professor:\n");
    printf("Digite o numero da opção desejada:\n");
    printf("1 - Buscar Professor Ordenados por Nome\n");
    printf("2 - Buscar Professor Ordenados por Data de Nascimento\n");
    printf("3 - Listar Professor por Sexo\n");
    printf("4 - Listar todos os Professores\n");
    printf("5 - Listar Aniversariantes do mês\n");
    printf("9 - Retornar Menu Anterior\n");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
    case 1:

      break;
    case 2:

      break;
    case 3:

     printf("###### Professores Cadastrados por Sexo: ######\n");
      if (qtdProfessores > 0) {
        printf("Professores Cadastrados:\n");
        for (int i = 0; i <= qtdProfessores; i++) {
          if(listaProf[i].sexo == 'm' || listaProf[i].sexo == 'M'){
          printf("Nome: %s\n", listaProf[i].nome);
          printf("Matricula: %d\n", listaProf[i].matricula);
          }
        }
          printf("Professoras Cadastradas:\n");
        for (int i = 0; i <= qtdProfessores; i++) {
          if(listaProf[i].sexo == 'f' || listaProf[i].sexo == 'F'){
          printf("Nome: %s\n", listaProf[i].nome);
          printf("Matricula: %d\n", listaProf[i].matricula);
          }
        }       
        }
      
       else
        printf("Nenhum Professor Cadastrado\n");
      printf("####################\n");
      break;
    case 4:
      printf("###### Professores Cadastrados ######\n");
      if (qtdProfessores > 0) {
        printf("%d Professores Cadastrados:\n", qtdProfessores);
        for (int i = 0; i <= qtdProfessores; i++) {
          printf("%s\n", listaProf[i].nome);
        }
      } else
        printf("Nenhum Professor Cadastrado\n");
      printf("####################\n");
      break;
      case 5:
      if(qtdProfessores<=0)
        printf("Não há professores cadastrados.\n");
      else{
        int niverMes = 0;
        printf("Informe o mês que deseja obter os aniversariantes:\n");
        scanf("%d", &niverMes);

        if(niverMes<=0 || niverMes>12)
          printf("Valor digitado invalido.\n");
        else{
          int qtdNiver=0;
          for(int i=0; i<=qtdProfessores;i++){          
            printf("Aniversariantes do mes %d:\n", niverMes);
            if(listaProf[i].dataNas.mes == niverMes){
              printf("Professor: %s", listaProf[i].nome);
              qtdNiver++;
            }
          }
          if(qtdNiver==0)
            printf("Sem aniversariantes no mes de %d.\n", qtdNiver);
        }
        
      }
        break;
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

int AtualizarProfessor(Prof listaProf[]) {

  while (opcao == 3) {
    int corretoCPF = 0;
    printf("##### Atualização de professores #####\n");

    if (qtdProfessores == 0) {
      printf("No momento não existem professores cadastrados\n");
      return 3;
    } else {
      printf("Professores cadastrados: %d\n", qtdProfessores);
      for (int count = 0; count < qtdProfessores; count++) {
        printf("Posição %d\n", count);
        printf("%s\n", listaProf[count].nome);
        printf("%s\n", listaProf[count].cpf);
        printf("%c\n", listaProf[count].sexo);
        printf("%d\n", listaProf[count].matricula);
        printf("%d/%d/%d\n", listaProf[count].dataNas.dia,
               listaProf[count].dataNas.mes, listaProf[count].dataNas.ano);
        printf("\n");
      }
      opcaoProfessor = TAM + 1;
      while (opcaoProfessor < 0 || opcaoProfessor >= qtdProfessores) {
        printf("Informe a posicao do professor que deseja atualizar:\n");
        scanf("%d", &opcaoProfessor);
        getchar();
        if (opcaoProfessor < 0 || opcaoProfessor >= qtdProfessores) {
          printf("Posicao incorreta, informe uma posição presente na lista"
                 "anterior\n");
        } else {

          printf("Insira o novo nome para %s:\n",
                 listaProf[opcaoProfessor].nome);
          fgets(listaProf[opcaoProfessor].nome, 50, stdin);
          size_t ln = strlen(listaProf[opcaoProfessor].nome) -
                      1; // size_t = unsigned integer type
          if (listaProf[opcaoProfessor].nome[ln] == '\n')
            listaProf[opcaoProfessor].nome[ln] = '\0';

          do {

            printf("Digite o novo CPF do Professor com '.' e'-':");

            fgets(validaCPFProf, 15, stdin);

            lnProfessor = strlen(validaCPFProf) -
                          1; // na função fgets o ultimo termo é o '\n' por
                             // isso fica com mais uma identação
            if (validaCPFProf[lnProfessor] == '\n') {
              validaCPFProf[lnProfessor] = '\0';
            }

            if (validaCPFProf[3] == '.' && validaCPFProf[7] == '.' &&
                validaCPFProf[11] == '-') {
              strcpy(listaProf[opcaoProfessor].cpf,
                     validaCPFProf); // essa função copia a strcpy(destino,
                                     // copiada)
              corretoCPF = 1;
            } else
              printf("Formato incorreto:\n");
          } while (!corretoCPF);
          do {
            getchar();
            printf("Insira o novo sexo:\n");
            scanf("%c", &listaProf[opcaoProfessor].sexo);
            getchar();
            if (listaProf[opcaoProfessor].sexo != 'm' &&
                listaProf[opcaoProfessor].sexo != 'M' &&
                listaProf[opcaoProfessor].sexo != 'f' &&
                listaProf[opcaoProfessor].sexo != 'F')
              printf("Digite um valor de sexo valido\n");
          } while (listaProf[opcaoProfessor].sexo != 'm' &&
                   listaProf[opcaoProfessor].sexo != 'M' &&
                   listaProf[opcaoProfessor].sexo != 'f' &&
                   listaProf[opcaoProfessor].sexo != 'F');

          do {
            printf("Digite a nova matricula de %s\n",
                   listaProf[opcaoProfessor].nome);
            scanf("%d", &listaProf[opcaoProfessor].matricula);
            getchar();
            if (listaProf[opcaoProfessor].matricula <= 0)
              printf("Valor invalido.\n");
          } while (listaProf[opcaoProfessor].matricula <= 0);
          do {
            printf("Digite a Data de Nascimento do Professor:\n");
            scanf("%d %d %d", &listaProf[opcaoProfessor].dataNas.dia,
                  &listaProf[opcaoProfessor].dataNas.mes,
                  &listaProf[opcaoProfessor].dataNas.ano);
            printf("\n");
          } while (listaProf[opcaoProfessor].dataNas.dia < 1 ||
                   listaProf[opcaoProfessor].dataNas.dia > 31 ||
                   listaProf[opcaoProfessor].dataNas.mes < 1 ||
                   listaProf[opcaoProfessor].dataNas.mes > 12 ||
                   listaProf[opcaoProfessor].dataNas.ano > 2023);
          opcaoProfessor = 3;
          while (opcaoProfessor == 3) {
            printf("#### Professor atualizado com sucesso:\n Deseja atualizar "
                   "outro professor?\n Digite 3 para sim ou 9 para não:\n");
            scanf("%d", &opcaoProfessor);
            getchar();
            if (opcaoProfessor != 3 && opcaoProfessor != 9) {
              printf("Opção inválida, digite novamente.\n");
              opcaoProfessor = 3;
            } else {
              opcaoProfessor = 0;
              opcao = 9;
            }
          }
        }
      }
    }
  }
  return 9;
}

int RemoverProfessor(Prof listaProf[]) {
  Prof copiaProfessor;
  if (qtdProfessores == 0) {
    printf("Não há Professores cadastrados!!!\n");
    return 4;
  }

  while (opcao == 4) {
    printf("###### Professores Cadastrados ######\n");
    printf("%d Professores Cadastrados:\n", qtdProfessores);
    for (int i = 0; i <= qtdProfessores; i++) {
      printf("Posição %d: \n %s\n", i, listaProf[i].nome);
    }
    printf("Digite a posição do professor que deseja remover:\n");
    scanf("%d", &opcaoProfessor);
    getchar();
    if (opcaoProfessor < 0 || opcaoProfessor >= qtdProfessores) {
      printf("Posicao invalida\n");
    } else {

      listaProf[opcaoProfessor].cpf[0] = '\0';
      listaProf[opcaoProfessor].dataNas.ano = 0;
      listaProf[opcaoProfessor].dataNas.mes = 0;
      listaProf[opcaoProfessor].dataNas.dia = 0;
      listaProf[opcaoProfessor].nome[0] = '\0';
      listaProf[opcaoProfessor].sexo = '\0';
      listaProf[opcaoProfessor].matricula = 0;
      for (int j = opcaoProfessor; j < qtdProfessores - 1;
           j++) { // reordenação do vetor!
        copiaProfessor = listaProf[j];
        listaProf[j] = listaProf[j + 1];
        listaProf[j + 1] = copiaProfessor;
      }
      printf("Professor excluido com sucesso");
      opcao = 5;
      qtdProfessores--;
    }
  }
  return 4;
}