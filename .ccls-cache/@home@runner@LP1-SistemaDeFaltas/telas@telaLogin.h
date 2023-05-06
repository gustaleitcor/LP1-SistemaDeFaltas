#pragma once
#include "../alunos/Aluno.h"
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"
#include "iostream"
#include "setSystem.h"
#include <fstream>
#include <string>

bool telaLogin(GerenciadorDoBancoDeDados bd) {
  system(CLEAR_CONSOLE);

  std::string login;
  std::string senha;
  std::string input;

  while (true) {

    std::cout << "----LOGIN----" << std::endl;
    std::cout << std::endl;

    std::cout << "Digite o login: ";
    getline(std::cin, login);
    std::cout << "Digite a senha: ";
    getline(std::cin, senha);

    // Retira espaços extras no login
    int spacePos = login.find_last_not_of(' ');

    if (spacePos != std::string::npos) {
      login.erase(spacePos + 1);
    }

    // Tenta acessar um login
    if (bd.ehUsuarioCadastrado(login, senha)) {
      setenv("LOGIN", login.c_str(), true);
      setenv("SENHA", senha.c_str(), true);
      return true;
    }
    system(CLEAR_CONSOLE);

    // Quando o login não é encontrado 
    do {
      std::cout << "Usuario não reconhecido, deseja tentar novamente? (y/n) ";
      getline(std::cin, input);
      
      if (input == "") {
        continue;
      } else if (input == "y") {
        break;
      } else if (input == "n") {
        return false;
      }
      
    } while (true);
    
  }
  
  return false;
}