#pragma once
#include <string>

class User {
private:
  std::string login;
  std::string senha;

public:
  void setLogin(std::string val) { login = val; }
  void setSenha(std::string val) { senha = val; }

  std::string getLogin() { return login; }
  std::string getSenha() { return senha; }
};