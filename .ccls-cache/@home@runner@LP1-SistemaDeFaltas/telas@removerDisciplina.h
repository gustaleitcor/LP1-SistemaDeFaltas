#pragma once
#include "../alunos/Aluno.h"
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"
#include "printPerfil.h"
#include "setSystem.h"
#include <fstream>
#include <stdlib.h>

void removerDisciplina(GerenciadorDoBancoDeDados &bd, Aluno *&aluno) {

  // Carregando o banco de dados
  std::vector<std::vector<std::string>> file = bd.getFile();
  unsigned int UserIndex = bd.indexOfUser(getenv("LOGIN"), getenv("SENHA"));
  short input;

  // Limpando tela
  system(CLEAR_CONSOLE);

  unsigned int qtdDisciplinas = (file[UserIndex].size() - 6) / 4;

  printDisciplinas(aluno);

  std::cout << "0 - Sair" << std::endl;

  // Perguntando ao usuário qual disciplina será excluída
  do {
    std::cout << "Selecione a diciplina a ser excluída: ";
    std::cin >> input;
    std::cin.ignore();

    if (input == 0) {
      return;
    }

  } while (input < 0 || input > qtdDisciplinas);

  for (int i = 0; i < 4; i++) {
    file[UserIndex].erase(file[UserIndex].begin() + 6 + (3 * (input - 1)));
  }

  bd.atualizarBancoDeDados(bd.getDirectory(), file);
  bd.mountAluno(aluno);
}