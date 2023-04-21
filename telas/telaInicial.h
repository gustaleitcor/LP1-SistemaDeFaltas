#pragma once
#include "setSystem.h"
#include "telaCadastro.h"
#include "telaLogin.h"
#include <iostream>
#include <stdio.h>

void telaInicial() {
  unsigned short input;
  bool logged = false;

  while (!logged) {

    system(CLEAR_CONSOLE);

    std::cout << "1 - Login" << std::endl;
    std::cout << "2 - Cadastrar" << std::endl;

    std::cin >> input;
    std::cin.ignore();

    switch (input) {
    case 1:
      logged = telaLogin();
      break;
    case 2:
      telaCadastro();
      break;
    }
  }

  return;
}