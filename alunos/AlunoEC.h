#pragma once

#include "Aluno.h"

class AlunoEC : public Aluno {
public:
  AlunoEC(std::string nome, std::string matricula, int curso,
          unsigned int periodo);
  AlunoEC();
  virtual ~AlunoEC();

  bool isObrigatorio(std::string disciplina) override;

  std::vector<std::vector<Disciplina>> getDisciplinasObg() override;
};