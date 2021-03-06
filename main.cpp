#include "sortedarray.h"
#include "dati_prova.h"
#include <string>

/**
@file main.cpp
@brief File di test per la classe templata sortedarray.h
**/

int main(int argc, char const *argv[]) {

  persona p1= {"Francesca", "Baro", 22, 1};
  persona p2= {"Fabio", "Casiraghi", 22, 0};
  persona p3= {"peirpaloeo", "asfcasa", 45, 0};
  persona p4= {"Simba", "Gatto", 2, 0};
  persona p5= {"Giovanna", "D'Arco", 350, 1};
  persona p6= {"Nala", "Gatto", 1, 1};
  persona p7= {"Cami", "Hawke", 27, 1};
  persona p8= {"Giovanni", "Muciaccia", 42, 0};
  persona p9= {"Daniele", "Casiraghi", 10, 0};
  persona p10= {"Ultimo", "DeiMoicani", 84, 1};

  sorted_array<persona,lungh_cognome> pers(10);
  pers.addElement(p1);
  pers.addElement(p2);
  pers.addElement(p3);
  pers.addElement(p4);
  pers.addElement(p5);
  pers.addElement(p6);
  pers.addElement(p7);
  pers.addElement(p8);
  pers.addElement(p9);
  pers.addElement(p10);

  std::cout << "PERS età" << '\n';
  std::cout << pers << std::endl;

  std::cout << "---------------------------------------------" << std::endl;

  std::cout << "PERS inserimento" << '\n';
  printMem(pers);

  std::cout << "---------------------------------------------" << std::endl;


  persona pp= {"Gigio", "Cuo", 30, 1};
  pers.addElement(pp);

  std::cout << "PERS età" << '\n';
  std::cout << pers << std::endl;

  std::cout << "---------------------------------------------" << std::endl;


  sorted_array<persona,lungh_cognome> asf(50);
  asf= pers;

  std::cout << "ASF età" << '\n';
  std::cout << asf << std::endl;

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
  printMem(sa);

  std::cout << "---------------------------------------------------" << '\n';

  std::cout << "Array per ordine logico:" << '\n';
  std::cout << sa << '\n';

  std::cout << "---------------------------------------------------" << '\n';

  sorted_array<int,maggiore>::const_iterator i, ie;
  i= sa.begin();
  ie= sa.end();

  std::cout << "CONST ITERATOR SU OGGETTI TIPO PERSONA" << '\n';

  std::cout << *i << '\n';
  std::cout << "---------------------------------" << '\n';
  if(ie>i)
    std::cout << "true" << '\n';
  else
    std::cout << "false" << '\n';

  std::cout << "---------------------------------" << '\n';
  std::cout << *(i+2) << '\n';
  std::cout << "---------------------------------" << '\n';
  std::cout << i[6] << '\n';
  std::cout << "---------------------------------" << '\n';
  i+= 7;
  std::cout << *i << '\n';
  std::cout << "----------------------------------" << '\n';
  std::cout << i[3] << '\n';
  std::cout << "----------------------------------" << '\n';
  if(i<ie)
    std::cout << "true" << '\n';
  else
    std::cout << "false" << '\n';

  std::cout << "------------------------------------" << '\n';

  sa.clear();

  std::cout << "Array per ordine logico:" << '\n';
  std::cout << sa;

  std::cout << "---------------------------------------------------" << '\n';

  std::cout << "Array per ordine di inserimento:" << '\n';
  printMem(sa);

  std::cout << "---------------------------------------------" << std::endl;


  sa.addElement(42);
  sa.addElement(8);
  sa.addElement(50);

  std::cout << "Array per ordine logico:" << '\n';
  std::cout << sa << '\n';

  multiplo mul;
  find_count(sa, 5, mul);

  lungh_cognome lc;
  persona esempio= {"ciao", "letto", 12, 0};
  find_count(pers, esempio, lc);

  return 0;
}
