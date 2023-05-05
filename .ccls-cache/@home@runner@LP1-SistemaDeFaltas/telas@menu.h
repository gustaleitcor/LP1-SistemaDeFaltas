#pragma once
#include "../alunos/Aluno.h"
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"
#include "./adicionarDisciplina.h"
#include "./adicionarFalta.h"
#include "./printPerfil.h"
#include "./removerDisciplina.h"
#include "atualizarPerfil.h"
#include <iostream>

bool menu(GerenciadorDoBancoDeDados &bd, Aluno *&aluno) {

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
    adicionarDisciplina(bd, aluno);
    break;
  case 2:
    removerDisciplina(bd, aluno);
    break;
  case 3:
    adicionarFalta(bd, aluno);
    break;
  case 4:
    atualizarPerfil(bd, aluno);
    break;
  case 5:
    setenv("LOGIN", "", true);
    setenv("SENHA", "", true);
    return false;
  default:
    break;
  }

  return true;
}