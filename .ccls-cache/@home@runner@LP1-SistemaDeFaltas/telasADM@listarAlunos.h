#pragma once
#include "../alunos/Aluno.h"
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"
#include <stdio.h>
#include <string>
#include <vector>
#define LOGIN 0
#define SENHA 1

void listarAlunos(GerenciadorDoBancoDeDados &bd) {
  Aluno *aluno;
  std::vector<std::vector<std::string>> file = bd.getFile();
  std::string input;
  unsigned int index = 0;
  std::string cursos[3] = {"Engenharia da Computação", "Ciência da Computação",
                           "Ciência de Dados e Inteligência Artificial"};

  printf("    %-25s%-50s%s\n", "NOME\0", "CURSO\0", "MATRICULA\0");

  for (auto user : file) {
    index++;
    if (index != 1) {
      bd.mountAluno(aluno, user[LOGIN], user[SENHA]);
      printf("%d - %-25s%-50s%s\n", index - 1,
             (aluno->getPrimeiroNome() + " " + aluno->getUltimoNome()).c_str(),
             cursos[aluno->getCurso() - 1].c_str(),
             aluno->getMatricula().c_str());
    }
  }
  std::cout << std::endl << "pressione ENTER para sair" << std::endl;
    while (true) {
      getline(std::cin, input);
      if (input == "")
        return;
    }
}