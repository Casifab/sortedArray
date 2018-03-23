#include "sortedarray.h"
#include "dati_prova.h"
#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char const *argv[]) {
// TEST TIPO INT
  sorted_array<int> sa(25);
  int array_int[5]= {43,6,100,1,11};

  for (int i=0; i < 5; i++) {
    sa.addElement(array_int[i]);
  }
  
  sa.printLogicPosition();

/*
  sa.setNodePosition(0,3);
  sa.setNodePosition(1,1);
  sa.setNodePosition(2,4);
  sa.setNodePosition(3,0);
  sa.setNodePosition(4,2);*/
/*
  sorted_array<int>::const_iterator i, ie;
  i= sa.begin();
  ie= sa.end();

  std::cout << "-----------------------------------------------------" << '\n';
  std::cout << "Print Testa e Coda:" << '\n';
  std::cout << *i << '\n';
  std::cout << *ie << '\n';
  std::cout << "Un passo avanti:" << '\n';
  ++i;
  std::cout << *i << '\n';
  std::cout << "-----------------------------------------------------" << '\n';
*/
  std::cout << "Array per ordine di inserimento:" << '\n';
  for (int i = 0; i < sa.getContents(); i++) {
    std::cout << sa(i) << '\n';
  }

  std::cout << "---------------------------------------------------" << '\n';
  std::cout << "Array per ordine logico:" << '\n';
  for (int i = 0; i < sa.getContents(); i++) {
    std::cout << sa[i] << '\n';
  }
/*
  sorted_array<int> ciccio= sa;
  std::cout << "---------------------------------------------------" << '\n';
  std::cout << "Array CICCIO per ordine logico:" << '\n';
  for (int i = 0; i < ciccio.getContents(); i++) {
    std::cout << ciccio[i] << '\n';
  }

  std::cout << "---------------------------------------------------" << '\n';
  std::cout << "Per ordine inserimento:" << '\n';
  for (int i = 0; i < ciccio.getContents(); i++) {
    std::cout << ciccio(i) << '\n';
  }
  */
  /*std::cout << "----------------------------------------------------" << '\n';
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
  }*/

  return 0;
}
