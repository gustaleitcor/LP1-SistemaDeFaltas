#pragma once
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"
#include "setSystem.h"
#include "telaCadastro.h"
#include "telaLogin.h"
#include <iostream>
#include <stdio.h>

void telaInicial(GerenciadorDoBancoDeDados &bd) {
  char input;
  bool logged = false;

  while (!logged) {

    system(CLEAR_CONSOLE);

    std::cout << "1 - Login" << std::endl;
    std::cout << "2 - Cadastrar" << std::endl;

    std::cin >> input;
    std::cin.ignore();

    switch (input) {
    case '1':
      logged = telaLogin(bd);
      break;
    case '2':
      telaCadastro(bd);
      break;
    }
  }

  return;
}