
#include <iostream>
#include <vector>
#include <windows.h>
#include "tAutoPointer.h"
#include "classeLeak1.h"

void funct1();
void funct2();
Leak* createLeak(int nVal);
Leak* createLeak2(int nVal);


//Resultado esperado:
/*
Vamos processar!
nVal = 1 sVal = Leak1
nVal = 2 sVal = Leak2
nVal = 3 sVal = Leak3
nVal = 4 sVal = Leak4
nVal = 3 sVal = Leak3
nVal = 5 sVal = Leak5
nVal = 6 sVal = Leak6
nVal = 7 sVal = Leak7
nVal = 8 sVal = Leak8
nVal = 9 sVal = Leak9
nVal = 10 sVal = Leak10
nVal = 11 sVal = Leak11
nVal = 12 sVal = Leak12
nVal = 13 sVal = Leak13
nVal = 14 sVal = Leak14
nVal = 15 sVal = Leak15
nVal = 16 sVal = Leak16
123456789
123456789 abcdefghij
*/

int main()
{
    std::cout << "Vamos processar!\n";
    {
      Leak* leak1 = new Leak(1);

      Leak leak2(2);
      leak2.newStr("Leak2");

      Leak* leak3 = createLeak(3);

      Leak* leak4 = createLeak2(4);
      //leak4->newStr("Leak4"); //GPF!

      std::vector<Leak*> listaVetor;
      listaVetor.push_back(leak3);

      for (int i = 5; i < 15; i++) {
        listaVetor.push_back(new Leak(i));
        std::string sValor = "Leak";
        sValor += std::to_string(i);
        listaVetor.back()->newStr(sValor.c_str());
      }

      tAutoPointer<Leak> leak15(new Leak(15));
      std::string* sRet15 = leak15->newStr("Leak15");

      tAutoPointer<Leak> leak16(new Leak(16));
      std::string* sRet16 = leak16->newStr("Leak16");

      leak1->newStr("Leak1");
      std::string* sRet = leak1->newStr("Leak1");

      std::string* sRet3 = leak3->newStr("Leak3");

      leak1->printVal();

      leak2.printVal();

      leak3->printVal();

      //leak4->printVal(); //GPF!
      for (Leak* tmp : listaVetor)
        tmp->printVal();

      leak15->printVal();

      leak16->printVal();

      funct1();
      funct2();

      delete sRet3;
      delete leak1;
      delete leak3;
      delete sRet16;
    }

    return 0;
}


void funct1() {
  std::string* teste = new std::string;
  *teste = "123456789";
  std::cout << *teste << "\n";
}

void funct2() {
  std::string* teste = new std::string;
  std::string* abc = new std::string("abcdefghij");
  *teste = "123456789";
  std::cout << *teste << " ";
  teste = abc;
  std::cout << *teste;
  delete teste;
}


Leak* createLeak(int nVal) {
  return new Leak(nVal);
}


Leak* createLeak2(int nVal) {
  Leak* tmp = new Leak(nVal);
  delete tmp;
  return tmp;
}