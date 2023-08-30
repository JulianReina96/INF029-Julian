#ifndef struct_h
#define struct_h

#define TAM 2

typedef struct {
  char nome[51];
  int codigo;
  char semestre[7]; // 2023.2 exemplo
  int matriculaProfessor;
  int matriculaAluno[TAM];
} Disciplina;

typedef struct {
  int dia;
  int mes;
  int ano;

} DtNasc;

typedef struct {
  int matricula;
  char sexo;
  char nome[51];
  DtNasc dataNas;
  char cpf[15];

} Aluno;

typedef struct {
  int matricula;
  char nome[51];
  char sexo;
  DtNasc dataNas;
  char cpf[15];
} Prof;


#endif
