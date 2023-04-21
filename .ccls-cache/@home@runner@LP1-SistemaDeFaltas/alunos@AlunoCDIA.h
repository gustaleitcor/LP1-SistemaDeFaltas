#pragma once

#include "Aluno.h"

class AlunoCDIA : public Aluno {
public:
  AlunoCDIA();
  virtual ~AlunoCDIA();

  bool isObrigatorio(Disciplina disciplina) override;
};
