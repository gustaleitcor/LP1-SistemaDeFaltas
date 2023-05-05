#pragma once
#include "../alunos/attAluno.h"
#include "../bancoDeDados/gerenciadorDoBancoDeDados.h"
#include "./printPerfil.h"
#include "setSystem.h"
#include <stdlib.h>
#include <string>
#include <vector>

void adicionarFalta(Aluno *&aluno) {
  std::vector<std::vector<std::string>> file;

  file = carregarBancoDeDados("bancoDeDados/alunos.txt");

  unsigned int index = 0;

  for (auto user : file) {
    if (user[0] == getenv("LOGIN") && user[1] == getenv("SENHA")) {
      break;
    }
    index++;
  }

  unsigned int input;

  system(CLEAR_CONSOLE);

  unsigned int qtdDisciplinas = printDisciplinas(aluno);
  std::cout << "0 - Sair" << std::endl;

  do {

    std::cout << "Digite o numero da disciplina: ";

    std::cin >> input;
    std::cin.ignore();

    if (input == 0) {
      return;
    }
  } while (input < 0 || input > qtdDisciplinas);

  file[index][5 + (4 * input)] =
      std::to_string(std::stoi(file[index][5 + (4 * input)]) + 1);

  salvarBancoDeDados("bancoDeDados/alunos.txt", file);

  attAluno(aluno);
}