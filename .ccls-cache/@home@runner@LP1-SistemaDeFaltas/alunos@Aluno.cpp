#include "Aluno.h"
#include "../Disciplina.h"

std::vector<std::string> split(std::string str) {
  char c;
  std::vector<std::string> splited_str;
  std::string aux;
  for (char c : str) {
    if (c == ' ') {
      splited_str.push_back(aux);
      aux = "";
      continue;
    }
    aux += c;
  }
  splited_str.push_back(aux);
  return splited_str;
}

Aluno::Aluno() {
  setNome("");
  setMatricula("");
  setCurso(0);
  setPeriodo(0);
}

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

std::string Aluno::getPrimeiroNome() { return split(getNome())[0]; }
std::string Aluno::getUltimoNome() {
  if (split(getNome()).size() > 1) {
    return split(getNome())[split(getNome()).size() - 1];
  }
  return "";
}