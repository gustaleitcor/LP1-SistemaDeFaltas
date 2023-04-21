#pragma once
#include <fstream>

void setQtdZero(){
  std::ofstream outputFile("bancoDeDados/alunos.bin");

  outputFile << 0;
  return
}