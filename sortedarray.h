#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include <algorithm>
#include <iostream>
#include <cstddef>
#include <functional>

template <typename T, typename F= std::less<T> > class sorted_array {

private:

  T *nd_array;
  unsigned int size;
  unsigned int contents;
  T* *pos_array;
  F funct;

  friend class const_iterator;
  friend class unsorted_const_iterator;

public:

  sorted_array(): size(0), nd_array(0), contents(0), pos_array(0) {
  }

  explicit sorted_array(unsigned int sz= 100):
    size(sz), nd_array(0), contents(0), pos_array(0) {
    nd_array= new T[size];
    pos_array= new T*[size];
  }

  sorted_array(const sorted_array &other):
    size(0), nd_array(0), contents(0), pos_array(0) {
    size= other.getSize();
    nd_array= new T[size];
    contents= other.getContents();
    pos_array= new T*[size];

    for(int i= 0; i < contents; i++) {
      nd_array[i]= other.nd_array[i];
    }

    for(int i= 0; i < contents; i++) {
      pos_array[i]= other.pos_array+i;
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
        std::swap(tmp.nd_array[i], nd_array[i]);
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
        nd_array[0]= val;
        pos_array[0]= nd_array+0;
        contents++;
      }
      else {
        nd_array[contents]= val;
        T *tmp= nd_array+contents;
        bool flag= true;
        for (int i = 0; i < contents; i++) {
          if(funct(*tmp,*pos_array[i])) {
            flag= false;
            std::swap(tmp, pos_array[i]);
          }
        }
        if(flag) {
          pos_array[contents]= nd_array+contents;
        }
        else {
          pos_array[contents]= tmp;
        }
        contents++;
      }
    }
    else {
      std::cout << "Array pieno, impossibile inserire elemento" << std::endl;
    }
  }

  T operator[](int index) const {
        return *pos_array[index];
  }

  T operator()(int index) const {
    return nd_array[index];
  }

  void clear() {
    T *tmp= new T[size];
    delete[] nd_array;
    nd_array= tmp;
    contents= 0;
    T* *tmpPos= new T*[size];
    delete[] pos_array;
    pos_array= tmpPos;
  }

  class const_iterator;
  class unsorted_const_iterator;

  class const_iterator {
  private:

    friend class sorted_array;
    const T* *tvalue;

    const_iterator(T* *val): tvalue(val) {}

  public:

    typedef std::bidirectional_iterator_tag   iterator_category;
		typedef T*                                 value_type;
		typedef ptrdiff_t                         difference_type;
		typedef const T**                          pointer;
		typedef const T*&                          reference;

    const_iterator(): tvalue(0) {}
    const_iterator(const const_iterator &other): tvalue(other.tvalue) {}

    const_iterator& operator=(const const_iterator &other) {
      tvalue= other.tvalue;
      return *this;
    }

    ~const_iterator() {
      tvalue= 0;
    }

    reference operator*() const {
      return *tvalue;
    }

    pointer operator->() const {
      return &(*tvalue);
    }

    bool operator==(const const_iterator &other) const {
	    return tvalue == other.tvalue;
    }

  	bool operator!=(const const_iterator &other) const {
  		return tvalue != other.tvalue;
  	}

    const_iterator operator++() {
          return const_iterator(**tvalue+1);
    }

  };

  const_iterator begin() const {
        return const_iterator(pos_array+0);
  }

  const_iterator end() const {
        return const_iterator(pos_array+contents-1);
  }

  class unsorted_const_iterator {
  private:

    friend class sorted_array;
    const T *tvalue;

    unsorted_const_iterator(const T *val): tvalue(val) {}

  public:

    typedef std::bidirectional_iterator_tag   iterator_category;
		typedef T                                 value_type;
		typedef ptrdiff_t                         difference_type;
		typedef const T*                          pointer;
		typedef const T&                          reference;

    unsorted_const_iterator(): tvalue(0) {}
    unsorted_const_iterator(const unsorted_const_iterator &other): tvalue(other.tvalue) {}

    unsorted_const_iterator& operator=(const unsorted_const_iterator &other) {
      tvalue= other.tvalue;
      return *this;
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

	bool operator==(const unsorted_const_iterator &other) const {
		return tvalue == other.tvalue;
	}

	bool operator!=(const unsorted_const_iterator &other) const {
		return tvalue != other.tvalue;
	}

    unsorted_const_iterator operator++() {
      return tvalue+1;
    }

    unsorted_const_iterator operator++(int) {
      unsorted_const_iterator tmp(*this);
      tmp.tvalue= this->tvalue+1;
      return tmp;
    }

    unsorted_const_iterator operator--() {
      return tvalue-1;
    }

    unsorted_const_iterator operator--(int) {
      unsorted_const_iterator tmp(*this);
      tmp.tvalue= this->tvalue-1;
      return tmp;
    }
  };

  unsorted_const_iterator ubegin() const {
    return unsorted_const_iterator(nd_array+0);
  }

  unsorted_const_iterator uend() const {
    return unsorted_const_iterator(nd_array+contents-1);
  }

};

#endif
