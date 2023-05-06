#pragma once
#include <string>

void tiraEspacos(std::string &str){
int spacePos = str.find_last_not_of(' ');

    if (spacePos != std::string::npos) {
      str.erase(spacePos + 1);
    }
}