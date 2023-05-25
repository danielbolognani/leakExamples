#pragma once

#include <string>
#include <iostream>

class Leak
{
public:
  Leak(int newVal);
  ~Leak();

  void printVal();
  int getVal();
  std::string* newStr(const char* sVal);
  std::string* getStr();

private:
  int valor;
  std::string* novaStr;


};
