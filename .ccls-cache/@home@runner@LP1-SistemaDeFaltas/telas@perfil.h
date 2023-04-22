#pragma once
#include "../alunos/Aluno.h"

void perfil(Aluno *&aluno) {

  std::cout << "Curso: " << aluno->getCurso() << std::endl;
  std::cout << aluno->getNome() << " (Periodo "
            << (aluno->getPeriodo() > 1 ? std::to_string(aluno->getPeriodo())
                                        : "não informado")
            << "):" << std::endl;

  unsigned int index = 1;

  for (auto d : aluno->getParesDisciplinasFaltas()) {
    std::cout << index << "  " << d.first.getNome() << ' '
              << d.first.getProfessor() << ' ' << d.second << std::endl;
    index++;
  }

  return;
}