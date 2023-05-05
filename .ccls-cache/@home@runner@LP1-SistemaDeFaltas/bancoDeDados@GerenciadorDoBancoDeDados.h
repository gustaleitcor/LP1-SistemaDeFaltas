#pragma once
#include "../Exceptions.h"
#include "../alunos/Aluno.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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
  void mountAluno(Aluno *&aluno);
};