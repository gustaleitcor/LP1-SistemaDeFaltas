#include "AlunoEC.h"

AlunoEC::AlunoEC(std::string nome, std::string matricula, int curso,
                 unsigned int periodo)
    : Aluno(nome, matricula, curso) {}
AlunoEC::AlunoEC(){};

AlunoEC::~AlunoEC() {}

bool AlunoEC::isObrigatorio(std::string disciplina) {
  std::vector <std::string> obrigatorias = {"ijdslajk", "jeaslçk"};

  for (auto d : obrigatorias) {
    if (disciplina ==  d)
      return true;
  }

  return false;
  
} // VAI SER IMPLEMENTADO