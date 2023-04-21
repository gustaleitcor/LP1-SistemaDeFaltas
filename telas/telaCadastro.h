#include "../alunos/Aluno.h"
#include "../alunos/AlunoCC.h"
#include "../alunos/AlunoCDIA.h"
#include "../alunos/AlunoEC.h"

#include "iostream"
#include "setSystem.h"
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <fstream>

void telaCadastro() {

  std::string login;
  std::string test;
  std::string pass;

  std::cout << "Digite o login: ";
  getline(std::cin, login);
  std::cout << "Digite a senha: ";
  getline(std::cin, pass);

  return;
}