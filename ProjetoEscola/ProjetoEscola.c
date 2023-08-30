#include "ModuloAluno/ModuloAluno.h"
#include "ModuloProfessor/ModuloProfessor.h"
#include "ModuloDisciplina/ModuloDisciplina.h"
#include <stdio.h>
#include <stdlib.h>

Aluno listaAluno[TAM];
Disciplina listaDisciplina[TAM];
Prof listaProf[TAM];
int qtdAlunos=0;
int qtdProfessores=0;
int qtdDisciplina=0;


int opcao = 1, opcaoModulo;

void menuGeral() {
  printf("Bem vindo a Escola\n");
  printf("Digite o numero da opção desejada:\n");
  printf("1 - Modulo Estudantes\n");
  printf("2 - Modulo Professor\n");
  printf("3 - Modulo Disciplina\n");
  printf("0 - Encerrar Aplicação\n");
}

int main(void) {

  while (opcao != 0) {
    menuGeral();
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
    case 1:
      opcao = ModuloAluno(listaAluno, listaDisciplina);
      break;
    case 2:
      opcao = ModuloProfessor(listaProf);
      break;
    case 3:
      opcao = ModuloDisciplina(opcao, listaDisciplina, listaAluno, listaProf);
      break;
    case 0:
      break;
    default:
      printf("Opcao invalida, digite novamente o valor desejado:\n");
    }
  }
}

// buscar listar alunos e professores ordenados por x ou y

// Atualizacao e exclusao
