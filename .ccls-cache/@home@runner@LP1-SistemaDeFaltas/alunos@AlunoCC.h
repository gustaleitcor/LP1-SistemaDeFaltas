#pragma once

#include "Aluno.h"

class AlunoCC : public Aluno {
public:
  AlunoCC(std::string nome, std::string matricula, int curso,
          unsigned int periodo);
  AlunoCC();
  virtual ~AlunoCC();

  bool isObrigatorio(std::string disciplina) override;
};