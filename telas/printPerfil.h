#pragma once
#include "../alunos/Aluno.h"
#include <stdio.h>

void printDisciplinas(Aluno *&aluno) {
  unsigned int index = 0;

  printf("   %-25s%-25s%-25s\n", "Disciplina", "Professor", "Faltas");

  for (auto d : aluno->getParesDisciplinasFaltas()) {

    index++;

    printf("%d - %-25s%-25s%-25d\n", index, d.first.getNome().c_str(),
           d.first.getProfessor().c_str(), d.second);
  }
  return;
}

void printPerfil(Aluno *&aluno) {

  std::string cursos[3] = {"Engenharia da Computação", "Ciência da Computação",
                     "Ciência de Dados e Inteligência Artificial"};

  std::cout << "Curso: " << cursos[aluno->getCurso() - 1] << std::endl;
  std::cout << aluno->getNome() << " (Periodo "
            << (aluno->getPeriodo() != 65535
                    ? std::to_string(aluno->getPeriodo())
                    : "não informado")
            << "):" << std::endl;

  printDisciplinas(aluno);

  return;
}