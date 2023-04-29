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

    int spacePos = login.find_last_not_of(' ');

    if (spacePos != std::string::npos) {
      login.erase(spacePos + 1);
    }

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

    bool validated = false;

    do { // apenas aceite que funciona
      std::cout << "(Pode deixar em branco) Digite o periodo: ";
      getline(std::cin, periodo);
      if (periodo == "") {
        break;
      }
      try {
        std::stoi(periodo);
        validated = true;
      } catch (...) {
        validated = false;
      }
    } while (periodo[0] == '-' || periodo == "," || !validated);

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

  std::ifstream disciplinasObg("bancoDeDados/cursos.txt");

  if (!outputFile.is_open() || !disciplinasObg.is_open()) {
    std::cout << "Erro ao abrir o arquivo" << std::endl;
  }

  outputFile << login << ',';
  outputFile << senha << ',';
  outputFile << nome << ',';
  outputFile << matricula << ',';
  outputFile << periodo << ',';
  outputFile << curso << std::endl;

  std::string disciplinaObg;

  /*
  do {
    getline(disciplinasObg, disciplinaObg);
  } while (disciplinaObg != std::to_string(curso));

  while (getline(disciplinasObg, disciplinaObg)) {
    if (disciplinaObg == std::to_string(curso + 1)) {
      break;
    }
    outputFile << disciplinaObg << std::endl;
  }
  */

  //outputFile << ',' << std::endl;

  outputFile.close();
  disciplinasObg.close();

  return;
}