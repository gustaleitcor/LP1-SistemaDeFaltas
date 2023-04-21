#include "Aluno.h"
#include "Disciplina.h"

Aluno::Aluno(std::string nome, std::string matricula, int curso,
             unsigned int periodo) {
  setNome(nome);
  setMatricula(matricula);
  setCurso(curso);
  setPeriodo(periodo);
}

void Aluno::addDisciplina(Disciplina disciplina) {
  disciplinas.push_back({disciplina, 0});
  // Adiciona a disciplina e inicializa em 0 as faltas;
}

void Aluno::updateFalta(Disciplina disciplina, unsigned int falta) {
  // Pecorre todo o vetor de pares até achar a disciplina
  for (std::pair<Disciplina, unsigned int> &d : disciplinas) {
    if (d.first.getNome() == disciplina.getNome()) {
      if (falta == -1) {
        d.second++; // Se não for especificado a falta adiciona-se 1 à falta
      } else {
        d.second = falta; // C.C. Efetua a atualização da falta
      }
      return;
    }
  }
}