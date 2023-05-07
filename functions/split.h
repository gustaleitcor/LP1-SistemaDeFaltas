#pragma once
#include <string>
#include <vector>

std::vector<std::string> split(std::string &linha) {
  std::vector<std::string> objeto;
  std::string atributo;

  for (char c : linha) {
    if (c == ',') {
      objeto.push_back(atributo);
      atributo = "";
      continue;
    }
    atributo += c;
  }
  return objeto;
}