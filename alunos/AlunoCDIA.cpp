#include "AlunoCDIA.h"

AlunoCDIA::AlunoCDIA(std::string nome, std::string matricula, int curso,
                     unsigned int periodo)
    : Aluno(nome, matricula, curso) {}

AlunoCDIA::AlunoCDIA(){};

AlunoCDIA::~AlunoCDIA() {}

std::vector<std::vector<Disciplina>> AlunoCDIA::getDisciplinasObg() {
  return {{{"CÁLCULO VETORIAL E GEOMETRIA ANALÍTICA", "Indefinido", 60},
           {"CÁLCULO DIFERENCIAL E INTEGRAL I", "Indefinido", 60},
           {"INTRODUÇÃO A PROGRAMAÇÃO", "Indefinido", 60},
           {"INTRODUCAO AO COMPUTADOR", "Indefinido", 60},
           {"METODOLOGIA DO TRABALHO CIENTIFICO", "Indefinido", 45}},
          {{"CÁLCULO DIFERENCIAL E INTEGRAL II", "Indefinido", 60},
           {"INTRODUÇÃO À ÁLGEBRA LINEAR", "Indefinido", 60},
           {"MATEMÁTICA DISCRETA", "Indefinido", 60},
           {"PROGRAMAÇÃO ESTRUTURADA", "Indefinido", 60},
           {"INTRODUÇÃO À CIÊNCIA DE DADOS", "Indefinido", 60}},
          {{"CÁLCULO DIFERENCIAL E INTEGRAL III", "Indefinido", 60},
           {"ESTRUTURA DE DADOS", "Indefinido", 60},
           {"ÁLGEBRA LINEAR COMPUTACIONAL", "Indefinido", 60},
           {"PROGRAMAÇÃO ORIENTADA A OBJETOS", "Indefinido", 60},
           {"TEORIA DAS PROBABILIDADES", "Indefinido", 60}},
          {{"BANCO DE DADOS I", "Indefinido", 60},
           {"PESQUISA OPERACIONAL", "Indefinido", 60},
           {"MÉTODOS MATEMÁTICOS I", "Indefinido", 60},
           {"PESQUISA APLICADA À CIÊNCIA DE DADOS", "Indefinido", 45},
           {"INTRODUÇÃO A INTELIGÊNCIA ARTIFICIAL", "Indefinido", 60},
           {"INFERÊNCIA ESTATÍSTICA", "Indefinido", 60}},
          {{"ANÁLISE E PROJETO DE ALGORITMOS", "Indefinido", 60},
           {"OTIMIZAÇÃO NÃO-LINEAR", "Indefinido", 60},
           {"TEORIA DOS GRAFOS APLICADA", "Indefinido", 60},
           {"APRENDIZAGEM DE MÁQUINA", "Indefinido", 60},
           {"EQUAÇÕES DIFERENCIAIS ORDINÁRIAS", "Indefinido", 60}},
          {{"ENGENHARIA DE SOFTWARE", "Indefinido", 60},
           {"APRENDIZADO PROFUNDO", "Indefinido", 60},
           {"ANÁLISE MULTIVARIADA E APRENDIZAGEM NÃO SUPERVISIONADO",
            "Indefinido", 60},
           {"MÉTODOS NUMÉRICOS I", "Indefinido", 60},
           {"COMPUTADORES E SOCIEDADE", "Indefinido", 60}},
          {{"INTELIGÊNCIA COMPUTACIONAL", "Indefinido", 60},
           {"VISUALIZAÇÃO DE DADOS", "Indefinido", 60},
           {"MINERAÇÃO ESTATÍSTICA DE DADOS", "Indefinido", 60},
           {"EMPREENDEDORISMO", "Indefinido", 60}},
          {{"BIG DATA", "Indefinido", 60},
           {"ESTÁGIO SUPERVISIONADO", "Indefinido", 300},
           {"TRABALHO DE CONCLUSÃO DE CURSO", "Indefinido", 60}}};
};

bool AlunoCDIA::isObrigatorio(std::string disciplina) {}