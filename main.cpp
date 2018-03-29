#include "sortedarray.h"
#include "dati_prova.h"
#include <iostream>
#include <string>
#include <algorithm>

struct maggiore {
  bool operator()(const int a, const int b) const {
    return a > b;
  }
};

struct vecchiaia {
  bool operator()(const persona &a, const persona &b) const {
    return a.eta > b.eta;
  }
};

int main(int argc, char const *argv[]) {
/*
  persona p1= {"Francesca", "Baro", 22, 0};
  persona p2= {"Fabio", "Casiraghi", 22, 1};
  persona p3= {"peirpaloeo", "asfcasa", 45, 0};
  persona p4= {"Simba", "Nala", 1, 1};

  sorted_array<persona,vecchiaia> pers(10);
  pers.addElement(p1);
  pers.addElement(p2);
  pers.addElement(p3);
  pers.addElement(p4);

  std::cout << "Array per ordine di inserimento:" << '\n';
  for (int i = 0; i < pers.getContents(); i++) {
    pers(i).printPerson();
  }

  std::cout << "---------------------------------------------" << std::endl;

  std::cout << "Array per ordine di età:" << '\n';
  for (int i= 0; i < pers.getContents(); ++i) {
    pers[i].printPerson();
  }

std::cout << "---------------------------------------------" << std::endl;


  persona pp= {"Gigio", "Cuo", 30, 1};
  pers.addElement(pp);

  std::cout << "Array per ordine di età:" << '\n';
  for (int i = 0; i < pers.getContents(); i++) {
    pers[i].printPerson();
  }

std::cout << "---------------------------------------------" << std::endl;


  sorted_array<persona,vecchiaia> asf= pers;

  std::cout << "Array per ordine di età:" << '\n';
  for (int i = 0; i < asf.getContents(); i++) {
    asf[i].printPerson();
  }

std::cout << "---------------------------------------------" << std::endl;

*/
  sorted_array<int,maggiore> sa(25);
  int array_int[]= {43,6,100,1,11};

  for (int i=0; i < 5; i++) {
    sa.addElement(array_int[i]);
  }

  sa.addElement(3412);
  sa.addElement(8);
  sa.addElement(0);
  sa.addElement(-333);
  sa.addElement(11);
  sa.addElement(0);
  sa.addElement(-777);

  std::cout << "Array per ordine di inserimento:" << '\n';
  for (int i = 0; i < sa.getContents(); i++) {
    std::cout << sa(i) << '\n';
  }

  std::cout << "---------------------------------------------------" << '\n';
  std::cout << "Array per ordine logico:" << '\n';
  for (int i = 0; i < sa.getContents(); i++) {
    std::cout << sa[i] << '\n';
  }

  /*sa.clear();

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
*/
  std::cout << "---------------------------------------------------" << '\n';

  sorted_array<int,maggiore>::const_iterator i, ie;
  i= sa.begin();
  ie= sa.end();
  
  for(i; i != ie; i++) {
    std::cout << *i << std::endl;
  }

  std::cout << "----------------------------------------------------" << '\n';

  std::cout << *ie << std::endl;

  return 0;
}
