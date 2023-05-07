#pragma once
#include "../alunos/Aluno.h"
#include "../bancoDeDados/GerenciadorDoBancoDeDados.h"
#include "./menuADM.h"
#include <stdio.h>
#include <string>
#include <vector>
#define LOGIN 0
#define SENHA 1

void telaADM(GerenciadorDoBancoDeDados &bd) {
  while (menuADM(bd))
    system(CLEAR_CONSOLE);

  setenv("LOGIN", "", true);
  setenv("SENHA", "", true);
}