#ifndef DATI_PROVA_H
#define DATI_PROVA_H

#include <iostream>
#include <string>
#include <algorithm>

/**
@file dati_prova.h
@brief File contenente strutture dati custom per il test della
classe templata sortedarray.h
**/

struct persona {
  std::string nome;
  std::string cognome;
  unsigned int eta;
  bool sesso; //true= maschio, false= femmina
};

std::ostream& operator<<(std::ostream &os, const persona &p)  {
    std::cout << "[" << p.nome << ", " << p.cognome << ", " << p.eta << ", " << p.sesso << "]" << std::endl;
    return os;
}

#endif
