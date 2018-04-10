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

/**
@brief Struttura dati rappresentante una PERSONA

Una persona viene rappresentata con nome, cognome, età e sesso.
Per rappresentare il sesso viene usato un valore booleano, se = 1
significa che la persona è di genere femminile, se = 0, maschile.
**/
struct persona {
  std::string nome;
  std::string cognome;
  unsigned int eta;
  bool sesso; //true= femmina, false= maschio
};

/**
@brief Operatore di ostream per la struttura custom persona

Stampa sullo standard output gli attributi di una persona, racchiusi tra
parentesi quadre.

@param os Operatore di ostream
@param p Persona da stampare

@return Operatore di ostream ridefinito
**/
std::ostream& operator<<(std::ostream &os, const persona &p)  {
    std::cout << "[" << p.nome << ", " << p.cognome << ", " << p.eta << ", " << p.sesso << "]" << std::endl;
    return os;
}

/**
@brief Funtore di confronto tra interi per ordine decrescente

Ritorna true se l'intero a è maggiore dell'intero b

@param a Primo intero
@param b Secondo intero

@return Valore booleano
**/
struct maggiore {
  bool operator()(const int a, const int b) const {
    return a > b;
  }
};

/**
@brief Funtore per il confronto tra interi per divisibilità

Ritorna true se a è divisibile per b

@param a Primo intero
@param b Primo intero

@return Valore booleano
**/
struct multiplo {
  bool operator()(const int a, const int b) const {
    return ((a%b) == 0);
  }
};

/**
@brief Funtore di confronto tra persone per età

Ritorna true se p1 è più vecchia di p2

@param p1 Prima persona
@param p2 Seconda persona

@return Valore booleano
**/
struct vecchiaia {
  bool operator()(const persona &p1, const persona &p2) const {
    return (p1.eta > p2.eta);
  }
};

/**
@brief Funtore per confronto tra persone per lunghezza del lunghezza del cognome

Ritorna true se la lunghezza del cognome di p1 è maggiore di quella del
cognome di p2

@param p1 Prima persona
@param p2 Seconda persona

@return Valore booleano
**/
struct lungh_cognome {
  bool operator()(const persona &p1, const persona &p2) const {
    return (p1.cognome.size() > p2.cognome.size());
  }
};

#endif
