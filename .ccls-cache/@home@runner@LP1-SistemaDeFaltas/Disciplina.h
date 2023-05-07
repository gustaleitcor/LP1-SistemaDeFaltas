#pragma once

#include <iostream>

class Disciplina {
public:
  // contrutores e dtor
  Disciplina();
  Disciplina(std::string nome, std::string professor, int cargaHoraria);
  virtual ~Disciplina();

  // métodos set
  void setNome(std::string nome) { this->nome = nome; }
  void setProfessor(std::string professor) { this->professor = professor; }
  void setCargaHoraria(int cargaHoraria) { this->cargaHoraria = cargaHoraria; }

  // métodos get
  std::string getNome() { return nome; }
  std::string getProfessor() { return professor; }
  int getCargaHoraria() { return cargaHoraria; }

protected:
  std::string nome;
  std::string professor;
  int cargaHoraria;
};