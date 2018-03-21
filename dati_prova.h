#ifndef DATI_PROVA_H
#define DATI_PROVA_H

#include <iostream>
#include <string>
#include <algorithm>

struct persona {
  std::string nome;
  std::string cognome;
  unsigned int eta;
  bool sesso; //true= maschio, false= femmina

public:

  void printPerson() {
    std::cout << "[" << nome << ", " << cognome << ", " << eta << ", " << sesso << "]" << std::endl;
  }
};

#endif
