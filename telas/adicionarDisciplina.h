#pragma once
#include "../alunos/Aluno.h"
#include "../alunos/attAluno.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void adicionarDisciplina(Aluno *&aluno) {
  std::ifstream outputFile("bancoDeDados/alunos.txt");

  if (!outputFile.is_open()) {
    std::cout << "Não foi possivel abrir o banco de dados" << std::endl;
    return;
  }

  std::vector<std::string> file;
  std::string line;

  while (getline(outputFile, line)) {
    file.push_back(line);
  }

  outputFile.close();

  unsigned long long int index = 0;

  for (; index < file.size(); index++) {
    if (file[index] == getenv("LOGIN") && file[index + 1] == getenv("SENHA")) {
      break;
    }
  }

  for (; index < file.size(); index++) {
    if (file[index] == ",") {
      break;
    }
  }

  std::cout << "Digite o nome da disciplina a ser adicionada: ";
  getline(std::cin, line);
  file.insert(file.begin() + index++, line);
  std::cout << "Digite o nome do professor da disciplina: ";
  getline(std::cin, line);
  file.insert(file.begin() + index++, line);
  std::cout << "Digite a carga horaria da disciplina: ";
  getline(std::cin, line);
  file.insert(file.begin() + index++, line);
  file.insert(file.begin() + index++, std::string("0"));

  std::ofstream inputFile("bancoDeDados/alunos.txt");

  if (!inputFile.is_open()) {
    std::cout << "Não foi possivel abrir o banco de dados" << std::endl;
    return;
  }

  for (auto l : file) {
    inputFile << l << std::endl;
  }

  inputFile.close();

  attAluno(aluno);

  return;
}