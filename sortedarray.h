#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include <algorithm>
#include <iostream>
#include <cstddef>
#include <functional>
#include <iterator>
#include <stdexcept>

/**
@file sortedarray.h
@brief Dichiarazione classe sorted_array.h

La classe contiene la definizione di un sorted_array e tre funzioni globali,
due delle quali per la stampa su standard output di un generico sorted_array
**/

/**
@brief Sorted Array templato

Classe che rappresenta un array di elementi che possono essere letti per ordine
di inserimento in memoria o per ordine logico dettato dal funtore funct
**/
template <typename T, typename F= std::less<T> > class sorted_array {

private:

  /** Array di elementi T per la memorizzazione*/
  T *nd_array;
  /** Dimensione dell'array */
  unsigned int size;
  /** Elementi contenuti nell'array */
  unsigned int contents;
  /** Array di puntatori a elementi T per l'ordine logico */
  T* *pos_array;
  /** Funtore per l'ordinamento logico */
  F funct;

  friend class const_iterator;
  friend class unsorted_const_iterator;

public:

  /**
  @brief Costruttore di default

  Costruttore di default che inizializza semplicemente l'array
  **/
  sorted_array(): size(0), nd_array(0), contents(0), pos_array(0) {
  }

  /**
  @brief Costruttore secondario

  Costruttore che istanzia un sorted_array di una data dimensione,
  se la dimensione non viene specificata viene posta a 100

  @param sz Dimensione del sorted_array

  @throw Eccezione di allocazione di memoria
  **/
  explicit sorted_array(unsigned int sz= 100): size(sz), nd_array(0), contents(0), pos_array(0) {
    try{
      nd_array= new T[size];
      pos_array= new T*[size];
    } catch(...) {
      clear();
      throw;
    }
  }

  /**
  @brief Costruttore copia

  Costruttore che istanzia un sorted_array da un altro passato
  come parametro

  @param other sorted_array da copiare

  @throw Eccezione di allocazione di memoria
  **/
  sorted_array(const sorted_array &other): size(0), nd_array(0), contents(0), pos_array(0) {
    try {
      size= other.getSize();
      nd_array= new T[size];
      contents= other.getContents();
      pos_array= new T*[size];

      for(int i= 0; i < contents; i++) {
        nd_array[i]= other.nd_array[i];
      }

      for(int i= 0; i < contents; i++) {
        pos_array[i]= other.pos_array[i];
      }
    } catch(...) {
      clear();
      throw;
    }
  }

  /**
  @brief Operatore di assegnamento

  Metodo fondamentale per l'istanziazione di un sorted_array tramite
  operatore di uguaglianza

  @param other sorted_array da assegnare
  @return reference al nuovo sorted_array
  **/
  sorted_array &operator=(const sorted_array &other) {
    if(&other != this) {
      sorted_array tmp(other);
      std::swap(tmp.size, size);
      std::swap(tmp.nd_array, nd_array);
      std::swap(tmp.contents, contents);
      std::swap(tmp.pos_array, pos_array);

      return *this;
    }
  }

  /**
  @brief Distruttore

  Rimuove il sorted_array dalla memoria
  **/
  ~sorted_array() {
    delete [] nd_array;
    nd_array= 0;
    size= 0;
    contents= 0;
    delete [] pos_array;
    pos_array= 0;
  }

  /**
  @brief Get Size

  @return Dimensione del sorted_array
  **/
  unsigned int getSize() const {
    return this->size;
  }

  /**
  @brief Get Contents

  @return Elementi contenuti dal sorted_array
  **/
  unsigned int getContents() const {
    return this->contents;
  }

  /**
  @brief Funzione per l'aggiunta di un elemento

  Aggiunge l'elemento passato come parametro al sorted_array,
  nella prima posizione disponibile. Successivamente aggiusta
  i puntatori per l'ordine logico.

  @param val Valore da inserire nel sorted_array
  **/
  void addElement(const T &val) {
    if(contents < size) {
      if(contents == 0) {
        nd_array[0]= val;
        pos_array[0]= nd_array+0;
        contents++;
      }
      else {
        nd_array[contents]= val;
        T *tmp= nd_array+contents;
        for (int i = 0; i < contents; i++) {
          if(funct(*tmp,*pos_array[i])) {
            std::swap(tmp, pos_array[i]);
          }
        }
        pos_array[contents]= tmp;
        contents++;
      }
    }
    else {
      std::cout << "Array pieno, impossibile inserire elemento" << std::endl;
    }
  }

  /**
  @brief Operatore di accesso in sola lettura per ordine logico

  @param index Indice del sorted_array
  @return Elemento del sorted_array alla posizione logica uguale a index
  **/
  const T &operator[](int index) const {
        return *pos_array[index];
  }

  /**
  @brief Operatore di accesso in sola lettura per ordine d'inserimento
  in memoria

  @param index Indice del sorted_array
  @return Elemento del sorted_array alla posizione di memorizzazione uguale
  a index
  **/
  T operator()(int index) const {
    return nd_array[index];
  }

  /**

  @brief Funzione che svuota il sorted_array

  Funzione che svuota il sorted_array, cancellando i vecchi dati in memoria
  e riallocando un nuovo sorted_array vuoto

  @throw Eccezione di allocazione di memoria
  **/
  void clear() {
    try {
      delete[] nd_array;
      T *tmp= new T[size];
      nd_array= tmp;
      contents= 0;
      delete[] pos_array;
      T* *tmpPos= new T*[size];
      pos_array= tmpPos;
    } catch(...) {
      std::cout << "Errore nell'allocazione della memoria" << '\n';
    }
  }

  class const_iterator;
  class unsorted_const_iterator;

  /**
  @brief Iteratore costante per l'ordine logico

  Classe che rappresenta un iteratore logico in sola lettura del sorted_array.
  Scorre gli elementi ordinati secondo il funtore funct
  **/
  class const_iterator {
  private:

    friend class sorted_array;
    T* const *tvalue;

    const_iterator(T* const &val): tvalue(&val) {}

  public:

    typedef std::random_access_iterator_tag   iterator_category;
		typedef T*                                 value_type;
		typedef ptrdiff_t                         difference_type;
		typedef const T**                          pointer;
		typedef const T&                          reference;

    const_iterator(): tvalue(0) {}
    const_iterator(const const_iterator &other): tvalue(other.tvalue) {}

    const_iterator& operator=(const const_iterator &other) {
      if(this != &other) {
        tvalue= other.tvalue;
        return *this;
      }
    }

    ~const_iterator() {
      tvalue= 0;
    }

    reference operator*() const {
      return (**tvalue);
    }

    pointer operator->() const {
      return &(*tvalue);
    }

    reference operator[](int index) {
      return *tvalue[index];
    }

    bool operator==(const const_iterator &other) const {
	    return tvalue == other.tvalue;
    }

  	bool operator!=(const const_iterator &other) const {
  		return tvalue != other.tvalue;
  	}

    const_iterator& operator++() {
      tvalue= tvalue+1;
      return *this;
    }

    const_iterator operator++(int) {
      const_iterator tmp(*this);
      tvalue= tvalue+1;
      return tmp;
    }

    const_iterator& operator--() {
      tvalue= tvalue-1;
      return *this;
    }

    const_iterator operator--(int) {
      const_iterator tmp(*this);
      tvalue= tvalue-1;
      return tmp;
    }

    const_iterator operator+(int offset) {
      return const_iterator(*(tvalue + offset));
    }

    const_iterator operator-(int offset) {
      return const_iterator(*(tvalue - offset));
    }

    const_iterator& operator+=(int offset) {
      tvalue+= offset;
      return *this;
    }

    const_iterator& operator-=(int offset) {
      tvalue-= offset;
      return *this;
    }

    difference_type operator-(const const_iterator &other) {
      return tvalue - other.tvalue;
    }

    bool operator>(const const_iterator &other) const {
      return tvalue > other.tvalue;
    }

    bool operator>=(const const_iterator &other) const {
      return tvalue >= other.tvalue;
    }

    bool operator<(const const_iterator &other) const {
      return tvalue < other.tvalue;
    }

    bool operator<=(const const_iterator &other) const {
      return tvalue <= other.tvalue;
    }

  };

  /**
  @brief Funzione begin per il const_iterator

  @return Puntatore al primo valore logico del sorted_array
  **/
  const_iterator begin() const {
        return const_iterator(pos_array[0]);
  }

  /**
  @brief Funzione end per il const_iterator

  @return Puntatore alla cella successiva all'ultimo valore logico
  del sorted_array
  **/
  const_iterator end() const {
        return const_iterator(pos_array[contents]);
  }

  /**
  @brief Iteratore costante per l'ordine d'inserimento

  Classe che rappresenta un iteratore per l'ordine d'inserimento
  in sola lettura del sorted_array.
  Scorre gli elementi secondo l'ordine in cui sono stati inseriti
  **/
  class unsorted_const_iterator {
  private:

    friend class sorted_array;
    const T *tvalue;

    unsorted_const_iterator(const T *val): tvalue(val) {}

  public:

    typedef std::random_access_iterator_tag   iterator_category;
		typedef T                                 value_type;
		typedef ptrdiff_t                         difference_type;
		typedef const T*                          pointer;
		typedef const T&                          reference;

    unsorted_const_iterator(): tvalue(0) {}
    unsorted_const_iterator(const unsorted_const_iterator &other): tvalue(other.tvalue) {}

    unsorted_const_iterator& operator=(const unsorted_const_iterator &other) {
      if(this != &other) {
        tvalue= other.tvalue;
        return *this;
      }
    }

    ~unsorted_const_iterator() {
      tvalue= 0;
    }

    reference operator*() const {
      return *tvalue;
    }

    pointer operator->() const {
      return &(tvalue);
    }

    reference operator[](int index) {
      return tvalue[index];
    }

  	bool operator==(const unsorted_const_iterator &other) const {
  		return tvalue == other.tvalue;
  	}

  	bool operator!=(const unsorted_const_iterator &other) const {
  		return tvalue != other.tvalue;
  	}

    unsorted_const_iterator operator++() {
      tvalue= tvalue+1;
      return *this;
    }

    unsorted_const_iterator operator++(int) {
      unsorted_const_iterator tmp(*this);
      tvalue= tvalue+1;
      return tmp;
    }

    unsorted_const_iterator operator--() {
      tvalue= tvalue-1;
      return *this;
    }

    unsorted_const_iterator operator--(int) {
      unsorted_const_iterator tmp(*this);
      tvalue= tvalue-1;
      return tmp;
    }

    unsorted_const_iterator operator+(int offset) {
      return unsorted_const_iterator(tvalue+offset);
    }

    unsorted_const_iterator operator-(int offset) {
      return unsorted_const_iterator(tvalue-offset);
    }

    unsorted_const_iterator& operator+=(int offset) {
      tvalue+= offset;
      return *this;
    }

    unsorted_const_iterator& operator-=(int offset) {
      tvalue-= offset;
      return *this;
    }

    difference_type operator-(const unsorted_const_iterator &other) {
      return tvalue - other.tvalue;
    }

    bool operator>(const unsorted_const_iterator &other) const {
      return tvalue > other.tvalue;
    }

    bool operator>=(const unsorted_const_iterator &other) const {
      return tvalue >= other.tvalue;
    }

    bool operator<(const unsorted_const_iterator &other) const {
      return tvalue < other.tvalue;
    }

    bool operator<=(const unsorted_const_iterator &other) const {
      return tvalue <= other.tvalue;
    }

  };

  /**
  @brief Funzione begin per l'unsorted_const_iterator

  @return Puntatore al primo valore in memoria del sorted_array
  **/
  unsorted_const_iterator ubegin() const {
    return unsorted_const_iterator(nd_array+0);
  }

  /**
  @brief Funzione end per l'unsorted_const_iterator

  @return Puntatore alla cella successiva all'ultimo valore in memoria
  del sorted_array
  **/
  unsorted_const_iterator uend() const {
    return unsorted_const_iterator(nd_array+contents);
  }

};

