#pragma once
#include "../Disciplina.h"
#include "../User.h"
#include <iostream>
#include <utility>
#include <vector>

class Aluno : public User {
public:
  // Construtor e Destrutor
  Aluno();
  Aluno(std::string nome, std::string matricula, int curso,
        unsigned int periodo = -1);
  virtual ~Aluno(){};

  // Metodos SET
  void setNome(std::string val) { nome = val; }
  void setMatricula(std::string val) { matricula = val; }
  void setCurso(int val) { curso = val; }
  void setPeriodo(unsigned short int val) { periodo = val; }
  void setCurso(unsigned short int val) { curso = val; }

  // Metodos GET
  std::string getNome() { return nome; }
  std::string getMatricula() { return matricula; }
  std::vector<std::pair<Disciplina, unsigned int>> getParesDisciplinasFaltas() {
    return disciplinas;
  }
  unsigned short int getPeriodo() { return periodo; }
  unsigned short int getCurso() { return curso; }

  // Metodos

  void addDisciplina(Disciplina disciplina);
  void updateFalta(Disciplina disciplina, unsigned int falta = -1);
  virtual bool isObrigatorio(
      std::string disciplina) = 0; // vai ser implementado pelas classes filhas

protected:
  std::string nome;
  std::string matricula;
  unsigned short int curso; // = 1 -> ENG C, = 2 -> CC, = 3 -> CDIA
  unsigned short int periodo;

  std::vector<std::pair<Disciplina, unsigned int>> disciplinas;
  // Um vetor com pares Disciplina e um unsigned int para as faltas
};