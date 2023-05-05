#pragma once
#include "../Exceptions.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Função para pegar os atributos da classe Aluno separados por vírgula
std::vector<std::string> split(std::string &linha) {
  std::vector<std::string> objeto;
  std::string atributo;

  for (char c : linha) {
    if (c == ',') {
      objeto.push_back(atributo);
      atributo = "";
      continue;
    }
    atributo += c;
  }
  return objeto;
}

// Verifica se o login existe no sistema
bool ehUsuarioCadastrado(std::string login, std::string senha) {

  std::vector<std::string> object;
  std::string line;

  std::ifstream inputFile("bancoDeDados/alunos.txt");

  if (!inputFile.is_open()) {
    throw FileHasNotOpenException("Erro ao abrir o banco de dados");
  }

  while (getline(inputFile, line)) {
    object = split(line);
    if (object[0] == login && object[1] == senha) {
      inputFile.close();
      return true;
    }
  }

  inputFile.close();
  return false;
}

// Verifica se o nome do login já existe ou não
bool loginUnico(std::string login) {

  std::vector<std::string> object;
  std::string line;

  std::ifstream inputFile("bancoDeDados/alunos.txt");

  if (!inputFile.is_open()) {
    throw FileHasNotOpenException("Erro ao abrir o banco de dados");
  }

  while (getline(inputFile, line)) {
    object = split(line);
    if (object[0] == login) {
      inputFile.close();
      return false;
    }
  }

  inputFile.close();
  return true;
}

std::vector<std::vector<std::string>>
carregarBancoDeDados(std::string directory) {
  std::ifstream inputFile(directory);

  if (!inputFile.is_open()) {
    throw FileHasNotOpenException("Erro ao abrir o banco de dados");
  }

  std::vector<std::vector<std::string>> file;
  std::vector<std::string> object;
  std::string line;

  while (getline(inputFile, line)) {
    object = split(line);
    file.push_back(object);
  }

  inputFile.close();

  return file;
}

void salvarBancoDeDados(std::string directory,
                        std::vector<std::vector<std::string>> &file) {
  std::ofstream outputFile(directory);

  if (!outputFile.is_open()) {
    throw FileHasNotOpenException("Erro ao abrir o banco de dados");
  }

  for (auto line : file) {
    for (auto atribute : line) {
      outputFile << atribute << ',';
    }
    outputFile << std::endl;
  }
}

class GerenciadorDoBancoDeDados {
private:
  std::vector<std::vector<std::string>> file;

public:
  void loadFile(std::string directory);
  std::vector<std::vector<std::string>> getFile() { return file; }
}