#pragma once
#include "../Exceptions.h"
#include "../alunos/Aluno.h"
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"
#include "../functions/tiraEspacos.h"
#include "../telas/printPerfil.h"
#include "../telas/setSystem.h"
#include <iostream>
#include <string>

void deletarAluno(GerenciadorDoBancoDeDados &bd) {

  std::string input, atributo;
  bool validated = false, found = false;
  Aluno *aluno;

  do {
    std::cout << "DELETAR ALUNO" << std::endl;
    std::cout << "1 - Deletar pelo nome" << std::endl;
    std::cout << "2 - Deletar pela matricula (Recomendavel)" << std::endl;
    std::cout << "0 - Sair" << std::endl;

    getline(std::cin, input);

    try {
      std::stoi(input);
      validated = true;
    } catch (...) {
      continue;
    }
  } while (!validated || std::stoi(input) < 0 || std::stoi(input) > 2);

  switch (std::stoi(input)) {
  case 1:
    while (!found) {

      std::cout << "Digite o nome do Aluno: ";
      getline(std::cin, atributo);
      tiraEspacos(atributo);
      try {
        aluno = bd.findAlunoByName(atributo, bd);
        found = true;
      } catch (ElementNotFoundException) {
        std::cout
            << "Elemento não encontrado, deseja tentar novamente? (y/n): ";
        getline(std::cin, input);
        if (input == "n") {
          return;
        }
      }
    }
    std::cout << std::endl;
    printPerfil(aluno);
    std::cout << std::endl
              << "Deseja REALMENTE deletar este aluno? (y/n) " << std::endl;
    while (true) {
      getline(std::cin, input);
      if (input == "y") {
        bd.deletarAlunoByName(aluno->getNome(), bd);
        break;
      } else if (input == "n") {
        return;
      }
    }
    break;
  case 2:
    while (!found) {

      std::cout << "Digite a matricula do Aluno: ";
      getline(std::cin, atributo);
      tiraEspacos(atributo);
      try {
        aluno = bd.findAlunoByMatricula(atributo, bd);
        found = true;
      } catch (ElementNotFoundException) {
        std::cout << "Aluno não encontrado, deseja tentar novamente? (y/n): ";
        getline(std::cin, input);
        if (input == "n") {
          return;
        }
      }
    }
    std::cout << std::endl;
    printPerfil(aluno);
    while (true) {
      std::cout << std::endl
                << "Deseja REALMENTE deletar este aluno? (Y/N) " << std::endl;
      getline(std::cin, input);
      if (input == "Y") {
        bd.deletarAlunoByMatricula(aluno->getMatricula(), bd);
        break;
      } else if (input == "N") {
        return;
      }
    }
    system(CLEAR_CONSOLE);
  }
}