#pragma once
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"
#include "./printPerfil.h"
#include "setSystem.h"
#include <exception>
#include <stdlib.h>
#include <string>
#include <vector>

// Função para atualizar a quantidade de faltas do cadastrado
void adicionarFalta(GerenciadorDoBancoDeDados &bd, Aluno *&aluno) {
  std::vector<std::vector<std::string>> file = bd.getFile();
  unsigned int UserIndex = bd.indexOfUser(getenv("LOGIN"), getenv("SENHA"));
  std::string input;
  bool validated = false;
  unsigned int qtdDisciplinas = (file[UserIndex].size() - 6) / 4;

  system(CLEAR_CONSOLE);

  printDisciplinas(aluno);
  std::cout << "0 - Sair" << std::endl;

  do {

    std::cout << "Digite o numero da disciplina: ";

    getline(std::cin, input);

    try {
      std::stoi(input);
      validated = true;
    } catch (std::invalid_argument) {
      validated = false;
    }
  } while (!validated || (abs(std::stoi(input)) < 0 ||
                          abs(std::stoi(input)) > qtdDisciplinas));

  if (input == "0") {
    return;
  }

  file[UserIndex][5 + (4 * abs(std::stoi(input)))] = std::to_string(
      std::stoi(file[UserIndex][5 + (4 * abs(std::stoi(input)))]) +
      (std::stoi(input) < 0
           ? (-1 *
              (file[UserIndex][5 + (4 * abs(std::stoi(input)))] == "0" ? 0 : 1))
           : 1));

  bd.atualizarBancoDeDados(bd.getDirectory(), file);
  bd.mountAluno(aluno);
}