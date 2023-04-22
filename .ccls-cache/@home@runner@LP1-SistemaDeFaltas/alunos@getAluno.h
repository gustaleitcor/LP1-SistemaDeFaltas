#pragma once
#include "../Disciplina.h"
#include "Aluno.h"
#include "AlunoCC.h"
#include "AlunoCDIA.h"
#include "AlunoEC.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

void getAluno(Aluno *&aluno) {
  std::string reading;
  std::string login;
  std::string senha;

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
  std::string periodo;
  std::string curso;
  Disciplina disciplina;

  getline(file, nome);
  getline(file, matricula);
  getline(file, periodo);
  getline(file, curso);

  switch (std::stoi(curso)) {
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
  aluno->setCurso(std::stoi(curso));
  aluno->setMatricula(matricula);
  aluno->setPeriodo(std::stoi(periodo));

  std::string professor, nomeDisciplina;
  std::string cargaHoraria;

  while (getline(file, nomeDisciplina)) {
    if (nomeDisciplina == ",") {
      break;
    }

    getline(file, professor);
    getline(file, cargaHoraria);

    disciplina.setNome(nomeDisciplina);
    disciplina.setProfessor(professor);
    disciplina.setCargaHoraria(std::stoi(cargaHoraria));

    aluno->addDisciplina(disciplina);
  }

  file.close();

  return;
}