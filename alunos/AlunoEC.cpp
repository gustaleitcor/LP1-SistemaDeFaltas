#include "AlunoEC.h"
#include "../Disciplina.h"

AlunoEC::AlunoEC(std::string nome, std::string matricula, int curso,
                 unsigned int periodo)
    : Aluno(nome, matricula, curso) {}
AlunoEC::AlunoEC(){};

AlunoEC::~AlunoEC() {}

std::vector<std::vector<Disciplina>> AlunoEC::getDisciplinasObg() {
  return {
      {{"CÁLCULO VETORIAL E GEOMETRIA ANALÍTICA", "Manasses", 60},
       {"CÁLCULO DIFERENCIAL E INTEGRAL I", "Renata", 60},
       {"METODOLOGIA DO TRABALHO CIENTÍFICO", "Thais Gaudencio", 45},
       {"INTRODUÇÃO À ENGENHARIA DE COMPUTAÇÃO", "Anand Subramanian", 60},
       {"LABORATÓRIO DE INTRODUÇÃO À PROGRAMAÇÃO", "Linconl David Nery", 60},
       {"INTRODUÇÃO À PROGRAMAÇÃO PARA ENGENHARIA DE COMPUTAÇÃO",
        "Linconl David Nery", 60},
       {"MATERIAIS PARA MICRO E NANOTECNOLOGIA", "Ruy", 60}},
      {{"FÍSICA APLICADA À COMPUTAÇÃO I", "Alexandre Rosas", 60},
       {"CÁLCULO DIFERENCIAL E INTEGRAL II", "Isabella", 60},
       {"LABORATÓRIO DE LINGUAGEM DE PROGRAMAÇÃO I", "Derzu Omaia", 60},
       {"LINGUAGEM DE PROGRAMAÇÃO I", "Marcelo Iury", 60},
       {"CIRCUITOS LÓGICOS I", "José Antônio", 60},
       {"ELETRICIDADE E CIRCUITOS PARA COMPUTAÇÃO I", "Mardson", 60},
       {"FÍSICA EXPERIMENTAL PARA COMPUTAÇÃO", "Jairo", 30}},
      {{"INTRODUÇÃO À ÁLGEBRA LINEAR", "Indefinido", 60},
       {"CÁLCULO DIFERENCIAL E INTEGRAL III", "Indefinido", 60},
       {"PESQUISA APLICADA À COMPUTAÇÃO", "Indefinido", 45},
       {"CÁLCULO DAS PROBABILIDADES I", "Indefinido", 60},
       {"CIRCUITOS LÓGICOS II", "Indefinido", 60},
       {"ELETRICIDADE E CIRCUITOS PARA COMPUTAÇÃO II", "Indefinido", 60},
       {"MECÂNICA PARA ENGENHARIA DA COMPUTAÇÃO", "Indefinido", 60}},
      {{"SÉRIES E EQUAÇÕES DIFERENCIAIS ORDINÁRIAS", "Indefinido", 60},
       {"LINGUAGEM DE PROGRAMAÇÃO II", "Indefinido", 60},
       {"ESTRUTURA DE DADOS", "Indefinido", 60},
       {"ELETRÔNICA APLICADA I", "Indefinido", 60},
       {"ARQUITETURA DE COMPUTADORES", "Indefinido", 60}},
      {{"BANCO DE DADOS I", "Indefinido", 60},
       {"CÁLCULO NUMÉRICO", "Indefinido", 60},
       {"ANÁLISE E PROJETO DE ALGORITMOS", "Indefinido", 60},
       {"ELETRÔNICA APLICADA II", "Indefinido", 60},
       {"INTRODUÇÃO À MECÂNICA DOS FLUIDOS", "Indefinido", 30},
       {"INTRODUÇÃO À MICROELETRÔNICA", "Indefinido", 60}},
      {{"ENGENHARIA DE SOFTWARE", "Indefinido", 60},
       {"MICROCONTROLADORES", "Indefinido", 60},
       {"PESQUISA OPERACIONAL", "Indefinido", 60},
       {"REDES DE COMPUTADORES I", "Indefinido", 60},
       {"SINAIS E SISTEMAS DINÂMICOS", "Indefinido", 60},
       {"SISTEMAS OPERACIONAIS I", "Indefinido", 60}},
      {{"AVALIAÇÃO DE DESEMPENHO DE SISTEMAS OPERACIONAIS", "Indefinido", 60},
       {"REDES SEM FIO", "Indefinido", 60},
       {"INTRODUÇÃO À COMPUTAÇÃO GRÁFICA", "Indefinido", 60},
       {"INTRODUÇÃO AO PROCESSAMENTO DIGITAL DE IMAGENS", "Indefinido", 60},
       {"SISTEMAS E CONTROLE DE AUTOMAÇÃO", "Indefinido", 60},
       {"SISTEMAS EMBARCADOS I", "Indefinido", 60}},
      {{"INTRODUÇÃO A INTELIGÊNCIA ARTIFICIAL", "Indefinido", 60},
       {"ROBÓTICA", "Indefinido", 60},
       {"CONCEPÇÃO ESTRUTURADA DE CIRCUITOS INTEGRADOS", "Indefinido", 60},
       {"INTRODUÇÃO À TEORIA DA INFORMAÇÃO", "Indefinido", 60}},
      {{"ECONOMIA I", "Indefinido", 60},
       {"ADMINISTRAÇÃO PARA ENGENHARIA", "Indefinido", 45},
       {"COMPUTADORES E SOCIEDADE", "Indefinido", 60},
       {"TRABALHO DE CONCLUSÃO DE CURSO I", "Indefinido", 30}},
      {{"TRABALHO DE CONCLUSÃO DE CURSO II", "Indefinido", 30},
       {"ESTÁGIO SUPERVISIONADO", "Indefinido", 300}}};
}
