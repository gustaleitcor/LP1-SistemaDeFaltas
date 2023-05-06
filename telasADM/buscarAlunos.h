#pragma once
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"
#include "../telas/setSystem.h"
#include <iostream>
#include <string>
#define LOGIN 0
#define SENHA 1

void buscarAlunos(GerenciadorDoBancoDeDados &bd) {
  std::string input, atributo;
  bool validated = false;
  Aluno *aluno;
  std::vector<std::vector<std::string>> file = bd.getFile();
  unsigned int index = 0;
  std::string cursos[3] = {"Engenharia da Computação", "Ciência da Computação",
                           "Ciência de Dados e Inteligência Artificial"};

  do {
    std::cout << "BUSCAR ALUNOS" << std::endl;
    std::cout << "1 - Buscar pelo curso" << std::endl;
    std::cout << "2 - Buscar pela periodo" << std::endl;
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

    do {
      std::cout << std::endl;
      std::cout << "1 - Engenharia da Computação" << std::endl;
      std::cout << "2 - Ciência da Computação" << std::endl;
      std::cout << "3 - Ciência de Dados e Inteligência Artificial"
                << std::endl;
      std::cout << std::endl;
      std::cout << "Qual curso procurar? ";
      getline(std::cin, input);
      try {
        std::stoi(input);
        validated = true;
      } catch (...) {
        continue;
      }
    } while (!validated || std::stoi(input) < 1 || std::stoi(input) > 3);

    printf("%-6s%-25s%-50s%s\n", "INDEX\0", "NOME\0", "CURSO\0", "MATRICULA\0");

    for (auto user : file) {
      if (user[5] == input && index != 0) {
        bd.mountAluno(aluno, user[LOGIN], user[SENHA]);
        printf(
            " %-d - %-25s%-50s%s\n", index - 1,
            (aluno->getPrimeiroNome() + " " + aluno->getUltimoNome()).c_str(),
            cursos[aluno->getCurso() - 1].c_str(),
            aluno->getMatricula().c_str());
      }
      index++;
    }
    std::cout << std::endl << "pressione ENTER para sair" << std::endl;
    while (true) {
      getline(std::cin, input);
      if (input == "")
        return;
    }
    break;
  case 2:
    do {
      std::cout << "Digite o periodo: ";
      getline(std::cin, input);
      try {
        std::stoi(input);
        validated = true;
      } catch (...) {
        continue;
      }
    } while (!validated);

    printf("%-6s%-25s%-50s%s\n", "INDEX\0", "NOME\0", "CURSO\0", "MATRICULA\0");
    for (auto user : file) {
      if (user[4] == input && index != 0) {
        bd.mountAluno(aluno, user[LOGIN], user[SENHA]);
        printf(
            " %-d - %-25s%-50s%s\n", index - 1,
            (aluno->getPrimeiroNome() + " " + aluno->getUltimoNome()).c_str(),
            cursos[aluno->getCurso() - 1].c_str(),
            aluno->getMatricula().c_str());
      }
      index++;
    }
    std::cout << std::endl << "pressione ENTER para sair" << std::endl;
    while (true) {
      getline(std::cin, input);
      if (input == "")
        return;
    }
    break;
  case 0:
    return;
  }
}