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

  sorted_array<persona,vecchiaia>::const_iterator i, ie;

  std::cout << "Array per ordine di età:" << '\n';
  for (i= pers.begin(); i != pers.end(); ++i) {
    i.printPerson();
  }
  persona pp= {"Gigio", "Cuo", 30, 1};
  pers.addElement(pp);

  std::cout << "Array per ordine di età:" << '\n';
  for (int i = 0; i < pers.getContents(); i++) {
    pers[i].printPerson();
  }

  sorted_array<persona,vecchiaia> asf= pers;

  std::cout << "Array per ordine di età:" << '\n';
  for (int i = 0; i < asf.getContents(); i++) {
    asf[i].printPerson();
  }



  /*sorted_array<int,maggiore> sa(25);
  int array_int[]= {43,6,100,1,11, 4, 7 ,0, 3333,-777};

  for (int i=0; i < 10; i++) {
    sa.addElement(array_int[i]);
  }

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

  sa.addElement(42);
  sa.addElement(8);
  sa.addElement(50);

  std::cout << "Array per ordine di inserimento:" << '\n';
  for (int i = 0; i < sa.getContents(); i++) {
    std::cout << sa(i) << '\n';
  }

  std::cout << "---------------------------------------------------" << '\n';

  /*sorted_array<int,maggiore>::unsorted_const_iterator i, ie;
  i= sa.ubegin();
  ie= sa.uend();

  std::cout << *i << '\n';
  i= ++i;
  std::cout << *(ie--) << '\n';
  std::cout << *(--ie) << '\n';
*/
  return 0;
}
