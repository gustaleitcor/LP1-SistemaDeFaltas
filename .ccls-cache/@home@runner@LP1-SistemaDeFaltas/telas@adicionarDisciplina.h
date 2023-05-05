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

  std::vector<std::vector<std::string>> file;
  std::string line;

  file = carregarBancoDeDados("bancoDeDados/alunos.txt");

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

  salvarBancoDeDados("bancoDeDados/alunos.txt", file);

  attAluno(aluno);

  return;
}