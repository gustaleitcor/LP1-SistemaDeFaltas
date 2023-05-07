#pragma once
#include "../alunos/Aluno.h"
#include <stdio.h>

// Printa as disciplinas pagas
void printDisciplinas(Aluno *&aluno) {
  unsigned int index = 0;

  printf("   %-50s%-50s%s\n", "Disciplina", "Professor", "Faltas");

  for (auto d : aluno->getParesDisciplinasFaltas()) {

    index++;

    printf("%d - %-50s%-50s%d\n", index, d.first.getNome().c_str(),
           d.first.getProfessor().c_str(), d.second);
  }
  return;
}

// Printa o perfil do aluno na tela
void printPerfil(Aluno *&aluno, bool showDisciplinas = true) {

  std::string cursos[3] = {"Engenharia da Computação", "Ciência da Computação",
                     "Ciência de Dados e Inteligência Artificial"};

  std::cout << "Curso: " << cursos[aluno->getCurso() - 1] << std::endl;
  std::cout << aluno->getNome() << " (Periodo "
            << (aluno->getPeriodo() != 65535
                    ? std::to_string(aluno->getPeriodo())
                    : "não informado")
            << "):" << std::endl;
  
  if(showDisciplinas)
    printDisciplinas(aluno);

  return;
}