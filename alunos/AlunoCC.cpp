#include "AlunoCC.h"

AlunoCC::AlunoCC(std::string nome, std::string matricula, int curso,
                 unsigned int periodo)
    : Aluno(nome, matricula, curso) {}

AlunoCC::AlunoCC() {}

AlunoCC::~AlunoCC() {}

bool AlunoCC::isObrigatorio(std::string disciplina) {} // PRA SER IMPLEMENTADO