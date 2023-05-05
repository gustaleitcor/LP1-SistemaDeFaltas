#include "AlunoCDIA.h"

AlunoCDIA::AlunoCDIA(std::string nome, std::string matricula, int curso,
                     unsigned int periodo)
    : Aluno(nome, matricula, curso) {}

AlunoCDIA::AlunoCDIA(){};

AlunoCDIA::~AlunoCDIA() {}

bool AlunoCDIA::isObrigatorio(std::string disciplina) {}