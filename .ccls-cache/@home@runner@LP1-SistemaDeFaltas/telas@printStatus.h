#pragma once
#include "../alunos/Aluno.h"
#include <iostream>

std::string cursos[3] = {"Engenharia da Computação", "Ciência da Computação",
                         "Ciência de Dados e Inteligência Artificial"};

void printStatus(Aluno *aluno) {
  std::cout << std::endl;
  std::cout << "Nome: " << aluno->getNome() << std::endl;
  std::cout << "Matricula: " << aluno->getMatricula() << std::endl;
  std::cout << "Periodo: "
            << (aluno->getPeriodo() == (unsigned short)-1
                    ? "Não informado"
                    : std::to_string(aluno->getPeriodo()))
            << std::endl;
  std::cout << "Curso: " << cursos[aluno->getCurso() - 1] << std::endl;
  std::cout << std::endl;
}