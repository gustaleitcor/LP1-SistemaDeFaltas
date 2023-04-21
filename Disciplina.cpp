#include "Disciplina.h"

Disciplina::Disciplina() {}

Disciplina::Disciplina(std::string nome, std::string professor, int cargaHoraria) {
  setNome(nome);
  setProfessor(professor);
  setCargaHoraria(cargaHoraria);
}

Disciplina::~Disciplina() {}

