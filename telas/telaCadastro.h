#include "../alunos/Aluno.h"
#include "../alunos/AlunoCC.h"
#include "../alunos/AlunoCDIA.h"
#include "../alunos/AlunoEC.h"
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"

#include "iostream"
#include "setSystem.h"
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string>

void telaCadastro(GerenciadorDoBancoDeDados &bd) {

  std::string login;
  std::string senha;
  std::string nome;
  std::string matricula;
  std::string periodo;
  std::string curso;

  Aluno *aluno;

  system(CLEAR_CONSOLE);

  while (true) {

    std::cout << "----CADASTRO----" << std::endl;
    std::cout << std::endl;

    do {
      std::cout << "Digite o login: ";
      getline(std::cin, login);
    } while (login == "" || login == ",");

    // Retira espaços extras no login
    int spacePos = login.find_last_not_of(' ');

    if (spacePos != std::string::npos) {
      login.erase(spacePos + 1);
    }

    // Verificando se o login já existe ou não
    if (!bd.ehLoginUnico(login)) {
      system(CLEAR_CONSOLE);
      std::cout << "Desculpe, login já utilizado" << std::endl;
      std::cout << std::endl;
      continue;
    }

    // Leitura dos dados para o cadastro
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

    do { 
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
      std::cout << std::endl;
      std::cout << "1 - Engenharia da Computação" << std::endl;
      std::cout << "2 - Ciência da Computação" << std::endl;
      std::cout << "3 - Ciência de Dados e Inteligência Artificial"
                << std::endl;
      std::cout << std::endl;
      std::cout << "De qual destes curso você faz parte? ";
      getline(std::cin, curso);
      try {
        std::stoi(curso);
        validated = true;
      } catch (...) {
        continue;
      }

    } while (!validated || std::stoi(curso) < 1 || std::stoi(curso) > 3);

    break;
  }

  switch (std::stoi(curso)) {
  case 1:
    aluno = new AlunoEC;
    break;
  case 2:
    aluno = new AlunoCC;
    break;
  case 3:
    aluno = new AlunoCDIA;
    break;
  }

  aluno->setLogin(login);
  aluno->setSenha(senha);
  aluno->setNome(nome);
  aluno->setMatricula(matricula);
  aluno->setPeriodo(std::stoi(periodo));
  aluno->setCurso(std::stoi(curso));

  bd.appendUsuario(aluno); // Escreve no arquivo as informações do aluno
  bd.loadFile(bd.getDirectory()); // Recarrega a base de dados

  delete aluno;

  return;
}