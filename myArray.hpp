#ifndef MYARRAY_HPP
#define MYARRAY_HPP

#include <iostream>
#include <cassert>

using namespace std;

template <typename a, typename lb, typename ub>
class myArray {
 public:
  // overload assignment operator
  const myArray &operator=(const myArray &right);

  myArray(ub uB);

  myArray(lb lB, ub uB);

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
  a *aPtr;  // pointer to int array
  lb lowerBound;
  ub upperBound;
};

#endif

template <typename a, typename lb, typename ub>
myArray<a, lb, ub>::myArray(ub uB) {
  if (uB <= 0) {
    cout << "Array size must be positive" << endl;
    cout << "Creating an array of size 5: (0-4)" << endl;
    lowerBound = 0;
    upperBound = 4;
  } else {
    lowerBound = 0;
    upperBound = uB;
  }

  aPtr = new int[upperBound];

  for (int i = 0; i < upperBound; i++) 
    aPtr[i] = 0;
}

template <typename a, typename lb, typename ub>
myArray<a, lb, ub>::myArray(lb lB, ub uB) {
  if (lB > uB) {
    cout << "Lower Bound must be less than or equal "
         << "to upperBound" << endl;
    cout << "Creating an array of size 5: (0-4)" << endl;
    lowerBound = lB;
    upperBound = uB;
  } else {
    lowerBound = lB;
    upperBound = uB;
  }

  aPtr = new int[uB - lB];

  for (int i = 0; i < uB - lB; i++) 
    aPtr[i] = 0;
}

template <typename a, typename lb, typename ub>
myArray<a, lb, ub>::myArray() {
  lowerBound = 0;
  upperBound = 5;

  aPtr = new int[upperBound - lowerBound];

  for (int i = 0; i < upperBound - lowerBound; i++) aPtr[i] = 0;
}

template <typename a, typename lb, typename ub>
myArray<a, lb, ub>::myArray(const myArray<a, lb, ub> &copy)  // copy constructor
{
  upperBound = copy.upperBound;
  lowerBound = copy.lowerBound;

  aPtr = new int[upperBound - lowerBound];

  for (int i = 0; i < upperBound - lowerBound; i++) aPtr[i] = copy.aPtr[i];
}

template <typename a, typename lb, typename ub>
myArray<a, lb, ub>::~myArray()  // destructor
{
  delete[] aPtr;
}

// overload the assignment operator
template <typename a, typename lb, typename ub>
const myArray<a, lb, ub> &myArray<a, lb, ub>::operator=(const myArray<a, lb, ub> &right) {
  if (this != &right)  // avoid self copy
  {
    delete[] aPtr;

    upperBound = right.upperBound;
    lowerBound = right.lowerBound;

    aPtr = new int[upperBound - lowerBound];

    for (int i = 0; i < upperBound - lowerBound; i++) aPtr[i] = right.aPtr[i];
  }

  return *this;
}

template <typename a, typename lb, typename ub>
int &myArray<a, lb, ub>::operator[](int index) {
  assert(lowerBound <= index && index < upperBound);
  return aPtr[index - lowerBound];
}

template <typename a, typename lb, typename ub>
const int &myArray<a, lb, ub>::operator[](int index) const {
  assert(lowerBound <= index && index < upperBound);
  return aPtr[index - lowerBound];
}

// overload relational operators
template <typename a, typename lb, typename ub>
bool myArray<a, lb, ub>::operator==(const myArray<a, lb, ub> &right) const {
  if (upperBound != right.upperBound && lowerBound != right.lowerBound)
    return false;
  else
    for (int i = 0; i < upperBound - lowerBound; i++)
      if (aPtr[i] != right.aPtr[i]) return false;
  return true;
}

template <typename a, typename lb, typename ub>
bool myArray<a, lb, ub>::operator!=(const myArray<a, lb, ub> &right) const {
  return (!(*this == right));
}