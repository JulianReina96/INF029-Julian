#include "ModuloDisciplina.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opcaoDisciplina;
extern int qtdDisciplina;
extern int qtdAlunos;
extern int qtdProfessores;

int codigoDisciplina;
int validadorDisciplina = -1;
int validadorAluno = -1;
int matriculaAluno;
int qtdAlunoDisciplina = 0;

int CadastroDisciplina();
int MatricularAluno(int opcaoDisciplina, Aluno listaAluno[],
                    Disciplina listaDisciplinas[]);
int ListarDisciplinas(int opcaoDisciplina, Disciplina listaDisciplina[]);
int AtualizarDisciplina(int opcao, int opcaoDisciplina,
                        Disciplina listaDisciplina[], Prof listaProf[]);
int RemoverDisciplina(int opcaoDisciplina, Disciplina listaDisciplina[]);

int ModuloDisciplina(int opcao, Disciplina listaDisciplina[],
                     Aluno listaAluno[], Prof listaProf[]) {


  while (opcao != 0) {
    printf("Bem vindo ao Modulo Disciplina\n");
    printf("Digite o numero da opção desejada:\n");
    printf("1 - Cadastrar Disciplina\n");
    printf("2 - Listar Disciplinas\n");
    printf("3 - Matricular aluno em Disciplinas\n");
    printf("4 - Atualizar Disciplinas\n");
    printf("5 - Remover Disciplinas\n");
    printf("9 - Retornar Menu Anterior\n");

    scanf("%d", &opcaoDisciplina);
    getchar();

    switch (opcaoDisciplina) {
    case 1:
      opcao = CadastroDisciplina(opcaoDisciplina, listaDisciplina, listaProf);
      break;
    case 2:
      opcao = ListarDisciplinas(opcaoDisciplina, listaDisciplina);
      break;
    case 3:
      opcao = MatricularAluno(opcaoDisciplina, listaAluno, listaDisciplina);
      break;
    case 4:
      opcao = 4;
      opcao = AtualizarDisciplina(opcao, opcaoDisciplina, listaDisciplina,
                                  listaProf);
      break;
    case 5:
      opcao = RemoverDisciplina(opcaoDisciplina, listaDisciplina);
      break;
    case 9:
      return opcaoDisciplina;
      break;
    default:
      printf("Opcao invalida, digite novamente o valor desejado:\n");
      opcao--;
    }
  }
  return opcao;
}

int CadastroDisciplina(int opcaoDisciplina, Disciplina listaDisciplina[],
                       Prof listaProf[]) {
  if(qtdDisciplina==TAM){
    printf("Não é possivel cadastras mais disciplinas. Por favor, exclua alguma para novo cadastro.\n");
    return 9;
  }
  if(qtdProfessores==0)
  {printf("Não há professores lecionando no momento.\n");
  return 9;}

  while (opcaoDisciplina == 1) {
    int validaProf = 0;
    printf("Informe o nome da disciplina:\n");
    fgets(listaDisciplina[qtdDisciplina].nome, 50, stdin);
    size_t ln = strlen(listaDisciplina[qtdDisciplina].nome) -
                1; // size_t = unsigned integer type
    if (listaDisciplina[qtdDisciplina].nome[ln] == '\n')
      listaDisciplina[qtdDisciplina].nome[ln] = '\0';
    printf("Informe o codigo da disciplina:\n");
    scanf("%d", &listaDisciplina[qtdDisciplina].codigo);
    getchar();

    printf("Qual o semestre da disciplina?\n");
    fgets(listaDisciplina[qtdDisciplina].semestre, 6, stdin);
    ln = strlen(listaDisciplina[qtdDisciplina].semestre) -
         1; // size_t = unsigned integer type
    if (listaDisciplina[qtdDisciplina].semestre[ln] == '\n')
      listaDisciplina[qtdDisciplina].semestre[ln] = '\0';
    do {
      printf(
          "Qual professor será vinculado a disciplina?\n Informe o numero da "
          "matricula do mesmo:\n");
      scanf("%d", &listaDisciplina[qtdDisciplina].matriculaProfessor);
      for (int i = 0; i <= qtdProfessores; i++) {
        if (listaDisciplina[qtdDisciplina].matriculaProfessor ==
            listaProf[i].matricula) {
          validaProf = 1;
          break;
        }
      }
      if (validaProf == 0)
        printf("Professor nao encontrado, verifique a matricula e digite "
               "corretamente.\n");
    } while (validaProf == 0);
    qtdDisciplina++;

    printf("\n");
    printf("### Deseja cadastrar outra disciplina? ###\n");
    printf("##Opcao 1- Sim");
    printf("##Opcao 9 - Nao");
    scanf("%d", &opcaoDisciplina);
    getchar();
    if (opcaoDisciplina != 1 && opcaoDisciplina != 9) {
      printf("Opcao nao encontrada, escolha entre as disponiveis \n");
      while (opcaoDisciplina != 1 && opcaoDisciplina != 9) {
        printf("##Opcao 1- Sim");
        printf("##Opcao 9 - Nao");
        scanf("%d", &opcaoDisciplina);
        getchar();
      }
    }
  }

  return 9;
}

