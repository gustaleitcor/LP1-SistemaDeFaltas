#pragma once
#include "../alunos/Aluno.h"
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"
#include "printPerfil.h"
#include "setSystem.h"
#include <stdlib.h>
#include <string>
#include <vector>

// Método para atualizar o nome do cadastrado
void atualizarNome(std::vector<std::vector<std::string>> &file,
                   unsigned int index) {
  std::string nome;
  do {
    std::cout << "Digite o novo nome: ";
    getline(std::cin, nome);
  } while (nome == "" || (nome.find(',') != std::string::npos));
  file[index][2] = nome;
}

// Método para atualizar a matrícula do cadastradao
void atualizarMatricula(std::vector<std::vector<std::string>> &file,
                        unsigned int index) {
  std::string matricula;
  do {
    std::cout << "Digite a nova matricula: ";
    getline(std::cin, matricula);
  } while (matricula == "" || (matricula.find(',') != std::string::npos));
  file[index][3] = matricula;
}

// Método para atualizar o curso do cadastrado
void atualizarCurso(std::vector<std::vector<std::string>> &file,
                    unsigned int index) {

  std::string curso;
  bool validated = false;

  std::cout << std::endl;
  std::cout << "1 - Engenharia da Computação" << std::endl;
  std::cout << "2 - Ciência da Computação" << std::endl;
  std::cout << "3 - Ciência de Dados e Inteligência Artificial" << std::endl;
  std::cout << std::endl;

  do {
    std::cout << "De qual destes curso você faz parte? ";
    getline(std::cin, curso);
    try {
      std::stoi(curso);
      validated = true;
    } catch (...) {
      continue;
    }

  } while (!validated || std::stoi(curso) < 1 || std::stoi(curso) > 3);

  file[index][5] = curso;
}

// Método para atualizar o período do cadastrado
void atualizarPeriodo(std::vector<std::vector<std::string>> &file,
                      unsigned int index) {
  std::string periodo;
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

  file[index][4] = periodo;
}

// Função que atualiza o perfil do cadastrando utilizando as funções
// atualizarAtributo
void atualizarPerfil(GerenciadorDoBancoDeDados &bd, Aluno *&aluno) {
  std::vector<std::vector<std::string>> file = bd.getFile();
  unsigned int userIndex = bd.indexOfUser(getenv("LOGIN"), getenv("SENHA"));

  std::string cursos[3] = {"Engenharia da Computação", "Ciência da Computação",
                           "Ciência de Dados e Inteligência Artificial"};

  std::string input;

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

    bool validated = false;

    do {
      std::cout << "Digite o atributo a ser atualizado: ";
      getline(std::cin, input);
      try {
        std::stoi(input);
        validated = true;
      } catch (...) {
        continue;
      }
    } while (!validated || input == "");

    switch (std::stoi(input)) {
    case 1:
      atualizarNome(file, userIndex);
      break;
    case 2:
      atualizarMatricula(file, userIndex);
      break;
    case 3:
      atualizarCurso(file, userIndex);
      break;
    case 4:
      atualizarPeriodo(file, userIndex);
      break;
    case 0:
      return;
    default:
      continue;
    }
    bd.atualizarBancoDeDados(bd.getDirectory(), file);
    bd.mountAluno(aluno);
  }
}