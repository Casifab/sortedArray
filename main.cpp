#include "sortedarray.h"
#include "dati_prova.h"
#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char const *argv[]) {
// TEST TIPO INT
  sorted_array<int> sa(10);
  int array_int[5]= {43,6,100,1,11};

  for (int i=0; i < 5; i++) {
    sa.addElement(array_int[i]);
  }

  std::cout << "Contenuto dell'array:" << '\n';
  for (int i = 0; i < sa.getSize(); i++) {
    std::cout << sa[i] << '\n';
  }
std::cout << "---------------------------------------------------" << '\n';
  std::cout << sa.getSize() << '\n';
  std::cout << sa.getContents() << '\n';
std::cout << "----------------------------------------------------" << '\n';
  std::cout << "Array copia, ordinato secondo posizione logica:" << '\n';
  sorted_array<int> sa_v2(2);
  sa_v2= sa;
  sa_v2.addElement(300);

  for (int i = 0; i < sa_v2.getSize(); i++) {
    std::cout << sa_v2[i] << '\n';
  }
std::cout << "--------------------------------------------------------" << '\n';
// TEST TIPO PERSONA
  sorted_array<persona> sa1(10);
  persona p1= {"Francesca", "Baro", 22, false};
  persona p2= {"Fabio", "Casiraghi", 22, true};
  persona p3= {"Laura", "Fino", 56, false};
  persona p4= {"Paolo", "Rossi", 123, true};

  sa1.addElement(p1);
  sa1.addElement(p2);
  sa1.addElement(p3);
  sa1.addElement(p4);

  std::cout << "Contenuto dell'array:" << '\n';
  for (int i = 0; i < sa1.getSize(); i++) {
    sa1[i].printPerson();
  }

  std::cout << "Array copia, con operatore =, con aggiunta elemento:" << '\n';
  sorted_array<persona> sa1_v2(500);
  sa1_v2= sa1;

  persona nuova= {"Gioppo", "Prova", 23, 0};

  sa1_v2.addElement(nuova);

  for (int i = 0; i < sa1_v2.getSize(); i++) {
    sa1_v2[i].printPerson();
  }

  std::cout << "------------------------------------------------------" << '\n';
  std::cout << "Svuoto l'array:" << '\n';

  sa1_v2.clear();

  for (int i = 0; i < sa1_v2.getSize(); i++) {
    sa1_v2[i].printPerson();
  }

  return 0;
}
