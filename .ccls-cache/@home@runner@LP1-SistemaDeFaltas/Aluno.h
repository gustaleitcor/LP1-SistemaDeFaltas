#pragma once
#include "Disciplina.h"
#include <iostream>
#include <utility>
#include <vector>

class Aluno {
public:

  // EI BOY, TEM QUE COLOCAR OS NGC COMO VIRTUAL
  
  // Construtor e Destrutor
  Aluno(); // COLOQUEI CONSTRUTOR PADRAO
  Aluno(std::string nome, std::string matricula, int curso,
        unsigned int periodo = -1);
  virtual ~Aluno(){};

  // Metodos SET
  void setNome(std::string val) { nome = val; }
  void setMatricula(std::string val) { matricula = val; }
  //void setCurso(std::string val) { curso = val; }
  void setCurso(int val) { curso = val; }
  void setPeriodo(unsigned int val) { periodo = val; }

  // Metodos GET
  std::string getNome() { return nome; }
  std::string getMatricula() { return matricula; }
  std::vector<std::pair<Disciplina, unsigned int>> getParesDisciplinasFaltas() {
    return disciplinas;
  }
  unsigned int getPeriodo() { return periodo; }
  //std::string getCurso() { return curso; }
  int getCurso() { return curso; }

  // Metodos

  void addDisciplina(Disciplina disciplina);
  void updateFalta(Disciplina disciplina, unsigned int falta = -1);

  protected: // LOIRO MUDEI DE PRIVATE PRA PROTECTED PRA FAZER AS HERANÇAS
  std::string nome;
  std::string matricula;
  //std::string curso;
  short int curso; // = 1 -> ENG C, = 2 -> CC, = 3 -> CDIA esse dado
  unsigned short int periodo; // MUDEI PRA SHORT INT (MARCELO IURY GOSTA) 

  std::vector<std::pair<Disciplina, unsigned int>> disciplinas;
  // Um vetor com pares Disciplina e um unsigned int para as faltas
};