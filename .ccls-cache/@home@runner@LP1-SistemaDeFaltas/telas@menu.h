#pragma once
#include "../alunos/Aluno.h"
#include "./adicionarDisciplina.h"
#include "./printPerfil.h"
#include <iostream>

bool menu(Aluno *&aluno) {

  short input;

  printPerfil(aluno);

  std::cout << std::endl;

  std::cout << "1 - Adicionar disciplina" << std::endl;
  std::cout << "2 - Remover disciplina" << std::endl;
  std::cout << "3 - Adicionar falta à disciplina" << std::endl;
  std::cout << "4 - Atualizar perfil" << std::endl;
  std::cout << "5 - Sair" << std::endl;
  std::cout << std::endl;

  std::cin >> input;
  std::cin.ignore();

  switch (input) {
  case 1:
    adicionarDisciplina(aluno);
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    return false;
  default:
    break;
  }

  return true;
}