int MatricularAluno(int opcaoDisciplina, Aluno listaAluno[],
                    Disciplina listaDisciplinas[]) {
  if (qtdAlunos == 0)
    printf("Não há alunos Cadastrados.\n");
  else if (qtdDisciplina == 0)
    printf("Não há disciplinas cadastradas.\n");
  else {
    printf("Digite o codigo da disciplina:\n");
    scanf("%d", &codigoDisciplina);
    getchar();
    for (int i = 0; i < qtdDisciplina; i++) {
      if (codigoDisciplina == listaDisciplinas[i].codigo) {
        validadorDisciplina = i;
        break;
      }
    }
    if (validadorDisciplina >= 0) {
      printf("Digite a matricula do aluno:\n");
      scanf("%d", &matriculaAluno);
      getchar();
      for (int count = 0; count < qtdAlunos; count++) {
        if (matriculaAluno == listaAluno[count].matricula) {
          validadorAluno = count;
          break;
        }
      }
      if (validadorAluno >= 0) {
        listaDisciplinas[validadorDisciplina]
            .matriculaAluno[qtdAlunoDisciplina] = matriculaAluno;
        qtdAlunoDisciplina++;
        printf("Aluno %s cadastrado com sucesso na disciplina %s",
               listaAluno[validadorAluno].nome,
               listaDisciplinas[validadorDisciplina].nome);
        validadorAluno = validadorDisciplina = -1;

      } else {
        printf("Aluno nao encontrado.\n");
        validadorAluno = validadorDisciplina = -1;
        return 3;
      }

    } else {
      printf("Disciplina nao encontrada!!\n");
      return 3;
    }

    // PAREI AQUI VALIDANDO A DISCIPLINA E ALUNO
  }
  return 9;
}

int ListarDisciplinas(int opcaoDisciplina, Disciplina listaDisciplina[]) {
  if (qtdDisciplina > 0) {
    for (int i = 0; i < qtdDisciplina; i++) {
      printf("##########");
      printf("Posição: %d\n", i);
      printf("Disciplina: %s\n", listaDisciplina[i].nome);
      printf("Codigo: %d\n", listaDisciplina[i].codigo);
      printf("Semestre: %s\n", listaDisciplina[i].semestre);
      printf("Professor: %d\n", listaDisciplina[i].matriculaProfessor);
      printf("##########");
    }
    int validaOpcao=0;
    int opcaoEscolhida=0;
    do{
    
    printf("Digite a posição da disciplina para maiores informações ou 9 para retornar:\n");
    scanf("%d", &opcaoEscolhida);
    if(opcaoEscolhida<0 || (opcaoEscolhida>qtdDisciplina && opcaoEscolhida!=9))
      printf("Digite uma opção valida.\n");
    else
      validaOpcao=1;
    }while(validaOpcao==0);
    if(opcaoEscolhida!=9)
      printf("Disciplina: %s.\n", listaDisciplina[opcaoEscolhida].nome);
    int qtdAlunosMatriculados=0;
    printf("Alunos Matriculados:\n");
    for (int i=0; i<=TAM; i++){
      if(listaDisciplina[opcaoEscolhida].matriculaAluno[i]==0)
        break;
      printf("%d", listaDisciplina[opcaoEscolhida].matriculaAluno[i]);       
    }
    return 9;
      

  } else
    printf("Não há disciplinas cadastradas\n");
  return 9;
}

