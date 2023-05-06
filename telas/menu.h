#pragma once
#include "../alunos/Aluno.h"
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"
#include "./adicionarDisciplina.h"
#include "./adicionarFalta.h"
#include "./printPerfil.h"
#include "./removerDisciplina.h"
#include "atualizarPerfil.h"
#include "setSystem.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <exception>

bool menu(GerenciadorDoBancoDeDados &bd, Aluno *&aluno) {

  std::string input;
  bool validated = false;

  
  
  do{
  printPerfil(aluno);
    
  std::cout << std::endl;
  std::cout << "1 - Adicionar disciplina" << std::endl;
  std::cout << "2 - Remover disciplina" << std::endl;
  std::cout << "3 - Adicionar falta à disciplina" << std::endl;
  std::cout << "4 - Atualizar perfil" << std::endl;
  std::cout << "5 - Sair" << std::endl;
  std::cout << std::endl;

  getline(std::cin, input);

    try{
      std::stoi(input);
      validated = true;
    }catch(std::invalid_argument){
      system(CLEAR_CONSOLE);
    }

  }while(!validated);

  switch (std::stoi(input)) {
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