#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string &linha){
  std::vector<std::string> objeto;
  std::string atributo;
  
  for(char c: linha){
    if(c == ','){
      objeto.push_back(atributo);
      atributo = "";
      continue;
    }
    atributo += c;
  }
  return objeto;
}

bool ehUsuarioCadastrado(std::string login, std::string senha) {
  
  std::vector<std::string> object;
  std::string line;

  std::ifstream outputFile("bancoDeDados/alunos.txt");

  if (!outputFile.is_open()) {
    std::cout << "Erro ao abrir o banco de dados" << std::endl;
  }

  while (getline(outputFile, line)) {
    object = split(line);
    if(object[0]== login && object[1]==senha){
      outputFile.close();
      return true;
    }
  }

  outputFile.close();
  return false;
}

bool loginUnico(std::string login) {
  
  std::vector<std::string> object;
  std::string line;

  std::ifstream outputFile("bancoDeDados/alunos.txt");

  if (!outputFile.is_open()) {
    std::cout << "Erro ao abrir o banco de dados" << std::endl;
  }

  while (getline(outputFile, line)) {
    object = split(line);
    if(object[0] == login){
      outputFile.close();
      return false;
    }
  }

  outputFile.close();
  return true;
}