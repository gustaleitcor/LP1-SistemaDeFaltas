#pragma once
#include "../Exceptions.h"
#include "../alunos/Aluno.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Essa classe possui os métodos que controlam o sistema CRUD
class GerenciadorDoBancoDeDados {
private:
  std::vector<std::vector<std::string>> file;
  std::string directory;

public:
  GerenciadorDoBancoDeDados(std::string directory);
  virtual ~GerenciadorDoBancoDeDados();

  std::vector<std::vector<std::string>> getFile() { return file; }
  void setDirectory(std::string val) { directory = val; }
  std::string getDirectory() { return directory; }

  void loadFile(std::string directory);
  void atualizarBancoDeDados(std::string directory,
                             std::vector<std::vector<std::string>> &file);

  bool ehLoginUnico(std::string login);
  bool ehUsuarioCadastrado(std::string login, std::string senha);
  unsigned int indexOfUser(std::string name, std::string senha);

  void appendUsuario(Aluno *aluno);
  void mountAluno(Aluno *&aluno, std::string login = getenv("LOGIN"),
                  std::string senha = getenv("SENHA"));

  Aluno *findAlunoByName(std::string name, GerenciadorDoBancoDeDados &bd);
  Aluno *findAlunoByMatricula(std::string matricula,
                              GerenciadorDoBancoDeDados &bd);

  void deletarAlunoByName(std::string name, GerenciadorDoBancoDeDados &bd);

  void deletarAlunoByMatricula(std::string matricula,
                               GerenciadorDoBancoDeDados &bd);
};