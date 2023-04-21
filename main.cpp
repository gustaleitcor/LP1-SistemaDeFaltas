#include "./alunos/Aluno.h"
#include "./telas/telaInicial.h"
#include <iostream>

int main() {

  // Apenas testes, sinta-se livre em apagar

  telaInicial();

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