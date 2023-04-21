#include "../alunos/Aluno.h"
#include "../alunos/AlunoCC.h"
#include "../alunos/AlunoCDIA.h"
#include "../alunos/AlunoEC.h"
#include "../bancoDeDados/gerenciadorDoBancoDeDados.h"

#include "iostream"
#include "setSystem.h"
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string>

void telaCadastro() {

  std::string login;
  std::string senha;
  std::string nome;
  std::string matricula;
  std::string periodo;
  unsigned short curso = -1;

  system(CLEAR_CONSOLE);

  while (true) {

    std::cout << "----CADASTRO----" << std::endl;
    std::cout << std::endl;

    do {
      std::cout << "Digite o login: ";
      getline(std::cin, login);
    } while (login == "" || login == ",");

    if (!loginUnico(login)) {
      system(CLEAR_CONSOLE);
      std::cout << "Desculpe, login já utilizado" << std::endl;
      std::cout << std::endl;
      continue;
    }

    do {
      std::cout << "Digite a senha: ";
      getline(std::cin, senha);
    } while (senha == "" || senha == ",");

    do {
      std::cout << "Digite o nome completo: ";
      getline(std::cin, nome);
    } while (nome == "" || nome == ",");

    do {
      std::cout << "Digite a matricula: ";
      getline(std::cin, matricula);
    } while (matricula == "" || matricula == ",");

    do {
      std::cout << "*Digite o periodo: ";
      getline(std::cin, periodo);
    } while (periodo[0] == '-' || periodo == ",");

    if (periodo == "") {
      periodo = "-1";
    }

    do {
      try {
        std::cout << std::endl;
        std::cout << "1 - Engenharia da Computação" << std::endl;
        std::cout << "2 - Ciência da Computação" << std::endl;
        std::cout << "3 - Ciência de Dados e Inteligência Artificial"
                  << std::endl;
        std::cout << std::endl;
        std::cout << "De qual destes curso você faz parte? ";
        std::cin >> curso;
        std::cin.ignore();
      } catch (...) {
        continue;
      }

    } while (curso < 1 || curso > 3);

    break;
  }

  std::ofstream outputFile("bancoDeDados/alunos.txt", std::ios_base::app);

  std::ifstream cursosObg("bancoDeDados/cursos.txt");

  if (!outputFile.is_open() || !cursosObg.is_open()) {
    std::cout << "Erro ao abrir o arquivo" << std::endl;
  }

  outputFile << login << std::endl;
  outputFile << senha << std::endl;
  outputFile << nome << std::endl;
  outputFile << matricula << std::endl;
  outputFile << periodo << std::endl;
  outputFile << curso << std::endl;
  outputFile << '@' << std::endl;

  std::string cursoObg;

  do {
    getline(cursosObg, cursoObg);
  } while (cursoObg != std::to_string(curso));

  while (getline(cursosObg, cursoObg)) {
    if (cursoObg == std::to_string(curso + 1)) {
      break;
    }
    outputFile << cursoObg << std::endl;
  }

  outputFile << ',' << std::endl;

  outputFile.close();

  return;
}