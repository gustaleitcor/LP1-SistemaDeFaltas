#include "./alunos/Aluno.h"
#include "./alunos/attAluno.h"
#include "./telas/menu.h"
#include "./telas/telaInicial.h"
#include <fstream>
#include <iostream>

int main() {

  Aluno *aluno = nullptr;

  telaInicial(); // tela de login e cadastro

  attAluno(aluno); // busca do aluno no banco de dados

  system(CLEAR_CONSOLE);

  while (menu(aluno)) // printa o menu
    system(CLEAR_CONSOLE);

  delete aluno; // deleta o aluno (ponteiro)

  return 0;
}

/*Aluno aluno("Enzo Fernandes", "20220023799", 1);

  Disciplina calculoVetorial("CÁLCULO VETORIAL", "Manasses", 270);
  Disciplina calculo("CÁLCULO DIFERENCIAL E INTEGRAL II", "Isabella Silva",
                     340);
  Disciplina teoriaDaComputação("TEORIA DA COMPUTAÇÃO", "Antonio Oliveira",
                                210);

  aluno.addDisciplina(calculoVetorial);
  aluno.addDisciplina(calculo);
  aluno.addDisciplina(teoriaDaComputação);

  aluno.updateFalta(calculoVetorial, 3);
  aluno.updateFalta(calculo);

  std::cout << "Curso: " << aluno.getCurso() << std::endl;
  std::cout << aluno.getNome() << " (Periodo "
            << (aluno.getPeriodo() < 0 ? std::to_string(aluno.getPeriodo())
                                       : "não informado")
            << "):" << std::endl;

  for (std::pair<Disciplina, unsigned int> d :
       aluno.getParesDisciplinasFaltas()) {
    std::cout << "  " << d.first.getNome() << ' ' << d.first.getProfessor()
              << ' ' << d.second << std::endl;
  }*/