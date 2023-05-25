#include "classeLeak1.h"

#include <string>

Leak::Leak(int newVal) {
  valor = newVal;
  novaStr = NULL;
}

Leak::~Leak() {

}

void Leak::printVal() {
  if (novaStr)
    std::cout << "nVal = " << valor << " sVal = " << *novaStr << "\n";
  else
    std::cout << "nVal = " << valor << "\n";
}

int Leak::getVal() {
  return valor;
}

std::string* Leak::getStr() {
  return novaStr;
}

std::string* Leak::newStr(const char* sVal) {
  novaStr = new std::string(sVal);
  return novaStr;
}