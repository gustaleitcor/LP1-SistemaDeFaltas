#pragma once
#include "../alunos/Aluno.h"
#include "iostream"
#include "setSystem.h"
#include <fstream>
#include <string>

void telaLogin() {
  system(CLEAR_CONSOLE);

  Aluno *aluno;
  std::ifstream file;
  std::string login;
  std::string pass;

  std::cout << "Digite o login: ";
  getline(std::cin, login);
  std::cout << "Digite a senha: ";
  getline(std::cin, pass);

  setenv("login", login.c_str(), true);
  setenv("pass", pass.c_str(), true);

  return;
}