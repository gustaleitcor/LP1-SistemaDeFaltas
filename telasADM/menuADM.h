#pragma once
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"
#include "./buscarAluno.h"
#include "./buscarAlunos.h"
#include "./deletarAluno.h"
#include "./listarAlunos.h"
#include "./deletarAluno.h"
#include <exception>
#include <iostream>
#include <string>
#include <vector>

bool menuADM(GerenciadorDoBancoDeDados &bd) {
  std::string input;
  bool validated = false;

  do {
    system(CLEAR_CONSOLE);
    std::cout << "---MENU ADM---" << std::endl;
    std::cout << "1 - Buscar aluno" << std::endl;
    std::cout << "2 - Buscar alunos" << std::endl;
    std::cout << "3 - Listar alunos" << std::endl;
    std::cout << "4 - Deletar aluno" << std::endl;
    std::cout << "0 - Sair" << std::endl;

    getline(std::cin, input);

    try {
      std::stoi(input);
      validated = true;
    } catch (...) {
      continue;
    }
  } while (!validated || std::stoi(input) < 0 || std::stoi(input) > 4);

  system(CLEAR_CONSOLE);

  switch (std::stoi(input)) {

  case 1:
    buscarAluno(bd);
    break;
  case 2:
    buscarAlunos(bd);
    break;
  case 3:
    listarAlunos(bd);
    break;
  case 4:
    deletarAluno(bd);
    break;
  case 0:
    return false;
  }
  return true;
}
