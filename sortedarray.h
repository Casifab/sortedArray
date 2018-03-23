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
    node(const T &newT, unsigned int pos): value(newT), logic_pos(pos) {}

    int getPosition() {
      return this->logic_pos;
    }
  };

  node *nd_array;
  unsigned int size;
  unsigned int contents;
  int *pos_array;
  F funct;

  friend class const_iterator;

public:

  sorted_array(): size(0), nd_array(0), contents(0), pos_array(0) {
  }

  explicit sorted_array(unsigned int sz= 100):
    size(sz), nd_array(0), contents(0), pos_array(0) {
    nd_array= new node[size];
    pos_array= new int[size];
  }

  sorted_array(const sorted_array &other):
    size(0), nd_array(0), contents(0), pos_array(0) {
    size= other.getSize();
    nd_array= new node[size];
    contents= other.getContents();
    pos_array= new int[size];

    for(int i= 0; i < contents; i++) {
      nd_array[i].value= other.nd_array[i].value;
      nd_array[i].logic_pos= other.nd_array[i].logic_pos;
    }

    for(int i= 0; i < contents; i++) {
      pos_array[i]= other.pos_array[i];
    }
  }

  sorted_array &operator=(const sorted_array &other) {
    if(&other != this) {
      sorted_array tmp(other);
      std::swap(tmp.size, size);
      std::swap(tmp.nd_array, nd_array);
      std::swap(tmp.contents, contents);
      std::swap(tmp.pos_array, pos_array);

      for (int i = 0; i < contents; i++) {
        std::swap(tmp.nd_array[i].value, nd_array[i].value);
        std::swap(tmp.nd_array[i].logic_pos, nd_array[i].logic_pos);
      }

      for(int i= 0; i < contents; i++) {
        std::swap(tmp.pos_array[i], pos_array[i]);
      }

      return *this;
    }
  }

  ~sorted_array() {
    delete [] nd_array;
    nd_array= 0;
    size= 0;
    contents= 0;
    delete [] pos_array;
    pos_array= 0;
  }

  unsigned int getSize() const {
    return this->size;
  }

  unsigned int getContents() const {
    return this->contents;
  }

  void addElement(const T &val) {
    if(contents < size) {
      if(contents == 0) {
        nd_array[contents].value= val;
        contents++;
      }
      else {
        T min= val;
        int pos_min= 0;
        for(int i= 0; i < contents; i++) {
          if(F(val, nd_array[i]) && !(F(min, nd_array[i]))) {
            min= nd_array[i];
            pos_min= i;
          }
        }
        nd_array[contents].value= val;
        pos_array[contents]= pos_array[pos_min];
        pos_array[pos_min]+= 1;
        for(int i= 0; i < contents; i++) {
          if(pos_array[i] > pos_array[pos_min])
            pos_array[i]+= 1;
        }
      }
    }
    else {
      std::cout << "Array pieno, impossibile inserire elemento" << std::endl;
    }
  }

  T operator[](int index) const {
    for(int i= 0; i < contents; i++) {
      if(nd_array[i].logic_pos == index) {
        return nd_array[i].value;
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
    int *tmpInt= new int[size];
    delete[] pos_array;
    pos_array= tmpInt;
  }

  void printLogicPosition() {
    for(int i= 0; i < contents; i++) {
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
    const_iterator(const const_iterator &other): nd(other.nd) {}

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
          nd= nd+1;
          return *this;
    }

    const_iterator operator++(int) {
      const_iterator tmp(*this);
      nd= nd+1;
      return tmp;
    }

		bool operator==(const const_iterator &other) const {
			return nd == other.nd;
		}

		bool operator!=(const const_iterator &other) const {
			return nd != other.nd;
		}
  };

  const_iterator begin() const {
    for(int i= 0; i < contents; i++)
      if(nd_array[i].logic_pos == 0)
        return const_iterator(nd_array+i);
  }

  const_iterator end() const {
    for(int i= 0; i < contents; i++)
      if(nd_array[i].logic_pos == contents-1)
        return const_iterator(nd_array+i);
  }
};
#endif