int AtualizarDisciplina(int opcao, int opcaoDisciplina,
                        Disciplina listaDisciplina[], Prof listaProf[]) {
  while (opcao == 4) {
    printf("##### Atualização de Disciplinas #####\n");

    if (qtdDisciplina == 0) {
      printf("No momento não existem Disciplinas cadastradas\n");
      return 4;
    } else {
      printf("Disciplinas cadastradas: %d\n", qtdDisciplina);
      for (int count = 0; count < qtdDisciplina; count++) {
        printf("Posição %d\n", count);
        printf("%s\n", listaDisciplina[count].nome);
        printf("%s\n", listaDisciplina[count].semestre);
        printf("%d\n", listaDisciplina[count].codigo);
        printf("%d\n", listaDisciplina[count].matriculaProfessor);
        printf("\n");
      }
      opcaoDisciplina = TAM + 1;
      while (opcaoDisciplina < 0 || opcaoDisciplina >= qtdDisciplina) {
        int validaProf = 0;
        printf("Informe a posicao da disciplina que deseja atualizar:\n");
        scanf("%d", &opcaoDisciplina);
        getchar();
        if (opcaoDisciplina < 0 || opcaoDisciplina >= qtdDisciplina) {
          printf("Posicao incorreta, informe uma posição presente na lista "
                 "anterior\n");
        } else {

          printf("Insira o novo nome para %s:\n",
                 listaDisciplina[opcaoDisciplina].nome);
          fgets(listaDisciplina[opcaoDisciplina].nome, 50, stdin);
          size_t ln = strlen(listaDisciplina[opcaoDisciplina].nome) -
                      1; // size_t = unsigned integer type
          if (listaDisciplina[opcaoDisciplina].nome[ln] == '\n')
            listaDisciplina[opcaoDisciplina].nome[ln] = '\0';

          printf("Insira um novo Semestre:\n");
          fgets(listaDisciplina[opcaoDisciplina].semestre, 6, stdin);
          ln = strlen(listaDisciplina[opcaoDisciplina].semestre) - 1;
          if (listaDisciplina[opcaoDisciplina].semestre[ln] == '\n')
            listaDisciplina[opcaoDisciplina].semestre[ln] = '\0';

          printf("Insira o novo codigo:\n");
          scanf("%d", &listaDisciplina[opcaoDisciplina].codigo);
          getchar();
          do {
            printf("Insira a nova matricula:\n");
            scanf("%d", &listaDisciplina[opcaoDisciplina].matriculaProfessor);
            getchar();

            for (int i = 0; i <= qtdProfessores; i++) {
              if (listaDisciplina[opcaoDisciplina].matriculaProfessor ==
                  listaProf[i].matricula) {
                validaProf = 1;
                break;
              }
            }
            if (validaProf == 0)
              printf("Professor nao encontrado, verifique a matricula e digite "
                     "corretamente.\n");
          } while (validaProf == 0);
          opcaoDisciplina = 4;
          while (opcaoDisciplina == 4) {
            printf("#### Disciplina atualizada com sucesso:\n Deseja atualizar "
                   "outra disciplina?\n Digite 4 para sim ou 9 para não:\n");
            scanf("%d", &opcaoDisciplina);
            getchar();
            if (opcaoDisciplina != 4 && opcaoDisciplina != 9) {
              printf("Opção inválida, digite novamente.\n");
              opcaoDisciplina = 4;
            } else {
              opcaoDisciplina = 0;
              opcao = 9;
            }
          }
        }
      }
    }
  }
  return 9;
}

int RemoverDisciplina(int opcaoDisciplina, Disciplina listaDisciplina[]) {
  Disciplina copiaDisciplina;
  if (qtdDisciplina == 0) {
    printf("Não há Disciplinas cadastrados!!!\n");
    return 5;
  }

  while (opcaoDisciplina == 5) {
    printf("###### Disciplinas Cadastradas ######\n");
    printf("%d Disciplinas Cadastrados:\n", qtdDisciplina);
    for (int i = 0; i <= qtdDisciplina; i++) {
      printf("Posição %d: \n %s\n", i, listaDisciplina[i].nome);
    }
    printf("Digite a posição da Disciplina que deseja remover:\n");
    scanf("%d", &opcaoDisciplina);
    getchar();
    if (opcaoDisciplina < 0 || opcaoDisciplina >= qtdDisciplina) {
      printf("Posicao invalida\n");
    } else {

      listaDisciplina[opcaoDisciplina].semestre[0] = '\0';
      listaDisciplina[opcaoDisciplina].nome[0] = '\0';
      listaDisciplina[opcaoDisciplina].codigo = 0;
      listaDisciplina[opcaoDisciplina].matriculaProfessor = 0;
      listaDisciplina[opcaoDisciplina].matriculaAluno[0] = '\0';
      for (int j = opcaoDisciplina; j < qtdDisciplina - 1;
           j++) { // reordenação do vetor!
        copiaDisciplina = listaDisciplina[j];
        listaDisciplina[j] = listaDisciplina[j + 1];
        listaDisciplina[j + 1] = copiaDisciplina;
      }
      printf("Disciplina excluida com sucesso");
      opcaoDisciplina = 6;
      qtdDisciplina--;
    }
  }
  return 4;
}

// validacao professor quando cadastrar disciplina