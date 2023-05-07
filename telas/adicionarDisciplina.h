#pragma once
#include "../alunos/Aluno.h"
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Adicona disciplina no perfil do cadastrado
void adicionarDisciplina(GerenciadorDoBancoDeDados &bd, Aluno *&aluno) {

  bool validated = false;

  std::vector<std::vector<std::string>> file = bd.getFile();
  unsigned int userIndex = bd.indexOfUser(getenv("LOGIN"), getenv("SENHA"));
  std::string input;

  do {
    std::cout << "Digite o nome da disciplina a ser adicionada: ";
    getline(std::cin, input);
  } while (input == "" || (input.find(',') != std::string::npos));
  file[userIndex].push_back(input); // nome da disciplina
  std::cout << "Digite o nome do professor da disciplina: ";

  do {
    getline(std::cin, input);
  } while (input == "" || (input.find(',') != std::string::npos));
  file[userIndex].push_back(input); // nome do professor
  std::cout << "(Pode deixar em branco) Digite a carga horaria da disciplina: ";

  do {
    try {
      getline(std::cin, input);
      validated = true;
    } catch (...) {
      continue;
    }
  } while (!validated || (input.find(',') != std::string::npos));
  if (input == "") {
    input = "0";
  }
  file[userIndex].push_back(input); // carga horaria

  file[userIndex].push_back("0"); // faltas

  bd.atualizarBancoDeDados(bd.getDirectory(),
                           file); // atualiza o banco de dados
  bd.mountAluno(aluno);           // remonta o aluno

  return;
}