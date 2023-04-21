#pragma once
#include "setSystem.h"
#include "telaLogin.h"
#include "telaCadastro.h"
#include <iostream>
#include <stdio.h>

void telaInicial() {
  system(CLEAR_CONSOLE);

  unsigned short input;

  std::cout << "1 - Login" << std::endl;
  std::cout << "2 - Cadastrar" << std::endl;

  std::cin >> input;
  std::cin.ignore();
  
  switch (input) {
  case 1:
    telaLogin();
    break;
  case 2:
    telaCadastro();
    break;
  }

  return;
}