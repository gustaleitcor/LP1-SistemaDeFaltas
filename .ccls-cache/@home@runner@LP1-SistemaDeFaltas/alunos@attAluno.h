#pragma once
#include "../Disciplina.h"
#include "../bancoDeDados/gerenciadorDoBancoDeDados.h"
#include "Aluno.h"
#include "AlunoCC.h"
#include "AlunoCDIA.h"
#include "AlunoEC.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

void attAluno(Aluno *&aluno) {

  std::ifstream inputFile("bancoDeDados/alunos.txt");

  if (!inputFile.is_open()) {
    std::cout << "Erro ao abrir o arquivo" << std::endl;
  }

  std::vector<std::vector<std::string>> file;
  std::vector<std::string> object;
  std::string line;

  while (getline(inputFile, line)) {
    object = split(line);
    if (object[0] == getenv("LOGIN") && object[1] == getenv("SENHA")) {
      break;
    }
  }

  std::string nome = object[2];
  std::string matricula = object[3];
  std::string periodo = object[4];
  std::string curso = object[5];

  Disciplina disciplina;

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
  std::string cargaHoraria, faltas;

  for (unsigned int i = 6; i < object.size(); i += 4) {
    nomeDisciplina = object[i];
    professor = object[i + 1];
    cargaHoraria = object[i + 2];
    faltas = object[i + 3];

    disciplina.setNome(nomeDisciplina);
    disciplina.setProfessor(professor);
    disciplina.setCargaHoraria(std::stoi(cargaHoraria));

    aluno->addDisciplina(disciplina);
      std::cout << faltas << std::endl;
    aluno->updateFalta(disciplina, std::stoi(faltas));
  }

  inputFile.close();

  return;
}