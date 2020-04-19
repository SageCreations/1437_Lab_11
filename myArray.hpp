#ifndef MYARRAY_HPP
#define MYARRAY_HPP

#include <iostream>

using namespace std;

class myArray {
 public:
  // overload assignment operator
  const myArray &operator=(const myArray &right);

  myArray(int uB);

  myArray(int lB, int uB);

  myArray();

  // copy constructor
  myArray(const myArray &copy);

  // destructor
    ~myArray();

  int &operator[](int);
  const int &operator[](int) const;

  // overload relational operator
  bool operator==(const myArray &right) const;
  bool operator!=(const myArray &right) const;

 private:
  int *aPtr;  // pointer to int array
  int lowerBound;
  int upperBound;
};

#endif
