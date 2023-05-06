#include "GerenciadorDoBancoDeDados.h"
#include "../Exceptions.h"
#include "../functions/tolowercase.h"
#include <fstream>
#include <vector>

std::vector<std::string> split(std::string &linha) {
  std::vector<std::string> objeto;
  std::string atributo;

  for (char c : linha) {
    if (c == ',') {
      objeto.push_back(atributo);
      atributo = "";
      continue;
    }
    atributo += c;
  }
  return objeto;
}

GerenciadorDoBancoDeDados::GerenciadorDoBancoDeDados(std::string directory) {
  setDirectory(directory);
  loadFile(directory);
}

GerenciadorDoBancoDeDados::~GerenciadorDoBancoDeDados() {}

void GerenciadorDoBancoDeDados::loadFile(std::string directory) {
  std::ifstream inputFile(directory);

  if (!inputFile.is_open()) {
    throw FileHasNotOpenException("Erro ao abrir o banco de dados");
  }

  std::vector<std::vector<std::string>> file;
  std::vector<std::string> object;
  std::string line;

  while (getline(inputFile, line)) {
    object = split(line);
    file.push_back(object);
  }

  inputFile.close();

  this->file = file;
}

void GerenciadorDoBancoDeDados::atualizarBancoDeDados(
    std::string directory, std::vector<std::vector<std::string>> &file) {

  std::ofstream outputFile(directory);

  if (!outputFile.is_open()) {
    throw FileHasNotOpenException("Erro ao abrir o banco de dados");
  }

  for (auto line : file) {
    for (auto atribute : line) {
      outputFile << atribute << ',';
    }
    outputFile << std::endl;
  }
  this->file = file;
}

unsigned int GerenciadorDoBancoDeDados::indexOfUser(std::string login,
                                                    std::string senha) {
  unsigned int index = 0;
  for (auto user : getFile()) {
    if (user[0] == login && user[1] == senha) {
      return index;
    }
    index++;
  }

  throw ElementNotFoundException("Usuario não encontrado");
}

bool GerenciadorDoBancoDeDados::ehUsuarioCadastrado(std::string login,
                                                    std::string senha) {

  for (auto user : getFile()) {
    if (user[0] == login && user[1] == senha) {
      return true;
    }
  }
  return false;
}

bool GerenciadorDoBancoDeDados::ehLoginUnico(std::string login) {

  for (auto user : getFile()) {
    if (user[0] == login) {
      return false;
    }
  }
  return true;
}

void GerenciadorDoBancoDeDados::appendUsuario(Aluno *aluno) {
  std::ofstream outputFile(getDirectory(), std::fstream::app);

  if (!outputFile.is_open()) {
    throw FileHasNotOpenException("Arquivo append não foi aberto");
  }

  outputFile << aluno->getLogin() << ',';
  outputFile << aluno->getSenha() << ',';
  outputFile << aluno->getNome() << ',';
  outputFile << aluno->getMatricula() << ',';
  outputFile << aluno->getPeriodo() << ',';
  outputFile << aluno->getCurso() << ',';
  outputFile << std::endl;

  outputFile.close();
}

#include "../Disciplina.h"
#include "../alunos/AlunoCC.h"
#include "../alunos/AlunoCDIA.h"
#include "../alunos/AlunoEC.h"
#define NOME 2
#define MATRICULA 3
#define PERIODO 4
#define CURSO 5
#define DISCIPLINA 0
#define PROFESSOR 1
#define CARGAHORARIA 2
#define FALTAS 3

void GerenciadorDoBancoDeDados::mountAluno(Aluno *&aluno, std::string login,
                                           std::string senha) {

  std::vector<std::vector<std::string>> file = getFile();
  unsigned int userIndex = indexOfUser(login, senha);

  switch (std::stoi(file[userIndex][CURSO])) {
  case 1:
    aluno = new AlunoEC;
    break;
  case 2:
    aluno = new AlunoCC;
    break;
  case 3:
    aluno = new AlunoCDIA;
    break;
  default:
    std::cout << "Algo de errado ocorreu!" << std::endl;
  }

  aluno->setNome(file[userIndex][NOME]);
  aluno->setMatricula(file[userIndex][MATRICULA]);
  aluno->setPeriodo(std::stoi(file[userIndex][PERIODO]));
  aluno->setCurso(std::stoi(file[userIndex][CURSO]));

  Disciplina disciplina;
  std::string professor, nomeDisciplina;
  std::string cargaHoraria, faltas;

  for (unsigned int i = 6; i < file[userIndex].size(); i += 4) {
    disciplina.setNome(file[userIndex][i + DISCIPLINA]);
    disciplina.setProfessor(file[userIndex][i + PROFESSOR]);
    disciplina.setCargaHoraria(std::stoi(file[userIndex][i + CARGAHORARIA]));

    aluno->addDisciplina(disciplina);
    aluno->updateFalta(disciplina, std::stoi(file[userIndex][i + FALTAS]));
  }

  return;
}

Aluno *
GerenciadorDoBancoDeDados::findAlunoByName(std::string name,
                                           GerenciadorDoBancoDeDados &bd) {
  Aluno *aluno;
  bool first = true;
  std::vector<std::vector<std::string>> file = bd.getFile();

  for (auto user : file) {
    if (first) {
      first = false;
      continue;
    }
    if (tolowercase(user[2]).find(tolowercase(name)) != std::string::npos) {
      bd.mountAluno(aluno, user[0], user[1]);
      return aluno;
    }
  }

  throw ElementNotFoundException("Usuario não encontrado");
}

Aluno *
GerenciadorDoBancoDeDados::findAlunoByMatricula(std::string matricula,
                                                GerenciadorDoBancoDeDados &bd) {
  Aluno *aluno;
  std::vector<std::vector<std::string>> file = bd.getFile();
  bool first = true;

  for (auto user : file) {
    if (first == true) {
      first = false;
      continue;
    }
    if (user[3] == matricula) {
      bd.mountAluno(aluno, user[0], user[1]);
      return aluno;
    }
  }

  throw ElementNotFoundException("Usuario não encontrado");
}

void GerenciadorDoBancoDeDados::deletarAlunoByName(
    std::string name, GerenciadorDoBancoDeDados &bd) {
  unsigned int index = 0;
  std::vector<std::vector<std::string>> file = bd.getFile();

  for (auto user : file) {
    if (user[2] == name && index != 0) {
      file.erase(file.begin() + index);
      bd.atualizarBancoDeDados(bd.getDirectory(), file);
      bd.loadFile((bd.getDirectory()));
      return;
    }
    index++;
  }
  throw ElementNotFoundException("Usuario não encontrado");
}

void GerenciadorDoBancoDeDados::deletarAlunoByMatricula(
    std::string matricula, GerenciadorDoBancoDeDados &bd) {
  std::vector<std::vector<std::string>> file = bd.getFile();
  unsigned int index = 0;

  for (auto user : file) {
    if (user[3] == matricula && index != 0) {
      file.erase(file.begin() + index);
      bd.atualizarBancoDeDados(bd.getDirectory(), file);
      bd.loadFile((bd.getDirectory()));
      return;
    }
    index++;
  }

  throw ElementNotFoundException("Usuario não encontrado");
}
