#include "./alunos/Aluno.h"
#include "./bancoDeDados/GerenciadorDoBancoDeDados.h"
#include "./telas/menu.h"
#include "./telas/telaInicial.h"
#include "./telasADM/telaADM.h"

int main() {

  Aluno *aluno = nullptr;
  GerenciadorDoBancoDeDados bda(
      "bancoDeDados/alunos.txt"); // Banco de Dados Aluno

  telaInicial(bda); // tela de login e cadastro

  if (getenv("LOGIN") == bda.getFile()[0][0] &&
      getenv("SENHA") == bda.getFile()[0][1]) {

    system(CLEAR_CONSOLE);

    telaADM(bda);

  } else {
    bda.mountAluno(aluno); // busca e monta o aluno do banco de dados

    system(CLEAR_CONSOLE);

    while (menu(bda, aluno)) // printa o menu
      system(CLEAR_CONSOLE);
  }

  delete aluno; // deleta o aluno (ponteiro)

  return 0;
}
