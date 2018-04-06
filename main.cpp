#include "sortedarray.h"
#include "dati_prova.h"
#include <iostream>
#include <string>
#include <algorithm>

/**
@file main.cpp
@brief File di test per la classe templata sortedarray.h
**/

struct maggiore {
  bool operator()(const int a, const int b) const {
    return a > b;
  }
};

struct multiplo {
  bool operator()(const int a, const int b) const {
    return ((a%b) == 0);
  }
};

struct vecchiaia {
  bool operator()(const persona &p1, const persona &p2) const {
    return (p1.eta > p2.eta);
  }
};

int main(int argc, char const *argv[]) {

  persona p1= {"Francesca", "Baro", 22, 0};
  persona p2= {"Fabio", "Casiraghi", 22, 1};
  persona p3= {"peirpaloeo", "asfcasa", 45, 0};
  persona p4= {"Simba", "Nala", 1, 1};

  sorted_array<persona,vecchiaia> pers(10);
  pers.addElement(p1);
  pers.addElement(p2);
  pers.addElement(p3);
  pers.addElement(p4);

  std::cout << "PERS inserimento" << '\n';
  for (int i = 0; i < pers.getContents(); i++) {
    std::cout << pers(i) << std::endl;
  }

  std::cout << "---------------------------------------------" << std::endl;

  std::cout << "PERS età" << '\n';
  for (int i= 0; i < pers.getContents(); ++i) {
    std::cout << pers[i] << std::endl;
  }

std::cout << "---------------------------------------------" << std::endl;


  persona pp= {"Gigio", "Cuo", 30, 1};
  pers.addElement(pp);

  std::cout << "PERS età" << '\n';
  for (int i = 0; i < pers.getContents(); i++) {
    std::cout << pers[i] << std::endl;
  }

std::cout << "---------------------------------------------" << std::endl;


  sorted_array<persona,vecchiaia> asf= pers;

  std::cout << "ASF età" << '\n';
  for (int i = 0; i < asf.getContents(); i++) {
    std::cout << asf[i] << std::endl;
  }

std::cout << "---------------------------------------------" << std::endl;

  sorted_array<int,maggiore> sa(25);
  int array_int[]= {43,6,100,1,11};

  for (int i=0; i < 5; i++) {
    sa.addElement(array_int[i]);
  }

  sa.addElement(3412);
  sa.addElement(8);
  sa.addElement(30);
  sa.addElement(-333);
  sa.addElement(-777);
  sa.addElement(4);
  sa.addElement(11);

  std::cout << "Array per ordine di inserimento:" << '\n';
  for (int i = 0; i < sa.getContents(); i++) {
    std::cout << sa(i) << '\n';
  }

  std::cout << "---------------------------------------------------" << '\n';
  std::cout << "Array per ordine logico:" << '\n';
  for (int i = 0; i < sa.getContents(); i++) {
    std::cout << sa[i] << '\n';
  }

  sa.clear();

  std::cout << "Array per ordine di inserimento:" << '\n';
  for (int i = 0; i < sa.getContents(); i++) {
    std::cout << sa(i) << '\n';
  }

  std::cout << "---------------------------------------------------" << '\n';
  std::cout << "Array per ordine logico:" << '\n';
  for (int i = 0; i < sa.getContents(); i++) {
    std::cout << sa[i] << '\n';
  }

  std::cout << "---------------------------------------------" << std::endl;


  sa.addElement(42);
  sa.addElement(8);
  sa.addElement(50);

  std::cout << "Array per ordine di inserimento:" << '\n';
  for (int i = 0; i < sa.getContents(); i++) {
    std::cout << sa(i) << '\n';
  }

  std::cout << "---------------------------------------------------" << '\n';

  sorted_array<persona,vecchiaia>::const_iterator i, ie;
  i= pers.begin();
  ie= pers.end();

  std::cout << "CONST ITERATOR SU OGGETTI TIPO PERSONA \n" << '\n';
  for(i; i != ie; i++) {
    std::cout << *i << std::endl;
  }

  std::cout << "----------------------------------------------------" << '\n';

  std::cout << *ie << std::endl;

  std::cout << "----------------------------------------------------" << '\n';

  multiplo mul;

  find_count(sa, 4, mul);

  return 0;
}
