#pragma once

#include "Aluno.h"
#include "../Disciplina.h"
#include <vector>

class AlunoCC : public Aluno {
public:
  AlunoCC(std::string nome, std::string matricula, int curso,
          unsigned int periodo);
  AlunoCC();
  virtual ~AlunoCC();

  std::vector<std::vector<Disciplina>> getDisciplinasObg() override;

  bool isObrigatorio(std::string disciplina) override;
};