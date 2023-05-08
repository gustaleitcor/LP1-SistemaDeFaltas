#include "AlunoCC.h"

AlunoCC::AlunoCC(std::string nome, std::string matricula, int curso,
                 unsigned int periodo)
    : Aluno(nome, matricula, curso) {}

AlunoCC::AlunoCC() {}

AlunoCC::~AlunoCC() {}

std::vector<std::vector<Disciplina>> AlunoCC::getDisciplinasObg() {
  return {{{"CÁLCULO VETORIAL E GEOMETRIA ANALÍTICA", "Indefinido", 60},
           {"CÁLCULO DIFERENCIAL E INTEGRAL I", "Indefinido", 60},
           {"INTRODUÇÃO A PROGRAMAÇÃO", "Indefinido", 60},
           {"MATEMÁTICA DISCRETA", "Indefinido", 60},
           {"METODOLOGIA DO TRABALHO CIENTÍFICO PARA CIÊNCIA DA COMPUTAÇÃO",
            "Indefinido", 30},
           {"INTRODUÇÃO À CIÊNCIA DA COMPUTAÇÃO", "Indefinido", 60},
           {"PESQUISA APLICADA À COMPUTAÇÃO", "Indefinido", 30}},
          {{"CÁLCULO DIFERENCIAL E INTEGRAL II", "Indefinido", 60},
           {"INTRODUÇÃO À ÁLGEBRA LINEAR", "Indefinido", 60},
           {"LÓGICA APLICADA À COMPUTAÇÃO", "Indefinido", 60},
           {"PROGRAMAÇÃO ORIENTADA A OBJETOS", "Indefinido", 60},
           {"ARQUITETURA DE COMPUTADORES I", "Indefinido", 60}},
          {{"CÁLCULO DAS PROBABILIDADES E ESTATÍSTICA I", "Indefinido", 60},
           {"LINGUAGENS FORMAIS E COMPUTABILIDADE", "Indefinido", 60},
           {"ESTRUTURAS DE DADOS E ALGORITMOS I", "Indefinido", 60},
           {"PROGRAMAÇÃO FUNCIONAL", "Indefinido", 60},
           {"CÁLCULO NUMÉRICO", "Indefinido", 60},
           {"ARQUITETURA DE COMPUTADORES II", "Indefinido", 60}},
          {{"ENGENHARIA DE SOFTWARE", "Indefinido", 60},
           {"INTRODUÇÃO A INTELIGÊNCIA ARTIFICIAL", "Indefinido", 60},
           {"ESTRUTURAS DE DADOS E ALGORITMOS II", "Indefinido", 60},
           {"INTRODUÇÃO AO PROCESSAMENTO DIGITAL DE IMAGENS", "Indefinido", 60},
           {"REDES DE COMPUTADORES I", "Indefinido", 60},
           {"SISTEMAS OPERACIONAIS I", "Indefinido", 60}},
          {{"BANCO DE DADOS I", "Indefinido", 60},
           {"ESPECIFICAÇÃO DE REQUISITOS DE SOFTWARE", "Indefinido", 60},
           {"PARADIGMAS DE LINGUAGENS DE PROGRAMAÇÃO", "Indefinido", 60},
           {"SISTEMAS BASEADOS EM CONHECIMENTO", "Indefinido", 60},
           {"PROGRAMAÇÃO CONCORRENTE E DISTRIBUÍDA", "Indefinido", 60},
           {"ANÁLISE E PROJETO DE ALGORITMOS", "Indefinido", 60}},
          {{"MÉTODOS DE PROJETO DE SOFTWARE", "Indefinido", 60},
           {"PARADIGMAS DE APRENDIZAGEM DE MÁQUINA", "Indefinido", 60},
           {"SEGURANÇA COMPUTACIONAL", "Indefinido", 60},
           {"SISTEMAS DISTRIBUÍDOS", "Indefinido", 60},
           {"INOVAÇÃO DE BASE CIENTÍFICA-TECNOLÓGICA E EMPREENDEDORISMO",
            "Indefinido", 60},
           {"CONSTRUÇÃO DE COMPILADORES I", "Indefinido", 60}},
          {{"ENGENHARIA DE SISTEMAS DISTRIBUÍDOS", "Indefinido", 60},
           {"GERENCIAMENTO DE PROJETO DE SOFTWARE", "Indefinido", 60},
           {"TESTE DE SOFTWARE", "Indefinido", 60},
           {"TRABALHO DE CONCLUSÃO DE CURSO PARA CIÊNCIA DA COMPUTAÇÃO",
            "Indefinido", 60},
           {"INTERAÇÃO HUMANO-COMPUTADOR", "Indefinido", 60},
           {"SISTEMAS DE INFORMAÇÃO NAS ORGANIZAÇÕES", "Indefinido", 60}},
          {{"COMPUTADORES E SOCIEDADE", "Indefinido", 60},
           {"ESTÁGIO SUPERVISIONADO", "Indefinido", 300}}};
}