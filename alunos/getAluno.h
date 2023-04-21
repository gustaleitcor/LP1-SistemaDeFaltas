#pragma once
#include "../Disciplina.h"
#include "Aluno.h"
#include "AlunoCC.h"
#include "AlunoCDIA.h"
#include "AlunoEC.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

Aluno *getAluno() {
  std::string reading;
  std::string login;
  std::string senha;

  Aluno *aluno;

  std::ifstream file("bancoDeDados/alunos.txt");

  if (!file.is_open()) {
    std::cout << "Erro ao abrir o arquivo" << std::endl;
  }

  while (getline(file, reading)) {
    if (getenv("LOGIN") == reading) {
      getline(file, reading);
      if (getenv("SENHA") == reading) {
        break;
      }
    }

    do {
      getline(file, reading);
    } while (reading != ",");
  }

  std::string nome;
  std::string matricula;
  unsigned short periodo;
  short curso;
  Disciplina disciplina;
  char lixo;

  getline(file, nome);
  getline(file, matricula);
  file >> periodo;
  file >> curso;

  switch (curso) {
  case 1:
    aluno = new AlunoEC;
    break;
  case 2:
    aluno = new AlunoCC;
    break;
  case 3:
    aluno = new AlunoCDIA;
    break;
  default:
    std::cout << "Algo de errado ocorreu!" << std::endl;
  }

  aluno->setNome(nome);
  aluno->setCurso(curso);
  aluno->setMatricula(matricula);
  aluno->setPeriodo(periodo);

  std::string professor;
  unsigned int cargaHoraria;

  while (getline(file, nome)) {
    if (nome == ",") {
      break;
    }

    getline(file, professor);
    file >> cargaHoraria;
    file >> lixo;

    disciplina.setNome(nome);
    disciplina.setProfessor(professor);
    disciplina.setCargaHoraria(cargaHoraria);

    aluno->addDisciplina(disciplina);
  }

  file.close();

  return aluno;
}