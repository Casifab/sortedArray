#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include <algorithm>
#include <iostream>

template <typename T> class sorted_array {

private:

  struct node {
    T value;
    unsigned int logic_pos;

    node():value(), logic_pos(0) {}
    node(const T &newT, unsigned int pos):value(newT), logic_pos(pos) {}
  };

  node *nd_array;
  unsigned int size;
  unsigned int contents;

public:

  sorted_array(): size(0), nd_array(0), contents(0) {
  }

  explicit sorted_array(unsigned int sz= 100): size(sz), nd_array(0), contents(0) {
    nd_array= new node[size];
  }

  sorted_array(const sorted_array &other): size(0), nd_array(0), contents(0) {
    size= other.getSize();
    nd_array= new node[size];

    for(int i= 0; i < size; i++) {
      nd_array[i].value= other.nd_array[i].value;
      nd_array[i].logic_pos= other.nd_array[i].logic_pos;
    }

    contents= other.getContents();
  }

  sorted_array &operator=(const sorted_array &other) {
    if(&other != this) {
      sorted_array tmp(other);
      std::swap(tmp.size, size);
      std::swap(tmp.nd_array, nd_array);
      std::swap(tmp.contents, contents);
      for (int i = 0; i < size; i++) {
        nd_array[i].value= other.nd_array[i].value;
        nd_array[i].logic_pos= other.nd_array[i].logic_pos;
      }

      return *this;
    }
  }

  ~sorted_array() {
    delete [] nd_array;
    nd_array= 0;
    size= 0;
  }

  unsigned int getSize() const {
    return this->size;
  }

  unsigned int getContents() const {
    return this->contents;
  }

  void addElement(const T &val) {
    if(this->contents < this->size) {
      this->nd_array[contents].value= val;
      this->contents++;
    }
    else {
      std::cout << "Array pieno, impossibile inserire elemento" << std::endl;
    }
  }

  T &operator[](int index) const {
    return nd_array[index].value;
  }

  T operator()(int pos) const {
    for(int i= 0; i < size; i++) {
      if(this->nd_array[i].logic_pos == pos) {
        return this->nd_array[i].value;
      }
    }
    return 0;
  }

  void clear() {
    node *tmp= new node[size];
    delete[] nd_array;
    nd_array= tmp;
    contents= 0;
  }

  class const_iterator {
  private:
    friend class sorted_array;
    const node *nd;

    const_iterator(const node *nodo): nd(nodo) {}

  public:

    typedef std::bidirectional_iterator_tag   iterator_category;
		typedef T                                 value_type;
		typedef ptrdiff_t                         difference_type;
		typedef const T*                          pointer;
		typedef const T&                          reference;

    
  };
};
#endif
