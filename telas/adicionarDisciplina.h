#pragma once
#include "../alunos/Aluno.h"
#include "../alunos/attAluno.h"
#include "../bancoDeDados/gerenciadorDoBancoDeDados.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void adicionarDisciplina(Aluno *&aluno) {
  std::ifstream inputFile("bancoDeDados/alunos.txt");

  if (!inputFile.is_open()) {
    std::cout << "Não foi possivel abrir o banco de dados" << std::endl;
    return;
  }

  std::vector<std::vector<std::string>> file;
  std::vector<std::string> object;
  std::string line;

  while (getline(inputFile, line)) {
    object = split(line);
    file.push_back(object);
  }

  inputFile.close();

  unsigned long long int index = 0;

  for(auto objeto : file){
    if(objeto[0] == getenv("LOGIN") && objeto[1] == getenv("SENHA")){
      break;
    }
    index++;
  }
  

  std::cout << "Digite o nome da disciplina a ser adicionada: ";
  getline(std::cin, line);
  file[index].push_back(line); // nome da disciplina
  std::cout << "Digite o nome do professor da disciplina: ";
  getline(std::cin, line);
  file[index].push_back(line); // nome do professor
  std::cout << "Digite a carga horaria da disciplina: ";
  getline(std::cin, line);
  file[index].push_back(line); // carga horaria
  file[index].push_back("0"); // faltas

  std::ofstream outputFile("bancoDeDados/alunos.txt");

  if (!outputFile.is_open()) {
    std::cout << "Não foi possivel abrir o banco de dados" << std::endl;
    return;
  }

  for (auto objeto : file) {
    for(auto atributo : objeto){
      outputFile << atributo << ',';
    }
    outputFile << std::endl;
  }

  outputFile.close();

  attAluno(aluno);

  return;
}