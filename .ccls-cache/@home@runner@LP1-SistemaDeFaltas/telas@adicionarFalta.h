#pragma once
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"
#include "./printPerfil.h"
#include "setSystem.h"
#include <stdlib.h>
#include <string>
#include <vector>

void adicionarFalta(GerenciadorDoBancoDeDados &bd, Aluno *&aluno) {
  std::vector<std::vector<std::string>> file = bd.getFile();
  unsigned int UserIndex = bd.indexOfUser(getenv("LOGIN"), getenv("SENHA"));
  unsigned int input;
  unsigned int qtdDisciplinas = (file[UserIndex].size() - 6) / 4;
  
  system(CLEAR_CONSOLE);

  printDisciplinas(aluno);
  std::cout << "0 - Sair" << std::endl;

  do {

    std::cout << "Digite o numero da disciplina: ";

    std::cin >> input;
    std::cin.ignore();

    if (input == 0) {
      return;
    }
  } while (input < 0 || input > qtdDisciplinas);

  file[UserIndex][5 + (4 * input)] =
      std::to_string(std::stoi(file[UserIndex][5 + (4 * input)]) + 1);

  bd.atualizarBancoDeDados(bd.getDirectory(), file);
  bd.mountAluno(aluno);
}