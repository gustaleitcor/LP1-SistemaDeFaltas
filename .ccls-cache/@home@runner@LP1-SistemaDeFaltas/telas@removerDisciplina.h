#pragma once
#include "../alunos/Aluno.h"
#include "../alunos/attAluno.h"
#include "../bancoDeDados/gerenciadorDoBancoDeDados.h"
#include "printPerfil.h"
#include "setSystem.h"
#include <fstream>
#include <stdlib.h>

void removerDisciplina(Aluno *&aluno) {

  // Carregando o banco de dados
  std::vector<std::vector<std::string>> file =
      carregarBancoDeDados("bancoDeDados/alunos.txt");

  long long int UserIndex = 0;
  int input;

  for (auto user : file) {
    if (user[0] == getenv("LOGIN") && user[1] == getenv("SENHA")) {
      break;
    }
    UserIndex++;
  }

  // Limpando tela
  system(CLEAR_CONSOLE);

  unsigned int qtdDisciplinas = printDisciplinas(aluno);

  std::cout << "0 - Sair" << std::endl;

  // Perguntando ao usuário qual disciplina será excluída
  do {
    std::cout << "Selecione a diciplina a ser excluída: ";
    std::cin >> input;
    std::cin.ignore();

    if (input == 0) {
      return;
    }

  } while (input < 0 || input > qtdDisciplinas);

  for (int i = 0; i < 4; i++) {
    file[UserIndex].erase(file[UserIndex].begin() + 6 + (3 * (input - 1)));
  }

  salvarBancoDeDados("bancoDeDados/alunos.txt", file);

  attAluno(aluno);
}