/**
@brief Funzione templata per la conta degli elementi che soddisfano
un dato predicato all'interno del sorted_array

Scorre il sorted_array e conta se e quanti elementi
verificano un determinato predicato binario insieme al valore
passato come parametro.
Stampa a schermo il numero degli elementi che soddisfano il predicato

@param sa Sorted_array da scorrere
@param val Secondo valore del predicato binario
@param pred Predicato binario da applicare tra ogni elemento
del sorted_array e val
**/
template <typename T, typename F, typename P> void find_count(const sorted_array<T,F> &sa, const T &val, P pred) {
  int count= 0;
  for(int i= 0; i < sa.getContents(); i++) {
    if(pred(sa[i], val))
      count++;
  }
  std::cout << "Trovati " << count << " elementi che soddisfano il predicato" << std::endl;
}

/**
@brief Operatore di ostream per il sorted_array

Stampa gli elementi del sorted array per ordine logico, ognuno su
una nuova riga

@param os Operatore di ostream
@param sa Sorted_array da stampare

@return Operatore di ostream ridefinito
**/
template <typename T, typename F> std::ostream& operator<<(std::ostream &os, const sorted_array<T,F> &sa) {
  for(int i= 0; i < sa.getContents(); i++) {
    std::cout << sa[i] << std::endl;
  }

  return os;
}

/**
@brief Funzione per la stampa di un sorted_array

Stampa gli elementi del sorted_array per ordine di memorizzazione,
ognuno su una nuova riga

@param sa Sorted_array da stampare
**/
template <typename T, typename F> void printMem(const sorted_array<T,F> &sa) {
  for(int i= 0; i < sa.getContents(); i++) {
    std::cout << sa(i) << std::endl;
  }
}

#endif
