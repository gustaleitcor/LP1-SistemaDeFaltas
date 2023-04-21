#pragma once

#include "Aluno.h"

class AlunoCC : public Aluno {
public:
  AlunoCC();
  virtual ~AlunoCC();

  bool isObrigatorio(Disciplina disciplina) override;
};