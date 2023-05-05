#pragma once

#include "Aluno.h"

class AlunoCDIA : public Aluno {
public:
  AlunoCDIA(std::string nome, std::string matricula, int curso,
            unsigned int periodo);
  AlunoCDIA();
  virtual ~AlunoCDIA();

  bool isObrigatorio(std::string disciplina) override;
};
