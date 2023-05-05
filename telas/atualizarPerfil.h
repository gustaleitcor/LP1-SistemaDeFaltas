#pragma once
#include "../alunos/Aluno.h"
#include "../alunos/attAluno.h"
#include "../bancoDeDados/gerenciadorDoBancoDeDados.h"
#include "printPerfil.h"
#include "setSystem.h"
#include <stdlib.h>
#include <string>
#include <vector>

void atualizarNome(std::vector<std::vector<std::string>> &file,
                   unsigned int index) {
  std::string nome;
  std::cout << "Digite o novo nome: ";
  getline(std::cin, nome);
  file[index][2] = nome;
}

void atualizarMatricula(std::vector<std::vector<std::string>> &file,
                        unsigned int index) {
  std::string matricula;
  std::cout << "Digite a nova matricula: ";
  getline(std::cin, matricula);
  file[index][3] = matricula;
}

void atualizarCurso(std::vector<std::vector<std::string>> &file,
                    unsigned int index) {

  int curso;

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

  file[index][5] = std::to_string(curso);
}

void atualizarPeriodo(std::vector<std::vector<std::string>> &file,
                      unsigned int index) {
  std::string periodo;
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

  file[index][4] = periodo;
}

void atualizarPerfil(Aluno *&aluno) {
  std::vector<std::vector<std::string>> file;

  char *cursos[3] = {"Engenharia da Computação\0", "Ciência da Computação\0",
                     "Ciência de Dados e Inteligência Artificial\0"};

  file = carregarBancoDeDados("bancoDeDados/alunos.txt");

  unsigned int index = 0;

  for (auto user : file) {
    if (user[0] == getenv("LOGIN") && user[1] == getenv("SENHA")) {
      break;
    }
    index++;
  }

  short input;

  while (true) {

    system(CLEAR_CONSOLE);

    std::cout << "1 - "
              << "Nome: " << aluno->getNome() << std::endl;
    std::cout << "2 - "
              << "Matricula: " << aluno->getMatricula() << std::endl;
    std::cout << "3 - "
              << "Curso: " << cursos[aluno->getCurso() - 1] << std::endl;
    std::cout << "4 - "
              << "Periodo: "
              << (aluno->getPeriodo() == 65535
                      ? std::string("Não informado")
                      : std::to_string(aluno->getPeriodo()))
              << std::endl;
    std::cout << "0 - Sair" << std::endl;
    std::cout << "Digite o atributo a ser atualizado: ";

    std::cin >> input;
    std::cin.ignore();

    switch (input) {
    case 1:
      atualizarNome(file, index);
      break;
    case 2:
      atualizarMatricula(file, index);
      break;
    case 3:
      atualizarCurso(file, index);
      break;
    case 4:
      atualizarPeriodo(file, index);
      break;
    case 0:
      return;
    default:
      continue;
    }
    salvarBancoDeDados("bancoDeDados/alunos.txt", file);
    attAluno(aluno);
  }
}