#pragma once
#include <fstream>
#include <iostream>
#include <string>

bool ehUsuarioCadastrado(std::string login, std::string senha) {

  std::string loginAux;
  std::string senhaAux;

  std::fstream file("bancoDeDados/alunos.txt", std::fstream::in);

  if (!file.is_open()) {
    std::cout << "Erro ao abrir o banco de dados" << std::endl;
  }

  while (getline(file, loginAux)) {
    getline(file, senhaAux);

    if (loginAux == login && senhaAux == senha) {
      file.close();
      return true;
    }

    do {
      getline(file, loginAux);
    } while (loginAux != ",");
  }

  file.close();
  return false;
}

bool loginUnico(std::string login) {

  std::string loginAux;
  std::string senhaAux;

  std::fstream file("bancoDeDados/alunos.txt", std::fstream::in);

  if (!file.is_open()) {
    std::cout << "Erro ao abrir o banco de dados" << std::endl;
  }

  while (getline(file, loginAux)) {
    getline(file, senhaAux);

    if (loginAux == login) {
      file.close();
      return false;
    }

    do {
      getline(file, loginAux);
    } while (loginAux != ",");
  }

  file.close();
  return true;
}