#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include <algorithm>
#include <iostream>
#include <cstddef>
#include <functional>

template <typename T, typename F= std::less<T> > class sorted_array {

private:

  struct node {
    T value;
    unsigned int logic_pos;

    node():value(), logic_pos(0) {}
    node(const T &newT, unsigned int pos):value(newT), logic_pos(pos) {}

    int getPosition() {
      return this->logic_pos;
    }
  };

  node *nd_array;
  unsigned int size;
  unsigned int contents;
  F funct;

  friend class const_iterator;

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
    int newLogicPos= 0;
    if(this->contents < this->size) {
      this->nd_array[contents].value= val;
      this->contents++;
    }
    else {
      std::cout << "Array pieno, impossibile inserire elemento" << std::endl;
    }
  }

  T operator[](int index) const {
    for(int i= 0; i < size; i++) {
      if(this->nd_array[i].logic_pos == index) {
        return this->nd_array[i].value;
      }
    }
    return 0;
  }

  T operator()(int index) const {
    return nd_array[index].value;
  }

  void clear() {
    node *tmp= new node[size];
    delete[] nd_array;
    nd_array= tmp;
    contents= 0;
  }

  void printLogicPosition() {
    for(int i= 0; i < size; i++) {
      std::cout << nd_array[i].logic_pos << '\n';
    }
  }

  void setNodePosition(unsigned int arr_pos, unsigned int new_pos) {
    this->nd_array[arr_pos].logic_pos= new_pos;
  }

  class const_iterator;
  class unsorted_const_iterator;

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

    const_iterator(): nd(0) {}
    const_iterator(const const_iterator &other): nd(other) {}

    const_iterator& operator=(const const_iterator &other) {
      nd= other.nd;
      return *this;
    }

    ~const_iterator() {
      nd= 0;
    }

    reference operator*() const {
      return nd->value;
    }

    pointer operator->() const {
      return &(nd->value);
    }

    const_iterator& operator++() {
      for(int i= 0; i < contents; i++) {
        if(nd_array[i]->logic_pos == (nd->logic_pos+1)) {
          nd= nd_array[i];
          return *this;
        }
      }
    }


  };
};
#endif
