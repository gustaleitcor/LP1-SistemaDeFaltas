#pragma once
#include <exception>
#include <string>

class FileHasNotOpenException : public std::exception {

  std::string description;

public:
  FileHasNotOpenException(){};
  FileHasNotOpenException(std::string val) { description = val; };
  ~FileHasNotOpenException(){};

  std::string what() { return description; }
};

class ElementNotFoundException : public std::exception {

  std::string description;

public:
  ElementNotFoundException(){};
  ElementNotFoundException(std::string val) { description = val; };
  ~ElementNotFoundException(){};

  std::string what() { return description; }
};