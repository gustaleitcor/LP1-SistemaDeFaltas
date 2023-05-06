#pragma once
#include <string>

std::string tolowercase(std::string str){
  char c;
  std::string response;
  for(char c : str){
    response += tolower(c);
  }
  return response;
}