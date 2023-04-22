#pragma once
#include "../alunos/Aluno.h"
#include <stdio.h>

void printPerfil(Aluno *&aluno) {

  char *cursos[3] = {"Engenharia da Computação\0", "Ciência da Computação\0",
                     "Ciência de Dados e Inteligência Artificial\0"};

  std::cout << "Curso: " << cursos[aluno->getCurso() - 1] << std::endl;
  std::cout << aluno->getNome() << " (Periodo "
            << (aluno->getPeriodo() > 1 ? std::to_string(aluno->getPeriodo())
                                        : "não informado")
            << "):" << std::endl;

  unsigned int index = 1;

  printf("   %-25s%-25s%-25s\n", "Disciplina", "Professor", "Faltas");

  for (auto d : aluno->getParesDisciplinasFaltas()) {

    printf("%d - %-25s%-25s%-25d\n", index, d.first.getNome().c_str(),
           d.first.getProfessor().c_str(), d.second);

    index++;
  }

  return;
}