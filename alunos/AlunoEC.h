#pragma once

#include "Aluno.h"

class AlunoEC : public Aluno {
public:
  AlunoEC();
  virtual ~AlunoEC();

  bool isObrigatorio(Disciplina disciplina) override;
};